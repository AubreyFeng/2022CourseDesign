#include "mage.h"
Stack::Stack()
{
    s = NULL;
}

void Stack::push(point e)
{
    //Á´Õ»²»ĞèÒªÅĞ¶ÏÕ»Âú
    StackNode *p = new StackNode;
    p->data = e;
    p->next = s;
    s = p;
}

bool Stack::empty()
{ //ÅĞ¿Õ
    return s == NULL;
}

bool Stack::pop()
{ //³öÕ»
    if (!s)
        return false;

    StackNode *p = s;
    s = s->next;
    delete p;
    return true;
}

point Stack::getTop()
{ //È¡Õ»¶¥ÔªËØ
    return s->data;
}

void Stack::setTopFlag(int f)
{ //ÉèÖÃÕ»¶¥×ø±ê·½Ïò
    s->data.d = f;
}