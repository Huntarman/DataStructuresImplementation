//
// Created by micha on 13.03.2023.
//

#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H

#include "Node.h"

class LinkedList{
private:
    int size;
    Node* frontOfList;//"najmlodszy" element listy - najbardziej na prawo
    Node* backOfList;//"najstarszy" element listy - najbardziej na lewo
public:
    LinkedList();
    void addValueFront();//funkcja umieszczajaca element o losowej typu Node na wskaznik początku listy
    void addValueFront(int value);//funkcja umieszczajaca element typu Node na wskaznik początku listy
    void addValueBack();//funkcja umieszczajaca element typu Node na wskaznik koncu listy
    void addValueBack(int value);//funkcja umieszczajaca element typu Node na wskaznik koncu listy
    void addValueMiddle(int index);//funkcja umieszczajaca element typu Node na miejscu n-tego elementu
    void addValueMiddle(int index, int value);//funkcja umieszczajaca element typu Node na miejscu n-tego elementu
    void deleteValueFront();//funkcja usuwajaca element na poczatku listy
    void deleteValueBack();//funkcja usuwajaca element na kocu listy
    void deleteValueMiddle(int index);//funkcja usuwajaca element w srodku listy
    void printList();
    void addNElements(int amount);//funkcja dodajaca n elementow na poczatek listy
    void removeList();// funkcja usuwajaca liste
    bool searchValue(int value);// zwraca prawde/falsz w zaleznosci czy lista zawira wartosc
    int getSize();
};
#endif //UNTITLED_LINKEDLIST_H
