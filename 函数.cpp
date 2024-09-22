#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//函数声明
extern void sdd(int a, int b);
void sdd(int a, int b);
//函数定义
void sdd(int a, int b)//交换函数
{
	int temp = a;
	a = b;
	b = temp;

	printf("a=%d\n", a);
	printf("b=%d\n", b);
}
//较连个字符串是否相同
char ass(char ch1[], char ch2[])
{
	int i = 0;
	while (ch1[i] == ch2[i])
	{
		if (ch1[i] == '\0')
		{
			return 0;
		}
		i++;
	}
	return ch1[i] == ch2[i] ? 1 : -1;
}

int aff()//无参函数
{
	 return  printf("无参函数\n");
}
//冒泡排序函数版
void bubblesort(int arr[], int len)
{
	for (int i = 0;i < len-1;i++)
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
int main8()
{
	int a=10;
	int b=20;
    sdd(a,b);
	
	/*char ch1[]={"hell"};
	char ch2[]={"hell"};
	scanf("%s %s", ch1, ch2);
	int val = ass(ch1, ch2);
	if (val == 0)
		printf("两个字符串相同\n");
	else
		printf("两个字符不相同\n");*/


	aff();
	exit(404);//退出程序
	int arr[] = { 9,8,6,4,3,6,1,2,5,10 };
	bubblesort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0;i < 10;i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}