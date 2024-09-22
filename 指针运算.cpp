#include<stdio.h>

void strcpy(char* dest, char* ch)//拷贝字符串数组
{
	int i = 0;
	while (ch[i])
	{
		dest[i] = ch[i];
		i++;
	}
	dest[i] = 0;
}

void strcpy1(char* dest, char* ch)//指针加偏移量
{
	int i = 0;
	while (*(ch+i))
	{
		*(dest + i) = *(ch + i);
		i++;
	}
	*(dest + i) = 0;
}

void strcpy2(char* dest, char* ch)//指针
{
	while (*ch)
	{
		*dest = *ch;
		*dest++;//指针加一相当于指针指向下一个地址 内存地址变化了sizeof(char)
		*ch++;
	}
	*dest = 0;
}

void strcpy3(char* dest, char* ch)
{
	while (*dest++ = *ch++);
}

int main14()
{
	char ch[] = { "hello" };
	char dest[100];

	strcpy1(dest, ch);
	printf("%s\n", dest);
	return 0;
}

int main15()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };

	int* p;
	p = &arr[3];
	//printf("%p\n", p);
	//printf("%p\n", arr);
	//p--;//指针的加减运算和指针的类型有关
	//p--;
	//p--;
	//内存地址相差是 12 / sizeof(int) = 偏移量
	int stp = p - arr;
	printf("%d\n", stp);
	printf("%p\n", arr);

	printf("%d\n", p[-1]);//*(p-1)

	return 0;

}