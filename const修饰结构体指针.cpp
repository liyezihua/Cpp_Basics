#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

//结构体变量作为函数参数

typedef struct st s;
struct st
{
	char name[21];
	//char* name;//地址传递
	int age;
	int score;
	char addr[51];
};

void fun1(s stu)
{
	strcpy(stu.name,"狗");
	printf("%s\n", stu.name);
}

int main54()
{
	 s st1 ={"小",18,100,"四川"};
	//st1.name = (char*)malloc(sizeof(char*) * 21);
	//strcpy(st1.name, "小");
	fun1(st1);
	printf("%s\n", st1.name);
	return 0;
}

void fun2(s* p)
{
	strcpy(p->name,"小金");
	printf("%s\n", p->name);
}

//数组作为函数参数退化为指针 丢失元素精度 需要传递个数
void bubbie(s *stur, int len)
{
	//printf("%d\n", sizeof(stur));
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (stur[j].age > stur[j + 1].age)
			{
				s temp = stur[j];
				stur[j] = stur[j + 1];
				stur[j + 1] = temp;
			}
		}
	}
}
int main55()
{
	//结构体指针作为函数参数
	s stu = { "小气",19,10,"四川" };
	fun2(&stu);
	printf("%s\n", stu.name);
	

	 s st2[3] =
	{
		{"吏曹",11,100,"四川"},
		{"哈哈哈",12,120,"湖北"},
		{"交换机",13,140,"湖南"}
	};

	 bubbie(st2, 3);

	 for (int i = 0;i < 3;i++)
	 {
		 printf("姓名：%s\n", st2[i].name);
		 printf("年龄：%d\n", st2[i].age);
		 printf("分数：%d\n", st2[i].score);
		 printf("地址：%s\n\n", st2[i].addr);
	 }
	 return 0;
}

int main56()
{
	s stt = { "小金",19,100,"四川" };
	s str = { "吏曹",11,100,"四川" };
	//const修饰结构体指针类型
	//const s* p = &stt;
	//p = &str;//ok
	//p->age = 888;//err

	//const修饰结构体指针变量
	//s* const p = &stt;
	//p = &str;//err
	//p->age = 888;//ok

	//const修饰结构体指针类型和变量
	const s* const p = &stt;
	//p = &str;//err
	//p->age = 888;//err

	return 0;

}