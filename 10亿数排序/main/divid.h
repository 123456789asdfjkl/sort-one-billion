#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"QuickSort.h"
#define MAX 1000000000/500
#define MAX2 500



int divid()
{
	char name[80];
	double begin,begin1;
	double end,end1;
	FILE* fp;
	int *a;
	a = new int[MAX+1];
	int i;
	int j;
	fopen_s(&fp, "D:\\�㷨\\10��������\\main\\data2.txt", "r");
	if (fp == NULL)
	{
		return 0;
	}
	
	std::cout.precision(3);
	begin1 = (double)time(NULL);
	for (j = 1; j <= MAX2; j++)
	{

		sprintf_s(name, "D:\\�㷨\\10��������\\main\\divideandsort\\%02d.txt", j);

		//��ȡ�ļ�
		begin = (double)time(NULL);
		for (i = 1; i < MAX + 1; i++)
		{
			fscanf_s(fp, "%d", &a[i]);
		}
		end = (double)time(NULL);
		//std::cout << "�������ݻ��ѵ�ʱ��:" << (end - begin) << "\n";

		//��������
		begin = (double)time(NULL);
		QuickSort(a,MAX);
		end = (double)time(NULL);
		//std::cout << "�������������ѵ�ʱ��:" << (end - begin) << "\n";

		//д���ļ�
		FILE* fp1;
		fopen_s(&fp1, name, "w");
		begin = (double)time(NULL);
		if (fp1 == NULL)
		{
			return 0;
		}
		for (i = 1; i < MAX; i++)
		{
			fprintf_s(fp1, "%d ", a[i]);
			if (i % 30 == 0 && i != 0)
			{
				fprintf(fp1, "\n");
			}
		}
		fprintf_s(fp1, "%d", a[i]);
		end = (double)time(NULL);
		fclose(fp1);
		//std::cout << "д�����ݻ��ѵ�ʱ��:" << (end - begin) << "\n";
	}
	end1 = (double)time(NULL);
	//std::cout << "��ʮ�����ֳ�ʮ�����ļ������������ѵ�ʱ��:" << (end1 - begin1);
	fclose(fp);
	delete[] a;
	return 0;
}