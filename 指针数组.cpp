#include<stdio.h>

int main12()
{
	//指针和数组
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p;
	p = arr;//指针p指向数组arr的内存地址
	printf("%p\n", p);
	printf("%p\n", arr);
	*p = 100;

	for (int i = 0;i < 10;i++)
	{
		//printf("%d\n", arr[i]);
		//printf("%d\n", p[i]);
		//printf("%d\n", *(arr+1));//指针类型变量加一等同于内存地址+sizeof(int)
		//printf("%d\n", *(p+i));
		printf("%d\n", *p++);
	}
	/*printf("%p\n", p);
	printf("%p\n", arr);*/

	//两个指针相减得到的是两个指针之间的偏移量（步长）
	int stp = p - arr;
	printf("%d", stp);


	return 0;
}

//数组作为函数参数会退化为指针 丢失数组的精度
void bubblerost(int* arr, int len)
{
	printf("%d\n", sizeof(arr));

	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - i - 1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				/*int temp = arr[j];//数组操作
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;*/
				if (*(arr + j) > *(arr + j + 1))//指针操作
				{
					int temp = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = temp;
				}
			}
		}
	}
}

int main13()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	bubblerost(arr, 10);

	for (int i = 0;i < 10;i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}


int main16()
{
	//定义指针数组

	int a = 10;
	int b = 20;
	int c = 30;
	int* arr[] = { &a,&b,&c };

	for (int i = 0;i < sizeof(arr) / sizeof(arr[0]);i++)//遍历
	{
		printf("%d\n", *arr[i]);
	}

	printf("%d\n", *arr[0]);
	printf("指针数组大小：%d", sizeof(arr));
	printf("指针元素大小：%d", sizeof(arr[0]));

	return 0;
}

int main17()
{
	int a[] = { 1,2,3 };
	int b[] = { 2,3,4 };
	int c[] = { 4,5,6 };
	//指针数组是一个特殊的二维数组模型
	//指针数组想当于二级指针
	int* arr[] = { a,b,c };

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			//printf("%d ",arr[i][j]);
			//printf("%d", *(arr[i] + j));
			printf("%d ", *(*(arr + i) + j));
		}
		puts(" ");
	}


	return 0;
}