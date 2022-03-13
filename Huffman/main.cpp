#include "Huffman.h"
int main()
{
    HuffmanCode st;
    st.set("DataFile.txt");
    st.Coding();
    st.EnCoding("ToBeTran.txt");
    st.DeCoding("CodeFile.txt");

    system("pause");
    return 0;
}