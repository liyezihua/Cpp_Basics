#include<stdio.h>

//int argc 表示传递的参数
//gcc -o hello hello.c (4个参数) "gcc" "-o" "hello" "hello.c"
//char*argv[]={"gcc" "-o" "hello" "hello.c"}  表示参数具体内容
int main28(int argc,char*argv[])
{
	//gcc  cmd操作
	if (argc < 3)
	{
		printf("缺少参数");
		return -1;
	}

	for (int i = 0;i < argc;i++)
	{
		printf("%s\n", argv[i]);
	}

	return 0;
}