#include "stop.h"
stop::stop(int size) : s(size) {}

void stop::arrive(car e)
{
    if (!s.isFull())
    {
        e.a = time(0);
        display_in(e);
        s.push(e);
        cout << "车牌号为" << e.ID << "进入" << s.Length() << "号停车位！\n";
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
        cout << "车牌号为" << a.ID << "退出" << s.Length() + 1 << "号停车位！\n";
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
        cout << "车牌号为" << a.ID << "进入" << s.Length() << "号停车位！\n";
    }

    if (!q.IsEmpty())
    {
        car a;
        q.DeQueue(a);
        display_in(a);
        s.push(a);
        cout << "车牌号为" << a.ID << "进入" << s.Length() << "号停车位！\n";
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
    cout << "车牌号：" << e.ID << endl;
    cout << "车位号：" << s.Length() + 1 << endl;
    tm *ltm = localtime(&e.a);
    cout << "进入时间：" << ltm->tm_hour << ":" << ltm->tm_min << endl;
    cout << "------------------------------------" << endl;
}

void stop::display_out(car e)
{
    cout << "\n\n";
    cout << "------------------------------------" << endl;
    cout << "车牌号：" << e.ID << endl;
    tm *ltm1 = localtime(&e.a);
    cout << "进入时间：" << ltm1->tm_hour << ":" << ltm1->tm_min << endl;
    e.l = time(0);
    tm *ltm2 = localtime(&e.l);
    cout << "离开时间：" << ltm2->tm_hour << ":" << ltm2->tm_min << endl;
    cout << "停车费：" << compute(e) << endl;
    cout << "------------------------------------" << endl;
}