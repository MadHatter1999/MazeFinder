#include <iostream>
#include "Stack.h"



///Default Construcor for the Stack.
Stack::Stack() : _top(nullptr) { }


///Custom Destructor Function for the Stack
Stack::~Stack() {
    while (_top != nullptr) {
        Pop();
    }
}


/// Push a new Point to the Stack.
///@param data Stack being pushed
void Stack::Push(Point data) {
    _top = new StackNode(data, _top);
}

///Peek into the Stack and return the current top cord
///@return Point from the topmost StackNode.
Point Stack::Peek() {
    return _top->getPoint();
}

void Stack::Pop() {
    if (_top != nullptr) {
        StackNode* node = _top;
        _top = _top->getNext();
        delete node;
    } else {
        std::cerr << "error: can not Pop() an empty Stack!" << std::endl;
    }
}


///Checks if the Stack is empty.
///@return Boolean if top is a nullptr.
bool Stack::empty() {
    return _top == nullptr;
}


///Return the topmost Point from the Stack.
///@return Point from the topmost portion of Stack.
Point Stack::getTop() {
    return _top->getPoint();
}
