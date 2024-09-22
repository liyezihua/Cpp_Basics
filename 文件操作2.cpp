#include<stdio.h>
#include<string.h>
#include<time.h>;
#include<stdlib.h>
//文件打印四则运算
enum op
{
	add, sub, mlt, dive
}op;
int main65()
{
	srand((size_t)time(NULL));
	FILE* fp1 = fopen("D:\shizhe.txt", "w");
	if (!fp1)
		return -1;
	int a, b;
	char c;
	char* p = (char*)malloc(sizeof(char) * 20);
	for (int i = 0;i < 100;i++)
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		switch (rand() % 4)
		{
		case add:c = '+';break;
		case sub:c = '-';break;
		case mlt:c = '*';break;
		case dive:c = '/';break;
		}
		memset(p, 0, 20);
		sprintf(p, "%d%c%d=\n", &a, &c, b);
		fputs(p, fp1);
	}
	free(p);
	fclose(fp1);
	p = NULL;
	fp1 = NULL;

	return 0;
}


int main66()
{
	FILE* fp1 = fopen("D:\shizhe.txt", "r");
	FILE* fp2 = fopen("D:\shizheyunsuan.txt", "w");
	if (!fp1 || !fp2)
	{
		printf("打开文件失败");
		return -1;
	}
	int a, b, sum = 0;
	char c;
	char* p = (char*)malloc(sizeof(char) * 20);
	for (int i = 0;i < 100;i++)
	{
		memset(p, 0, 20);
		fgets(p, 20, fp1);
		sscanf(p, "%d%c%d=\n", &a, &c, &b);
		switch (c)
		{
		case'+':sum = a + b;break;
		case'-':sum = a - b;break;
		case'*':sum = a * b;break;
		case'/':sum = a / b;break;
		}
		memset(p, 0, 20);
		sprintf(p, "%d%c%d=%d\n", a, c, b, sum);
		fputs(p, fp2);
	}
	free(p);
	fclose(fp1);
	fclose(fp2);
	return 0;
}

//文件格式化读写
int main67()
{
	FILE* fp1 = fopen("D:/a.txt", "r");
	if (!fp1)
		return -1;
	char* p = (char*)malloc(sizeof(char) * 100);

	fscanf(fp1, "%s", p);
	printf("%s", p);

	free(p);
	fclose(fp1);
	return 0;
}

int main68()
{
	FILE* fp1 = fopen("D:/a.txt", "r");
	if (!fp1)
		return -1;

	int a, b, c;

	//fscanf(fp1, "%d+%d=%d", &a, &b, &c);
	fscanf(fp1, "%x", &a);
	//fprintf(fp1, "%d", &a);
	printf("%05d", a);

	//printf("%d\n", a);
	//printf("%d\n", b);
	//printf("%d\n", c);

	fclose(fp1);

	return 0;
}

//大文件排序
int main69()
{
	srand((size_t)time(NULL));
	FILE* fp1 = fopen("D:/ass.txt", "w");
	if (!fp1)
		return -1;
	for (int i = 0;i < 1000;i++)
	{
		fprintf(fp1, "%d\n", rand() % 256);
	}
	fclose(fp1);
	return 0;
}

//冒泡排序版
void bubbleso(int arr[], int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
#define size 1000
int main70()
{
	FILE* fp1 = fopen("D:/ass.txt", "r");
	FILE* fp2 = fopen("D:/assdd.txt", "w");
	if (!fp1 || !fp2)
		return -1;

	//冒泡排序
	int* arr = (int*)malloc(sizeof(int) * 1000);
	for (int i = 0;i < 1000;i++)
	{
		fscanf(fp1, "%d\n", &arr[i]);
	}
	bubbleso(arr, size);
	for (int i = 0;i < size;i++)
	{
		fprintf(fp2, "%d\n", arr[i]);
	}
	free(arr);
	fclose(fp1);
	fclose(fp2);

	return 0;
}

//数据插入版排序
int main71()
{
	FILE* fp1 = fopen("D:/ass.txt", "r");
	FILE* fp2 = fopen("D:/assddff.txt", "w");
	if (!fp1 || !fp2)
		return -1;
	int* arr = (int*)malloc(sizeof(int) * 256);

	memset(arr, 0, sizeof(int) * 256);
	for (int i = 0;i < 1000;i++)
	{
		int val;
		fscanf(fp1, "%d\n", &val);
		arr[val]++;
	}

	for (int i = 0;i < 256;i++)
	{
		for (int j = 0;j < arr[i];j++)
		{
			fprintf(fp2, "%d\n", i);
		}
	}

	free(arr);
	fclose(fp1);
	fclose(fp2);

	return 0;
}