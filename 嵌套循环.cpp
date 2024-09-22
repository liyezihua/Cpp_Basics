#include<stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
int main2()
{
	//嵌套循环外层执行一次内层执行一个周期
	//时钟
	//for (int i = 0;i < 24;i++)
	//{
	//	for (int j = 0;j < 60;j++)
	//	{
	//		for (int k = 0;k < 60;k++)
	//		{
	//			system("cls");//清屏
	//			printf("%02d:%02d:%02d\n", i, j,k);
	//			Sleep(950);//0.95
	//		}
	//	}
	//}
	
	//九九乘法表
	//for (int i = 1;i <= 9;i++)
	//{
	//	for (int j = 1;j <= i;j++)
	//	{
	//			printf("%d*%d=%d\t", j, i, i * j);
	//	}
	//	printf("\n");
	//}

	//打印金字塔
	//int a = 0;
	//printf("请输入打印的层数");
	//std::cin >> a;
	//for (int i = 1;i <= a;i++)
	//{
	//	for (int j = 1;j <=a-i;j++)
	//	{
	//		printf(" ");
	//	}
	//	for (int k = 1;k <= 2 * i - 1;k++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	for (int i = 0;i < 10, cout << i;i++);
	

	return 0;
}
