#pragma once

//��Ƽ����ڴ�أ����̶���С���ڴ�أ�Ҳ���������
template <class T>
class ObjectPool
{
	//����һ���ڲ��࣬��������ÿ������ڴ�Ľڵ�
	struct Node
	{
		Node* _memory;    //ָ�����ڴ��ָ��
		size_t _n;       //��ǰ�ڵ�����Ķ������
		Node* _next;     //ָ����һ������ڴ�ڵ�

		Node(size_t nobjs)   //���캯��
		{
			_n = nobjs;
			_memory = (Node*)::operator new(_n * GetObjSize());//����operator newʧ�ܺ�ֱ�����쳣,��������캯��
			_next = NULL;
		}
		~Node()            //��������
		{
			::operator delete(_memory);//operator deleteֱ���������󣬲������������
			_memory = NULL;
			_next = NULL;
			_n = 0;
		}
	};
	
public:
	ObjectPool(size_t initNobjs = 16,size_t maxNobjs = 1024)//���캯��
		:_initNobjs(initNobjs)
		,_maxNobjs(maxNobjs)
	{
		_head = _tail = new Node(initNobjs);     //Ĭ�ϳ�ʼ����ڴ�ڵ㴴��16������
		_useInCount = 0;                        //�տ�ʼ��û��ʹ�ö���
		_lastDelete = NULL;                     //Ҳû���ͷŻ����Ľڵ�
	} 
	~ObjectPool()    //��������
	{
		Node* cur = _head;
		while (cur)
		{
			Node* next = cur->_next;   //������һ������ڴ�ڵ�
			delete cur;               //�ͷŵ�ǰ�ڵ�
			cur = next;               //���µ�ǰ�ڵ�
		}
		_head = _tail = NULL;
	}
	inline static size_t GetObjSize()    /*��ȡÿ������Ĵ�С��\
		                                 \���þ�̬��Ա��������֤�����еĿɼ���\
									   \�������������������������*/
	{
		return sizeof(T)>sizeof(T*) ? sizeof(T):sizeof(T*);
	}

	//O(1)
	void* Allocate()    //����ռ�
	{
		//���������ͷŻ����Ķ���
		if (_lastDelete)//���_lastDelete��Ϊ�գ�˵�����ͷŻ����Ķ���Ӧ�ظ�����
		{
			void* obj = _lastDelete;        //��obj�������һ���ͷŵĶ���
			_lastDelete = *(T**)_lastDelete;/*��ʽ������_lastDeleteǿתΪT**,Ȼ��\
			                                \������ȡ��ǰsizeof(T*)���ֽڣ����ڶ���\
			                                \����ͷŵĶ���,Ȼ���丳ֵ��_lastDelete*/
			return obj;                   //����obj
		}

		//��Node�����ȡ����,���û���ڴ��ʹ�ã��ͷ���������ڴ�
		if (_useInCount >= _tail->_n)
		{
			AllocateNewNode();//����������ڴ棬������
		}

		//�ڴ���л����Ѿ�����õ�δʹ�õ��ڴ�
		void* obj = (char*)_tail->_memory + _useInCount*GetObjSize();//��ָ��ƫ�Ƶ�δʹ�õĶ���
		_useInCount++;                //�Ѿ�ʹ�õĶ������++
		return obj;
	}
	void Deallocate(void* ptr)      //�ͷ��ڴ�
	{
		if (ptr)
		{
			//�൱��ͷ��
			*(T**)ptr = _lastDelete;//������ͷŶ������ʽ����ĵ�ַ������ǰҪ�ͷŶ����ǰ(T*)���ֽ�
			_lastDelete = (T*)ptr;//����ǰҪ�ͷŵĶ���ĵ�ַ��ֵ��_lastDelete
		}
	}

	//ģ�庯��
	template <class Val>
	T* New(const Val& val)//��������ҳ�ʼ��
	{
		void* obj = Allocate();
		return new(obj)T(val);//����new��λ���ʽ���½ڵ���г�ʼ��
	}
	void Delete(T* ptr)//�ͷ��ڴ沢�������
	{
		if (ptr)
		{
			ptr->~T();   //��ʾ���������������������
			Deallocate(ptr);
		}
	}
protected:
	
	void AllocateNewNode()       //�������ڴ�ڵ�
	{
		size_t n = _tail->_n * 2;//ÿ������������Ϊ�ϸ��ڵ��2��
		if (n > _maxNobjs)      //���ڵ������Ϊ_maxNobjs������
			n = _maxNobjs;

		Node* node = new Node(n);
		_tail->_next = node;    //��������½����������ĩ��
		_tail = node;          //����β�ڵ�
		_useInCount = 0;       //���½�����ʹ�õĶ������Ϊ0
	}
	
protected:
	size_t _initNobjs;     //��Ҫ����Ĵ���ڴ�Ķ��������Ĭ��ֵΪ16��
	size_t _maxNobjs;     //����ڴ�ڵ����ɷ���Ķ��������Ĭ�����Ϊ1024��
	Node* _head;          //ָ�����ڴ������ͷ
	Node* _tail;          //ָ�����ڴ������β
	size_t _useInCount;   //��ǰ�ڵ��Ѿ����˶��ٸ�����
	T* _lastDelete;       //ָ�������ͷŵĶ���ռ�
};

void TestObjectPool()
{
	ObjectPool<string> pool;             //����һ���ڴ�ض���
	string* p1 = (string*)pool.Allocate();//ʹ�����е�һ������
	string* p2 = (string*)pool.Allocate();//��ʹ�����е�һ������
	pool.Deallocate(p1);                 //�ͷŶ���
	pool.Deallocate(p2);                 //�ͷŶ���
	string* p3 = (string*)pool.Allocate();//��Ӧ�ظ�ʹ���ͷŵĶ���
	string* p4 = (string*)pool.Allocate();//��Ӧ�ظ�ʹ���ͷŵĶ���
	
	ObjectPool<string> pool1;
	string* p5 = pool1.New("����");
	pool.Delete(p5);
	string* p6 = (string*)pool1.Allocate();
	pool1.Deallocate(p6);

	
	pool.Deallocate(p3);
	pool.Deallocate(p4);
}