#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Common.h"

#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表的结构
typedef struct SeqList
{
	ElemType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);

void SeqListPopBack(SeqList *plist);
void SeqListClear(SeqList *plist);
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
void SeqListSort(SeqList *plist);

size_t SeqListLength(SeqList *plist);

/////////////////////////////////////////////////////////////////////////////////
void SeqListPopFront(SeqList *plist);
bool SeqListInsertByVal(SeqList *plist, ElemType x);
//////////////////////////////////////////////////////////////////////////////////

bool IsFull(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}

void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);
	plist->size = 0;
}

void SeqListDestroy(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}

void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if(IsFull(plist))
	{
		printf("顺序表已满，%d 不能头部插入.\n", x);
		return;
	}
	plist->base[plist->size++] = x;
}

void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	//判满
	if(IsFull(plist))
	{
		printf("顺序表已满，%d 不能尾部插入.\n", x);
		return;
	}
	//头插
	for(size_t i=plist->size; i>0; --i)
		plist->base[i] = plist->base[i-1];
	plist->base[0] = x;
	plist->size++;
}

void SeqListShow(SeqList *plist)
{
	assert(plist != NULL);
	for(size_t i=0; i<plist->size; ++i)
		printf("%d ",plist->base[i]);
	printf("\n");
}

size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}

void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	//判空
	if(IsEmpty(plist))
	{
		printf("顺序表已空,不能尾部删除.\n");
		return;
	}
	plist->size--;
}

void SeqListClear(SeqList *plist)
{
	assert(plist != NULL);
	plist->size = 0;
}

bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if(IsFull(plist))
	{
		printf("顺序表已满,%d 不能在 %d 位置插入.\n", x, pos);
		return false;
	}
	if(pos<0 || pos>plist->size)
	{
		printf("要插入的位置[%d]是非法位置, %d 不能插入.\n", pos, x);
		return false;
	}

	for(size_t i=plist->size; i>pos; --i)
		plist->base[i] = plist->base[i-1];
	plist->base[pos] = x;
	plist->size++;

	return true;
}

void SeqListSort(SeqList *plist)
{
	assert(plist != NULL);
	for(size_t i=0; i<plist->size-1; ++i)
	{
		for(size_t j=0; j<plist->size-i-1; ++j)
		{
			if(plist->base[j] > plist->base[j+1])
				Swap(&plist->base[j], &plist->base[j+1]);
		}
	}
}

#endif /* _SEQLIST_H_ */