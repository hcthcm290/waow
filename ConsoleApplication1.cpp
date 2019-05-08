// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node
{
	int info;
	node* pNext;
	node* pPrevious;
};

struct list
{
	node* pHead = NULL;
	node* pTail = NULL;
};

node* getNode(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->pNext = NULL;
	p->pPrevious = NULL;
	return p;
}

void addTail(list &a, int x)
{
	node* p = getNode(x);
	if (a.pHead == NULL)
	{
		a.pHead = a.pTail = p;
		return;
	}
	a.pTail->pNext = p;
	p->pPrevious = a.pTail;
	a.pTail = p;
}

void input(list& a)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		addTail(a, x);
	}
}

void output(list& a)
{
	node* p = a.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int a[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int temp = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] < a[temp])
		{
			if (temp + 1 != i)
			{
				swap(a[temp], a[temp + 1]);
				swap(a[temp], a[i]);
				temp += 1;
			}
			else
			{
				swap(a[i], a[temp]);
				temp += 1;
			}
		}
	}
	quickSort(a, l, temp - 1);
	quickSort(a, temp + 1, r);
}

void quickSortLINKED(node* left, node* right)
{
	if (left == NULL || right == NULL)
	{
		return;
	}
	if ((left == right) || (left->pPrevious == right) || (right->pNext == left))
	{
		return;
	}
	node* temp = left;
	node* p = left->pNext;
	while (true)
	{
		if (p == NULL)
		{
			break;
		}
		else if (p->pPrevious == right)
		{
			break;
		}
		if (temp->info > p->info)
		{
			if (temp->pNext == p)
			{
				swap(temp->info, p->info);
				temp = temp->pNext;
			}
			else
			{
				swap(temp->info, temp->pNext->info);
				swap(temp->info, p->info);
				temp = temp->pNext;
			}
		}
		p = p->pNext;
	}
	quickSortLINKED(left, temp->pPrevious);
	quickSortLINKED(temp->pNext, right);
	return;
}

void heapify(int a[], int k)
{
	if (a[2 * k + 1] > a[2 * k + 2])
	{
	}
}

int main()
{
	//int a[100];
	//int n;
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> a[i];
	//}
	//quickSort(a, 0, n - 1);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;

	list a;
	input(a);
	quickSortLINKED(a.pHead, a.pTail);
	output(a);
    return 0;
}

