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
////	Lock(const Lock&);//��ֹ����
////	Lock& operator=(const Lock&);//��ֹ��ֵ
////
////	mutex& _mtx;
////};
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()// ��ȡΨһ����ʵ���Ľӿں���
//	{
//		if (NULL == _inst)//˫�����ƣ�ֻ�д���ʵ����ʱ��Ž��м�����������ߴ���Ч��
//		{
//			//_mtx.lock();//�����������ڼ������̲߳��ܷ��ʸ��ٽ���
//			//Lock lock(_mtx);//RAII����
//			lock_guard<mutex>lock(_mtx);
//
//			if (NULL == _inst)//ֻ�е���һ�ν���_instΪ�յ�ʱ��Ŵ���ʵ��
//			{
//				//_inst = new Singleton;
//				Singleton* tmp = new Singleton;
//				MemoryBarrier();//�Ż�----�ڴ�դ������ֹ��������ָ����ˮ���������Ż�
//				_inst = tmp;
//			}
//
//			//_mtx.unlock();//����
//		}
//
//		return _inst;//����ʵ������Ψһ����
//	}
//	void Print()
//	{
//		cout << "Singleton:" <<_inst<< endl;
//	}
//	static void DellInstance()//��ĳЩ�������Ҫ�ͷ�
//	{
//		lock_guard<mutex> lock(_mtx);//��ֹ�����ͷŶ��
//					
//		if (_inst)
//		{
//			cout << "delete" << endl;
//			delete _inst;
//			_inst = NULL;//��ֹҰָ��ĳ���
//		}
//	}
//	struct GC//ʵ�ַ�ʽ����������
//	{
//		~GC()
//		{
//			DellInstance();//������������
//		}
//	};
//private:
//	Singleton()//�����캯����Ϊ˽�еģ���ֹ���ⲿ����ʵ��
//	{}
//	Singleton(const Singleton&);//���������캯������Ϊ˽�е�
//	Singleton& operator=(const Singleton&);//����ֵ�������������Ϊ˽�е�
//	~Singleton()
//	{
//		//�ر��ļ������ļ���������ݿ����ӵ�
//	}
//
//	static Singleton* _inst;// ָ��ʵ����ָ�붨��Ϊ��̬˽�У��������徲̬��Ա������ȡ����ʵ�� 
//	int _a; // ���������������
//	static mutex _mtx; // ��֤�̰߳�ȫ�Ļ�����
//};
//
//Singleton* Singleton::_inst = NULL;//����ָ̬�븳ֵ
//mutex Singleton::_mtx;//_mtx�����mutexĬ�ϵ��޲ι��캯�������Բ��ó�ʼ��
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
//	//atexit(Singleton::DellInstance);//ע��ص���������main����֮���������
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

	Singleton* Singleton::_inst = new Singleton;//��̬��Ա��main����֮ǰ��ʼ��

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
				static Singleton1 inst;//��̬����ֻ�ᴴ��һ��
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