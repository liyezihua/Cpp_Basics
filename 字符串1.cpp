#include<stdio.h>
#include<string>

//统计字符串出现次数
char* strctr1(char* dest, char* src)
{
	if (*src == '\0')//如果src直接为空，那就返回dest
		return dest;
	char* s1 = NULL;//遍历dest字符串
	char* s2 = NULL;//遍历src字符串
	char* sign = dest;//记录dest
	while (*sign)
	{
		s1 = sign;//每回都让sign赋给s1
		s2 = src;//如果有一部分字符相同，但整体不相同，那此时跳出循环再让src回滚
		while (*s1 == *s2 && *s1 && *s2)//如果两个字符串到了都相同，那就跳出循环
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return sign;//
		sign++;
	}
	return NULL;//循环结束了还没有那就是找不到了
}

int main29()
{
	//char* str;
	char ch[] = "47267846824hhh93472394hhhajdajhhh9479237hhh";
	//str = ch;
	char ch1[] = "hhh";
	char* p = strctr1(ch, ch1);
	int count = 0;
	while (p)
	{
		p += strlen(ch1);
		p = strctr1(p, ch1);
		count++;
	}
	//printf("%s\n", p);
	printf("在字符串中出现了：%d", count);
	return 0;
}

//统计字符串去除空格后字符串的个数
int getcount(char* ch)//数组实现
{
	int count = 0;
	int i = 0;
	while (ch)
	{
		if (ch[i] != ' ')
		{
			count++;
		}
		i++;
		if (i > strlen(ch))
			return  count;
	}
}
int getcount1(char* ch)//指针实现
{
	int count = 0;
	while (*ch)
	{
		if (*ch != ' ')
			count++;
		ch++;
	}
	return count;
}
int main30()
{
	char ch[] = "   hell o world  ";

	int len = getcount1(ch);

	printf("%d", len);

	return 0;
}


//统计单个字符出现次数
int main31()
{
	//统计字符串出现的次数
	char ch[] = "aucsiochosvjoaidhviaosdhfuasdifdhuivbasduivh";//97 97+26
	//存储字符串出现的次数
	int arr[26] = { 0 };
	for (int i = 0;i < strlen(ch); i++)
	{
		arr[ch[i] - 'a']++;
	}

	for (int i = 0;i < 26;i++)
	{
		if (arr[i] != 0)
			printf("字母：%c 出现次数：%d\n", i + 'a', arr[i]);
	}
	return 0;
}

//字符串逆置
void inves(char* ch)//数组实现
{
	int i = 0;//从头开始
	int j = strlen(ch) - 1;//从尾开始
	while (i < j)
	{
		char temp = ch[i];
		ch[i] = ch[j];
		temp = ch[j];
		i++;
		j--;
	}
	return;
}
void inves1(char* ch)//指针实现
{
	char* ftemp = ch;
	char* rtemp = ch + strlen(ch) - 1;
	while (ftemp < rtemp)
	{
		char temp = *ftemp;
		*ftemp = *rtemp;
		*rtemp = temp;
		ftemp++;
		rtemp--;
	}
	return;
}

int main32()
{
	char ch[] = "hello wold";
	inves1(ch);
	printf("%s\n", ch);

	return 0;
}

//判断是否是回文字符串
int sytem(char* ch)
{
	char* ftemp = ch;
	char* rtemp = ch + strlen(ch) - 1;
	while (ftemp < rtemp)
	{
		if (*ftemp != *rtemp)
			return 1;
		ftemp++;
		rtemp--;
	}
	return 0;
}

int main33()
{
	char ch[] = "heojkjoehd";

	int val = sytem(ch);
	if (!val)
		printf("相同");
	else
		printf("不相同");
	return 0;
}