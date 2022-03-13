#include "Huffman.h"
/*���캯��*/
HuffmanCode::HuffmanCode()
{
    // 1.��ʼ��HuffmanTree����
    HuffmanTree = new HuffmanNode[256];
    for (int i = 0; i < 256; i++)
    { // Ҷ�ӽ��Ϊlen,���������2*len-1�����
        HuffmanTree[i].leftChild = HuffmanTree[i].rightChild =
            HuffmanTree[i].parent = -1;
        HuffmanTree[i].code = "";
    }
}

/*���ɹ�������*/
void HuffmanCode::set(string s)
{
    int i;
    // 2.�������ļ�DataFile.data�ж����ַ���ÿ���ַ���Ȩֵ��������������HuffTree
    ifstream file;
    file.open(s, ios::in);
    for (i = 0; !file.eof(); i++)
    {
        file >> HuffmanTree[i].ch;
        file >> HuffmanTree[i].weight;
    }
    leafSize = i;
    file.close();

    // 3.ѡȡ������Сֵ�ϲ�
    int first, second; // ������С�Ľ��
    for (i = leafSize; i < (2 * leafSize - 1); i++)
    {                             // ��leafSize-1��
        getMin(first, second, i); // ѡȡ������С��Ԫ��
        Merge(first, second, i);  // �ϲ�
    }
}

/*��������*/
HuffmanCode::~HuffmanCode()
{
    delete[] HuffmanTree;
}

/*ѡȡȨֵ������С��Ԫ��*/
void HuffmanCode::getMin(int &first, int &second, int parent)
{
    double weight = 0;
    int i;

    // ��Ȩ����СԪ��
    for (i = 0; i < parent; i++)
    {
        if (HuffmanTree[i].parent != -1) // ��ѡ����ֱ������
            continue;
        if (weight == 0)
        { // ��һ���ҵ�ûѡ���Ľ��
            weight = HuffmanTree[i].weight;
            first = i;
        }
        else if (HuffmanTree[i].weight < weight)
        { // Ȩֵ��С
            weight = HuffmanTree[i].weight;
            first = i;
        }
    }
    // ��Ȩ�ش�СԪ��
    weight = 0;
    for (i = 0; i < parent; i++)
    {
        if (HuffmanTree[i].parent != -1 || i == first) // ��ѡ����ֱ������
            continue;
        if (weight == 0)
        { // ��һ���ҵ�ûѡ���Ľ��
            weight = HuffmanTree[i].weight;
            second = i;
        }
        else if (HuffmanTree[i].weight < weight)
        { // Ȩֵ��С
            weight = HuffmanTree[i].weight;
            second = i;
        }
    }
}

/*�ϲ�*/
void HuffmanCode::Merge(int first, int second, int parent)
{
    HuffmanTree[first].parent = HuffmanTree[second].parent = parent;                     // �����
    HuffmanTree[parent].leftChild = first;                                               // ����
    HuffmanTree[parent].rightChild = second;                                             // �Һ���
    HuffmanTree[parent].weight = HuffmanTree[first].weight + HuffmanTree[second].weight; // Ȩֵ
}

/*����:���ù���������ԭ������ݽ��м���*/
void HuffmanCode::Coding()
{
    string code; // �洢���ŵĲ����������Ʊ���
    int i, j, k, parent;

    for (i = 0; i < leafSize; i++)
    { // ��Ҷ�ӽ�����
        j = i;
        code = ""; // ��ʼ��Ϊ��
        while (HuffmanTree[j].parent != -1)
        {                                           // �����ҵ������
            parent = HuffmanTree[j].parent;         // �����
            if (j == HuffmanTree[parent].leftChild) // ��������ӣ����Ϊ0
                code += "0";
            else // �Һ��ӣ���Ϊ1
                code += "1";
            j = parent; // ���Ƶ������
        }
        // ����Ҫ����������Ϊ�Ǵ�Ҷ�������ߵ�������������Ҫ�Ӹ��ߵ�Ҷ�ӽ��
        for (k = (int)code.size() - 1; k >= 0; k--)
            HuffmanTree[i].code += code[k]; // �������
        cout << "�ַ���" << HuffmanTree[i].ch << "\t\t����Ϊ��"
             << HuffmanTree[i].code << endl;
    }
    cout << endl;
}

/*��������*/
string HuffmanCode::Encode(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '.')
            s[i] = 123;
        else if (s[i] == ' ')
            s[i] = 124;
        else if (s[i] == '\n')
            s[i] = 125;

    string k;
    for (int i = 0; i < s.length(); i++)
    {
        int pos = s[i] - 'a';
        k = k + HuffmanTree[pos].code;
    }
    // cout << k << endl;
    return k;
}

/*��������*/
void HuffmanCode::Decode(string str, string &deCode)
{
    string decode, temp;    // decode������������, temp����ÿһ������
    int len = str.length(); // ����ĳ���
    int i, j;

    decode = temp = ""; // ��ʼ��Ϊ��
    for (i = 0; i < len; i++)
    {
        temp += str[i]; // ��һ������
        for (j = 0; j < leafSize; j++)
        {
            if (HuffmanTree[j].code == temp)
            {                                // ��Ҷ�ӽ�����ҵ���Ӧ�ı���
                decode += HuffmanTree[j].ch; // ת�ɶ�Ӧ���ַ�
                temp = "";
                break;
            }
        }
        if (i == len - 1 && j == leafSize)
        { // �����궼û�ҵ���Ӧ�ı���
            cout << "�������" << endl;
            return;
        }
    }

    for (int i = 0; i < decode.length(); i++)
        if (decode[i] == 123)
            decode[i] = '.';
        else if (decode[i] == 124)
            decode[i] = ' ';
        else if (decode[i] == 126)
            decode[i] = '\n';

    deCode = decode;
}
