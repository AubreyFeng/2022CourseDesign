#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct HuffmanNode
{
    int weight;                        //权重，出现的次数或者频率
    char ch;                           //存储符号
    string code;                       //存储该符号对应的编码
    int leftChild, rightChild, parent; //左、右孩子，父结点
};

class HuffmanCode
{
private:
    HuffmanNode *HuffmanTree; //数组
    int leafSize;             //统计不同字符的个数

public:
    HuffmanCode();                  //构造函数
    ~HuffmanCode();                 //析构函数
    void set(string);               //生成哈夫曼树
    void getMin(int &, int &, int); //选取两个较小的元素
    void Merge(int, int, int);      //合并
    void Coding();                  //字符编码：利用哈夫曼编码原理对数据进行加密
    void DeCoding(string);          //读取文档，解码文字
    void Decode(string, string &);  //解码文字
    void EnCoding(string);          //读取文档，编码文字
    string Encode(string);          //编码文字
    void write(string, string &);   //写入文档
};