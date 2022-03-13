#include "stop.h"
stop::stop(int size) : s(size) {}

void stop::arrive(car e)
{
    if (!s.isFull())
    {
        e.a = time(0);
        display_in(e);
        s.push(e);
        cout << "���ƺ�Ϊ" << e.ID << "����" << s.Length() << "��ͣ��λ��\n";
    }

    else
        q.EnQueue(e);
}

bool stop::leave(string str)
{
    int size = s.Length();
    Stack temp(size);
    while (!s.isEmpyt())
    {
        car a;
        s.pop(a);
        cout << "���ƺ�Ϊ" << a.ID << "�˳�" << s.Length() + 1 << "��ͣ��λ��\n";
        if (a.ID == str)
        {
            display_out(a);
            break;
        }
        temp.push(a);
    }

    if (temp.Length() == size)
        return false;

    while (!temp.isEmpyt())
    {
        car a;
        temp.pop(a);
        s.push(a);
        cout << "���ƺ�Ϊ" << a.ID << "����" << s.Length() << "��ͣ��λ��\n";
    }

    if (!q.IsEmpty())
    {
        car a;
        q.DeQueue(a);
        display_in(a);
        s.push(a);
        cout << "���ƺ�Ϊ" << a.ID << "����" << s.Length() << "��ͣ��λ��\n";
    }

    return true;
}

int stop::compute(car &e)
{
    int date = e.l - e.a;
    int min = date % 3600;
    int hour = date / 3600;
    if (min > 0)
        hour += 1;

    return hour * 5;
}

void stop::display_in(car e)
{
    cout << "\n\n";
    cout << "------------------------------------" << endl;
    cout << "���ƺţ�" << e.ID << endl;
    cout << "��λ�ţ�" << s.Length() + 1 << endl;
    tm *ltm = localtime(&e.a);
    cout << "����ʱ�䣺" << ltm->tm_hour << ":" << ltm->tm_min << endl;
    cout << "------------------------------------" << endl;
}

void stop::display_out(car e)
{
    cout << "\n\n";
    cout << "------------------------------------" << endl;
    cout << "���ƺţ�" << e.ID << endl;
    tm *ltm1 = localtime(&e.a);
    cout << "����ʱ�䣺" << ltm1->tm_hour << ":" << ltm1->tm_min << endl;
    e.l = time(0);
    tm *ltm2 = localtime(&e.l);
    cout << "�뿪ʱ�䣺" << ltm2->tm_hour << ":" << ltm2->tm_min << endl;
    cout << "ͣ���ѣ�" << compute(e) << endl;
    cout << "------------------------------------" << endl;
}