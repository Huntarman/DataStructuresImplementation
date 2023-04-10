//
// Created by micha on 13.03.2023.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

//klasa pojedynczego elementu listy zawierajaca
//wartosc oraz wskazniki na nastepna i poprzednia wartosc
class Node{
private:
    const int NODE_SIZE = sizeof(Node);
    int value;
    Node* pointerNext;
    Node* pointerPrev;
public:
    Node(int value1);
    int getValue();
    void setPointerNext(Node* ptr);
    void setPointerPrev(Node* ptr);
    Node* getNext();
    Node* getPrev();
};


#endif //UNTITLED_NODERB_H
