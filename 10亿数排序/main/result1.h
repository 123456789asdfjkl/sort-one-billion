#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define MAX3 500

//��Сֵ����������±�
template <class Type> int Min(Type* a, int N)
{
	int m = -1;//��Ϊ�����ļ�����ȡ��ϵı�־
	for (int i = 0; i < N; ++i)
	{
		if (a[i] == -1)//���ļ��Ѷ�ȡ��ϣ�����-1����Ϊһ��������Ƚ�
			continue;
		if (m == -1 || a[m] > a[i])
			m = i;
	}
	return m;
}

int result()
{
	//�ϲ��ļ�
	time_t begin, end;
	FILE* fp = NULL;
	FILE* FileList[MAX3];
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\�㷨\\10��������\\main\\result.txt", "w")) != 0)//��������������ļ�
	{
		cout << "File open error!\n";
		return 0;
	}
	for (int i = 0; i < MAX3; i++)
	{
		char name[200];
		sprintf_s(name, "D:\\�㷨\\10��������\\main\\divideandsort\\%02d.txt", i + 1);
		fopen_s(&FileList[i], name, "r");
	}
	int number[MAX3];//ÿ���ļ�����С��Ԫ�ؼ���һ��Ԫ��
	for (int i = 0; i < MAX3; i++)
		fscanf_s(FileList[i], "%d", &number[i]);
	//��ʼ�鲢
	while (1)
	{
		int min = Min(number, MAX3);
		cout << number[min] << ends;
		if (min == -1)
			break;  //�����ļ���ȡ���
		fprintf(fp, "%d ", number[min]);
		fscanf_s(FileList[min], "%d", &number[min]);
		if (feof(FileList[min]))
		{
			number[min] = -1;  //���ļ���ȡ���
		}
	}
	for (int i = 0; i < MAX3; i++)
		fclose(FileList[i]);
	fclose(fp);
}