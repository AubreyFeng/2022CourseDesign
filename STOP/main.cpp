#include "stop.h"
int main()
{
    int n;
    cout << "�����복λ����";
    cin >> n;
    stop a(n);
    int choice;
    while (1)
    {
        cout << "1.����\n";
        cout << "2.�뿪\n";
        cout << "�����룺";
        car e;
        string s;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "�����복�ƺţ�";
            cin >> e.ID;
            a.arrive(e);
            break;

        case 2:
            cout << "�����복�ƺţ�";
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