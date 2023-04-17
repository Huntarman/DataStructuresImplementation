//
// Created by micha on 20.03.2023.
//

#ifndef UNTITLED_REDBLACKTREE_H
#define UNTITLED_REDBLACKTREE_H


#include "NodeRB.h"
//TODO komentarze
class RedBlackTree {
private:
    int size = 0;
    NodeRB* root = nullptr;
    NodeRB* nullNode;//wspolny wskaznik na kazdy tzw. lisc NIL
    void printTree(NodeRB* node, std::string interspace,bool right);
    NodeRB* searchKey(NodeRB* node, int key);//funkcja wspomagajaca do szukania wezlow
    void deleteValue(NodeRB* node, int key);//funkcja wspomagajaca do usuwania wezlow
    void rotateRight(NodeRB* node);//funkcja wykonywujaca prawa rotacje wezla
    void rotateLeft(NodeRB* node);//funkcja wykonywujaca lewa rotacje wezla
    void replaceNodes(NodeRB* node1, NodeRB* node2);//funkcja zamieniajaca 2 wezly miejscami
public:
    RedBlackTree();
    NodeRB* findMinimumNode(NodeRB* node);//funkcja zwracajaca wartosc minimalna drzewa/poddrzewa
    NodeRB* findMaximumNode(NodeRB* node);//funkcja zwracajaca wartosc maksymalna drzewa/poddrzewa
    void addValue(int value);//funkcja dodajaca wezel oraz naprawiająca strukture drzewa
    void addValue();
    void deleteValue(int key);//funkcja usuwuajaca pierwszy napotkany wezel zawierajacy dana wartosc
    void printTree();
    void addNElements(int amount); // funkcja dodaje n wezlow o losowych wartosciavh
    int getSize();//zwraca ilosc elementow drzewa
    NodeRB* searchKey(int key);//funkcja zwracajaca pierwszy napotkany wezel zawierajacy dana wartosc
    bool searchKeyBool(int key);//funkcja zwracajaca pierwszy napotkany wezel zawierajacy dana wartosc
};


#endif //UNTITLED_REDBLACKTREE_H
