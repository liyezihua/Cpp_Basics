#include<stdio.h>
#include<stdlib.h>
#include<string>

//字符串拷贝
void strcopy(char* dest, char* src)
{
	/*while (*dest = *src)
	{
		*dest++;
		*src++;
	}*/
	while (*dest++ = *src++);
}
void strncopy(char* dest, char* src, size_t num)
{
	/*for (int i = 0;i < num;i++)
	{
		*dest = *src;
		*dest++;
		*src++;
	}*/
	while ((*dest++ = *src++) && --num);
}
int main34()
{
	char ch[] = "hello world";
	char ch1[100] = { 0 };
	//字符串拷贝
	//strcpy(ch1, ch);//系统自带函数
	//strcopy(ch1, ch);
	//字符串有限拷贝
	//strncpy(ch1,ch,50);//系统自带函数
	strncopy(ch1, ch, 5);
	printf("%s\n", ch1);
	return 0;
}


//字符串拼接追加
void strcoat(char* dest, char* src)
{

	//找到dest字符串中\0的位置
	while (*dest)dest++;
	//拷贝
	while (*dest++ = *src++);
}
void strncoat(char* dest, char* src, size_t n)
{

	//找到dest字符串中\0的位置
	while (*dest)dest++;
	//拷贝
	while ((*dest++ = *src++) && --n);
}
int main35()
{
	char ch[100] = "hello";
	char ch1[10] = "world";
	//字符串追加
	//strcat(ch, ch1);//系统函数实现
	//strcoat(ch, ch1);
	//字符串有限追加
	//strncat(ch, ch1, 3);
	//strncoat(ch, ch1,4);
	printf("%s\n", ch);
	return 0;
}


//字符串比较
int strcmp1(char* ch, char* ch1)
{
	while (*ch == *ch1)//字符串相等
	{
		if (*ch == '\0')//去除空格
			return 0;
		ch++;
		ch1++;
	}
	//字符串不相等
	return *ch > *ch1 ? 1 : -1;
}

int strncmp1(char* ch, char* ch1, size_t n)
{
	for (int i = 0;i < n && ch[i] && ch1[i];i++)
	{
		if (ch[i] != ch1[i])//不相等
			return ch[i] > ch1[i] ? 1 : -1;
	}
	//相等
	return 0;
}

int main36()
{
	char ch[] = "helro";
	char ch1[] = "hello";
	int val = 0;
	//字符串比较
	//val = strcmp(ch, ch1);//系统函数实现
	//val = strcmp1(ch, ch1);
	//字符串有限比较
	//val = strncmp(ch, ch1, 3);//系统函数实现
	val = strncmp1(ch, ch1, 5);
	if (val == 0)
		printf("相等");
	else
		printf("不相等");
	//printf("%d\n",val);

	return 0;
}


int main37()
{
	//sprinf字符串格式化输出与printf输出函数相似
	//不同：sprintf是输出到字符串里,printf是输出到命令行
	char ch[100];
	//sprintf(ch, "hello world");
	//sprintf(ch, "%d+%d=%d", 1, 2, 3);
	//sprintf(ch, "%0.2d+%0.2d=%0.2d", 1, 2, 3);
	//sprintf(ch, "%x+%o=%d", 0xff, 23, 18);


	//sscanf字符串格式化输入与scanf输入函数相似
	//不同于scanf，sscanf是以固定字符作为输入源，scanf是以键盘作为输入源
	char ch2[] = "hello world";
	char str1[100];
	char str2[100];
	//sscanf(ch2, "%[^\n]", str1);
	sscanf(ch2, "%5s%s", str1, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);

	//char ch1[] = "0xff+27=18";
	//int a, b, c;
	//sscanf(ch1, "%x+%o=%d",&a,&b,&c);
	//printf("%d\n", a);
	//printf("%d\n", b);
	//printf("%d\n", c);
	return 0;
}