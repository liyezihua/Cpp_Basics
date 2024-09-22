#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
using namespace std;
#define max 10
//全局变量
//作用域：项目中所有
//生命周期：程序创建到销毁
//存储位置；数据区
int d = 0;

//静态全局变量
//作用域：定义的文件中
//生命周期：程序创建到销毁
//存储位置；数据区
static int c = 0;

//全局函数
//作用域：项目中所有文件
//生命周期：程序创建到销毁
//存储位置；代码区

void str()
{
	//静态变量只能被初始化一次，可以多次赋值
	static int c = 0;
	c++;
	printf("%d", c);
}

//静态函数
//作用域：定义所在文件中
//生命周期：程序创建到销毁
//存储位置；代码区
static void sre1();

int main41()
{
	//局部变量
	//作用域：函数内部
	//生命周期：局部变量创建到函数结束
	//存储位置；栈区
	int a = 0;

	//静态局部变量
	//作用域：函数内部
	//生命周期：程序创建到销毁
	//存储位置；数据区
	static int b = 0;
	for (int i = 0;i < 10;i++)
	{
		str();
	}
	return 0;
}

//全局变量
int a;
int a1 = 0;
//静态全局变量
static int b;
static int b1 = 0;
int main42()
{
	//局部变量
	int c;
	int c1 = 0;
	//静态局部变量
	static int d;
	static int d1 = 0;
	//数组
	int arr[100];
	int arr1[] = { 0 };
	//指针
	int* p;
	int* p1 = NULL;

	char ch[100];
	char ch1[] = "\0";
	printf("未初始化的全局变量%p\n", &a);
	printf("初始化的全局变量%p\n", &a1);
	printf("未初始化的静态全局变量%p\n", &b);
	printf("初始化的静态全局变量%p\n", &b1);
	printf("未初始化的局部变量%p\n", &c);
	printf("初始化的局部变量%p\n", &c1);
	printf("未初始化的静态局部变量%p\n", &d);
	printf("初始化的静态局部变量%p\n", &d1);
	printf("未初始化的数组%p\n", &arr);
	printf("初始化的数组%p\n", &arr1);
	printf("未初始化的指针%p\n", &p);
	printf("初始化的指针%p\n", &p1);
	printf("未初始化的字符串%p\n", &ch);
	printf("初始化的字符串%p\n", &ch1);
	return 0;
}

//堆空间的开辟使用和释放
int main43()
{
	//栈区大小1M
	//int arr[210000] = { 0 };

	////开辟堆空间存放数据
	//int* p = (int*)malloc(sizeof(int));

	//printf("%p\n", p);
	////使用堆空间
	////int a = 110;
	//*p =111;

	//printf("%d\n", *p);
	////释放堆空间
	//free(p);
	//p = NULL;

	int* pp = (int*)malloc(sizeof(int) * 8200000 * 100);
	printf("%p\n", pp);

	free(pp);

	return 0;
}

//堆空间存储数据
void bubblesor(int arr[], int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main44()
{
	srand((size_t)time(NULL));

	int* p = (int*)malloc(sizeof(int) * 10);

	for (int i = 0;i < max;i++)
	{
		p[i] = rand() % 100;
		printf("%d ", p[i]);
	}
	bubblesor(p, max);

	for (int i = 0;i < max;i++)
	{
		//printf("%d\n", p[i]);
		printf("%d\n", *p);
		p++;
	}

	free(p);
	return 0;
}

//内存处理函数
int main45()
{
	int* p = (int*)malloc(sizeof(int) * 10);
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//memset重置内存空间的值
	//memset(p, 0, sizeof(int)*10);

	//memcpy内存拷贝，不同于strcpy字符串拷贝遇到\0不会停止，拷贝的内容和字节有关
	//memcpy(p, arr, sizeof(int) * 10);

	//memmove内存拷贝和memcpy区别在于目标dest和源src所指的空间重叠时仍能处理不过效率比memcpy低一些
	memmove(&arr[5], &arr[3], 20);

	//memcmp内存比较
	int arr1[] = { 1,2,3,4,5,8,7 };
	int arr2[] = { 1,2,3,4,5 };
	int pp = memcmp(arr1, arr2, 20);
	printf("%d\n", pp);

	for (int i = 0;i < max;i++)
	{
		printf("%d\n", arr[i]);
	}
	free(p);
	return 0;
}


//开辟二级指针对应的堆空间
int main46()
{
	//int arr[5][3];
	//开辟二级指针对应的堆空间
	int** p = (int**)malloc(sizeof(int*) * 5);

	for (int i = 0;i < 5;i++)
	{
		//开辟一级指针对应的堆空间
		p[i] = (int*)malloc(sizeof(int*) * 3);
	}

	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			scanf("%d ", p[i][j]);
		}
		printf("\n");
	}

	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	//释放
	for (int i = 0;i < 5;i++)
	{
		//先释放内层
		free(p);
	}
	//释放外层
	free(p);
	return 0;
}