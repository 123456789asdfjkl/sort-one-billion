#pragma once
template <class T>
int Partition(T L[], int low, int high)//一次快排 
{
	int pivotkey;
	L[0] = L[low];
	pivotkey = L[low];
	while (low < high)
	{
		while (low < high && L[high] >= pivotkey)
		{
			--high;
		}
		L[low] = L[high];
		while (low < high && L[low] <= pivotkey)
		{
			++low;
		}
		L[high] = L[low];
	}
	L[low] = L[0];
	return low;

}
template <class T>
void QSort(T L[], int low, int high)//比较函数 
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
void QuickSort(T L[],int max)//快速排序 
{
	QSort(L, 1, max);
}