//
// Created by micha on 11.03.2023.
//

#ifndef UNTITLED_ARRAY_H
#define UNTITLED_ARRAY_H
class Array{
private:
    int* array;
    int size;
    const int INT_SIZE = sizeof(int);
    int range;
public:
    Array();
    void addElementBeginning(int value);//dodaje losowy element na początku tablicy
    void addElementBeginning();//dodaje losowy element na początku tablicy
    void addElementEnd();//dodaje losowy element na koncu tablicy tzn. na miejscu za ostatnim dotychczasowym elementem
    void addElementEnd(int a);//dodaje podany element na koncu
    void addElementMiddle(int index);//dodaje losowy element na podanym ineksie tablicy
    void addElementMiddle(int index, int value);//dodaje losowy element na podanym ineksie tablicy
    void removeElementBeginning();//usuwa element na początku tablicy
    void removeElementEnd();//usuwa ostatni elementtablicy
    void removeElementMiddle(int index);//usuwa element na podanym indeksie
    void addNElements(int amount);// dodaje do tablicy n losowych wartosci
    void removeArray();//usuwa tablice
    void printArray();//wyswietla tablice
    bool searchValue(int value);//zwraca prawda/falsz w zaleznosci czy w tablicy istnieje wartosc.
    int getSize();//zwraca wielkosc tablicy
};

#endif //UNTITLED_ARRAY_H
