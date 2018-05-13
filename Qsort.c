#include<stdio.h>
#include<stdlib.h>

void sort(int *a, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)
    {
        while(i<j && key<=a[j])
        {
            j--;
        }

        a[i] = a[j];

        while(i < j && key>=a[i])
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, left, i-1);
    sort(a, i+1, right);
}

int main()
{
    int num[] = {12, 14, 2, 87, 32, 17, 21};
    int *a;
    a = num;
    printf("排序前: ");
    for(int i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    sort(a, 0, 6);

    printf("排序后: ");
    for(int i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    system("pause");
}