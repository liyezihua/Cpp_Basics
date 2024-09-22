#include<stdio.h>

char* strctr(char* str, char* dest)
{
	char* fstr = str;//遍历原字符指针
	char* rstr = str;//记录相同字符串首地址
	char* fdest = dest;
	while (*fstr)
	{
		rstr = fstr;
		while (*fstr=*fdest)
		{
			if (*fstr != '\0')
			{
				fstr++;
				fdest++;
			}
		}
		if (*fdest == '\0')
		{
			return rstr;
		}
		//回滚
		fdest = dest;//目标字符串更新到回滚位置
		fstr = str;
		fstr++;
	}
}
//char* strctr1(char* dest, char* src)
//{
//	if (*src == '\0')//如果src直接为空，那就返回dest
//		return dest;
//	char* s1 = NULL;//遍历dest字符串
//	char* s2 = NULL;//遍历src字符串
//	char* sign = dest;//记录dest
//	while (*sign)
//	{
//		s1 = sign;//每回都让sign赋给s1
//		s2 = src;//如果有一部分字符相同，但整体不相同，那此时跳出循环再让src回滚
//		while (*s1 == *s2 && *s1 && *s2)//如果两个字符串到了都相同，那就跳出循环
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return sign;//
//		sign++;
//	}
//	return NULL;//循环结束了还没有那就是找不到了
//}
int main24()
{
	char str[] = "hello world";
	char dest[] = "llo\0";

	char* p = strctr(str, dest);

	printf("%s", p);

	return 0;
}
