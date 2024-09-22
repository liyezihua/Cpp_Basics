#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//字符串查找
char* strchr1(char* ch, int c)
{
	while (*ch)
	{
		if (*ch == c)
			return ch;
		ch++;
	}
	return NULL;
}

int main38()
{
	char ch[] = "hello world";
	char c = 'l';
	char b[] = "llo";
	//字符串查找
	//char* p = strchr(ch, c);
	//char* p = strchr1(ch, c);
	//字符串中查找字符串
	char* p = strstr(ch, b);
	printf("%s\n", p);

	return 0;
}
//字符串分割
int main39()
{
	//strtok字符串截取会破坏原字符串，会用\0替换分割的标志位
	//char ch[] = "www.baidu.com";
	//www\0baidu.com 第一次截取
	//www\0baidu\0com 第二次截取
	//ww\0baidu\0com\0 第三次截取

	/*char* p = strtok(ch, ".");
	printf("%s\n", p);
	p = strtok(NULL, ".");
	printf("%s\n", p);
	p = strtok(NULL, ".");
	printf("%s\n", p);*/

	/*char ch1[] = "2134652266@qq.com";
	char str[100];
	strcpy(str, ch1);
	char* p = strtok(str, "@");//2134652266
	printf("%s\n",p);
	p = strtok(NULL, ".");//qq
	printf("%s\n", p);*/

	//char ch2[]="dhsd\ndanks\ndjjd\nddjdjd\nfnkj\njfjfk";
	char ch2[] = "你愁啥\n瞅你咋地\n再抽一个事实\n试试就试试\n滚开点\n别逼我";
	char str2[100];
	//备份
	strcpy(str2, ch2);
	//开始分割分割标志为\n
	char*p1=strtok(str2,"\n");
	//printf("%s\n", p1);
	//循环分割
	while (p1)
	{
		printf("%s\n", p1);
		p1 = strtok(NULL, "\n");//二次分割
	}
	return 0;
}


//字符串类型转换
int main40()
{
	//atoi将字符串类型转为整形
	//atoi会跳过空格从数字或正负号开始转换，遇到非数字或字符串\0停止转换
	char ch[] = "   -123-45678abcdf123";//-123
	int p = atoi(ch);
	printf("%d\n", p);
	//atof将字符串类型转为浮点型
	char ch1[] = "   -123.45678abcdf123";
	double a = atof(ch1);//-123.46
	printf("%.2f\n", a);
	//atol将字符串转换为long长整型
	char ch2[] = "   -123.4.5678abcdf123";
	long b = atof(ch2);//-123
	printf("%ld\n", b);

	return 0;
}