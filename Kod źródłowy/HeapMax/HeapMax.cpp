//
// Created by micha on 19.03.2023.
//
#include <iostream>
#include <cmath>
#include <random>
#include "HeapMax.h"
using std::cout;
using std::cin;
using std::endl;
const int range = 100000;
std::random_device generatorHeap;
std::uniform_int_distribution<int> distributionHeap(1,range);
HeapMax::HeapMax() {
    size = 0;
    heap = (int*) malloc(size*INT_SIZE);
}
void HeapMax::addValue() {
    //dodaje wartosc na ostatnim indeksie tablicy, ktora wyrazony jest stos
    size++;
    heap = (int*) realloc(heap, size * INT_SIZE);
    if (size == 0){
        heap[0] = distributionHeap(generatorHeap);
    }
    else{
        //zamienia indeksy elementow pomiedzy rodzicem a aktualnym, tak długo az wartosc nie jest mniejsza niz ejj rodzic
        // lub wartosc nie jest korzeniem
        heap[size - 1] = distributionHeap(generatorHeap);
        int indexCurr = size - 1;
        while (indexCurr!= 0 && heap[getParentIndex(indexCurr)] < heap[indexCurr]){
            int pom = heap[indexCurr];
            heap[indexCurr] = heap[getParentIndex(indexCurr)];
            heap[getParentIndex(indexCurr)] = pom;
            indexCurr = getParentIndex(indexCurr);
        }
    }
}
void HeapMax::addValue(int value) {
    //analogicznie, jednak przyjmuje wartosc argumentu
    size++;
    heap = (int*) realloc(heap, size * INT_SIZE);
    if (size == 0){
        heap[0] = value;
    }
    else{
        heap[size - 1] = value;
        int indexCurr = size - 1;
        while (indexCurr!= 0 && heap[getParentIndex(indexCurr)] < heap[indexCurr]){
            int pom = heap[indexCurr];
            heap[indexCurr] = heap[getParentIndex(indexCurr)];
            heap[getParentIndex(indexCurr)] = pom;
            indexCurr = getParentIndex(indexCurr);
        }
    }
}
void HeapMax::removeRoot() {
    //zamienia korzen oraz ostatni element stosu
    //zmniejsza stos ofektywnie usuwajac poprzedni korzen
    if (size == 0) cout<<"Heap is empty!"<<endl;
    else {
        heap[0] = heap[size - 1];
        size--;
        heap = (int *) realloc(heap, size * INT_SIZE);
        //tak dlugo jak jedno z dzieci, elementu jest wieksze niz element,
        //zamienia sie miejscami, z wiekszym z jej dzieci
        // pętla kontynuuje sie tak dlugo jak indeks lewego dziecka jest mniejszy niz
        //wielkosc stosu, co oznaczaloby dotarcie wartosci na "dól" syosu
        //albo tak dlugo jak jedno z dzieci jest wieksze niz wartosc
        heapify(0);
    }
}
void HeapMax::removeValueAtIndex(int index) {
    //funkcja dziala analogicznie do poprzedniej, jednak zamienia element na indeksie
    //z elementem ostatnim
    if (size == 0) cout<<"Heap is empty!"<<endl;
    else if (index<0 || index>size-1) cout<<"Incorrect index";
    else if (index == size-1) removeLastValue();
    else {
        heap[index] = heap[size - 1];
        size--;
        heap = (int *) realloc(heap, size * INT_SIZE);
        heapify(index);
    }
}
void HeapMax::removeLastValue() {
    //zmniejsza zaalokowana pamiec, usuwajac element na ostatnim indeksie
    if (size == 0) cout<<"Heap is empty!"<<endl;
    else {
        size--;
        heap = (int *) realloc(heap, size * INT_SIZE);
    }
}
int HeapMax::getRoot() {return heap[0];}//zwraca wartosc korzenia
bool HeapMax::searchForValue(int value) {
    //zwraca indeks szukanej wartosci
    for (int i=0;i<size;i++){
        if (heap[i] == value){
            return true;
        }
    }
    return false;
}
void HeapMax::buildHeap() {
    for (int i = size / 2 - 1;i>=0;i--) heapify(i);
}
void HeapMax::heapify(int index) {
    //naprawia miejsce danego wezla w stosie
    int largest;
    if (getChildLeft(index) < size && heap[getChildLeft(index)] > heap[index]) largest = getChildLeft(index);
    else largest = index;
    if (getChildRight(index) < size && heap[getChildRight(index)] > heap[largest]) largest = getChildRight(index);
    if (largest != index) {
        int pom = heap[largest];
        heap[largest] = heap[index];
        heap[index] = pom;
        heapify(largest);
    }
}
void HeapMax::addNElements(int n) {
    //dodaej n wartosci do tablicy, przy uzyciu funkcji addValue()
    if (n<0) cout<<"Incorrect amount"<<endl;
    else {
        for (int i = 0; i < n; ++i) {
            size++;
            heap = (int*) realloc(heap, size * INT_SIZE);
            heap[size-1] = distributionHeap(generatorHeap);
        }
    }
}
void HeapMax::deleteHeap() {
    delete heap;
    size = 0;
    heap = (int *) malloc(size * INT_SIZE);
}
void HeapMax::printHeap() {
    //wyswietla stos
    if (size == 0) cout << "Heap empty!" << endl;
    else {
        int heightHeap = log2(size);
        int maxWidth = pow(2, heightHeap + 1) - 1;
        int start = 0, end = 0;
        for (int i = 0; i <= heightHeap; i++) {
            int level = pow(2, i);
            start = end;
            end += level;
            int level_width = end - start;
            int left_padding = (maxWidth - level_width) / 2;
            for (int j = 0; j < left_padding; j++) {
                cout << " ";
            }
            for (int j = start; j < end; j++) {
                if (j<size) cout << heap[j];
                if (j != end - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
int HeapMax::getParentIndex(int index) {return (index - 1) / 2;}
int HeapMax::getChildLeft(int index) {return (2 * index) + 1;}
int HeapMax::getChildRight(int index) {return (2 * index) + 2;}
int HeapMax::getSize() {return size;}