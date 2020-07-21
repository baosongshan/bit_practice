#ifndef _SC_LIST_H_
#define _SC_LIST_H_

#include"Common.h"
typedef struct SCListNode
{
	ElemType data;
	struct SCListNode *next;
}SCListNode;

//不带头结点的单循环链表

typedef SCListNode* SCList;

void SCListInit(SCList *phead);
void SCListPushBack(SCList *phead, ElemType x);
void SCListShow(SCList phead);



///////////////////////////////////////////////////////////////
void SCListInit(SCList *phead)
{
	*phead = NULL;
}

void SCListPushBack(SCList *phead, ElemType x)
{
	assert(phead != NULL);
	SCListNode *s = (SCListNode*)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = x;

	//节点链接
	SCListNode *p = *phead;
	if(p == NULL)
		*phead = s;
	else
	{
		while(p->next != *phead)
			p = p->next;
		p->next = s;
	}
	s->next = *phead;
}

void SCListShow(SCList phead)
{
	SCListNode *p = phead;
	if(p != NULL)
	{
		while (p->next != phead)
		{
			printf("%d->", p->data);
			p = p->next;
		}
		printf("%d->", p->data);
	}
	printf("Over.\n");
}

#endif /* _SC_LIST_H_ */