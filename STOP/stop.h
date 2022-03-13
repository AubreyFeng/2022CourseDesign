#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

class car
{
public:
    string ID;
    time_t a;
    time_t l;
};

class Stack
{
private:
    car *data;
    int length;
    int maxSize;

public:
    Stack(int);
    ~Stack();
    int Length();
    bool isEmpyt();
    bool isFull();
    bool push(car &);
    bool pop(car &);
};

class QNode
{
public:
    car data;
    QNode *qnext;
};

class Linkqueue
{
public:
    Linkqueue();
    ~Linkqueue();
    bool IsEmpty();
    void EnQueue(car);
    void DeQueue(car &);

private:
    QNode *front;
    QNode *rear;
};

class stop
{
private:
    Stack s;
    Linkqueue q;

public:
    stop(int);
    void arrive(car);
    bool leave(string);
    int compute(car &);
    void display_in(car);
    void display_out(car);
};