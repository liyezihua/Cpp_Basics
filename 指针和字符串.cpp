#include<stdio.h>

int main25()
{
	char ch[] = "hello world";//栈区字符串
	//char* pp = "hello world";//数据区常量区字符串
	char* p = ch;

	ch[2] = 'm';
	//p[2] = 'k';

	printf("%s\n", ch);
	printf("%s\n", p);
	printf("%p\n", &ch);
	printf("%p\n", &p);
	return 0;
}

int main26()
{
	//字符串数组
	char ch1[] = "hello";
	char ch2[] = "borld";
	char ch3[] = "asjsjjsjfsfsfs";
	char* arr[] = { ch1,ch2,ch3 };

	//字符串排序
	for (int i = 0;i < 3-1;i++)
	{
		for (int j = 0;j < 3 - 1 - i;j++)
		{
			//找到首字母进行比较
			if (arr[j][0] > arr[j + 1][0])
			{
				//交换指针数组元素进行排序
				char* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i = 0;i < 3;i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}


//字符指针作为函数参数
//计算字符串有效长度 数组方式
int strlen(char* ch)
{
	int i = 0;
	while (ch[i]!='\0')i++;
	return i;
}
//计算字符串有效长度 指针方式
int strlen2(char* ch)
{
	char* temp = ch;
	while (*temp!='\0')temp++;
	return temp - ch;
}

int main27()
{
	char ch[] = "hello world";

	int len = strlen2(ch);
	printf("%d", len);

	return 0;
}