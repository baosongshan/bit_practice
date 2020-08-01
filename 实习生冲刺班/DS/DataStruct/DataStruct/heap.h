#ifndef _HEAP_H_
#define _HEAP_H_

#include"Common.h"

#define HEAP_DEFAULT_SIZE 20

typedef int HeapElemType;
typedef struct MinHeap
{
	HeapElemType *base;
	size_t        capacity;
	size_t        size;
}MinHeap;

void HeapInit(MinHeap *php,  int sz = HEAP_DEFAULT_SIZE);
void HeapInsert(MinHeap *php, HeapElemType x);
void HeapErase(MinHeap *php);
void HeapShow(MinHeap *php);
void HeapShiftUp(MinHeap *php, int start);
void HeapShiftDown(MinHeap *php, int start);
/////////////////////////////////////////////////////////////////////
void HeapInit(MinHeap *php, int sz)
{
	assert(php != NULL);
	php->capacity = sz > HEAP_DEFAULT_SIZE ? sz : HEAP_DEFAULT_SIZE;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType) * php->capacity);
	memset(php->base, 0, sizeof(HeapElemType) * php->capacity);
	php->size = 0;
}

void HeapInsert(MinHeap *php, HeapElemType x)
{
	assert(php != NULL);
	if(php->size >= php->capacity)
	{
		printf("堆空间已满，%d 不能插入堆.\n", x);
		return;
	}

	php->base[php->size] = x;
	HeapShiftUp(php, php->size);
	php->size++;
}

void HeapErase(MinHeap *php)
{

}


void HeapShow(MinHeap *php)
{
	assert(php != NULL);
	for(int i=0; i<php->size; ++i)
		printf("%d ", php->base[i]);
	printf("\n");
}

void HeapShiftUp(MinHeap *php, int start) //i=parent j=child
{
	int j = start;
	int i = (j-1) / 2;
	while(j > 0)
	{
		if(php->base[j] < php->base[i])
		{
			Swap(&php->base[j], &php->base[i]);
			j = i;
			i = (j-1) / 2;
		}
		else
			break;
	}
}

void HeapShiftDown(MinHeap *php, int start)
{

}

#endif /* _HEAP_H_ */