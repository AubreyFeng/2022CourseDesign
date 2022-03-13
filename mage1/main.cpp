#include "mage.h"
int main()
{
    show();
    Stack s;
    point begin, end;
    begin.x = 1;
    begin.y = 1;
    end.x = 8;
    end.y = 9;
    if (!DFS(s, begin, end))
        cout << "no";
    visit(s);

    show();

    system("pause");
    return 0;
}