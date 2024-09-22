#include<stdio.h>

int main9()
{
	//定义指针变量存储变量地址
	//定义指针变量 数据类型 * 指针变量名;
	int* p;//定义指针变量
	int a = 100;
	
	//&是取地址符号是升维度的，*是取值符号是降维度的
	p = &a;//指针指向变量a的地址
	*p = 150;//通过指针间接修改a变量的值
	//a = 120;

	printf("%d\n", *p);//取值,取出指针所指向地址对应的值
	printf("%d\n", a);

	printf("%p\n", p);
	printf("%p\n", &a);

	//在32位操作系统下所有指针类型是4个字节大小，64位操作系统下所有指针类型都是8个字节
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(float*));

	return 0;
}

int main10()
{
	//野指针：指针变量指向一个未知的空间
	int* p;
	//操作野指针指向的内存空间可能报错
	printf("%p\n", *p);

	//空指针是指内存编号为0的空间
	int* u = NULL;
	//操作空指针的内存空间会报错
	printf("%d\n", *u);

	//空指针可以用在条件判断
	if (u == NULL)
	{

	}

	int a = 100;
	//万能指针可以接收任意类型变量的地址
	void* k = &a;
	//通过万能指针修改变量的值时，要找到对于的变量对应额指针类型
	//*k = 12;
	*(int*)k = 18;

	printf("%d\n", sizeof(void*));
	printf("%d\n", *(int*)k);
	return 0;
}

int main11()
{
	int a = 10;
	int b = 20;

	//const int* p = &a;//常量指针

	//int* const p = &b;//指针常量 指向常量的指针

	const int* const p = &a;//常指针常量

	//const修饰指针类型(常量指针)可以修改变量的值，不可以修改指针指向内存空间的值
	//const修饰指针变量(指针常量)不可以修改变量的值，可以修改指针指向内存空间的值
	//const修饰指针类型和指针变量(常指针常量)bu可以修改变量的值，不可以修改指针指向内存空间的值

	//p = &b;
	//*p = 100;

	printf("%d\n",*p);



	return 0;
}