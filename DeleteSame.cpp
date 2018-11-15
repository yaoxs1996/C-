//Delete same elements from sequence list
//从有序线性表中删除

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool deleteSame(vector<int> &L)
{
    if(L.size() == 0)
        return false;

    //类似直接插入排序的思想
    int i, j;
    for(i=0, j=1; j<L.size(); j++)    //此处为j++
    {
        if(L[i] != L[j])
        {
            L[++i] = L[j];    //仅当不等时，++i，请注意
        }
    }

    //删除后序的重复序列
    /*C version
    L.length=i+1*/
    
    for(j=0; j<=i; j++)
        L.pop_back();

    return true;
}

int main()
{
    //有序线性表
    vector<int> list {1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 6};

    cout << "Before delete" << endl;
    for_each(list.begin(),list.end(),[](int x){cout << x << " ";});
    
    deleteSame(list);
    
    cout << endl << "After delete" << endl;
    for_each(list.begin(),list.end(),[](int x){cout << x << " ";});

    system("pause");
}
