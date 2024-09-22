#include<stdio.h>

int main18()
{
	int a[] = { 1,2,3 };
	int b[] = { 2,3,4 };
	int c[] = { 4,5,6 };
	//指针数组是一个特殊的二维数组模型
	//指针数组想当于二级指针
	int* arr[] = { a,b,c };

	int** p = arr;

	//printf("%d", **p);//arr[0][0] a[0]
	//二级指针加偏移量相当于跳过了一个一维数组大小
	//printf("%d", **(p + 1));

	//一级指针加偏移量相当于跳过了一个元素
	printf("%d", *( * p + 1));

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			//printf("%d", p[i][j]);
			//printf("%d", *(p[i] + j));
			printf("%d", *(*(p + i) + j));
		}
		puts(" ");
	}
	return 0;
}

int main19()
{
	int a = 10;//变量
	int b = 200;
	int c = 13;
	int d = 20;
	int* p = &a;//一级指针指向变量

	//pp二级指针变量的值，*pp一级指针的值，**pp变量的值
	int** pp = &p;//二级指针指向一级指针

	//ppp三级指针变量的值，*ppp二级指针的值，**ppp一级指针的值 ***ppp变量的值
	int*** ppp = &pp;//三级指针指向二级指针

	p = &d;
	**ppp = &c;
	*pp = &b;
	

	printf("%d\n", ***ppp);
	printf("%d\n", **pp);
	printf("%d\n", *p);
	printf("%d\n", a);

	return 0;
}

void zhi(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//指针作为函数参数
void dizhi(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main20()//值传递和地址传递
{
	int a = 10;
	int b = 120;
	//值传递形参不影响实参的值
	//zhi(a, b);

	//地址传递形参可以改变实参的值
	dizhi(&a, &b);

	printf("%d ", a);
	printf("%d ", b);
	return 0;
}

