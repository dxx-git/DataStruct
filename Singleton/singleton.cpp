//#include<iostream>
//#include<mutex>
//using namespace std;
//
//#include<windows.h>
//
////一般情况下，单例模式不考虑内存释放，线程池同，单例模式是全局定义的实例，不断释放开辟会降低代码效率
////有些情况需要释放，有一些文件锁，文件句柄，数据连接等不会随着程序的结束而释放    具有强迫症的程序员
//namespace LAZY//相对而言，复杂----但适用性高，各种场景下都适用
//{
//	class Lock
//	{
//	public:
//		//RAII:资源获取即初始化
//		Lock(mutex& mtx)
//			:_mtx(mtx)
//		{
//			_mtx.lock();
//		}
//		~Lock()
//		{
//			_mtx.unlock();
//		}
//	private:
//		Lock(const Lock&);//防止拷贝
//		Lock& operator=(const Lock&);//防止赋值
//
//		mutex& _mtx;
//	};
//
//	//const 引用& 没有缺省的构造函数的成员变量 修饰的变量必须在初始化列表进行初始化
//
//	//设计一个类成为单例：
//	class Singleton//线程不安全，因为新建对象不是原子操作
//	{
//	public:
//		static Singleton* GetInstance()//静态函数只能访问静态成员
//		{
//			/*static int i = 0;
//			int j = 0;
//			int *k = new int;
//			++i;
//			++j;//只有此语句是线程安全的
//			++*k;*/
//
//			if (NULL == _inst)//双检查
//			{
//				//lock;
//				//_mtx.lock();//如果在加锁之间产生异常，则会产生死锁----RAII
//				//Lock lock(_mtx);//RAII不够高效---双检查----不用自己造轮子，库里有lock_guard
//				lock_guard<mutex>lock(_mtx);
//
//				if (NULL == _inst)
//				{
//					//为了高效执行，cpu可能会将各语句的顺序打乱
//					//如：原本顺序：operator new开空间--构造函数--赋值
//					//如果顺序打乱为operator new开空间--赋值--构造函数--bug双检查导致没有变量未初始化
//					
//					//_inst = new Singleton;//优化----内存栅栏，防止编译器对指令流水进行乱序优化
//					Singleton* tmp = new Singleton;
//					MemoryBarrier();//内存栅栏之前的语句和内存栅栏之后的语句不能交换
//					_inst = tmp;
//				}
//
//				//unlock;
//				//_mtx.unlock();
//			}
//
//			return _inst;
//		}
//		void Print()
//		{
//			cout << "Singleton:" << _a << endl;
//		}
//		static void DellInstance()//在某些情况才需要释放
//		{
//			lock_guard<mutex> lock(_mtx);//防止对象被释放多次
//			
//			if (_inst)
//			{
//				cout << "delete" << endl;
//				delete _inst;
//				_inst = NULL;//防止野指针的出现
//			}
//		}
//		struct GC//实现方式二：类中类
//		{
//			~GC()
//			{
//				DellInstance();
//			}
//		};
//	private:
//		Singleton()
//			:_a(0)
//		{}
//		Singleton(const Singleton&);//防拷贝，只声明不定义
//		Singleton& operator=(const Singleton&);//理论上不需要声明为私有的，为了防止自己给自己赋值
//		~Singleton()
//		{
//			//关闭数据库连接
//		}
//
//		int _a;
//		static Singleton* _inst;
//		static mutex _mtx;
//	};
//
//	Singleton* Singleton::_inst = NULL;
//	mutex Singleton::_mtx;//调用无参构造函数
//
//	void Test()
//	{
//		Singleton::GetInstance()->Print();
//		Singleton::GetInstance()->Print();
//		Singleton::GetInstance()->Print();
//
//
//		//Singleton::DellInstance();
//
//		//Singleton copy(*Singleton::GetInstance());//线程不安全----必须防拷贝
//
//		//Singleton::GetInstance()->Print();//有可能释放之后又要适用对象，饿汉模式可能会出错
//
//		//atexit(Singleton::DellInstance);//1注册回调函数，在main函数之后调用析构
//
//	}
//  static Singleton::GC gc;
//}
//
//#include<cassert>
//namespace HUNGRY//简单高效，但是在某些场景下有缺陷----适用性会受到限制，动态库
//{
//	class Singleton
//	{
//	public:
//		static Singleton& GetInstance()
//		{
//			assert(_inst);
//			return *_inst;
//		}
//		void Print()
//		{
//			cout << "Singleton:" << _a << endl;
//		}
//	protected:
//		Singleton()
//			:_a(0)
//		{}
//		Singleton(const Singleton&);
//		Singleton& operator=(const Singleton&);
//
//		static Singleton* _inst;
//		int _a;
//	};
//
//	Singleton* Singleton::_inst = new Singleton;//静态成员在main函数之前
//
//	void Test()
//	{
//		Singleton::GetInstance().GetInstance().Print();
//		Singleton::GetInstance().GetInstance().Print();
//		Singleton::GetInstance().GetInstance().Print();
//	}
//
//	class Singleton1
//	{
//	public:
//		static Singleton1& GetInstance()
//		{
//			static Singleton1 inst;
//			return inst;
//		}
//		void Print()
//		{
//			cout << "Singleton1:" << _a << endl;
//		}
//	protected:
//		Singleton1()
//			:_a(0)
//		{}
//		Singleton1(const Singleton1&);
//		Singleton1& operator=(const Singleton1&);
//
//		int _a;
//	};
//
//	void Test1()
//	{
//		Singleton1::GetInstance().GetInstance().Print();
//		Singleton1::GetInstance().GetInstance().Print();
//		Singleton1::GetInstance().GetInstance().Print();
//	}
//}
//int main()
//{
//	LAZY::Test();
//	getchar();
//
//	HUNGRY::Test();
//	HUNGRY::Test1();
//	system("pause");
//	return 0;
//}


#include"review.h"

int main()
{
	//TestLazy();
	//Test();
	Test1();
	system("pause");
	return 0;
}