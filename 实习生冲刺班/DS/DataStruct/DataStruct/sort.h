#ifndef _SORT_H_
#define _SORT_H_

#include"Common.h"

void PrintArray(int ar[], int left, int right)
{
	for(int i=left; i<right; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}

//直接插入排序
void InsertSort(int *ar, int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		int end = i;
		while(end>left && ar[end]<ar[end-1])
		{
			Swap(&ar[end], &ar[end-1]);
			end--;
		}
	}
}

void InsertSort_1(int *ar, int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		int tmp = ar[i];
		int end = i;
		while(end>left && tmp<ar[end-1])
		{
			ar[end] = ar[end-1];
			end--;
		}
		ar[end] = tmp;
	}
}

//哨兵位的直接插入排序
void InsertSort_2(int *ar, int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		ar[0] = ar[i]; // 哨兵位
		int end = i;
		while(ar[0] < ar[end-1])
		{
			ar[end] = ar[end-1];
			end--;
		}
		ar[end] = ar[0];
	}
}

//折半插入排序
void BinInsertSort(int *ar, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		int tmp = ar[i];
		int low = 0;
		int high = i - 1;
		while (low <= high)
		{
			int m = (low + high) / 2;
			if (tmp < ar[m])
				high = m - 1;
			else
				low = m + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			ar[j + 1] = ar[j];
		ar[high + 1] = tmp;
	}
}

//二路插入排序
void TwoWayInsertSort(int *ar, int left, int right)
{
	//
}

void TestSort(int *ar, int left, int right)
{
	//InsertSort(ar, left, right);
	//InsertSort_1(ar, left, right);
	//InsertSort_2(ar, left, right);
	//BinInsertSort(ar, left, right);
	TwoWayInsertSort(ar, left, right);
}

void TestSortEfficiency()
{
	int n = 20000;
	int *a = (int *)malloc(sizeof(int) * n);
	int *a1 = (int *)malloc(sizeof(int) * n);
	int *a2 = (int *)malloc(sizeof(int) * n);
	int *a3 = (int *)malloc(sizeof(int) * n);

	srand(time(0));
	for(int i=0; i<n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
	}

	time_t start = clock();
	InsertSort(a, 0, n);
	time_t end   = clock();
	printf("InsertSort: %u\n", end - start);

	start = clock();
	InsertSort_1(a1, 0, n);
	end   = clock();
	printf("InsertSort_1: %u\n", end - start);

	start = clock();
	BinInsertSort(a2, 0, n);
	end   = clock();
	printf("BinInsertSort: %u\n", end - start);

	start = clock();
	TwoWayInsertSort(a3, 0, n);
	end   = clock();
	printf("BinInsertSort: %u\n", end - start);

}

#endif /* SORT_H_ */