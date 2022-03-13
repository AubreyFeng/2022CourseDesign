#include "mage.h"
Stack::Stack()
{
    s = NULL;
}

void Stack::push(point e)
{
    //��ջ����Ҫ�ж�ջ��
    StackNode *p = new StackNode;
    p->data = e;
    p->next = s;
    s = p;
}

bool Stack::empty()
{ //�п�
    return s == NULL;
}

bool Stack::pop()
{ //��ջ
    if (!s)
        return false;

    StackNode *p = s;
    s = s->next;
    delete p;
    return true;
}

point Stack::getTop()
{ //ȡջ��Ԫ��
    return s->data;
}

void Stack::setTopFlag(int f)
{ //����ջ�����귽��
    s->data.d = f;
}