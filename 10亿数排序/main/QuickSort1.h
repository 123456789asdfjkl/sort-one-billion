#pragma once
template <class T>
int Partition(T L[], int low, int high)//һ�ο��� 
{
	T pivotkey;
	L[0] = L[low];
	pivotkey = L[low].a;
	while (low < high)
	{
		while (low < high && L[high].a >= pivotkey.a)
		{
			--high;
		}
		L[low] = L[high];
		while (low < high && L[low].a <= pivotkey.a)
		{
			++low;
		}
		L[high] = L[low];
	}
	L[low] = L[0];
	return low;

}
template <class T>
void QSort(T L[], int low, int high)//�ȽϺ��� 
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

template<class T>
void QuickSort(T L[], int max)//�������� 
{
	QSort(L, 1, max);
}