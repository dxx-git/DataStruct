//#include<iostream>
//#include<mutex>
//using namespace std;
//
//#include<windows.h>
//
////һ������£�����ģʽ�������ڴ��ͷţ��̳߳�ͬ������ģʽ��ȫ�ֶ����ʵ���������ͷſ��ٻή�ʹ���Ч��
////��Щ�����Ҫ�ͷţ���һЩ�ļ������ļ�������������ӵȲ������ų���Ľ������ͷ�    ����ǿ��֢�ĳ���Ա
//namespace LAZY//��Զ��ԣ�����----�������Ըߣ����ֳ����¶�����
//{
//	class Lock
//	{
//	public:
//		//RAII:��Դ��ȡ����ʼ��
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
//		Lock(const Lock&);//��ֹ����
//		Lock& operator=(const Lock&);//��ֹ��ֵ
//
//		mutex& _mtx;
//	};
//
//	//const ����& û��ȱʡ�Ĺ��캯���ĳ�Ա���� ���εı��������ڳ�ʼ���б���г�ʼ��
//
//	//���һ�����Ϊ������
//	class Singleton//�̲߳���ȫ����Ϊ�½�������ԭ�Ӳ���
//	{
//	public:
//		static Singleton* GetInstance()//��̬����ֻ�ܷ��ʾ�̬��Ա
//		{
//			/*static int i = 0;
//			int j = 0;
//			int *k = new int;
//			++i;
//			++j;//ֻ�д�������̰߳�ȫ��
//			++*k;*/
//
//			if (NULL == _inst)//˫���
//			{
//				//lock;
//				//_mtx.lock();//����ڼ���֮������쳣������������----RAII
//				//Lock lock(_mtx);//RAII������Ч---˫���----�����Լ������ӣ�������lock_guard
//				lock_guard<mutex>lock(_mtx);
//
//				if (NULL == _inst)
//				{
//					//Ϊ�˸�Чִ�У�cpu���ܻὫ������˳�����
//					//�磺ԭ��˳��operator new���ռ�--���캯��--��ֵ
//					//���˳�����Ϊoperator new���ռ�--��ֵ--���캯��--bug˫��鵼��û�б���δ��ʼ��
//					
//					//_inst = new Singleton;//�Ż�----�ڴ�դ������ֹ��������ָ����ˮ���������Ż�
//					Singleton* tmp = new Singleton;
//					MemoryBarrier();//�ڴ�դ��֮ǰ�������ڴ�դ��֮�����䲻�ܽ���
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
//		static void DellInstance()//��ĳЩ�������Ҫ�ͷ�
//		{
//			lock_guard<mutex> lock(_mtx);//��ֹ�����ͷŶ��
//			
//			if (_inst)
//			{
//				cout << "delete" << endl;
//				delete _inst;
//				_inst = NULL;//��ֹҰָ��ĳ���
//			}
//		}
//		struct GC//ʵ�ַ�ʽ����������
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
//		Singleton(const Singleton&);//��������ֻ����������
//		Singleton& operator=(const Singleton&);//�����ϲ���Ҫ����Ϊ˽�еģ�Ϊ�˷�ֹ�Լ����Լ���ֵ
//		~Singleton()
//		{
//			//�ر����ݿ�����
//		}
//
//		int _a;
//		static Singleton* _inst;
//		static mutex _mtx;
//	};
//
//	Singleton* Singleton::_inst = NULL;
//	mutex Singleton::_mtx;//�����޲ι��캯��
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
//		//Singleton copy(*Singleton::GetInstance());//�̲߳���ȫ----���������
//
//		//Singleton::GetInstance()->Print();//�п����ͷ�֮����Ҫ���ö��󣬶���ģʽ���ܻ����
//
//		//atexit(Singleton::DellInstance);//1ע��ص���������main����֮���������
//
//	}
//  static Singleton::GC gc;
//}
//
//#include<cassert>
//namespace HUNGRY//�򵥸�Ч��������ĳЩ��������ȱ��----�����Ի��ܵ����ƣ���̬��
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
//	Singleton* Singleton::_inst = new Singleton;//��̬��Ա��main����֮ǰ
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