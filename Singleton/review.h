//#include<iostream>
//using namespace std;
//
//#include<mutex>
//#include<windows.h>
////class Lock
////{
////public:
////	Lock(mutex& mtx)
////		:_mtx(mtx)
////	{
////		_mtx.lock();
////	}
////	~Lock()
////	{
////		_mtx.unlock();
////	}
////private:
////	Lock(const Lock&);//防止拷贝
////	Lock& operator=(const Lock&);//防止赋值
////
////	mutex& _mtx;
////};
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()// 获取唯一对象实例的接口函数
//	{
//		if (NULL == _inst)//双检查机制，只有创建实例的时候才进行加锁解锁来提高代码效率
//		{
//			//_mtx.lock();//加锁，加锁期间其余线程不能访问该临界区
//			//Lock lock(_mtx);//RAII机制
//			lock_guard<mutex>lock(_mtx);
//
//			if (NULL == _inst)//只有当第一次进来_inst为空的时候才创建实例
//			{
//				//_inst = new Singleton;
//				Singleton* tmp = new Singleton;
//				MemoryBarrier();//优化----内存栅栏，防止编译器对指令流水进行乱序优化
//				_inst = tmp;
//			}
//
//			//_mtx.unlock();//解锁
//		}
//
//		return _inst;//返回实例化的唯一对象
//	}
//	void Print()
//	{
//		cout << "Singleton:" <<_inst<< endl;
//	}
//	static void DellInstance()//在某些情况才需要释放
//	{
//		lock_guard<mutex> lock(_mtx);//防止对象被释放多次
//					
//		if (_inst)
//		{
//			cout << "delete" << endl;
//			delete _inst;
//			_inst = NULL;//防止野指针的出现
//		}
//	}
//	struct GC//实现方式二：类中类
//	{
//		~GC()
//		{
//			DellInstance();//调用析构函数
//		}
//	};
//private:
//	Singleton()//将构造函数设为私有的，防止在外部创建实例
//	{}
//	Singleton(const Singleton&);//将拷贝构造函数声明为私有的
//	Singleton& operator=(const Singleton&);//将赋值运算符重载设置为私有的
//	~Singleton()
//	{
//		//关闭文件锁，文件句柄，数据库连接等
//	}
//
//	static Singleton* _inst;// 指向实例的指针定义为静态私有，这样定义静态成员函数获取对象实例 
//	int _a; // 单例类里面的数据
//	static mutex _mtx; // 保证线程安全的互斥锁
//};
//
//Singleton* Singleton::_inst = NULL;//给静态指针赋值
//mutex Singleton::_mtx;//_mtx会调用mutex默认的无参构造函数，所以不用初始化
//
//void TestLazy()
//{
//	Singleton::GetInstance()->Print();
//	Singleton::GetInstance()->Print();
//	Singleton::GetInstance()->Print();
//	Singleton::GetInstance()->Print();
//	
//	//Singleton::DellInstance();
//	Singleton::GetInstance()->Print();
//	Singleton::GetInstance()->Print();
//	//atexit(Singleton::DellInstance);//注册回调函数，在main函数之后调用析构
//}
//static Singleton::GC gc;


#include<iostream>
using namespace std;

#include<cassert>
class Singleton
	{
	public:
		static Singleton& GetInstance()
		{
			assert(_inst);
			return *_inst;
		}
		void Print()
		{
			cout << "Singleton:" << _a << endl;
		}
	protected:
		Singleton()
			:_a(0)
		{}
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);

		static Singleton* _inst;
		int _a;
	};

	Singleton* Singleton::_inst = new Singleton;//静态成员在main函数之前初始化

	void Test()
	{
		Singleton::GetInstance().GetInstance().Print();
		Singleton::GetInstance().GetInstance().Print();
		Singleton::GetInstance().GetInstance().Print();
	}

	class Singleton1
	{
		public:
			static Singleton1& GetInstance()
			{
				static Singleton1 inst;//静态变量只会创建一次
				return inst;
			}
			void Print()
			{
				cout << "Singleton1:" << _a << endl;
			}
		protected:
			Singleton1()
				:_a(0)
			{}
			Singleton1(const Singleton1&);
			Singleton1& operator=(const Singleton1&);
		
			int _a;
		};
		
		void Test1()
		{
			Singleton1::GetInstance().GetInstance().Print();
			Singleton1::GetInstance().GetInstance().Print();
			Singleton1::GetInstance().GetInstance().Print();
		}