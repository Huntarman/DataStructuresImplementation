#include <iostream>
#include <fstream>
#include <windows.h>
#include <random>
#include "Array/Array.h"
#include "LinkedList/LinkedList.h"
#include "HeapMax/HeapMax.h"
#include "Tree/RedBlackTree.h"

using std::cout;
using std::cin;

long long CounterStart = 0;
double PCFreq = 0.0;

void StartCounter();

double GetCounter();

void generateFile(int a);

const int range = 1000000;
std::random_device generator;
std::uniform_int_distribution<int> distribution(1,range);

int main() {
    int a;
    while (true) {
        cout << "Choose option:\n";
        cout << "1 - Dynamic Array\n";
        cout << "2 - Doubly Linked List\n";
        cout << "3 - Max type Heap\n";
        cout << "4 - Red Black Tree\n";
        cout << "5 - Generate file with nums\n";
        cout << "6 - Quit\n";
        cin >> a;
        switch (a) {
            case 1: {
                int b = 1;
                Array array;
                while (b != 10) {
                    cout << " Array: ";
                    array.printArray();
                    cout << "\n";
                    cout << "\nSize: " << array.getSize();
                    cout << "\nChoose option:\n";
                    cout << "0 - Add element at end\n";
                    cout << "1 - Add element at beginning\n";
                    cout << "2 - Add element in the middle\n";
                    cout << "3 - Delete element at end\n";
                    cout << "4 - Delete element at beginning\n";
                    cout << "5 - Delete element in the middle\n";
                    cout << "6 - Search for value\n";
                    cout << "7 - Add N elements\n";
                    cout << "8 - Create array from file\n";
                    cout << "9 - Delete array\n";
                    cout << "10 - Return to menu\n";
                    cout << "11 - Tests\n";
                    cin >> b;
                    switch (b) {
                        case 0: {
                            int value;
                            cout<<"Input :";
                            cin>>value;
                            array.addElementEnd(value);
                        }
                            break;

                        case 1: {
                            int value;
                            cout << "Input :";
                            cin >> value;
                            array.addElementBeginning(value);
                        }
                            break;

                        case 2: {
                            int index, value;
                            cout << "Index: ";
                            cin >> index;
                            cout << "Value: ";
                            cin >> value;
                            array.addElementMiddle(index,value);
                        }
                            break;

                        case 3:
                            array.removeElementEnd();
                            break;

                        case 4:
                            array.removeElementBeginning();
                            break;

                        case 5: {
                            int c;
                            cout << "Index: ";
                            cin >> c;
                            array.removeElementMiddle(c);
                        }
                            break;

                        case 6: {
                            int c;
                            cout << "Value: ";
                            cin >> c;
                            if (array.searchValue(c)) cout << "Match found";
                            else cout << "Match not found";
                        }
                            break;

                        case 7: {
                            int c;
                            cout << "How many elements: ";
                            cin >> c;
                            array.addNElements(c);
                        }
                            break;

                        case 8: {
                            std::ifstream file("data.txt");
                            int q, w;
                            file >> q;
                            for (int i = 0; i < q; i++) {
                                file >> w;
                                array.addElementEnd(w);
                            }
                            file.close();
                        }
                            break;

                        case 9:
                            array.removeArray();
                            break;

                        case 10:
                            break;

                        case 11: {
                            array.removeArray();
                            cout << array.getSize() << "\n";
                            cout << "TESTS \n";
                            cout << "Size of array:";
                            int cos;
                            cin >> cos;
                            int cond = 0;
                            while (cond != 8) {
                                cout << "TESTS|SIZE: " << cos;
                                cout << "\n1 - Add element beginning\n";
                                cout << "2 - Add element end\n";
                                cout << "3 - Add element middle\n";
                                cout << "4 - Delete element end\n";
                                cout << "5 - Delete element beginning\n";
                                cout << "6 - Delete element end\n";
                                cout << "7 - Search\n";
                                cout << "8 - Return\n";
                                cin >> cond;
                                switch (cond) {
                                    case 1: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            StartCounter();
                                            array.addElementEnd();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;

                                    case 2: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            StartCounter();
                                            array.addElementBeginning();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 3: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            StartCounter();
                                            array.addElementMiddle(cos / 2);//usuwa srodkowy element
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 4: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            StartCounter();
                                            array.removeElementEnd();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 5: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            StartCounter();
                                            array.removeElementBeginning();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 6: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            StartCounter();
                                            array.removeElementMiddle(cos / 2);
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 7: {
                                        std::ofstream file2("times.csv");

                                        for (int i = 0; i < 100; ++i) {
                                            array.addNElements(cos);
                                            int value = distribution(generator);
                                            StartCounter();
                                            array.searchValue(value);
                                            double time = GetCounter();
                                            std::string z = array.searchValue(value)? "Tak":"Nie";
                                            file2 << time << ";" << z << ";\n";
                                            cout << time << "\n";
                                            array.removeArray();
                                        }
                                        file2.close();
                                    }
                                        break;

                                    default:
                                        break;
                                }
                            }
                        }
                            break;
                        default:
                            cout << "Wrong value\n";
                            break;
                    }
                    getchar();
                    getchar();
                    system("cls");
                }
            }
                break;

            case 2: {
                int b = 0;
                LinkedList linkedList;
                while (b != 10) {
                    cout << "List: ";
                    linkedList.printList();
                    cout << "\nSize: " << linkedList.getSize();
                    cout << "\nChoose option:\n";
                    cout << "0 - Add element front\n";
                    cout << "1 - Add element end\n";
                    cout << "2 - Add element in the middle\n";
                    cout << "3 - Remove element front\n";
                    cout << "4 - Remove element end\n";
                    cout << "5 - Remove element in the middle\n";
                    cout << "6 - Search for value\n";
                    cout << "7 - Add N elements\n";
                    cout << "8 - Create list from file\n";
                    cout << "9 - Delete list\n";
                    cout << "10 - return to menu\n";
                    cout << "11 - tests\n";
                    cin >> b;
                    switch (b) {
                        case 0: {
                            int value;
                            cout << "Value: ";
                            cin >> value;
                            linkedList.addValueFront(value);
                        }
                            break;

                        case 1: {
                            int value;
                            cout << "Value: ";
                            cin >> value;
                            linkedList.addValueBack(value);
                        }
                            break;

                        case 2: {
                            int index;
                            cout << "Input index: ";
                            cin >> index;
                            int value;
                            cout << "Value: ";
                            cin >> value;
                            linkedList.addValueMiddle(index,value);
                        }
                            break;

                        case 3:
                            linkedList.deleteValueFront();
                            break;

                        case 4:
                            linkedList.deleteValueBack();
                            break;

                        case 5: {
                            int index;
                            cout << "Input index: ";
                            cin >> index;
                            linkedList.deleteValueMiddle(index);
                        }
                            break;

                        case 6: {
                            int value;
                            cout << "Input value: ";
                            cin >> value;
                            if (linkedList.searchValue(value)) cout << "Match found";
                            else cout << "Match not found";
                        }
                            break;

                        case 7: {
                            int amount;
                            cout << "Input amount: ";
                            cin >> amount;
                            linkedList.addNElements(amount);
                        }
                            break;
                        case 8: {
                            std::ifstream file("data.txt");
                            int q, w;
                            file >> q;
                            for (int i = 0; i < q; i++) {
                                file >> w;
                                linkedList.addValueFront(w);
                            }
                            file.close();
                        }
                            break;
                        case 9:
                            linkedList.removeList();
                            break;
                        case 10:
                            break;
                        case 11: {
                            linkedList.removeList();
                            cout << linkedList.getSize() << "\n";
                            cout << "TESTS \n";
                            cout << "List size: ";
                            int cos;
                            cin >> cos;
                            int cond = 0;
                            while (cond != 8) {
                                cout << "TESTS|SIZE: " << cos;
                                cout << "\n1 - Add element beginning\n";
                                cout << "2 - Add element end\n";
                                cout << "3 - Add element middle\n";
                                cout << "4 - Delete element end\n";
                                cout << "5 - Delete element beginning\n";
                                cout << "6 - Delete element end\n";
                                cout << "7 - Search\n";
                                cout << "8 - Return\n";
                                cin >> cond;
                                switch (cond) {
                                    case 1: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            StartCounter();
                                            linkedList.addValueFront();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;

                                    case 2: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            StartCounter();
                                            linkedList.addValueBack();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 3: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            StartCounter();
                                            linkedList.addValueMiddle(cos / 2);
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 4: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            StartCounter();
                                            linkedList.deleteValueFront();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 5: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            StartCounter();
                                            linkedList.deleteValueBack();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 6: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            StartCounter();
                                            linkedList.deleteValueMiddle(cos / 2);
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 7: {
                                        std::ofstream file2("times.csv");

                                        for (int i = 0; i < 100; ++i) {
                                            linkedList.addNElements(cos);
                                            int value = distribution(generator);
                                            StartCounter();
                                            linkedList.searchValue(value);
                                            double time = GetCounter();
                                            std::string z = linkedList.searchValue(value)? "Tak":"Nie";
                                            file2 << time << ";" << z << ";\n";
                                            cout << time << "\n";
                                            linkedList.removeList();
                                        }
                                        file2.close();
                                    }
                                        break;

                                    default:
                                        break;
                                }
                            }
                        }
                            break;
                        default:
                            cout << "Wrong value\n";
                            break;
                    }
                    getchar();
                    getchar();
                    system("cls");
                }
            }
                break;

            case 3: {
                HeapMax heap;
                int b = 0;
                while (b != 9) {
                    cout << "Heap: \n";
                    heap.printHeap();
                    cout << "\nSize: " << heap.getSize();
                    cout << "\nChoose option:\n";
                    cout << "0 - Add element\n";
                    cout << "1 - Delete root\n";
                    cout << "2 - Delete last value\n";
                    cout << "3 - Delete value at index\n";
                    cout << "4 - Search for value\n";
                    cout << "5 - Add n elements\n";
                    cout << "6 - Fix heap\n";
                    cout << "7 - Generate heap from file\n";
                    cout << "8 - Delete heap\n";
                    cout << "9 - Return to menu\n";
                    cout << "10 testy\n";
                    cin >> b;
                    switch (b) {
                        case 0: {
                            int value;
                            cout << "Value: ";
                            cin >> value;
                            heap.addValue(value);
                        }
                            break;
                        case 1:
                            heap.removeRoot();
                            break;
                        case 2:
                            heap.removeLastValue();
                            break;
                        case 3: {
                            int index;
                            cout << "Input index: ";
                            cin >> index;
                            heap.removeValueAtIndex(index);
                        }
                            break;
                        case 4: {
                            int value;
                            cout << "Input value: ";
                            cin >> value;
                            if (heap.searchForValue(value)) cout << "Match found";
                            else cout<<"Match not found";
                            cout << "\n";
                        }
                            break;
                        case 5: {
                            int amount;
                            cout << "Input amount: ";
                            cin >> amount;
                            heap.addNElements(amount);
                        }
                            break;
                        case 7: {
                            std::ifstream file("data.txt");
                            int w, q;
                            file >> w;
                            for (int i = 0; i < w; i++) {
                                file >> q;
                                heap.addValue(q);
                            }
                            file.close();
                        }
                            break;
                        case 6:
                            heap.buildHeap();
                            break;
                        case 8:
                            heap.deleteHeap();
                            break;
                        case 9:
                            break;
                        case 10: {
                            heap.deleteHeap();
                            cout << heap.getSize() << "\n";
                            cout << "TESTS \n";
                            cout << "Heap size:";
                            int cos;
                            cin >> cos;
                            int cond = 0;
                            while (cond != 10) {
                                cout << "TESTS|SIZE: " << cos;
                                cout << "\n1 - Add element\n";
                                cout << "2 - Delete root\n";
                                cout << "3 - Delete last element\n";
                                cout << "4 - Delete element in the middle\n";
                                cout << "5 - Search value\n";
                                cout << "6 - Search max value\n";
                                cout << "7 - Build-Heap\n";
                                cout << "8 - Add element min\n";
                                cout << "9 - Add element max\n";
                                cout << "10 - return\n";
                                cin >> cond;
                                switch (cond) {
                                    case 1: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            int pom = distribution(generator);
                                            StartCounter();
                                            heap.addValue(pom);
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;

                                    case 2: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            StartCounter();
                                            heap.removeRoot();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 3: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            StartCounter();
                                            heap.removeLastValue();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 4: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            StartCounter();
                                            heap.removeValueAtIndex((int)pow( 2,(int)((int)log2(cos) / 2)));
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 5: {
                                        std::ofstream file2("times.csv");

                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            int value = distribution(generator);
                                            StartCounter();
                                            heap.searchForValue(value);
                                            double time = GetCounter();
                                            std::string z = heap.searchForValue(value)? "Tak":"Nie";
                                            file2 << time << ";" << z << ";\n";
                                            cout << time << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 6: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            StartCounter();
                                            heap.getRoot();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 7: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            StartCounter();
                                            heap.buildHeap();
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 8: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            StartCounter();
                                            heap.addValue(0);
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                    break;

                                    case 9: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            heap.addNElements(cos);
                                            heap.buildHeap();
                                            StartCounter();
                                            heap.addValue(range * 2);
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                            heap.deleteHeap();
                                        }
                                        file2.close();
                                    }
                                    break;

                                    default:
                                        break;
                                }
                            }
                        }
                            break;
                        default:
                            cout << "Wrong value\n";
                            break;
                    }
                    getchar();
                    getchar();
                    system("cls");
                }
            }
                break;

            case 4: {
                RedBlackTree RBTree;
                int b = 0;
                while (b != 6) {
                    cout << "R B Tree: \n";
                    RBTree.printTree();
                    cout << "\nSize: " << RBTree.getSize();
                    cout << "\nChoose option:\n";
                    cout << "0 - Add value\n";
                    cout << "1 - Add random value\n";
                    cout << "2 - Delete value with key \n";
                    cout << "3 - Search for value with key\n";
                    cout << "4 - Generate a tree with n elements \n";
                    cout << "5 - Generate a tree with values from file \n";
                    cout << "6 - Return to menu\n";
                    cout << "7 - tests\n";
                    cin >> b;
                    switch (b) {
                        case 0: {
                            int value;
                            cout << "Input value:\n";
                            cin >> value;
                            RBTree.addValue(value);
                        }
                            break;

                        case 1:
                            RBTree.addValue(distribution(generator));
                            break;

                        case 2: {
                            int c;
                            cout << "Input key:\n";
                            cin >> c;
                            RBTree.deleteValue(c);
                        }
                            break;

                        case 3: {
                            int c;
                            cout << "Input key:\n";
                            cin >> c;
                            RBTree.searchKey(c);
                        }
                            break;
                        case 4: {
                            int amount;
                            cout << "Input amount: ";
                            cin >> amount;
                            RBTree.addNElements(amount);
                        }
                            break;

                        case 5: {
                            std::ifstream file("data.txt");
                            int q, w;
                            file >> q;
                            for (int i = 0; i < q; i++) {
                                file >> w;
                                RBTree.addValue(w);
                            }
                            file.close();
                        }
                            break;

                        case 6:
                            break;

                        case 7: {
                            cout << RBTree.getSize() << "\n";
                            cout << "TESTS \n";
                            cout << "Tree size:";
                            int cos;
                            cin >> cos;
                            int cond = 0;
                            while (cond != 4) {

                                cout << "TESTS|SIZE: " << cos;
                                cout << "\n1 - Add element\n";
                                cout << "2 - Delete element\n";
                                cout << "3 - Search element\n";
                                cout << "4 - return\n";
                                cin >> cond;
                                switch(cond) {
                                    case 1: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            RedBlackTree newTree;
                                            newTree.addNElements(cos);
                                            StartCounter();
                                            newTree.addValue(distribution(generator));
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 2: {
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            RedBlackTree newTree;
                                            newTree.addNElements(cos);
                                            StartCounter();
                                            newTree.deleteValue(distribution(generator));
                                            file2 << GetCounter() << ";\n";
                                            cout << GetCounter() << "\n";
                                        }
                                        file2.close();
                                    }
                                        break;
                                    case 3:{
                                        std::ofstream file2("times.csv");
                                        for (int i = 0; i < 100; ++i) {
                                            RedBlackTree newTree;
                                            newTree.addNElements(cos);
                                            int value = distribution(generator);
                                            StartCounter();
                                            newTree.searchKeyBool(value);
                                            double time = GetCounter();
                                            std::string z = newTree.searchKeyBool(value) ? "Tak":"Nie";
                                            file2 << time << ";" << z << "\n";
                                            cout << GetCounter() << "\n";
                                        }
                                        file2.close();
                                    }
                                        break;
                                    default:
                                        break;
                                }
                            }
                        }
                            break;

                        default:
                            break;
                    }
                    getchar();
                    getchar();
                    system("cls");
                }
            }
                break;

            case 5: {
                int b;
                generateFile(b);
            }
                break;

            case 6:
                exit(0);

            default:
                break;
        }

        system("cls");
    }

    return 0;
}

void StartCounter() {
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart) / 1000000.0;//czas w mikrosekundach
    //PCFreq = double(li.QuadPart)/1000.0;//czas w milisekundach
    //PCFreq = double(li.QuadPart);//czas w sekundach
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}

void generateFile(int a) {
    std::ofstream file("data.txt");
    file << a << "\n";
    for (int i = 0; i < a; i++) {
        file << distribution(generator) << "\n";
    }
    file.close();
}