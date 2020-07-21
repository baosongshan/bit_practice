#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<vld.h>

void SeqListEraseAll(int *ar, int *n, int key)
{

}

void main()
{
	int ar[] = {1,3,5,5,5,5,7,9,5,5,8,0,2};
	int n = sizeof(ar) / sizeof(ar[0]);
	int size = n;
	SeqListEraseAll(ar, &size, 5);
	for(int i=0; i<size; ++i)
		printf("%d ",ar[i]);
	printf("\n");
}


/*
typedef struct ListNode
{
	int data;       //������
	ListNode *next; //ָ����
}ListNode;

typedef ListNode* List;
void ListInit(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	(*phead)->next = NULL;
}
//β�巨
void ListCreate_Tail(List *phead)
{
	ListNode *p = *phead;
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

//ͷ�巨
void ListCreate_Head(List *phead)
{
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = (*phead)->next;
		(*phead)->next = s;
	}
}

void ListShow(List head)
{
	ListNode *p = head->next;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void main()
{
	List mylist;        //ListNode *mylist
	ListInit(&mylist);
	ListCreate_Head(&mylist);
	ListShow(mylist);
}

/*
//1->2->3->4......->10
//������
typedef struct ListNode
{
	int data;       //������
	ListNode *next; //ָ����
}ListNode;

typedef ListNode* List;
void ListInit(List *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
//β�巨
void ListCreate_Tail(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

//ͷ�巨
void ListCreate_Head(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = *phead;
		*phead = s;
	}
}

void ListCreate(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for(int i=2; i<=10; ++i)
	{
		p = p->next = (ListNode*)malloc(sizeof(ListNode));
		p->data = i;
		p->next = NULL;
	}
}

void ListShow(List head)
{
	ListNode *p = head;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void main()
{
	List mylist;        //ListNode *mylist
	ListInit(&mylist);
	ListCreate(&mylist);
	ListShow(mylist);
}

/*
//0  
void main()
{
	int a = 10;
	int b = 1;

	int res = a || ++b;  //��·��ֵ

	printf("res = %d\n", res); //
	printf("b = %d\n", b);     //
}

/*
void main()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 100;

	int *pa = (int*)malloc(sizeof(int)*10);
	//free(p);
}
*/