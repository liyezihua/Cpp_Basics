#include<stdio.h>
#include<string.h>
#include<time.h>;
#include<stdlib.h>

//文件块读写
int main72()
{
	FILE* fp1 = fopen("D:\cc.txt", "wb");
	if (!fp1)
		return -1;

	//int a = 1234;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	fwrite(arr, sizeof(int), 10, fp1);

	fclose(fp1);

	return 0;
}


int main73()
{
	FILE* fp1 = fopen("D:\cc.txt", "rb");
	if (!fp1)
		return -1;

	//int val;
	int arr[10] = { 0 };
	fread(&arr, sizeof(int), 10, fp1);

	for (int i = 0;i < 10;i++)
	{
		printf("%d\n", arr[i]);
	}
	fclose(fp1);
	return 0;
}

//文件读写结构体
typedef struct student
{
	char name[21];
	int age;
	int score;
	char addr[51];
}sty;
int main74()
{
	sty ss[3] =
	{
		{"小金",18,100,"四川宜宾"},
		{"小七",19,100,"四川"},
		{"小成",19,100,"四川成都"}
	};
	FILE* fp1 = fopen("D:\d.txt", "wb");
	if (!fp1)
		return -1;

	for (int i = 0;i < 3;i++)
	{
		fwrite(&ss[i], sizeof(ss), 1, fp1);
	}
;
	fclose(fp1);
	return 0;
}

int main75()
{
	FILE* fp = fopen("D:\d.txt", "rb");
	if (!fp)
		return -1;
	sty *ss = (sty*)malloc(sizeof(sty) * 3);
	int i = 0;
	while (!feof(fp))
	{
		fread(&ss[i], sizeof(sty), 1, fp);
		i++;
	}

	for (int i = 0;i < 3;i++)
	{
		printf("姓名：%s\n", ss[i].name);
		printf("年龄：%d\n", ss[i].age);
		printf("分数：%d\n", ss[i].score);
		printf("地址：%s\n", ss[i].addr);
	}
	free(ss);
	fclose(fp);

	return 0;
}




