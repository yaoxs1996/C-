#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<process.h>
using namespace std;

const unsigned int N=5;
const int THINKING=1;
const int HUNGRY=2;
const int DINING=3;

HANDLE hPhilosopher[N];
HANDLE semaphore[N];
HANDLE mutex;

DWORD WINAPI philosopherProc(LPVOID lpParameter)
{
    char stateStr[128];
    int ret;

    unsigned int leftFork;
    unsigned int rightFork;

    int myid = int(lpParameter);

    WaitForSingleObject(mutex, INFINITE);       //安全输出
    cout << "Philosopher" << myid << " begin......" << endl;
    ReleaseMutex(mutex);

    int mystate = THINKING;
    leftFork = (myid)%N;
    rightFork = (myid+1)%N;

    while(true)
    {
        switch(mystate)
        {
            case THINKING:
                mystate = HUNGRY;
                strcpy(stateStr, "HUNGRY");
                break;
            case HUNGRY:
                strcpy(stateStr, "HUNGRY");
                ret = WaitForSingleObject(semaphore[leftFork], 0);      //先看左手
                if(ret==WAIT_OBJECT_0)
                {
                    ret = WaitForSingleObject(semaphore[rightFork], 0);
                    if(ret==WAIT_OBJECT_0)
                    {
                        mystate = DINING;
                        strcpy(stateStr, "DINING");
                    }
                    else
                        ReleaseSemaphore(semaphore[leftFork], 1, NULL);
                }
                break;
            case DINING:
                ReleaseSemaphore(semaphore[leftFork], 1, NULL);
                ReleaseSemaphore(semaphore[rightFork], 1, NULL);
                mystate = THINKING;
                strcpy(stateStr, "THINKING");
                break;
        }
        WaitForSingleObject(mutex, INFINITE);
        cout << "philosopher" << myid << " is: " << stateStr << endl;
        ReleaseMutex(mutex);
        if(mystate == THINKING)
        {
            return 1;
        }
        Sleep(100);
    }
}

int main()
{
    mutex = CreateMutex(NULL, false, NULL);     //创建一个互斥变量
    for(int i=0; i<N; i++)
    {
        semaphore[i] = CreateSemaphore(NULL, 1, 1, NULL);       //创建一个信号量
        hPhilosopher[i] = CreateThread(NULL, 0,     //线程安全属性，堆栈大小
            philosopherProc, LPVOID(i),     //线程函数，线程参数
            CREATE_SUSPENDED, 0);       //线程创建属性，线程ID
    }

    for(int i=0; i<N; i++)
    {
        ResumeThread(hPhilosopher[i]);      //线程恢复函数
    }
    Sleep(800);
    system("pause");
    return 0;
}