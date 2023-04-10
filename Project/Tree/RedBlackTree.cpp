//
// Created by micha on 20.03.2023.
//
#include "iostream"
#include "random"
#include "RedBlackTree.h"
using std::cout;
using std::cin;
using std::endl;
const int range = 1000000;
std::random_device generatorTree;
std::uniform_int_distribution<int> distributionTree(1,range);

RedBlackTree::RedBlackTree() {
    //konstruktor tworzy wezel NIL i przypisuje go do korzenia
    nullNode = new NodeRB();
    root = nullNode;
}
void RedBlackTree::addValue() {
    addValue(distributionTree(generatorTree));
}
void RedBlackTree::addValue(int value) {
    //funkcja dodaje wartosc do drzewa
    size++;
    auto node = new NodeRB(value,nullNode);
    NodeRB* pom1 = root; //zmienna sledzaca wskaznik na miejsce gdzie umiescimy node
    NodeRB* pom2 = nullptr;// zmienna sledzaca wskaznik na poprzednia wartosc pom1,
                           //de facto rodzic nowego wezla
    //znajduje odpowiednie polozenie dla wezla
    while (pom1 != nullNode){
        pom2 = pom1;
        if (node->getValue() <= pom1->getValue())
            pom1= pom1->getChildLeft();
        else pom1 = pom1->getChildRight();
    }
    node->setParent(pom2);
    //jesli rodzic wezla jest NULL oznacza to ze wezel jest korzeniem
    // ustawia korzen na node oraz zmienia jej kolor na czarny
    // algorytm konczy dzialanie
    if (pom2 == nullptr){
        root = node;
        node->setColor(Black);
        return;
    }
    //w przeciwnym wypadku ustawia wskaznik na odpowiednie dziecko dla pom2 na node
    else if (node->getValue() <= pom2->getValue()) pom2->setChildLeft(node);
    else pom2->setChildRight(node);

    // jesli rodzicem wartosci jest korzen, algorytm konczy dzialanie
    if (node->getParent()->getParent() == nullptr){
        return;
    }

    NodeRB* pom;//wskaznik pomocniczy
    //petla dziala tak dlugo jak rodzic wartosci jest czerwony
    //jesli program dojdzie do tego miejsca kolor node zawsze jest czerwony
    //wlasnosci zostaja naruszone
    //jesli rodzic jest czarny, wlasnosci drzewa nie zostaja naruszone
    while(node->getParent()->getColor() == Red){

        //wypadek jesli rodzic wskaznika node jest prawym dzieckiem swojego ojca
        if (node->getParent() == node->getParent()->getParent()->getChildRight()){
            pom = node->getParent()->getParent()->getChildLeft();//stryj

            //przypadek 1 - stryj i rodzic jest czerwony
            //zamienia kolory : stryja oraz rodzica na czarny
            //praojca (dziadka) wezla na czerwony
            //te male poddrzewo zachowuje teraz własnosci
            //naruszenie wlasnosci moze zajsc dopiero przy praojcu wezla
            //ustawiamy zmienna obserwujaca wezel na dziadka tego wezla
            if (pom->getColor() == Red){
                pom->setColor(Black);
                node->getParent()->setColor(Black);
                node->getParent()->getParent()->setColor(Red);
                node = node->getParent()->getParent();

                //przypadki 2 i 3 - rodzic jest czerwony. stryj jest czarny (lub NIL'em)
            } else {

                //przypadek 3 - wezel jest lewym dzieckiem
                //w tym przypadku zrobienie rotacji w prawo
                //rodzica wezla, zredukuje przypadek 3 do przypadku 2
                if (node == node->getParent()->getChildLeft()){
                    node = node->getParent();
                    rotateRight(node);
                }
                //przypadek 2 - wezel jest prawym dzieckiem
                //dochodzi do rotacji lewej dziadka wezla
                //ustawia kolor dziadka(teraz brata) na czerwony
                //ustawia kolor rodzica na czarny
                //aby zachowac zalozenia
                node->getParent()->setColor(Black);
                node->getParent()->getParent()->setColor(Red);
                rotateLeft(node->getParent()->getParent());


            }
        }

        //wypadek jesli rodzic wskaznika node jest lewym dzieckiem swojego ojca
        else{

            pom = node->getParent()->getParent()->getChildRight();//stryj

            //analogicznie do przypadku 1, kiedy rodzic wskaznika jest prawym dzieckiem swojego ojca
            if (pom->getColor() == Red){
                pom->setColor(Black);
                node->getParent()->setColor(Black);
                node->getParent()->getParent()->setColor(Red);
                node = node->getParent()->getParent();
            }
                //przypadki 2 i 3 - rodzic jest czerwony. stryj jest czarny (lub NIL'em).
                //jednak zachowuja sie lustrzanie do przypadkow 2 i 3, kiedy rodzic wskaznika jest prawym dzieckiem swojego ojca
            else{
                //przypadek 3 - wezel jest prawym dzieckiem
                //w tym przypadku zrobienie rotacji w lewo
                //rodzica wezla, zredukuje przypadek 3 do przypadku 2
                if (node == node->getParent()->getChildRight()){
                    node = node->getParent();
                    rotateLeft(node);
                }
                //przypadek 2 - wezel jest lewy, dzieckiem
                //dochodzi do rotacji prawej dziadka wezla
                //ustawia kolor dziadka(teraz brata) na czerwony
                //ustawia kolor rodzica na czarny
                //aby zachowac zalozenia
                node->getParent()->setColor(Black);
                node->getParent()->getParent()->setColor(Red);
                rotateRight(node->getParent()->getParent());
            }


        }
        //jezeli wskaznik sledzacy wezel osiagnie wartosc korzenia, algorytm konczy sie
        if (node == root) break;
    }
    //upewnia sie ze korzen ma kolor czarny
    root->setColor(Black);
}
void RedBlackTree::addNElements(int amount) {
    for (int i = 0; i < amount; ++i) {
        addValue();
    }
}
void RedBlackTree::replaceNodes(NodeRB* node1, NodeRB* node2) {
    //funkcja nadpisujaca wartosci wezla 2 wartosciami wezla 1
    //jest funkcja pomocnicza do usuwania wartosci
    //zaklada ze czesc dzieci zostala juz wczesniej podmieniona
    if (node1->getParent() == nullptr){
        root = node2;
    }else if (node1 == node1->getParent()->getChildLeft()){
        node1->getParent()->setChildLeft(node2);
    } else {
        node1->getParent()->setChildRight(node2);
    }
    node2->setParent(node1->getParent());
}

