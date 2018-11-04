//将两个顺序表进行合并
//Merge two sequence list to one

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool merge(vector<int> a, vector<int> b, vector<int> &c)
{
    int i=0, j=0, k=0;

    while(i < a.size() && j < b.size())
    {
        if(a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < a.size())
        c[k++] = a[i++];

    while(j < b.size())
        c[k++] = b[j++];

    return true;
}

int main()
{
    vector<int> a {1, 3, 5, 7, 9, 11, 13};
    vector<int> b {0, 2 ,4, 6, 8, 10, 11};
    vector<int> c(a.size()+b.size());

    merge(a, b, c);

    for_each(c.begin(), c.end(), [](int x){cout << x << " ";});
    cout << endl;
    
    system("pause");
}