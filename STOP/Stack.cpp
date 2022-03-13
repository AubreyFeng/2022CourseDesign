#include "stop.h"
Stack::Stack(int size)
{
    length = -1;
    maxSize = size;
    data = new car[maxSize];
}

Stack::~Stack()
{
    delete[] data;
}

int Stack::Length()
{
    return length + 1;
}

bool Stack::isEmpyt()
{
    return length == -1;
}

bool Stack::isFull()
{
    return (length + 1) == maxSize;
}

bool Stack::push(car &e)
{
    if (isFull())
        return false;

    data[++length] = e;
    return true;
}

bool Stack::pop(car &e)
{
    if (isEmpyt())
        return false;

    e = data[length--];
    return true;
}