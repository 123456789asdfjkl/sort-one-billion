#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define MAX1 (500+1)

struct arr
{
	int a;
	int flag;
};

//inline void Exchange(arr L[], int i, int j)
//{
//	int temp;
//	temp = L[i].a;
//	L[i].a = L[j].a;
//	L[j].a = temp;
//	temp = L[i].flag;
//	L[i].flag = L[j].flag;
//	L[j].flag = temp;
//}

inline void HeepAdjust(arr L[], int s, int m)//堆排序的调整 
{
	arr rc;
	int j;
	rc.a = L[s].a;
	rc.flag = L[s].flag;
	for (j = 2 * s; j < m ; j *= 2)
	{
		if (j + 1 < m && L[j].a > L[j + 1].a)
		{
			++j;
		}
		if (!(rc.a > L[j].a))
		{
			break;
		}
		//Exchange(L, s, j);
		int temp;
		temp = L[s].a;
		L[s].a = L[j].a;
		L[j].a = temp;
		temp = L[s].flag;
		L[s].flag = L[j].flag;
		L[j].flag = temp;
		s = j;
	}
	L[s].a = rc.a;
	L[s].flag = rc.flag;
}

int result()
{
	arr b[MAX1];
	int i;
	int j;
	int l;
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
		sprintf_s(name, "D:\\算法\\10亿数排序\\main\\divideandsort\\%02d.txt", i);
		fopen_s(&fp[i], name, "r");
		if (fp[i] == NULL)
		{
			return 0;
		}

		fscanf_s(fp[i], "%d", &b[i].a);
		b[i].flag = i;
	}
	for (i = MAX1/2;i > 0 ; --i)
	{
		HeepAdjust(b, i,MAX1);
	}
	j = 1;
	l = MAX1;
	while (1)
	{
		fprintf_s(fp1, "%d ", b[1].a);
		//cout << b[1].a << ends;
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
			}
			else
			{
				//Exchange(b, 1, l);
				int temp;
				temp = b[1].a;
				b[1].a = b[l-1].a;
				b[l-1].a = temp;
				temp = b[1].flag;
				b[1].flag = b[l-1].flag;
				b[l-1].flag = temp;
				l--;
			}
			if (l<=1)
			{
				break;
			}
			HeepAdjust(b, 1, l);
		}
	}
	fclose(fp1);
	for (i = 1; i < MAX1; i++)
	{
		fclose(fp[i]);
	}
	return 0;
}