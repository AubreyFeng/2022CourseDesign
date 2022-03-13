#include "stop.h"
Linkqueue::Linkqueue()
{
    QNode *p = new QNode;
    p->qnext = NULL;
    front = p;
    rear = p;
}

Linkqueue::~Linkqueue()
{
    while (front)
    {
        rear = front->qnext;
        delete front;
        front = rear;
    }
}

bool Linkqueue::IsEmpty()
{
    if (rear == front)
        return true;
    else
        return false;
}

void Linkqueue::EnQueue(car e)
{
    QNode *pnew = new QNode;
    pnew->qnext = NULL;
    pnew->data = e;
    rear->qnext = pnew;
    rear = pnew;
}

void Linkqueue::DeQueue(car &e)
{
    QNode *p;
    p = front->qnext;
    e = p->data;
    front->qnext = front->qnext->qnext;
    if (rear == p)
        rear = front;
    delete p;
}