#include<iostream>
#include<iomanip>
#include<malloc.h>
#define StackSize 6
#define ERROR 0
#define OK 1
using namespace std;

typedef int SElemType;
typedef struct SNode
{
	SElemType data;
	struct SNode *next;
}SNode, *LinkStack;

int CreateTwo(LinkStack &head, int n)
{
	int i;
	SNode *p;
	head = (LinkStack)malloc(sizeof(SNode));
	head->next = NULL;
	cout << "���������ݣ����֣���" << endl;
	for (i = n; i > 0; --i)
	{
		p = (SNode *)malloc(sizeof(SNode));
		cin >> p->data;
		p->next = head->next;
		head->next = p;
	}
	return 1;
}

int MenuSelect()
{
	int sn;
	for (;;)
	{
		cin >> sn;
		if (sn < 1 || sn>6)
		{
			cout << "\n\t�����������������\n";
		}
		else
		{
			break;
		}
	}
	return sn;
}

int Push(LinkStack &top, SElemType e)
{
	SNode *q;
	q = (LinkStack)malloc(sizeof(SNode));
	if (!q)
	{
		cout << "�����" << endl;
		return(ERROR);
	}
	q->data = e;
	q->next = top->next;
	top->next = q;
	return(OK);
}

int Pop(LinkStack &top, SElemType &e)
{
	SNode *q;
	if (!top->next)
	{
		cout << "Error!" << endl;
		return(ERROR);
	}
	e = top->next->data;
	q = top->next;
	top->next = q->next;
	free(q);
	return(OK);
}

int main()
{
	int e;
	LinkStack top = nullptr;
	cout << "1.��ʼ��һ��ջ��" << endl;
	cout << "2.PUSH��" << endl;
	cout << "3.POP��" << endl;
	cout << "4.��ʾջ�����е�Ԫ�أ�" << endl;
	cout << "5.������" << endl;
	while (1)
	{
		switch (MenuSelect())
		{
		case 1:
			if (CreateTwo(top, StackSize))
				cout << "Success!" << endl;
			break;
		case 2:
			cout << "PUSH:" << endl;
			cin >> e;
			if (Push(top, e))
				cout << "Success!" << endl;
			break;
		case 3:
			if (Pop(top, e))
				cout << "Success!" << endl;
			cout << e << endl;
			break;
		case 4:
		{
			LinkStack p = nullptr;
			cout << "ջ�����е�Ԫ�أ�" << endl;
			p = top;
			while (p->next)
			{
				p = p->next;
				cout << setw(7) << p->data;
			}
			cout << endl;
			break;
		}
		case 5:
			return 0;
		}
	}
}