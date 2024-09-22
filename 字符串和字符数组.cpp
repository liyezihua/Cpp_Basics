#include <stdio.h>
#include<string.h>
int main5()
{
	char arr1[] = { 'h','e','l','l','o' };//字符数组
	char arr[] = { "hel\0lo" };//字符串 字符串默认结尾\0作为结束符
	printf("%s\n", arr);

	//定义字符数组存储字符串
	/*int arr2[10];
	scanf("%s", arr2);
	printf("%s\n", arr2);*/


	//字符串拼接
	/*char ch[] = {"hello"};
	char ch1[] = { "world" };
	char ch2[22];

	int i = 0, j = 0;
	while (ch[i]!='\0')
	{
		ch2[i] = ch[i];
		i++;
	}
	while (ch1[j]!='\0')
	{
		ch2[i + j] = ch1[j];
		j++;
	}
	ch2[i + j] = '\0';
	printf("%s", ch2);*/


	//字符串获取和打印
	char ar[100];

	//gets接收字符串可以带空格
	//gets_s(ar, 20);

	//fgets接收字符串可以带空格,获取字符串少于元素个数会自定添加\n 大于或等于则没有
	fgets(ar, sizeof(ar), stdin);

	//通过正则表达式scanf也可以接收空格
	//scanf("%[^\n]", ar);

	//printf("%s", ar);
	//puts(ar);//puts自带换行
	fputs(ar, stdout);//fputs不带换行

	//计算字符串长度
	char ch[] = "hello world";
	printf("数组大小：%d ", sizeof(ch));
	printf("字符串长度是：%d ", strlen(ch));

	/*int sum = 0;
	while (ch[sum]!='\0')
	{
		sum++;
	}
	printf("%d", sum);
	return 0;*/
	return 0;
}