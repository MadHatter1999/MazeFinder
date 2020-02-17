#include <ostream>
#include "StackNode.h"

class Stack {
private:
    StackNode *_top;

public:
    Stack();
    virtual ~Stack();

    void Push(Point data);
    Point Peek();
    void Pop();
    bool empty();

    Point getTop();
};

