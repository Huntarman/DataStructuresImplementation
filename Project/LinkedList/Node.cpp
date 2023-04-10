//
// Created by micha on 13.03.2023.
//
#include <iostream>
#include "Node.h"

Node::Node(int value1) {
    pointerPrev = NULL;
    pointerNext = NULL;
    value = value1;
}
int Node::getValue() {return value;}

void Node::setPointerNext(Node *ptr) { pointerNext = ptr;}

void Node::setPointerPrev(Node *ptr) { pointerPrev = ptr;}

Node *Node::getNext() {return pointerNext;}

Node *Node::getPrev() {return pointerPrev;}