#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define MAX1 500+1

struct arr
{
	int a;
	int flag;
};

void Exchange(arr L[], int i, int j)
{
	int temp;
	temp = L[i].a;
	L[i].a = L[j].a;
	L[j].a = temp;
	temp = L[i].flag;
	L[i].flag = L[j].flag;
	L[j].flag = temp;
}

int partition(arr l[], int low, int high)//一次快排 
{
	int pivotkey;
	Exchange(l, 0, low);
	pivotkey = l[low].a;
	while (low < high)
	{
		while (low < high && l[high].a >= pivotkey)
		{
			--high;
		}
		l[low] = l[high];
		while (low < high && l[low].a <= pivotkey)
		{
			++low;
		}
		Exchange(l, high, low);
	}
	Exchange(l, low, 0);
	return low;

}
void qsort(arr l[], int low, int high)//比较函数 
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = partition(l, low, high);
		qsort(l, low, pivotloc - 1);
		qsort(l, pivotloc + 1, high);
	}
}

void quicksort(arr l[], int max)//快速排序 
{
	qsort(l, 1, max);
}

void InsertSort(arr L[],int max)//二分查找法插入排序 
{
	int i;
	for (i=1;i<max-1;i++)
	{
		if (L[i].a<=L[i+1].a)
		{
			break;
		}
		Exchange(L, i, i + 1);
	}
}

int result()
{
	arr b[MAX1];
	int i;
	int flag1;
	int j;
	int k=0;
	int tmp;
	char name[80];
	FILE* fp[MAX1];
	FILE* fp1;
	fopen_s(&fp1, "D:\\算法\\10亿数排序\\main\\result.txt", "w");
	if (fp1 == NULL)
	{
		return 0;
	}
	for (i = 1; i < MAX1; i++)
	{
		sprintf_s(name,"D:\\算法\\10亿数排序\\main\\divideandsort\\%02d.txt", i);
		fopen_s(&fp[i], name, "r");
		if (fp[i] == NULL)
		{
			return 0;
		}
		
		fscanf_s(fp[i], "%d", &b[i].a);
		b[i].flag = i;
	}
	quicksort(b,MAX1);
	flag1 = 1;
	j = 1;
	while (flag1)
	{
		flag1 = 0;
		fprintf_s(fp1, "%d ", b[1].a);
		//cout << b[1].a<<ends;
		if (j == 30)
		{
			fprintf_s(fp1, "\n");
			j = 1;
		}
		else
		{
			j++;
		}
		tmp = b[1].flag;
		if (tmp > 0)
		{
			if (!feof(fp[tmp]))
			{
				fscanf_s(fp[tmp], "%d", &b[1].a);
				flag1 = 1;
			}
			else
			{
				for (i = 1; i < MAX1; i++)
				{
					if (fp[i] != NULL)
					{
						fscanf_s(fp[i], "%d", &b[1].a);
						b[1].flag = i;
						break;
						flag1 = 1;
					}
				}
				if (!flag1)
				{
					break;
				}
			}
			InsertSort(b,MAX1);
		}
	}
	for (i = 2; i < MAX1; i++)
	{
		fprintf_s(fp1, "%d ", b[i].a);
		//cout << b[1].a<<ends;
	}
	fclose(fp1);
	for  ( i = 1;  i < MAX1;  i++)
	{
		fclose(fp[i]);
	}
	return 0;
}