#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct HuffmanNode
{
    int weight;                        //Ȩ�أ����ֵĴ�������Ƶ��
    char ch;                           //�洢����
    string code;                       //�洢�÷��Ŷ�Ӧ�ı���
    int leftChild, rightChild, parent; //���Һ��ӣ������
};

class HuffmanCode
{
private:
    HuffmanNode *HuffmanTree; //����
    int leafSize;             //ͳ�Ʋ�ͬ�ַ��ĸ���

public:
    HuffmanCode();                  //���캯��
    ~HuffmanCode();                 //��������
    void set(string);               //���ɹ�������
    void getMin(int &, int &, int); //ѡȡ������С��Ԫ��
    void Merge(int, int, int);      //�ϲ�
    void Coding();                  //�ַ����룺���ù���������ԭ������ݽ��м���
    void DeCoding(string);          //��ȡ�ĵ�����������
    void Decode(string, string &);  //��������
    void EnCoding(string);          //��ȡ�ĵ�����������
    string Encode(string);          //��������
    void write(string, string &);   //д���ĵ�
};