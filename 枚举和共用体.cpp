#include<stdio.h>

//共用体
union yar
{
	int a;
	float b;
	double c;
	char d;
	short e[6];//12
};

int main57()
{
	union yar var;
	var.a = 100;
	printf("%d\n", var.a);
	//共用体内存地址一样
	printf("%p\n", &var.a);
	printf("%p\n", &var.b);
	printf("%p\n", &var.c);
	return 0;
}

//枚举
enum Color
{
	red, blue, green, pink, yellow, black, white
}color;

enum renwu
{
	yidong, gongji, beigongji, beibingdong, shoushang, taopao, shiqu, shiwang
};

int main58()
{
	int val;

	/*switch (val)
	{
	case red:
		printf("红色\n");
		break;
	case blue:
		printf("蓝色\n");
		break;
	case green:
		printf("绿色\n");
		break;
	case pink:
		printf("粉色\n");
		break;
	case yellow:
		printf("黄色\n");
		break;
	case black:
		printf("黑色\n");
		break;
	case white:
		printf("白色\n");
		break;
	default:
		break;
	}*/

	while (1)
	{
		scanf("%d", &val);
		switch (val)
		{
		case yidong:
			printf("人物向前移动\n");
			break;
		case gongji:
			printf("发起攻击\n");
			break;
		case beigongji:
			printf("人物正在遭受敌人的攻击\n");
			break;
		case beibingdong:
			printf("人物被冰冻无法行动\n");
			break;
		case shoushang:
			printf("人物受伤，无法行动\n");
			break;
		case taopao:
			printf("人物成功逃跑了\n");
			break;
		case shiqu:
			printf("人物正在拾取地上的物品\n");
			break;
		case shiwang:
			printf("人物已死亡");
			return 0;
			break;
		}
	}
	return 0;
}

//为已存在的类型取别名
struct stdon
{

};

typedef struct stdon ss;