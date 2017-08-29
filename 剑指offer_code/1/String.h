#pragma once
#include <iostream>
using namespace std;

//ǳ����(��������ʱ�����)
class CMyString
{
public:
	//���캯��
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

	//�������캯��
	CMyString(const CMyString& str)
		:m_pData(NULL)
	{
		//ǳ����
		m_pData = str.m_pData;
	}

	//��������
	~CMyString()
	{
		if (m_pData)
		{
			delete []m_pData;
			m_pData = NULL;
		}
	}

	//��ֵ���������
	CMyString& operator=(const CMyString& str)
	{
		//�ж��ǲ����Լ����Լ���ֵ
		if (this != &str)
		{
			//ǳ����
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


//���
class String
{
public:
	//���캯��
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

	//�������캯��
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		////��ͳд��
		//_str = NULL;//��ֹ������tmpָ������ռ䣬����������ɵ��±���
		//String tmp(s._str);//������ʱ�������н�������ֹs��ֵ���ı�
		//swap(_str,tmp._str);

		//���д��
		strcpy(_str,s._str);
	}

	////��ֵ��������أ��������������ã�����������ֵ��
	//String& operator=(const String& s)
	//{
	//	if (this != &s)//Ԥ���Լ����Լ���ֵ
	//	{
	//		////��ͳд��1
	//		//char* tmp(new char[strlen(s._str)+1]);//�����¿ռ�
	//		//strcpy(tmp,s._str);//Ϊ�¿ռ丳ֵ
	//		//delete []_str;//�ͷžɿռ� 
	//		//_str = tmp;

	//		////��ͳд��2
	//		//delete []_str;
	//		//_str = new char[strlen(s._str)+1];//�ڷ����ڴ�֮ǰ�ͷ�ԭ�пռ䣬�п���Υ���쳣��ȫԭ��
	//		//strcpy(_str,s._str);

	//		////���д��1
	//		//String temp(s);//���ÿ�������
	//		//swap(_str,temp._str);
	//		
	//		//���д��2
	//		String temp(s._str);//���ù��캯��
	//		swap(_str,temp._str);
	//	}

	//	return *this;
	//}
	//���д��3
	String& operator=(String s)
	{
		swap(_str,s._str);
		return *this;
	}

	//��������
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