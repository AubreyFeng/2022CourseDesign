#include "stop.h"
int main()
{
    int n;
    cout << "请输入车位数：";
    cin >> n;
    stop a(n);
    int choice;
    while (1)
    {
        cout << "1.进入\n";
        cout << "2.离开\n";
        cout << "请输入：";
        car e;
        string s;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "请输入车牌号：";
            cin >> e.ID;
            a.arrive(e);
            break;

        case 2:
            cout << "请输入车牌号：";
            cin >> s;
            a.leave(s);
            break;

        default:
            break;
        }
        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}