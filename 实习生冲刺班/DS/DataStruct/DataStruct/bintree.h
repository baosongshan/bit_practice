#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"Common.h"

///////////////////////////////////////////////////////////////////////////////////

struct BinTreeNode;
typedef BinTreeNode* LinkQueueElemType ;

typedef struct LinkQueueNode 
{
	LinkQueueElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *head; // 队头指针
	LinkQueueNode *tail; // 队尾指针
}LinkQueue;

void LinkQueueInit(LinkQueue *pq);
void LinkQueueEn(LinkQueue *pq, LinkQueueElemType x);
void LinkQueueDe(LinkQueue *pq);
LinkQueueElemType LinkQueueFront(LinkQueue *pq);
int LinkQueueSize(LinkQueue *pq);
bool LinkQueueEmpty(LinkQueue *pq);
void LinkQueueDestroy(LinkQueue *pq);
/////////////////////////////////////////////////////
void LinkQueueInit(LinkQueue *pq)
{
	assert(pq != NULL);
	pq->head = pq->tail = NULL;
}

void LinkQueueEn(LinkQueue *pq, LinkQueueElemType x)
{
	assert(pq != NULL);
	LinkQueueNode *node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;
	if(pq->head == NULL)
		pq->head = pq->tail = node;
	else
	{
		pq->tail->link = node;
		pq->tail = node;
	}
}
void LinkQueueDe(LinkQueue *pq)
{
	assert(pq != NULL);
	if(pq->head != NULL)
	{
		LinkQueueNode *p = pq->head;
		if(pq->head == pq->tail)
			pq->head = pq->tail = NULL;
		else
			pq->head = p->link;
		free(p);
	}
}
LinkQueueElemType LinkQueueFront(LinkQueue *pq)
{
	assert(pq != NULL);
	assert(pq->head != NULL);
	return pq->head->data;  //return pq->tail->data
}
int LinkQueueSize(LinkQueue *pq)
{
	assert(pq != NULL);
	int size = 0;
	LinkQueueNode *p = pq->head;
	while(p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}
bool LinkQueueEmpty(LinkQueue *pq)
{
	assert(pq != NULL);
	return pq->head == NULL;
}

void LinkQueueDestroy(LinkQueue *pq)
{
	assert(pq != NULL);
	LinkQueueNode *p = pq->head;
	while(p != NULL)
	{
		pq->head = p->link;
		free(p);
		p = pq->head;
	}
}

///////////////////////////////////////////////////////////////////////////////////

typedef char BinTreeElemType;
typedef struct BinTreeNode
{
	BinTreeElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef BinTreeNode* BinTree;

//二叉树的创建
void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);

//二叉树的遍历
void BinTreeVLR(BinTree t);
void BinTreeLVR(BinTree t);
void BinTreeLRV(BinTree t);
void BinTreeLevel(BinTree t);

int Size(BinTree t);
int Height(BinTree t);
BinTreeNode* Left(BinTreeNode *p);
BinTreeNode* Right(BinTreeNode *p);
BinTreeNode* BinTreeFind(BinTree t, BinTreeElemType key);
BinTreeNode* BinTreeParent(BinTree t, BinTreeNode *p);
BinTreeNode* BinTreeCopy(BinTree t);
bool         Equal(BinTree t1, BinTree t2);
////////////////////////////////////////////////////////////////////

void BinTreeInit(BinTree *t)  //BinTreeNode**t;
{
	*t = NULL;
}

void BinTreeCreate(BinTree *t)
{
	assert(t != NULL);
	BinTreeElemType item;
	scanf("%c", &item);
	if(item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate(&(*t)->leftChild);
		BinTreeCreate(&(*t)->rightChild);
	}
}

void BinTreeVLR(BinTree t)
{
	if(t != NULL)
	{
		printf("%c ", t->data);
		BinTreeVLR(t->leftChild);
		BinTreeVLR(t->rightChild);
	}
}

void BinTreeLVR(BinTree t)
{
	if(t != NULL)
	{
		BinTreeLVR(t->leftChild);
		printf("%c ", t->data);
		BinTreeLVR(t->rightChild);
	}
}
void BinTreeLRV(BinTree t)
{
	if(t != NULL)
	{
		BinTreeLRV(t->leftChild);
		BinTreeLRV(t->rightChild);
		printf("%c ", t->data);
	}
}

void BinTreeLevel(BinTree t)
{
	if(t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t);
		while(!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%c ", p->data);
			if(p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if(p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
		}

		LinkQueueDestroy(&Q);
	}
}

int Size(BinTree t)
{
	if(t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1;
}

int Height(BinTree t)
{
	if(t == NULL)
		return 0;
	else
	{
		int left_h = Height(t->leftChild);
		int right_h = Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
#endif /* _BINTREE_H_ */