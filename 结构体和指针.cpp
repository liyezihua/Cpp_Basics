#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

//结构体成员为指针
struct student
{
	char* name;
	int age;
	int* score;
	char* addr;
};

int main51()
{
	struct student stu;
	//stu.name =(char*)"张三";
	//开辟堆空间存储结构体
	stu.name = (char*)malloc(sizeof(char*) * 21);
	stu.score = (int*)malloc(sizeof(int*) * 3);
	stu.addr = (char*)malloc(sizeof(char*) * 51);
	strcpy(stu.name, "张三");
	stu.age = 18;
	stu.score[0] = 100;
	stu.score[1] = 99;
	stu.score[2] = 120;
	strcpy(stu.addr, "四川");

	printf("姓名：%s\n", stu.name);
	printf("年龄：%d\n", stu.age);
	printf("分数：%d\n",stu.score[0]);
	printf("分数：%d\n", stu.score[1]);
	printf("分数：%d\n", stu.score[2]);
	printf("地址：%s\n\n", stu.addr);
	//释放
	free(stu.name);
	free(stu.score);
	free(stu.addr);

	return 0;
}

struct stu
{
	char name[21];
	int age;
	int score[3];
	char addr[51];
};
int main52()
{
	//printf("I\n\nL\no\nv\ne\n\nG\nP\nL\nT");

	//结构体指针 通过指针指向结构体变量
	struct stu s = { "小金",18,100,100,100,"四川" };
	struct stu* p= &s;

	//结构体指针->成员  通过指针访问结构体成员
	//结构体变量.成员
	printf("%s\n",p->name);
	printf("%d\n", p->age);
	printf("%d\n", p->score[0]);
	printf("%d\n", p->score[1]);
	printf("%d\n", p->score[2]);
	printf("%s\n", p->addr);
	return 0;
}



typedef struct stu1 ss;
struct stu1
{
	char *name;
	int age;
	int *score;
	char *addr;
};
int main53()
{
	//开辟堆空间存储结构体
	ss* p = (ss*)malloc(sizeof(ss*) * 3);

	for (int i = 0;i < 3;i++)
	{
		p[i].name = (char*)malloc(sizeof(char) * 21);
		p[i].score = (int*)malloc(sizeof(char) * 3);
		p[i].addr = (char*)malloc(sizeof(char) * 51);
	}
	//输入
	for (int i = 0;i < 3;i++)
	{
		scanf("%s%d%d%s", p[i].name, &p[i].age, 
			p[i].score[0],p[i].score[1],p[i].score[2], p[i].addr);
	}
	//打印
	for (int i = 0;i < 3;i++)
	{
		printf("姓名：%s\n", p[i].name);
		printf("年龄：%d\n", p[i].age);
		printf("分数：%d\n", p[i].score[0]);
		printf("分数：%d\n", p[i].score[1]);
		printf("分数：%d\n", p[i].score[2]);
		printf("地址：%s\n\n", p[i].addr);
	}
	//释放
	for (int i = 0;i < 3;i++)
	{
		free(p[i].name);
		free(p[i].score);
		free(p[i].addr);
	}
	

	return 0;
}

