#include "mage.h"
int mage[11][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
}; //迷宫 1是障碍，0是通路，四周用1表示围墙

bool DFS(Stack &s, point begin, point end)
{                               // begin是起点坐标，end是终点坐标
    begin.d = 0;                //起点方向赋值，进入遍历
    s.push(begin);              //起点入栈
    mage[begin.y][begin.x] = 2; //为避免重复，走过的点统一设置为2
    while (!s.empty())
    {
        point t = s.getTop(); //取栈顶数据
        int x = t.x;
        int y = t.y;
        int d = t.d;
        if (x == end.x && y == end.y)
            return true; //若到达终点，则结束

        bool f = false; // f为该点周围找到可走点
        while (!f && ++d < 5)
        { // d为方向，有4个方向
            switch (d)
            {
            case 1: //右
                x = t.x + 1;
                y = t.y;
                break;
            case 2: //下
                x = t.x;
                y = t.y + 1;
                break;
            case 3: //左
                x = t.x - 1;
                y = t.y;
                break;
            case 4: //上
                x = t.x;
                y = t.y - 1;
                break;
            }

            if (mage[y][x] == 0) //该点受否有障碍或已走
                f = true;        // 0表示没有障碍，没有走过
        }

        if (f)
        {
            s.setTopFlag(d); //设置方向
            point e;
            e.x = x;
            e.y = y;
            e.d = 0;
            s.push(e);      //保存该点数据
            mage[y][x] = 2; //将该点设置为已走
        }
        else
        {
            mage[t.y][t.x] = 0; //将该点还原
            s.pop();            //将该点路径删除
        }
    }

    return false;
}

void show()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 10; j++)
            if (mage[i][j] == 1) // 1表示障碍
                cout << " *";
            else if (mage[i][j] == 2) // 2表示点走的路径
                cout << " &";
            else
                cout << "  "; // 0表示通路
        cout << endl;
    }
    cout << endl;
}

void visit(Stack &c)
{ //点走的每一步，栈中路径是反的，将链表数据倒置
    LinkStack p = NULL, q = c.s;
    while (q)
    { //倒置链表
        LinkStack t = q->next;
        q->next = p;
        p = q;
        q = t;
    }
    while (p)
    {
        cout << "(" << p->data.x << "," << p->data.y << "," << p->data.d << ")\n";
        p = p->next;
    }
    cout << endl;
}