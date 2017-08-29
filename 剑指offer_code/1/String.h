#pragma once
#include <iostream>
using namespace std;

//浅拷贝(析构对象时会出错)
class CMyString
{
public:
	//构造函数
	CMyString(char* pData = "")
		:m_pData(new char[strlen(pData)+1])
	{
		if (*pData)
		{
			strcpy(m_pData,pData);
		}
		else
		{
			*m_pData = '\0';
		}
	}

	//拷贝构造函数
	CMyString(const CMyString& str)
		:m_pData(NULL)
	{
		//浅拷贝
		m_pData = str.m_pData;
	}

	//析构函数
	~CMyString()
	{
		if (m_pData)
		{
			delete []m_pData;
			m_pData = NULL;
		}
	}

	//赋值运算符重载
	CMyString& operator=(const CMyString& str)
	{
		//判断是不是自己给自己赋值
		if (this != &str)
		{
			//浅拷贝
			m_pData = str.m_pData;
		}
		return *this;
	}

private:
	char* m_pData;
};

void TestString()
{
	CMyString s1("abcd");
	CMyString s2(s1);
	CMyString s3;
	s3 = s1;
}


//深拷贝
class String
{
public:
	//构造函数
	String(const char* pData = "")
		:_str(new char[strlen(pData)+1])
	{
		if (*pData)
		{
			strcpy(_str,pData);
		}
		else
		{
			*_str = '\0';
		}
	}

	//拷贝构造函数
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		////传统写法
		//_str = NULL;//防止交换后tmp指向随机空间，函数调用完成导致崩溃
		//String tmp(s._str);//给出临时变量进行交换，防止s的值被改变
		//swap(_str,tmp._str);

		//简洁写法
		strcpy(_str,s._str);
	}

	////赋值运算符重载（返回类对象的引用，方便连续赋值）
	//String& operator=(const String& s)
	//{
	//	if (this != &s)//预防自己给自己赋值
	//	{
	//		////传统写法1
	//		//char* tmp(new char[strlen(s._str)+1]);//开辟新空间
	//		//strcpy(tmp,s._str);//为新空间赋值
	//		//delete []_str;//释放旧空间 
	//		//_str = tmp;

	//		////传统写法2
	//		//delete []_str;
	//		//_str = new char[strlen(s._str)+1];//在分配内存之前释放原有空间，有可能违背异常安全原则
	//		//strcpy(_str,s._str);

	//		////简洁写法1
	//		//String temp(s);//调用拷贝构造
	//		//swap(_str,temp._str);
	//		
	//		//简洁写法2
	//		String temp(s._str);//调用构造函数
	//		swap(_str,temp._str);
	//	}

	//	return *this;
	//}
	//简介写法3
	String& operator=(String s)
	{
		swap(_str,s._str);
		return *this;
	}

	//析构函数
	~String()
	{
		if (_str)
		{
			delete []_str;
			_str = NULL;
		}
	}
	
private:
	char* _str;
};

void TestDepthString()
{
	String s1("abcd");
	String s2(s1);
	String s3;
	s3 = s1;
}