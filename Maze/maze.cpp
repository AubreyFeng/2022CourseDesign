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
}; //�Թ� 1���ϰ���0��ͨ·��������1��ʾΧǽ

bool f = false; //�Ƿ񵽴��յ�
struct xy
{
    int a, b; //����
    int c;    //���� 1->�� 2->�� 3->�� 4->��
};
vector<xy> d; //����·��

void show()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 10; j++)
            if (mage[i][j] == 1) // 1��ʾ�ϰ�
                cout << " *";
            else if (mage[i][j] == 2) // 2��ʾ���ߵ�·��
                cout << " &";
            else
                cout << "  "; // 0��ʾͨ·
        cout << endl;
    }
    cout << endl;
}

void search(int y, int x, int yy, int xx)
{ //���·��
    xy t;
    t.a = y;
    t.b = x;
    mage[y][x] = 2; //���߹��ĵ�����Ϊ2

    if (f) //�����յ㣬����
        return;

    if (x == xx && y == yy)
    {             //�����յ�
        f = true; //���õ����յ�
        return;
    }

    if (!f && mage[y][x + 1] == 0)
    { //û�е��յ㣬����
        t.c = 1;
        search(y, x + 1, yy, xx);
    }
    if (!f && mage[y + 1][x] == 0)
    { //û�е��յ㣬����
        t.c = 2;
        search(y + 1, x, yy, xx);
    }
    if (!f && mage[y][x - 1] == 0)
    { //û�е��յ㣬����
        t.c = 3;
        search(y, x - 1, yy, xx);
    }
    if (!f && mage[y - 1][x] == 0)
    { //û�е��յ㣬����
        t.c = 4;
        search(y - 1, x, yy, xx);
    }
    if (f) //�����յ㣬����·��
        d.push_back(t);
    else
    { //���õ㻹ԭ
        t.c = 0;
        mage[y][x] = 0;
    }
}

void show_l()
{ //�����·�����������
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
        cout << "δ�ҵ�ͨ·��\n\n";

    system("pause");
    return 0;
}