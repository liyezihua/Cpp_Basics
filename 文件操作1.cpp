#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//文件的打开和关闭
int main59()
{
	//fopen打开文件
	FILE* fp = fopen("D:\main.txt", "r");

	//1：找不到文件
	//2：文件权限（读，写，执行）
	//3：程序打开文件超出上限 65535
	if (fp == NULL)
	{
		printf("打开文件失败");
		return -1;
	}
	printf("文件打开成功%p\n", fp);



	//文件的字符读取 文件默认结尾为-1
	char ch;
	ch = fgetc(fp);
	printf("%c\n", ch);
	//不能修改文件的指针 文件在读取时光标流会自动向下移动
	//fp++;
	//EOF为-1最后一位
	while (ch != EOF)
	{
		ch = fgetc(fp);
		printf("%c\n", ch);
	}

	//关闭文件
	fclose(fp);
	return 0;
}

//文件的写入
int main60()
{
	//写文件 文件不存在会创建新的文件，存在会清空之前的文件
	FILE* fp1 = fopen("D:\main.txt", "w");
	if (!fp1)
		return -1;
	//写文件
	char c = 'a';
	fputc(c, fp1);

	char ch;
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '@')
			break;
		fputc(ch, fp1);
	}

	//关闭文件
	fclose(fp1);
	return 0;
}

//文件加密
int main61()
{
	FILE* fp1 = fopen("D:\jiemi.txt", "r");
	FILE* fp2 = fopen("D:\jiami.txt", "w");
	if (!fp1 || !fp2)
		return -1;
	char ch;
	while ((ch = fgetc(fp1)) != EOF)
	{
		//加密
		ch++;
		fputc(ch, fp2);
	}

	//关闭文件
	fclose(fp1);
	fclose(fp2);

	return 0;
}


//文件解密
int main62()
{
	FILE* fp1 = fopen("D:\jiam.txt", "r");
	FILE* fp2 = fopen("D:\jiem.txt", "w");

	if (!fp1 || !fp2)
		return -1;
	char ch;
	while ((ch = fgetc(fp1)) != EOF)
	{
		//解密
		ch--;
		fputc(ch, fp2);
	}

	//关闭文件
	fclose(fp1);
	fclose(fp2);

	return 0;
}

//文件行读
int main63()
{
	FILE* fp1 = fopen("D:\ds.txt", "r");
	if (!fp1)
		return -1;

	char* p = (char*)malloc(sizeof(char) * 100);
	if (p == NULL)
		return -2;
	//memset(p, 0, 100);
	//fgets(p, 100, fp1);

	//feof判断文件是否结尾 可以判断文本文件和我二进制
	//如果到文件结尾返回非0；没到文件结尾为0
	while (!feof(fp1))
	{
		memset(p, 0, 100);
		fgets(p, 100, fp1);
		printf("%s\n", p);

	}
	//printf("%s\n", *p);

	free(p);
	fclose(fp1);
	return 0;
}

//文件行写
int main64()
{
	FILE* fp1 = fopen("D:\ds.txt", "r");
	if (!fp1)
		return -1;

	char* p = (char*)malloc(sizeof(char) * 1024);

	while (1)
	{
		memset(p, 0, 1024);
		scanf("%[^\n]", p);
		//吞掉回车
		getchar();
		//停止输入命令
		if (!strcmp(p, "com"))
			break;
		//追加\n
		strcat(p, "\n");
		fputs(p, fp1);
	}
	free(p);
	fclose(fp1);
	return 0;
}
