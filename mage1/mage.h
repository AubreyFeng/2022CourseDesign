#include <iostream>
using namespace std;

struct point
{
    int x, y; //����
    int d;    //���� 1->�� 2->�� 3->�� 4->��
};
//��ջ�Ĵ洢�ṹ
typedef struct StackNode
{
    point data;
    struct StackNode *next;
} StackNode, *LinkStack;

class Stack
{
private:
    LinkStack s;

public:
    Stack();
    void push(point);           //��ջ
    bool empty();               //�п�
    bool pop();                 //��ջ
    point getTop();             //ȡջ��
    void setTopFlag(int);       //����ջ��Ԫ�ط���
    friend void visit(Stack &); //���ÿһ��
};

bool DFS(Stack &, point, point); //���·��
void show();                     //����Թ��͹켣ͼ