
//Custom Structure to hold data about positions inside of the Grid and Stack.
struct Point {
public:
    int col {0};
    int row {1};

    Point() = default;
    Point(int row, int col) : col(col), row(row) {}
    bool equals(Point p);
};

class StackNode {
private:
    Point _data;
    StackNode *_next;

public:
    StackNode(Point data, StackNode* next);
    virtual ~StackNode();

    Point getPoint();
    void setPoint(Point point);

    StackNode* getNext();
    void setNext(StackNode *next);
};

