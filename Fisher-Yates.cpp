#include<iostream>
#include<cstdlib>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;
const int N = 9;

void exchange(int *card)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    srand(time(NULL));

    cout << "洗牌后序列：";
    for(i=N; i>=0; i--)
    {
        j = (rand()%(i+1));
        temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }
    
    for(i=0; i<N; i++)
    {
        cout << card[i] << " ";
    }
    cout << endl;
}

int main()
{
    int card[N] = {1,2,3,4,5,6,7,8,9};
    
    cout << "初始化序列：";
    for(int i=0; i<N; i++)
    {
        cout << card[i] << " ";
    }
    cout << endl;
    
    exchange(card);
    system("pause");
}