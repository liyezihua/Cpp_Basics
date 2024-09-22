#include<stdio.h>
#include<string.h>
#include<time.h>;
#include<stdlib.h>
//获取文件状态头文件
#include<sys/types.h>
#include<sys/stat.h>


#define SIZE 1024
//大文件拷贝

//创建拷贝文件程序 通过cmd运行窗口实现
//gcc - o D : \copy.exe C : \Users\Administrator\Source\Repos\复习\文件操作3.cpp
// 通过创建的拷贝文件程序，进行拷贝
// D:\main.exe为源文件，D:\code\main.exe为拷贝后的文件
//D:\copy.exe D : \main.txt D : \code\main.txt
int main76(int argc, char* argv[])
{
	/*for (int i = 0;i < argc;i++)
	{
		printf("%s\n", argv[i]);
	}*/

	if (argc < 3)
	{
		printf("参数过少");
		return -1;
	}
	//argv程序名称 文件大小是50M
	FILE* fp1 = fopen(argv[1], "rb");
	FILE* fp2 = fopen(argv[2], "wb");

	if (!fp1 || !fp2)
	{
		printf("复制文件出错");
		return -2;
	}

	
	char* temp = NULL;
	int size = 0;
	struct stat st;
	stat(argv[1], &st);
	//根据文件实际大小开辟空间
	if (st.st_size > size)
	{
		temp= (char*)malloc(sizeof(char) * SIZE);
		size=SIZE;
	}
	else
	{
		temp = (char*)malloc(sizeof(char) * st.st_size+10);
		size = st.st_size+10;
	}
	
	int count = 0;
	while (!feof(fp1))
	{
		memset(temp, 0, size);
		//读取成功的实际个数
	    count =	fread(temp, sizeof(char), size, fp1);
		fwrite(temp, sizeof(char), size, fp2);
	}

	free(temp);
	fclose(fp1);
	fclose(fp2);

	return 0;
}

//获取文件状态
int main77()
{
	struct stat st;
	stat("D:\copy.exe", &st);

	printf("文件大小：%d\n", st.st_size);
	system("pause");

	return 0;
}

//文件随机读写
int main78()
{
	FILE* fp1 = fopen("D:/a.txt", "r");
	if (!fp1)
		return -1;

	char arr[100];
	memset(arr, 0, 100);
	fgets(arr, 100, fp1);
	printf("%s", arr);

	//文件随机读写
	//fseek(fp1, -8, SEEK_CUR);

	//正数从文件起始位置开始偏移，负数从末尾
	fseek(fp1, 7, 0);
	memset(arr, 0, 100);
	fgets(arr, 100, fp1);
	printf("%s", arr);

	return 0;
}

int main79()
{
	//a追加
	FILE* fp1 = fopen("D:/a.txt", "r+");
	if (!fp1)
		return -1;
	long pos = ftell(fp1);

	printf("%ld\n", pos);
		//fseek(fp1, 17, SEEK_CUR);
	fseek(fp1, -30, SEEK_END);

		pos = ftell(fp1);
		printf("%ld\n", fp1);
		fputs("瞅你在咋地",fp1);

		fclose(fp1);
	return 0;
}

int main80()
{
	FILE* fp1 = fopen("D:/main.txt", "r");
	if (!fp1)
		return -1;
	char arr[100];
	//获取文件光标输出输出流位置
	long pos = ftell(fp1);
	printf("%ld\n", pos);
	fgets(arr, 100, fp1);
	fseek(fp1, 6, SEEK_CUR);
	pos = ftell(fp1);
	printf("%ld\n", pos);

	//重置文件光标在起始位置
	rewind(fp1);//fseek(fp1,0,SEEK_SET)
	memset(arr, 0, 100);
	fgets(arr, 100, fp1);
	printf("%s\n", arr);
	return 0;
}

//删除文件和重命名文件
int main81()
{
	//删除
	int val= remove("D:\sss.txt");
	if (val == 0)
		printf("删除成功");
	else
		printf("删除失败");
	//重命名
	int val1 = rename("D:\ss.txt","D:ddd.txt");
	//移动文件
	//int val1 = rename("D:\ss.txt", "D:\ddd\ddd.txt");

	if (val1 == 0)
		printf("成功");
	else
		printf("失败");

		return 0;
}


//缓冲区更新
int main82()
{
	FILE* fp1 = fopen("D:/main.txt", "w");
	if (!fp1)
		return -1;
	char ch;
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '@')
			break;
		//缓冲区更新
		//缺点：持续和硬盘交互，损伤硬盘.  优点：随时更新，重要文件时使用，
		fflush(fp1);//将文件缓冲区的东西马上写入到文件中
		fputc(ch, fp1);
	}
	fclose(fp1);
	return 0;
}