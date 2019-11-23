#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

int read()
{
	FILE* fp;
	fopen_s(&fp, "D:\\Ëã·¨\\10ÒÚÊıÅÅĞò\\main\\data2.txt", "r");
	long int a;
	if (fp == NULL)
	{
		return 0;
	}
	for (int i = 0; i < 1000000000; i++)
	{
		fscanf_s(fp, "%ld ", &a);
		if (a/100000!=0)
		{
			std::cout << 1;
			return 0;
		}
	}
	std::cout << 0;
	return 0;
	fclose(fp);
}