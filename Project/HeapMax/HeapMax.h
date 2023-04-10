//
// Created by micha on 19.03.2023.
//

#ifndef UNTITLED_HEAPMAX_H
#define UNTITLED_HEAPMAX_H

//stos wyrażoby jest tablicą dynamiczą, której elementy zmieniają swoje indeksy
//i są inaczej rozumiane
// np indeks 0 osznacza korzen stosu
// elementy 1 i 2 to dzieci korzenia, kolejno lewy i prawy
// elementy 3 i 4 to dzieci elementu 1, a 5 i 6 elementu 2
// itd

class HeapMax {
private:
    int* heap;
    int size;
    const int INT_SIZE = sizeof(int);

    int getParentIndex(int index);//zwraca index rodzica elementu na danym indeksie
    int getChildLeft(int index);//zwraca indeks lewego dziecka -----||------
    int getChildRight(int index);//zwraca indeks prawego dziecka -----||-----
    void heapify(int index);//"naprawia" stos
public:
    HeapMax();
    void deleteHeap();
    void buildHeap();
    void addValue();//funkcja dodaje losowy element na koncu stosu, oraz wykonuje czynnosci umieszczające go w poprawnym miejscu
    void addValue(int value);//funkcja dodaje element na koncu stosu, oraz wykonuje czynnosci umieszczające go w poprawnym miejscu
    void removeRoot();//funkcja usuwająca korzen i "naprawiajaca" stos
    void removeLastValue();//funkcja usuwajaca najmlodszy element stosu
    void removeValueAtIndex(int index);//fukcja usuwa element z indeksu i "naprawia" stos
    int getRoot();//zwraca wartosc korzenia
    bool searchForValue(int value);//funkcja zwraca indeks pierwszej wartosci podanej w argumencie
    void addNElements(int n);//dodaje n elementow na koniec stosu, wykorzystujac funkcje addValue
    void printHeap();//wyswietla stos
    int getSize();//zwraca wielkosc stosu

};


#endif //UNTITLED_HEAPMAX_H
