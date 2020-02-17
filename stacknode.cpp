#include "StackNode.h"

///Custom StackNode Constructor function.
///@param data Point being put into this StackNode.
///@param next StackNode the next StackNode pointer.
StackNode::StackNode(Point data, StackNode *next) : _data(data), _next(next) { }

///Default StackNode Destructor function.
StackNode::~StackNode() = default;

///Return this StackNodes Point data.
///@return _data.
Point StackNode::getPoint() {
    return _data;
}

///Set this StackNodes Point data.
///param point Point being set.
void StackNode::setPoint(Point point) {
    _data = point;
}

///Get this StackNodes StackNode _next.
///@return _next.
StackNode *StackNode::getNext() {
    return _next;
}

///@param next The StackNode being set as the new _next.
void StackNode::setNext(StackNode *next) {
    _next = next;
}

///Check if two points are equal to each other by looking at each ones col and row property.
///@param p Point being compared to.
///@return Boolean if Points are equal.
bool Point::equals(Point p) {
    return ((this->col == p.col) && (this->row == p.row));
}
