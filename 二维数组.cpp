#include <stdio.h>

int main4() {
	//二维数组循环输入，循环输出
	//数据类型 数组名 [行][列];
	/*int arr[5][3];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/

	//学生成绩
	/*int arr[5][3];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			//printf("%d ", arr[i][j]);
			sum += arr[j][i];
		}
		printf("第%d名学生的总成绩为：%d\t 平均成绩为%d\n", i + 1, sum, sum / 3);
	}*/

	//三维数组
	//数据类型 数组名 [层][行][列];
	int arr[2][3][4] =
	{
		{
			{1,2,3,4},
		    {2,3,4,5},
		    {3,4,5,6}
		},
	    {
			{4,5,6,7},
		    {5,6,7,8},
		    {6,7,8,9}
        }
	};
	//三维数组遍历输出
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			for (int k = 0;k < 4;k++)
			{
				printf("%d ", arr[i][j][k]);
			}
		}
		printf("\n");
	}
	printf("三维数组的大小：%d\n", sizeof(arr));
	printf("三维数组的一层大小：%d\n", sizeof(arr[0]));
	printf("三维数组的一行大小：%d\n", sizeof(arr[0][0]));
	printf("三维数组的一列大小：%d\n", sizeof(arr[0][0][0]));

	printf("层：%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("行：%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));
	printf("列：%d\n", sizeof(arr[0][0]) / sizeof(arr[0][0][0]));

	return 0;
}

