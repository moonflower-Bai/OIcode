#define _CRT_SECURE_NO_WARNINGS
//3、编程建立一个图书类的对象数组，
//并检查该数组是否根据图书的借阅量排序。
//（1）图书类的定义包括，
//图书名称，作者，图书简介以及借阅量；
//（2）通过构造函数完成string以及char *对象成员的初始化；
//设计复制构造函数支持深复制；
//（3）按照排序算法的支持要求设计对应的运算符重载函数。
//本题内容包在下面的代码，按照要求完善出来。
#include<iostream>
#include<cmath>
#include "string"
#include<cstring>
using namespace std;

// 判断数组内容是否为从大到小排序的函数模板
template<typename T>
bool isDecSorted(T list[], int size)
{
	// 遍历数组，完成测试数组是否为从大到小降序排序的状态，排序返回真，不是降序排列则返回假
	for (int i = 0; i < size - 1; i++)
	{
		if (list[i] < list[i + 1])
		{
			return false;
			break;
		}
	}
	return true;
}
// 图书类

class CBook
{

	string bookname;    // 书名
	string bookauthor;  // 作者
	char *description;  // 简介
	int lendingtimes;   // 借出次数，借阅量
public:
	// 按照题目分析完成必要的构造函数，析构函数，
	//（2）通过构造函数完成string以及char *对象成员的初始化；
	CBook()
	{
		bookname = '\0';
		bookauthor = '\0';
		description = NULL;
		lendingtimes = 0;
	}
	CBook(string bn, string ba, const char *d, int l)
	{
		bookname = bn;
		bookauthor = ba;
		int a = strlen(d);
		cout << a;
		description = new char[a + 1];
		int i = 0;
		for (; i < strlen(d); i++)
		{
			description[i] = d[i];
		}
		description[i] = '\0';
		lendingtimes = l;
	}

	void setinfo(string name, string author, const char *des, int times)
	{
		//  完成重新设置图书信息的函数
		bookname = name;
		bookauthor = author;
		if (description != NULL)
		{
			description = nullptr;
		}
		int a = strlen(des);
		cout << a;
		description = new char[a + 1];
		int i = 0;
		for (; i < strlen(des); i++)
		{
			description[i] = des[i];
		}
		description[i] = '\0';

		lendingtimes = times;

	}
	void getinfo(string &name, string &au, char * des, int &num)
	{
		name = bookname;
		au = bookauthor;
		strcpy(des, description);
		num = lendingtimes;
	}
	void print()
	{
		// 输出书籍的所有信息，按照一行输出。
		cout << "书名为" << bookname << "，作者为：" << bookauthor << "，书目简介：" << description << "。借出次数，借阅量为：" << lendingtimes << endl;

	}
	bool operator<(CBook &other)
	{
		if (lendingtimes < other.lendingtimes)return true;
		else return false;
	}
	CBook(const CBook &other)
	{
		//CBook *newbook;
		//newbook= new CBook;
		//newbook->bookname = other.bookname;
		//newbook->bookauthor = other.bookauthor;
		//int a = strlen(other.description);
		//cout << a;
		//newbook->description = new char(a + 1);
		//int i = 0;
		//for (; i < a; i++)
		//{
		//	newbook->description[i] = other.description[i];
		//}
		//newbook->description[i] = '\0';
		//newbook->lendingtimes =other.lendingtimes;
		//return newbook;

		bookname = other.bookname;
		bookauthor = other.bookauthor;
		int a = strlen(other.description);
		cout << a;
		description = new char[a + 1];
		int i = 0;
		for (; i < a; i++)
		{
		description[i] = other.description[i];
		}
		description[i] = '\0';
	lendingtimes =other.lendingtimes;

	}
};
int main()
{

	int i;
	CBook bookarray[5] = { CBook("一句顶一万句","刘震云","底层百姓人物的故事",200),
						CBook("蛙","莫言","乡村女医生的人生经历",180),
						CBook("推拿","毕飞宇","推拿中心盲人的情感、尊严和梦想",170),
						CBook("你在高原","张炜","地质队员的故事",160),
						CBook("天行者","刘醒龙","乡村民办教师的故事",150),
	};
	for (i = 0; i < 5; i++)
	{
		bookarray[i].print();
	}

	if (isDecSorted(bookarray, 5))
		cout << "已经按借阅量排序" << endl;
	else
		cout << "没有按借阅量排序" << endl;

	CBook book1;
	book1.setinfo("人世间", "梁晓声", "描写了中国社会的巨大变迁和百姓生活", 150);

	CBook book2 = book1;
	book2.print();

	return 0;
}
