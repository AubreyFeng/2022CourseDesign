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
}; //�Թ� 1���ϰ���0��ͨ·��������1��ʾΧǽ

bool DFS(Stack &s, point begin, point end)
{                               // begin��������꣬end���յ�����
    begin.d = 0;                //��㷽��ֵ���������
    s.push(begin);              //�����ջ
    mage[begin.y][begin.x] = 2; //Ϊ�����ظ����߹��ĵ�ͳһ����Ϊ2
    while (!s.empty())
    {
        point t = s.getTop(); //ȡջ������
        int x = t.x;
        int y = t.y;
        int d = t.d;
        if (x == end.x && y == end.y)
            return true; //�������յ㣬�����

        bool f = false; // fΪ�õ���Χ�ҵ����ߵ�
        while (!f && ++d < 5)
        { // dΪ������4������
            switch (d)
            {
            case 1: //��
                x = t.x + 1;
                y = t.y;
                break;
            case 2: //��
                x = t.x;
                y = t.y + 1;
                break;
            case 3: //��
                x = t.x - 1;
                y = t.y;
                break;
            case 4: //��
                x = t.x;
                y = t.y - 1;
                break;
            }

            if (mage[y][x] == 0) //�õ��ܷ����ϰ�������
                f = true;        // 0��ʾû���ϰ���û���߹�
        }

        if (f)
        {
            s.setTopFlag(d); //���÷���
            point e;
            e.x = x;
            e.y = y;
            e.d = 0;
            s.push(e);      //����õ�����
            mage[y][x] = 2; //���õ�����Ϊ����
        }
        else
        {
            mage[t.y][t.x] = 0; //���õ㻹ԭ
            s.pop();            //���õ�·��ɾ��
        }
    }

    return false;
}

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

void visit(Stack &c)
{ //���ߵ�ÿһ����ջ��·���Ƿ��ģ����������ݵ���
    LinkStack p = NULL, q = c.s;
    while (q)
    { //��������
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