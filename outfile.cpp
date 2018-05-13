#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("test.txt");

    outFile << "Hello world!" << endl;
    outFile << "这是一个写入文本文件的程序" << endl;

    outFile.close();
    system("pause");
}