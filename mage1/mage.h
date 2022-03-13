#include <iostream>
using namespace std;

struct point
{
    int x, y; //坐标
    int d;    //方向 1->右 2->下 3->左 4->上
};
//链栈的存储结构
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
    void push(point);           //入栈
    bool empty();               //判空
    bool pop();                 //出栈
    point getTop();             //取栈顶
    void setTopFlag(int);       //设置栈顶元素方向
    friend void visit(Stack &); //输出每一步
};

bool DFS(Stack &, point, point); //求解路径
void show();                     //输出迷宫和轨迹图