void RedBlackTree::deleteValue(int key) {
    deleteValue(root,key);
}

void RedBlackTree::deleteValue(NodeRB* node, int key) {
    NodeRB* pom1 = nullNode; // wezel ktory bedziemy usuwac
    NodeRB* pom2;// pomocnicze
    NodeRB* pom3;//

    pom1 = searchKey(key);
    if (pom1 == nullNode){
        cout<<"Theres no node with given key!\n";
        return;
    }
    size--;
    pom2 = pom1;
    Colour orig_Colour = pom2->getColor();//przechowuje oryginalny kolor usuwanego wezla

    //w wypadku gdy wezel ma tylok 1 dziecko nastepuje zamiana wezla z jego jedynym dzieckiem
    // jesli nie ma dzieci funcja efektywnie usuwa go z drzewa, zamieniajac go z wezlem NIL
    if(pom1->getChildLeft() == nullNode){
        pom3 = pom1->getChildRight();
        replaceNodes(pom1, pom1->getChildRight());
    }
    else if (pom1->getChildRight() == nullNode){
        pom3 = pom1->getChildLeft();
        replaceNodes(pom1, pom1->getChildLeft());
    }
    //w wypadku gdy wezel ma obydwa dzieci funkcja znajduje minimalna wartosc prawego poddrzewa
    //wezla usuwanego, aby ulatwic usuniecie elementu
    else{
        pom2 = findMinimumNode(pom2->getChildRight());
        orig_Colour = pom2->getColor();
        pom3 = pom2->getChildRight();
        if (pom2->getParent() == pom1){
            pom3->setParent(pom2);
        }
        else{
            replaceNodes(pom2,pom2->getChildRight());
            pom2->setChildRight(pom1->getChildRight());
            pom2->getChildRight()->setParent(pom2);
        }
        //nadpisanie dzieci i rodzica pom2 efektywnie wylacza wezel usuwany
        replaceNodes(pom1,pom2);
        pom2->setChildLeft(pom1->getChildLeft());
        pom2->getChildLeft()->setParent(pom2);
        pom2->setColor(pom1->getColor());
    }

    delete pom1;
    //przypadki w ktorym wezel usuwany ma czerwone dziecko zostal wziety pod uwage w poprzednim kroku
    //pom3 jest jednym z dzieci wezla usuwanego, od ktorego zaczynamy naprawe drzewa
    if (orig_Colour == Black){
        //jesli wezel usuwany mial kolor czerwony, algorytm konczy dzialanie, zalozenia nie zostana naruszone
        //wszystkie kolejne przypadki zakladaja ze ten kolor jest czarny, poza swoimi wlasnymi zalozeniami
        NodeRB* pom;
        while (pom3 != root && pom3->getColor() == Black){

            // jesli wezel obbserwowany jest lewym dzieckiem
            if (pom3 == pom3->getParent()->getChildLeft()){
                pom = pom3->getParent()->getChildRight();// brat

                //przypadek 1
                //jezeli brat jest koloru czerwonego
                //zamieniamy kolory brata oraz rodzica
                //wykonujac lewa rotacje na rodzicu sprowadzamy
                //przypadek 1 na jeden z kolejnych przypadkow
                if(pom->getColor() == Red){
                    pom->setColor(Black);
                    pom3->getParent()->setColor(Red);
                    rotateLeft(pom3->getParent());
                    pom = pom3->getParent()->getChildRight();//ustawia pom na nowego brata wezla
                }

                //przypadek 2
                //jezeli brat jest koloru czarnego, oraz oba dzieci brata sa koloru czarnego
                //ustawia kolor brata na czerwony
                if(pom->getChildLeft()->getColor()== Black &&
                        pom->getChildRight()->getColor() == Black){
                    pom->setColor(Red);
                    pom3 = pom3->getParent();//ustawia wezel na ktorym wykonywujemy dzialanie naprawy na rodzica dotychczasowego
                }


                else{

                    //przypadek 3
                    //jezeli brat jest koloru czarnego
                    //lewe dziecko brata jest czerwone
                    //prawe dziecko brata jest czarne
                    //zamiana koloru lewgo dziecka brata na czarny, koloru brata na czerwony
                    //oraz rotacja prawa brata zredukuja przypadek 3 do przypadku 4
                    if(pom->getChildRight()->getColor() == Black){
                        pom->getChildLeft()->setColor(Black);
                        pom->setColor(Red);
                        rotateRight(pom);
                        pom = pom3->getParent()->getChildRight();
                    }

                    //przypadek 4
                    //jezeli brat jest kolory czarnego, a prawe dziecko brata jest czerwone
                    //zamiana koloru tego dziecka na czarne oraz lewa rotacja rodzica wezla
                    //pozbedzie sie dodatkowego czarnego wezla
                    pom->setColor(pom3->getParent()->getColor());
                    pom3->getParent()->setColor(Black);
                    pom->getChildRight()->setColor(Black);
                    rotateLeft(pom3->getParent());
                    pom3 = root;
                }
            }


            // jesli wezel pomocniczy jest prawym dzieckiem
            // przypadki sa lustrzanym odbiciem, do przypadku gdy wezel obserwowany jest lewym dzieckiem
            else{
                pom = pom3->getParent()->getChildLeft();//brat

                //przypadek 1 (odbity)
                //jezeli brat jest koloru czerwonego
                //zamieniamy kolory brata oraz rodzica
                //wykonujac prawa rotacje na rodzicu sprowadzamy
                //przypadek 1 na jeden z kolejnych przypadkow
                if(pom->getColor() == Red){
                    pom->setColor(Black);
                    pom3->getParent()->setColor(Red);
                    rotateRight(pom3->getParent());
                    pom = pom3->getParent()->getChildLeft();//ustawia pom na nowego brata wezla
                }

                //przypadek 2 (odbity)
                //jezeli brat jest koloru czarnego, oraz oba dzieci brata sa koloru czarnego
                //ustawia kolor brata na czerwony
                if(pom->getChildRight()->getColor() == Black &&
                        pom->getChildLeft()->getColor() == Black){
                    pom->setColor(Red);
                    pom3 = pom3->getParent();//ustawia wezel na ktorym wykonywujemy dzialanie naprawy na rodzica dotychczasowego
                }



                else{

                    //przypadek 3 (odbity)
                    //jezeli brat jest koloru czarnego
                    //lewe dziecko brata jest czarne
                    //prawe dziecko brata jest czerwone
                    //zamiana koloru lewgo dziecka brata na czarny, koloru brata na czerwony
                    //oraz rotacja lewa brata zredukuja przypadek 3 do przypadku 4
                    if(pom->getChildLeft()->getColor() == Black){
                        pom->getChildRight()->setColor(Black);
                        pom->setColor(Red);
                        rotateLeft(pom);
                        pom = pom3->getParent()->getChildLeft();//ustawia pom na nowego brata
                    }

                    //przypadek 4
                    //jezeli brat jest kolory czarnego, a prawe dziecko brata jest czerwone
                    //zamiana koloru tego dziecka na czarne oraz prawa rotacja rodzica wezla
                    //pozbedzie sie dodatkowego czarnego wezla
                    pom->setColor(pom3->getParent()->getColor());
                    pom3->getParent()->setColor(Black);
                    pom->getChildLeft()->setColor(Black);
                    rotateRight(pom3->getParent());
                    pom3 = root;// ustawia wezel obserwowany na korzen
                }
            }
        }
        //upewnienie ze korzen jset koloru czarnego
        pom3->setColor(Black);
    }
}
void RedBlackTree::rotateLeft(NodeRB *node) {
    NodeRB* pom = node->getChildRight();
    //lewa rotacja wezla
    //zamienia rodzica wezla otrzymanego w argumencie na jego lewe dziecko
    //zamienia lewe dziecko tego wezla na prawe dziecko jego uprzedniego rodzica
    node->setChildRight(pom->getChildLeft());

    if(pom->getChildLeft() != nullNode)
            pom->getChildLeft()->setParent(node);

    pom->setParent(node->getParent());

    if (node->getParent() == nullptr)
            root = pom;

    else if (node == node->getParent()->getChildLeft())
            node->getParent()->setChildLeft(pom);

    else node->getParent()->setChildRight(pom);

    pom->setChildLeft(node);
    node->setParent(pom);

}

