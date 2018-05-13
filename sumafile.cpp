#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
const int SIZE = 60;

int main()
{
    char filename[SIZE];
    ifstream inFile;
    inFile.open("test.txt");
    if(!inFile.is_open())
    {
        cout << "无法打开该文件" << endl;
        cout << "程序终止！" << endl;
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;
    while(inFile.good())
    {
        ++count;
        sum += value;
        inFile >> value;
    }
    if(inFile.eof())
    {
        cout << "已到达文件尾部" << endl;
    }
    else if(inFile.fail())
    {
        cout << "数据不匹配，输入终止" << endl;
    }
    else
    {
        cout << "未知原因输入终止" << endl;
    }

    if(count == 0)
    {
        cout << "无数据处理" << endl;
    }
    else
    {
        cout << "读取条目：" << count << endl;
        cout << "总和：" << sum << endl;
        cout << "平均数：" << sum/count << endl;
    }

    inFile.close();
    system("pause");
}