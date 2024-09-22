#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

//定义结构体
struct stdon
{
	char name[24];
	int age;
	int score;
	char addr[51];
}s1;//结构体变量

int main47()
{
	//创建结构体变量
	//struct stdon st1;

	//结构体赋值
	//struct stdon st1 = { "张三",18,129,"四川成都" };

	//st1.score = 130;
	//st1.age = 18;
	//strcpy(st1.name, "张三");
	//strcpy(st1.addr, "四川成都");
	
	//结构体输入数据
	//scanf("%s%d%d%s", st1.name, &st1.age, &st1.score, st1.addr);

	/*printf("姓名：%s\n", st1.name);
	printf("年龄：%d\n", st1.age);
	printf("分数：%d\n", st1.score);
	printf("地址：%s\n", st1.addr);*/
	return 0;
}


//结构体数组
int main48()
{
	struct stdon st1[3] =
	{
		{"吏曹",11,100,"四川"},
		{"哈哈哈",12,120,"湖北"},
		{"交换机",13,140,"湖南"}
	};
	//结构体数组排序
	for (int i = 0;i < 3 - 1;i++)
	{
		for (int j = 0;j < 3 - 1 - i;j++)
		{
			if (st1[j].age > st1[j + 1].age)
			{
				struct stdon temp = st1[j];
				st1[j] = st1[j + 1];
				st1[j + 1] = temp;
			}
		}
	}

	for (int i = 0;i < 3;i++)
	{
		printf("姓名：%s\n", st1[i].name);
		printf("年龄：%d\n", st1[i].age);
		printf("分数：%d\n", st1[i].score);
		printf("地址：%s\n\n", st1[i].addr);
	}
	return 0;
}

//开辟堆空间存储结构体
typedef struct stdon s;
int main49()
{
	s* p = (s*)malloc(sizeof(s) * 3);

	for (int i = 0;i < 3;i++)
	{
		scanf("%s%d%d%s",p[i].name,&p[i].age,&p[i].score,p[i].addr);
	}
	for (int i = 0;i < 3;i++)
	{
		printf("姓名：%s\n", p[i].name);
		printf("年龄：%d\n", p[i].age);
		printf("分数：%d\n", p[i].score);
		printf("地址：%s\n\n", p[i].addr);
	}
	return 0;
}


//结构体嵌套结构体
struct scores
{
	int c;
	int cpp;
	int cs;
};
struct student
{
	char name[21];
	int age;
	struct scores ss;//嵌套的结构体
	char addr[21];
};
//typedef struct studnet st;
int main50()
{
	struct student stu ={"小金",18,100,100,100,"四川"};

	//结构体赋值 s1不会影响stu 深拷贝和浅拷贝
	struct student s1 = stu;
	strcpy(s1.name, "狗七");
	printf("%s\n",s1.name);

	printf("姓名：%s\n", stu.name);
	printf("年龄：%d\n", stu.age);
	printf("分数：%d;%d;%d\n",stu.ss.c,stu.ss.cpp,stu.ss.cs);
	printf("地址：%s\n\n", stu.addr);

	printf("学生结构体大小：%d\n", sizeof(stu));
	printf("分数结构体大小：%d\n", sizeof(stu.ss));
	printf("名称数组大小：%d\n", sizeof(stu.name));
	return 0;
}