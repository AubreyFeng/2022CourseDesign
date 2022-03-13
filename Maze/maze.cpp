#include <iostream>
#include <vector>
using namespace std;

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

bool f = false; //是否到达终点
struct xy
{
    int a, b; //坐标
    int c;    //方向 1->右 2->下 3->左 4->上
};
vector<xy> d; //保存路径

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

void search(int y, int x, int yy, int xx)
{ //求解路径
    xy t;
    t.a = y;
    t.b = x;
    mage[y][x] = 2; //将走过的点设置为2

    if (f) //到底终点，返回
        return;

    if (x == xx && y == yy)
    {             //到底终点
        f = true; //设置到达终点
        return;
    }

    if (!f && mage[y][x + 1] == 0)
    { //没有到终点，向右
        t.c = 1;
        search(y, x + 1, yy, xx);
    }
    if (!f && mage[y + 1][x] == 0)
    { //没有到终点，向下
        t.c = 2;
        search(y + 1, x, yy, xx);
    }
    if (!f && mage[y][x - 1] == 0)
    { //没有到终点，向左
        t.c = 3;
        search(y, x - 1, yy, xx);
    }
    if (!f && mage[y - 1][x] == 0)
    { //没有到终点，向上
        t.c = 4;
        search(y - 1, x, yy, xx);
    }
    if (f) //到达终点，保存路径
        d.push_back(t);
    else
    { //将该点还原
        t.c = 0;
        mage[y][x] = 0;
    }
}

void show_l()
{ //输出点路径，倒序输出
    for (int i = d.size() - 1; i > -1; i--)
        printf("(%d,%d,%d)\n", d[i].a, d[i].b, d[i].c);

    cout << endl;
}

int main()
{
    show();
    search(1, 1, 9, 8);
    if (f)
    {
        show_l();
        show();
    }
    else
        cout << "未找到通路！\n\n";

    system("pause");
    return 0;
}