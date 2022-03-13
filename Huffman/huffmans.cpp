#include "Huffman.h"
void HuffmanCode::EnCoding(string s)
{
    ifstream file;
    file.open(s, ios::in);
    string a;
    while (!file.eof())
    {
        string b;
        getline(file, b);
        b.append("\n");
        a.append(b);
    }
    file.close();
    cout << "Ô­ÎÄ£º\n"
         << a << endl;

    string b = Encode(a);
    cout << "±àÂë£º\n"
         << b << "\n\n\n";
    write("Code.txt", b);
}

void HuffmanCode::DeCoding(string s)
{
    ifstream file;
    file.open(s, ios::in);
    string a;
    getline(file, a);
    file.close();
    cout << "±àÂë£º\n"
         << a << endl;

    string de;
    Decode(a, de);
    cout << "ÒëÎÄ£º\n"
         << de << "\n\n\n";
    write("Textfile.txt", de);
}

void HuffmanCode::write(string f, string &str)
{
    ofstream file;
    file.open(f, ios::out);
    file << str;
    file.close();
}
