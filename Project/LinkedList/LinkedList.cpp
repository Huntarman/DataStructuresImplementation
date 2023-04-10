//
// Created by micha on 13.03.2023.
//
#include <iostream>
#include "random"
#include "Node.h"
#include "LinkedList.h"
using std::cout;
const int range = 100000;
std::random_device generatorList;
std::uniform_int_distribution<int> distributionList(1,range);

LinkedList::LinkedList() {
    frontOfList = NULL;
    backOfList = NULL;
    size = 0;
}
void LinkedList::addValueFront(int n) {
    // tworzy element typu node
    //w wypadku bycia pierwszym elementem ustawia takze wskaznik na tyl list
    //ustawia wskaznik na nastepna wartosc poprzedniego konca listy na nowy element
    //ustawia wskaznik na poprzednia wartosc nowego elementu na poprzedni koniec listy
    // ustawia wskaznik przodu listy na ten element
    Node* node = new Node(n);
    if (size == 0){
        size++;
        frontOfList = node;
        backOfList = node;
    }
    else{
        size++;
        node->setPointerPrev(frontOfList);
        (frontOfList)->setPointerNext(node);
        frontOfList = node;
    }
}
void LinkedList::addValueFront() {
    addValueFront(distributionList(generatorList));
}
void LinkedList::addValueBack(int value) {
    // tworzy element typu node
    //w wypadku bycia pierwszym elementem ustawia takze wskaznik na przod list
    //ustawia wskaznik na poprzednia wartosc poprzedniego tylu listy na nowy element
    //ustawia wskaznik na nastepna wartosc nowego elementu na poprzedni ty; listy
    // ustawia wskaznik tylu listy na ten element
    Node* node = new Node(value);
    if (size == 0){
        size++;
        frontOfList = node;
        backOfList = node;
    }
    else{
        size++;
        node->setPointerNext(backOfList);
        (backOfList)->setPointerPrev(node);
        backOfList = node;
    }
}
void LinkedList::addValueBack() {
    addValueBack(distributionList(generatorList));
}
void LinkedList::addValueMiddle(int index, int value) {
    // tworzy element typu node
    // przechodzi przez elementy listy zaczynajac od tylu listy
    // w odpowiednim miejscu zamienia wskazniki odpowiednich elementow na siebie
    // ustawia odpowiednie wskazniki na te elementy
    if (index<0) cout<<"Incorrect index\n";
    else if(index == 0) addValueBack();
    else if (index == size) addValueFront();
    else{
        size++;
        Node* node = new Node(value);
        Node* element_pom = backOfList;
        for (int i=0;i<index-1;i++){
            element_pom = (element_pom)->getNext();
        }
        node->setPointerNext(element_pom->getNext());
        node->setPointerPrev(element_pom);
        (element_pom)->setPointerNext(node);
        (node->getNext())->setPointerPrev(node);
    }
}
void LinkedList::addValueMiddle(int index) {
    addValueMiddle(index, distributionList(generatorList));
}
void LinkedList::deleteValueFront() {
    //przuwa przod tablicy do wartosci poprzedniej
    //zmienia wskaznik na nastepna wartosc na null
    //w przypadku bycia ostatnia wartoscia zmienia wskazniki na przod i tyl na null
    if (size == 0) cout<<"List is empty\n";
    else if (size > 1) {
        Node *pom = frontOfList;
        frontOfList = (pom->getPrev());
        (frontOfList)->setPointerNext(NULL);
        free(pom);
        size--;
    }else{
        Node *pom = frontOfList;
        free(pom);
        frontOfList = NULL;
        backOfList = NULL;
        size--;
    }
}
void LinkedList::deleteValueBack() {
    //przuwa tyl tablicy do wartosci nastepnrj
    //zmienia wskaznik na poprzednia wartosc na null
    //w przypadku bycia ostatnia wartoscia zmienia wskazniki na przod i tyl na null
    if (size == 0) cout<<"List is empty\n";
    else if (size > 1) {
        Node *pom = backOfList;
        backOfList = (pom->getNext());
        (backOfList)->setPointerPrev(NULL);
        free(pom);
        size--;
    }else{
        Node *pom = frontOfList;
        free(pom);
        frontOfList = NULL;
        backOfList = NULL;
        size--;
    }
}
void LinkedList::deleteValueMiddle(int index) {
    // zaczynajac od tylu listy, po iteracji
    // zmienia wskazniki odpowiedniej wartosci na nastepny wskaznik nastepnej wartosci
    // analogicznie z poprzednimi wskaznikami
    // zwalnia miejsce usuwanego elementu
    if (size == 0) cout<<"List is empty\n";
    else if (index < 0 || index > size-1) cout<<"Incorrect index\n";
    else if (index == 0) deleteValueBack();
    else if (index == size-1) deleteValueFront();
    else if (size>1){
        Node* pom = backOfList;
        for (int i=0; i<index; i++){
            pom = pom->getNext();
        }
        (pom->getPrev())->setPointerNext(pom->getNext());
        (pom->getNext())->setPointerPrev(pom->getPrev());
        free(pom);
        size--;
    }
}
void LinkedList::addNElements(int amount) {
    //dodaje n losowych wartosci na przod listy
    for (int i=0;i<amount;i++){
        addValueFront();
    }
}
void LinkedList::removeList() {
    //usuwa wartosci z przodu tablicy tak dlugo jak istnieja jeszcze elementy
    while(backOfList != NULL && frontOfList != NULL) deleteValueFront();
}
bool LinkedList::searchValue(int value) {
    Node* pom = backOfList;
    while(pom!=NULL) {
        if (pom->getValue()==value) {
            return true;
        }
        pom = pom->getNext();
    }
    return false;
}
int LinkedList::getSize() {return size;}
void LinkedList::printList() {
    if (size == 0) cout<<"List is empty!";
    else {
        Node *pom = backOfList;
        while (pom != NULL) {
            cout<< pom->getValue() ;
            cout<< "  ";
            pom = pom->getNext();
        }
    }
}