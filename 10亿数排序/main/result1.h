#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define MAX3 500

//最小值所在数组的下标
template <class Type> int Min(Type* a, int N)
{
	int m = -1;//作为所以文件都读取完毕的标志
	for (int i = 0; i < N; ++i)
	{
		if (a[i] == -1)//此文件已读取完毕，所以-1不作为一个数参与比较
			continue;
		if (m == -1 || a[m] > a[i])
			m = i;
	}
	return m;
}

int result()
{
	//合并文件
	time_t begin, end;
	FILE* fp = NULL;
	FILE* FileList[MAX3];
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\算法\\10亿数排序\\main\\result.txt", "w")) != 0)//创建数据输出的文件
	{
		cout << "File open error!\n";
		return 0;
	}
	for (int i = 0; i < MAX3; i++)
	{
		char name[200];
		sprintf_s(name, "D:\\算法\\10亿数排序\\main\\divideandsort\\%02d.txt", i + 1);
		fopen_s(&FileList[i], name, "r");
	}
	int number[MAX3];//每个文件中最小的元素即第一个元素
	for (int i = 0; i < MAX3; i++)
		fscanf_s(FileList[i], "%d", &number[i]);
	//开始归并
	while (1)
	{
		int min = Min(number, MAX3);
		cout << number[min] << ends;
		if (min == -1)
			break;  //所有文件读取完毕
		fprintf(fp, "%d ", number[min]);
		fscanf_s(FileList[min], "%d", &number[min]);
		if (feof(FileList[min]))
		{
			number[min] = -1;  //本文件读取完毕
		}
	}
	for (int i = 0; i < MAX3; i++)
		fclose(FileList[i]);
	fclose(fp);
}