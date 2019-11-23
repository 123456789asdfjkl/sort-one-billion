#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random()
{
	FILE* fp;
	fopen_s(&fp, "D:\\Ëã·¨\\10ÒÚÊıÅÅĞò\\main\\data2.txt", "w");
	if (fp == NULL)
	{
		return 0;
	}
	long int length = 1000000000;
	unsigned long int a;
	srand((unsigned long int)time(NULL));
	for (int i = 0; i < length; i++)
	{
		a = rand();
		fprintf(fp, "%d ", a);
		if (i%30==0&&i!=0)
		{
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
	return 0;
}
