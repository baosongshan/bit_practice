#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

void RightLoopMove(char *pStr, unsigned short steps)
{
	assert(pStr != NULL && *pStr!='\0');
	int len = strlen(pStr);
	char *tmp = (char*)malloc(sizeof(char) * (len+1)); //空间复杂度O(n)
	steps %= len;
	for(int i=0; i<steps; ++i)
	{
		char tmp = pStr[len-1];
		for(int end=len-1; end>0; --end)
			pStr[end] = pStr[end-1];
		pStr[0] = tmp;
	}
}
void main()
{
	char str[] = "abcdefghi";
	printf("str = %s\n", str);
	RightLoopMove(str, 40);
	printf("str = %s\n", str);
}

/*
void RightLoopMove(char *pStr, unsigned short steps)
{
	assert(pStr != NULL && *pStr!='\0');
	int len = strlen(pStr);
	char *tmp = (char*)malloc(sizeof(char) * (len+1)); //空间复杂度O(n)
	assert(tmp != NULL);

	steps %= len;  //

	strcpy(tmp, pStr+(len-steps));
	strncat(tmp, pStr, len-steps);

	strncpy(pStr, tmp, len);
	free(tmp);
	tmp = NULL;
}
void main()
{
	char str[] = "abcdefghi";
	printf("str = %s\n", str);
	RightLoopMove(str, 20);
	printf("str = %s\n", str);
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	assert(p_data != NULL || (position>=1 && position<=8)); //更加完美

	if(flag)  //1
	{
		*p_data |= (0x01<<(position-1));
	}
	else      //0
	{
		*p_data &= ~(0x01<<(position-1));
	}
}
void main()
{
	unsigned char data = 123; //0 ~255  //0111 1011   double
	unsigned char pos = 3;
	bool flag = true;

	bit_set(&data, pos, flag);

	printf("data = %d\n", (int)data);  //0111 1111 ==> 127
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	if(flag)  //1
	{
		switch(position)
		{
		case 1:
			*p_data |= 0x01;  //0000 0001
			break;
		case 2:
			*p_data |= 0x02;  //0000 0010
			break;
		case 3:
			*p_data |= 0x04;  //0000 0100
			break;
		case 4:
			*p_data |= 0x08;  //0000 1000
			break;
		case 5:
			*p_data |= 0x10;  //0001 0000
			break;
		case 6:
			*p_data |= 0x20;  //0010 0000
			break;
		case 7:
			*p_data |= 0x40;  //0100 0000
			break;
		case 8:
			*p_data |= 0x80;  //1000 0000
			break;
		}
	}
	else   //0
	{
		switch(position)
		{
		case 1:
			*p_data &= ~0x01;  //~0000 0001 =>1111 1110
			break;
		case 2:
			*p_data &= ~0x02;  //0000 0010
			break;
		case 3:
			*p_data &= ~0x04;  //0000 0100
			break;
		case 4:
			*p_data &= ~0x08;  //0000 1000
			break;
		case 5:
			*p_data &= ~0x10;  //0001 0000
			break;
		case 6:
			*p_data &= ~0x20;  //0010 0000
			break;
		case 7:
			*p_data &= ~0x40;  //0100 0000
			break;
		case 8:
			*p_data &= ~0x80;  //1000 0000
			break;
		}
	}
}
void main()
{
	unsigned char data = 123; //0 ~255  //0111 1011
	unsigned char pos = 4;
	bool flag = false;

	bit_set(&data, pos, flag);

	printf("data = %d\n", (int)data);  //0111 1111 ==> 127
}

/*
void main()
{
	char *str = (char *)malloc(57);
	strcpy(str, "Hello");
	free(str);
	str = NULL; //预防野指针
	if (str != NULL)
	{
		strcpy(str, "C++");
		printf(str);
	}
}


/*
void GetMemory(char **p)
{
		*p = (char *)malloc(57);
		assert(*p != NULL);
}
void main()
{
		char *str = NULL;
		GetMemory(&str);
		strcpy(str,"HelloBIt");
		printf(str);

		free(str);
}


/*
char* GetMemory(void)
{
	char p[] = "HelloBit";
	return p;  //可以被返回
}
void main()
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}


/*
void GetMemory(char **p)
{
	*p = (char*)malloc(57);
}
void main()
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "HelloBit");
	printf(str);
}



/*
#define MAX_SIZE 255
void main()
{
	unsigned char buff[MAX_SIZE + 1];
	unsigned char i;
	for (i = 0; i <= MAX_SIZE; i++)
	{
		buff[i] = i;
		printf("sssssssssssss\n");
	}
}


/*
char str6[10];  //全局数组

//strlen  sizeof
int main()
{
	char ch = 5;

	char str1[] = "HelloBit";
	printf("len = %d\n", strlen(str1));
	printf("size = %d\n", sizeof(str1));

	char str2[10] = "HelloBit";
	printf("len = %d\n",  strlen(str2)); //
	printf("size = %d\n", sizeof(str2)); //

	char str3[10] ={'H','e', 'l', 'l', 'o', 'B','i','t'};
	printf("len = %d\n",  strlen(str3)); //
	printf("size = %d\n", sizeof(str3)); //

	char str4[] ={'H','e', 'l', 'l', 'o', 'B','i','t'};
	printf("len = %d\n",  strlen(str4)); //
	printf("size = %d\n", sizeof(str4)); //8

	char str5[10];
	for(int i=0; i<5; ++i)
		str5[i] = 'a' + i;
	printf("len = %d\n",  strlen(str5)); //随机
	printf("size = %d\n", sizeof(str5)); //

	for(int i=0; i<5; ++i)
		str6[i] = 'a' + i;
	printf("len = %d\n",  strlen(str6)); //5
	printf("size = %d\n", sizeof(str6)); //10

	char str7[10];
	for(int i=0; i<5; ++i)
		str7[i] = '0';  //'0'   '\0'
	printf("len = %d\n",  strlen(str7)); //随机
	printf("size = %d\n", sizeof(str7)); //10

	char str8[10];
	for(int i=0; i<5; ++i)
		str8[i] = 0; //str8[i] = '\0';  //'0'   '\0'   // '\0'==0
	printf("len = %d\n",  strlen(str8)); //随机
	printf("size = %d\n", sizeof(str8)); //10

	short *par[10][10]; //数组 10*10=100  short*=4
	printf("size = %d\n", sizeof(par));  //400

}
/*
int func( int a[] )
{
	//如果函数func参数传递数组Array,那么sizeof(a)呢？
	printf("%d\n", sizeof(a));  //4
	return 0;
}

void main()
{
	char str[] = "Welcome to Bit";
	int Array[] = {1,2,3,4,5,6,7,8,9};
	char *p = str;
	int  n;
	
	printf("len = %d\n",strlen(str));   //14
	printf("size = %d\n",sizeof(str));  //15
	printf("%d\n",sizeof(Array));       //36
	printf("%d\n", sizeof(p));          //4
	printf("%d\n",sizeof(n));           //4
	
	func(Array);

}
*/