void RedBlackTree::rotateRight(NodeRB *node) {
    NodeRB* pom = node->getChildLeft();
    //prawa rotacja wezla
    //zamienia rodzica wezla otrzymanego w argumencie na jego prawe dziecko
    //zamienia prawe dziecko tego wezla na lewe dziecko jego uprzedniego rodzica
    node->setChildLeft(pom->getChildRight());

    if (pom->getChildRight() != nullNode)
        pom->getChildRight()->setParent(node);

    pom->setParent(node->getParent());

    if (node->getParent() == nullptr)
        root = pom;

    else if (node == node->getParent()->getChildRight())
        node->getParent()->setChildRight(pom);

    else node->getParent()->setChildLeft(pom);

    pom->setChildRight(node);
    node->setParent(pom);
}

void RedBlackTree::printTree() {
    if (size != 0)
    printTree(root,"",false);
    else cout<<"Tree empty!";
}

NodeRB* RedBlackTree::searchKey(int key){
    NodeRB* node = searchKey(root, key);
    return node;
}
bool RedBlackTree::searchKeyBool(int key) {
    NodeRB* node = searchKey(root, key);
    if (node == nullptr || node == nullNode) return false;
    return true;
}
NodeRB* RedBlackTree::searchKey(NodeRB* node, int key) {
    //funkcja pomocnicza szukajaca wezla
    //wykorzystuje rekurencja
    if (node != nullptr) {
        if (node->getValue() == key) {
            return node;
        } else if (node->getValue() > key) return searchKey(node->getChildLeft(), key);
        else return searchKey(node->getChildRight(), key);
    }
    return nullptr;
}

