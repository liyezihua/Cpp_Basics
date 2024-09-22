#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main6()
{
	//添加随机数种子
	srand((size_t)time(NULL));

	for (int i = 0;i < 100;i++)
	{
		printf("%d\n", rand() % 50 + 51);//50-100
	}
	return 0;
}

int main7()//随机数去除重复值
{
	srand((unsigned int)time(NULL));
	int arr[6] = { 0 };
	int val = 0;
	int falg = 0;
	int j, i;
	for (i = 0;i < 6;i++)
	{
		val = rand() % 32 + 1;
		//去重
		for (j = 0;j < falg;j++)
		{
			if (arr[j] == val)
			{
				i--;
				break;
			}
		}
		if (j == falg)
		{
			arr[falg] = val;
			falg++;
		}
	}
	for (i = 0;i < 6;i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}