//#include"seqlist.h"
//#include"slist.h"
//#include"sclist.h"
//#include"dclist.h"
//#include"stack.h"
#include"queue.h"

void main()
{
	CycleSeqQueue Q;
	CycleSeqQueueInit(&Q);
	CycleSeqQueueEn(&Q, 1);
	CycleSeqQueueEn(&Q, 2);
	CycleSeqQueueEn(&Q, 3);
	CycleSeqQueueEn(&Q, 4);
	CycleSeqQueueEn(&Q, 5);
	CycleSeqQueueEn(&Q, 6);
	CycleSeqQueueEn(&Q, 7);
	CycleSeqQueueEn(&Q, 8);

	CycleSeqQueueEn(&Q, 9);
	CycleSeqQueueShow(&Q);

	CycleSeqQueueDe(&Q);
	CycleSeqQueueShow(&Q);
	CycleSeqQueueEn(&Q, 9);
	CycleSeqQueueShow(&Q);
}

/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q);
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 6);
	SeqQueueEn(&Q, 7);
	SeqQueueEn(&Q, 8);
	SeqQueueEn(&Q, 9);
	SeqQueueShow(&Q);

	SeqQueueDe(&Q);
	SeqQueueShow(&Q);
	printf("front = %d\n", SeqQueueFront(&Q));

	SeqQueueEn(&Q, 9);
}

/*
void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LinkQueueEn(&Q, 5);
	LinkQueueShow(&Q);
	
	int front_val;
	while(!LinkQueueEmpty(&Q))
	{
		front_val = LinkQueueFront(&Q);
		LinkQueueDe(&Q);
		printf("%d 出队.\n", front_val);
	}

	LinkQueueDestroy(&Q);
}

/*
void main()
{
	LinkStack st;
	LinkStackInit(&st);

	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);

	LinkStackPop(&st);
	LinkStackPop(&st);
	LinkStackShow(&st);

	printf("top = %d\n", LinkStackTop(&st));
	printf("size = %d\n", LinkStackSize(&st));

	LinkStackDestroy(&st);

}

/*
void main()
{
	SeqStack st;
	SeqStackInit(&st);

	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);

	int top_val;
	while(!SeqStackIsEmpty(&st))
	{
		//top_val = SeqStackTop(&st);
		SeqStackTop(&st, &top_val);
		SeqStackPop(&st);
		printf("%d 出栈.\n", top_val);
	}
	SeqStackDestroy(&st);
}

/*
int main()
{
	//SeqList list;
	//SeqListInit(&list);

	//SList list;
	//SListInit(&list);
	//SListNode *p = NULL;

	//SCList list;
	//SCListInit(&list);
	//SCListNode *p = NULL;

	DCList list;    //DCListNode *list
	DCListInit(&list);
	DCListNode *p = NULL;

	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while(select)
	{
		printf("*********************************************\n");
		printf("*  [1] push_back           [2] push_front   *\n");
		printf("*  [3] show_list           [0] quit_system  *\n");
		printf("*  [4] pop_back            [5] pop_front    *\n");
		printf("*  [6] insert_pos          [7] insert_val   *\n");
		printf("*  [8] erase_pos           [9] erase_val    *\n");
		printf("*  [10] find               [11] length      *\n");
		printf("*  [12] capacity           [13] sort        *\n");
		printf("*  [14] reverse            [15] clear       *\n");
		printf("*  [16] front              [17] back        *\n");
		printf("*  [18] binary_find        [19] erase_all   *\n");
		printf("*********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushBack(&list, item);
			}
			printf("头部插入数据成功......\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushFront(&list, item);
			}
			printf("尾部插入数据成功......\n");
			break;
		case 3:
			DCListShow(list);
			break;
		case 4:
			DCListPopBack(&list);
			printf("尾部删除数据成功......\n");
			break;
		case 5:
			DCListPopFront(&list);
			printf("头部删除数据成功......\n");
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			if(flag)
				printf("插入数据成功.......\n");
			else
				printf("插入数据失败.......\n");
			break;
		case 7:
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			//DCListSort(&list);
			DCListInsertByVal(list, item);
			printf("插入数据成功.......\n");
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			printf("删除数据成功.......\n");
			break;
		case 9:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			DCListEraseByVal(list, item);
			printf("删除数据成功.......\n");
			break;
		case 10:
			printf("请输入要查找的关键值:>");
			scanf("%d", &item);
			p = DCListFind(list, item);
			if(p == NULL)
				printf("数据查找失败.\n");
			else
				printf("数据查找成功.\n");
			break;
		case 11:
			printf("SList Length = %d\n", DCListLength(list));
			break;
		case 12:
			//printf("SeqList Capacity = %d\n", SeqListCapacity(&list));
			break;
		case 13:
			DCListSort(list);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			DCListReverse(list);
			printf("转置完成.\n");
			break;
		case 15:
			DCListClear(&list);
			break;
		case 16:
			printf("表头元素为: %d\n", DCListFront(list));
			break;
		case 17:
			printf("表尾元素为: %d\n", DCListBack(list));
			break;
		case 19:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			//SListEraseAll(&list, item);
			break;
		default:
			printf("命令出错,请重新输入......\n");
			break;
		}
		system("pause");
		system("cls");
	}

	DCListDestroy(&list);
	return 0;
}
*/