NodeRB* RedBlackTree::findMinimumNode(NodeRB *node) {
    //funkcja wykorzystujac rekurencje znajduje minimalna wartosc w poddrzewie
    NodeRB* minimum_node = node;
    while (minimum_node->getChildLeft() != nullNode) minimum_node = minimum_node->getChildLeft();
    return minimum_node;
}
NodeRB* RedBlackTree::findMaximumNode(NodeRB *node) {
    //funkcja wykorzystujac rekurencje znajduje maksymalna wartosc w poddrzewie
    NodeRB* maximum_node = node;
    while (maximum_node->getChildRight() != nullNode) maximum_node = maximum_node->getChildRight();
    return maximum_node;
}
int RedBlackTree::getSize() {return size;}
void RedBlackTree::printTree(NodeRB* node, std::string interspace, bool right){
    //funkcja rekurencyjnie printuje drzewp
    if (node != nullNode){
        cout<<interspace;
        if (right){
            cout<<"Right : ";
            interspace += "\t";
        }
        else{
            cout<<"Left  : ";
            interspace += "\t";
        }
        std::string color = node->getColor()?"BLACK":"RED";
        cout<<node->getValue()<<" "<<color<<endl;
        printTree(node->getChildLeft(),interspace,false);
        printTree(node->getChildRight(),interspace,true);
    }
}