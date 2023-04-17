//
// Created by micha on 20.03.2023.
//
#include "iostream"
#include "NodeRB.h"

NodeRB::NodeRB() {
    //konstruktor stwarzajacy wezel NIL
    value = NULL;
    color = Black;
    parent = nullptr;
    childLeft = nullptr;
    childRight = nullptr;
}
NodeRB::NodeRB(int val, NodeRB* leaf) {
    //konstruktor tworzacy wezel
    value = val;
    color = Red;
    childLeft = leaf;
    childRight = leaf;
    parent = nullptr;
}
NodeRB* NodeRB::getParent() {return parent;}
NodeRB* NodeRB::getChildRight() {return childRight;}
NodeRB* NodeRB::getChildLeft() {return childLeft;}
Colour NodeRB::getColor() {return color;}
int NodeRB::getValue() {return value;}
void NodeRB::setParent(NodeRB *newParent) {
    parent = newParent;
}
void NodeRB::setChildLeft(NodeRB *newChildLeft) {
    childLeft = newChildLeft;
}
void NodeRB::setChildRight(NodeRB *newChildRight) {
    childRight = newChildRight;
}
void NodeRB::setColor(Colour newColor) {
   color = newColor;
}
void NodeRB::recolor() {
    if (color == Red) color = Black;
    else color = Red;
}