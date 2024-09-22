#include<stdio.h>
#include<iostream>
using namespace std;
//new的使用
int* func()
{
	//在堆区创建整形数据
	int* p = new int(10);
	return p;
}

void test01()
{
	int* p = func();
	cout << *p << endl;

	//堆区由程序员管理释放
	//释放堆区空间
	delete(p);
}

//在堆区开辟数组
void test02()
{
	int* pp = new int(10);

	for (int i = 0;i < 10;i++)
	{
		pp[i] = 1 + 100;//给十个元素赋值
	}
	for (int i = 0;i < 10;i++)
	{
		cout << pp[i] << endl;
	}
	
	//释放堆空间数组
	delete[] pp;
}


int main()
{
	test01();
	test02();

	return 0;
}