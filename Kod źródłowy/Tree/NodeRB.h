//
// Created by micha on 20.03.2023.
//

#ifndef UNTITLED_NODERB_H
#define UNTITLED_NODERB_H
#include "Colour.cpp"
//klasa pomocnicza
//przedstawia pojedynczy wezel drzewa czerwono czarnego
class NodeRB {
private:
    int value;
    NodeRB* parent;
    NodeRB* childLeft;
    NodeRB* childRight;
    Colour color;
public:
    NodeRB();
    NodeRB(int val, NodeRB* leaf);
    int getValue();
    NodeRB* getParent();
    NodeRB* getChildLeft();
    NodeRB* getChildRight();
    Colour getColor();
    void setParent(NodeRB* newParent);
    void setChildLeft(NodeRB* newChildLeft);
    void setChildRight(NodeRB* newChildRight);
    void setColor(Colour newColor);
    void recolor();
};


#endif //UNTITLED_NODERB_H
