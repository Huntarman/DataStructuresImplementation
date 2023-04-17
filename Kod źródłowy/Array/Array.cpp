//
// Created by micha on 11.03.2023.
//
#include <iostream>
#include <random>
#include "Array.h"

using std::cout;
using std::cin;
using std::endl;
const int range = 100000;
std::random_device generatorArray;
std::uniform_int_distribution<int> distributionArray(1,range);

Array::Array() {
    size = 0;
    array = (int *) malloc(size * INT_SIZE);
}

void Array::addElementBeginning(int value) {
    //aby dodać element na początku tablicy, tzn. indeksie 0,
    //program przesuwa inne elementy tablicy, aby wylądowały na indeksie większym o 1
    //alokuje dodatkowy 4 bity pamięci do wskaznika na tablice oraz zwieksza zmienna rozmiar o 1
    size++;
    if (size == 1) {
        array = (int *) realloc(array, size * INT_SIZE);
        array[size - 1] = value;
    } else {
        array = (int *) realloc(array, size * INT_SIZE);
        int i = size - 1;
        do{
            array[i] = array[i-1];
            i--;
        } while (i>0);
        array[0] = value;
    }
}

void Array::addElementBeginning() {
    addElementBeginning(distributionArray(generatorArray));
}
void Array::addElementEnd(int value) {
    //alokuje dodatkowe 4 bity, zwieksza zmienna size, i przypisuje
    //losowa wartosc dla ostatniego indeksu tablicy
    size++;
    array = (int *) realloc(array, size * INT_SIZE);
    array[size - 1] = value;
}
void Array::addElementEnd() {
    addElementEnd(distributionArray(generatorArray));
}

void Array::addElementMiddle(int index, int value) {
    if (index == size) {
        size++;
        array = (int *) realloc(array, size * INT_SIZE);
        array[size - 1] = value;
    } else if (index < 0) {
        cout << "Incorrect index\n";
    } else if (index > size - 1) {
        cout << "Index too large\n";
    } else {
        size++;
        array = (int *) realloc(array, size * INT_SIZE);
        for (int i = size - 1; i > index - 1; i--) {
            array[i] = array[i - 1];
        }
        array[index] = value;
    }
}
void Array::addElementMiddle(int index) {
    addElementMiddle(index, distributionArray(generatorArray));
}

void Array::removeElementEnd() {
    //zmniejsza pamiec zaalokowana do tablicy, efektywnie usuwajac wartosc na koncu
    if (size > 0) {
        size--;
        array = (int *) realloc(array, size * INT_SIZE);
    } else cout << "Array is empty!";
}

void Array::removeElementBeginning() {
    //tworzy tymczasowa tablice,na którą zostalo zaalokowane mniej pamieci
    //zapisujac do niej elementy oryginalnej zaczynajac od indeksu 1
    // po czym nadpisuje tablice oryginalna
    if (size > 0) {
        for (int i = 0; i < size-1; i++) {
            array[i] = array[i+1];
        }
        size--;
        array = (int *) realloc(array, size * INT_SIZE);
    } else cout << "Array is empty!";
}

void Array::removeElementMiddle(int index) {
    //analogicznie do poprzedniej funkcji, jednak zaczyna od indeksu 0
    //az do indeksu podanego, po czym przyisuje dalej zaczynajac od indeksu wiekszego o 1
    if (size > 0) {
        if (index > size - 1 || index < 0) cout << "Incorrect index!\n";
        else {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
            array = (int *) realloc(array, size * INT_SIZE);
        }
    } else cout << "Array is empty!\n";
}

void Array::addNElements(int amount) {
    //wykonuje taka sama czynnosc co funkcja addElement() n razy
    if (amount > 0) {
        size += amount;
        array = (int *) realloc(array, size * INT_SIZE);
        for (int i = 0; i < size; i++) {
            array[i] = distributionArray(generatorArray);
        }
    } else {
        cout << "Wrong amount\n";
    }
}

void Array::removeArray() {
    delete[] array;
    size = 0;
    array = (int *) malloc(size * INT_SIZE);
}

bool Array::searchValue(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) return true;
    }
    return false;
}

int Array::getSize() { return size; }

void Array::printArray() {
    if (size == 0) {
        cout << "Array is empty!";
    } else {
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << "  ";
        }
    }
};