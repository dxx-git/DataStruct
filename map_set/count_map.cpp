#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

template <typename K,typename V>
void sortMap(string fruits[],size_t sz,const map<K,V> &m)//ͳ�Ƴ�������ǰk��ˮ��������
{
	map <string,int> count;
	
	for (size_t i = 0; i < sz; ++i)
	{
		count[fruits[i]]++;
	}
	//������������vector
	vector<map<string,int>::iterator> heap;
	map<string,int>::iterator mapIt = count.begin();
	while(mapIt != count.end())
	{
		heap.push_back(mapIt);
		++mapIt;
	}
	//��С��
	struct Com
	{
		bool operator()(const map<string,int>::iterator l,const map<string,int>::iterator r)
		{
			return l->second < r->second;
		}
	};
	sort(heap.begin(),heap.end(),Com());

	//make_heap(heap.begin(),heap.end(),Com());
	//int diff = heap.size() - k;
	////���µ���
	//while(diff--)
	//{
	//	pop_heap(heap.begin(),heap.end(),Com());
	//	heap.pop_back();
	//}
	//������
	while(heap.size() != 0)
	{
		cout<<heap.back()->first<<":"<<heap.back()->second<<endl;
		heap.pop_back();
	}
}

void CountMap(string fruits[],size_t sz)//ͳ��ˮ�����ֵĴ���
{
	map <string,int> count;

	for (size_t i = 0; i < sz; ++i)
	{
    ////����1
	//	map <string,int>::iterator it = count.find(fruits[i]);
	//	if (it != count.end())
	//	{
	//		it->second++;
	//		//*(it).second++;
	//	}
	//	else
	//	{
	//		count.insert(pair<string,int>(fruits[i],1));
	//	}

		////����2
		//pair <map<string,int>::iterator,bool> ret;
		//ret = count.insert(pair<string,int>(fruits[i],1));
		//if (ret.second == false)
		//{
		//	ret.first->second++;
		//}

		//����3
		count[fruits[i]]++;
	}
}

void PrintSet(const set<int>& s)
{
	set <int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}

void TestSet()
{
	set <int> s;

	//1��ͨ���룬����pair����
	pair<set<int>::iterator,bool> ret;

	ret = s.insert(2);
	if (ret.second == true)
	{
		cout<<"����ɹ�!"<<endl;
	}
	else
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ�ܣ�"<<endl;
	}

	ret = s.insert(4);
	if (ret.second == true)
	{
		cout<<"����ɹ�!"<<endl;
	}
	else
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ�ܣ�"<<endl;
	}

	ret = s.insert(2);
	if (ret.second == true)
	{
		cout<<"����ɹ�!"<<endl;
	}
	else
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ�ܣ�"<<endl;
	}
	PrintSet(s);
	
	//2�����ݵ�����λ�ý��в��룬����һ��������
	set<int>::iterator it = s.find(2);
	set<int>::iterator retIt = s.insert(it,3);

	if (retIt == s.end())
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ��"<<endl;
	}
	else
	{
		cout<<"����ɹ�!"<<endl;
	}

	retIt = s.insert(it,4);

	if (retIt == s.end())
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ��"<<endl;
	}
	else
	{
		cout<<"����ɹ�!"<<endl;
	}
	PrintSet(s);
	
	//3������һ�ε��������䣬�޷���ֵ
	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	vector<int>::iterator start = v.begin();
	vector<int>::iterator tail = v.end();

	s.insert(start,tail);
	PrintSet(s);

	//set��ɾ��
	s.insert(0);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	PrintSet(s);

	//1.ͨ��������λ��ɾ��,�޷���ֵ
	set<int>::iterator eraseIt = s.find(0);
	s.erase(eraseIt);
	PrintSet(s);

	//2.ͨ��ֵɾ��,ɾ���ɹ�����1,�����ڷ���0
	size_t a = s.erase(0);
	PrintSet(s);

	//3.ɾ������������,�޷���ֵ
	s.erase(++s.begin(),--s.end());//ֻ���µ�һ�������һ��,����ȫ��ɾ��
	PrintSet(s);
}


void PrintMap(map<int,int> m)
{
	map<int,int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout<<it->first<<":"<<it->second<<endl;
		++it;
	}
	cout<<endl;
}

void TestMap()
{
	map<int,int> m;
	pair<map<int,int>::iterator,bool> ret;

	//1��ֱ�Ӳ��룬����һ��pair���͵�ֵ
	ret = m.insert(make_pair(1,0));
	if (ret.second == true)
	{
		cout<<"����ɹ�!"<<endl;
	}
	else
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ�ܣ�"<<endl;
	}
	
	ret = m.insert(make_pair(1,0));
	if (ret.second == true)
	{
		cout<<"����ɹ�!"<<endl;
	}
	else
	{
		cout<<"�����ֵ�Ѵ��ڣ�����ʧ�ܣ�"<<endl;
	}
	PrintMap(m);

	//2����ָ��λ�ò��룬����һ��������
	map<int,int>::iterator it = m.find(1);

	map<int,int>::iterator retIt;
	retIt = m.insert(it,make_pair(2,0));

	if (retIt != m.end())
	{
		cout<<"����ɹ���"<<endl;
	}
	else
	{
		cout<<"�����Ԫ���Ѿ����ڣ�����ʧ�ܣ�"<<endl;
	}

	it = m.find(2);
	retIt = m.insert(it,make_pair(2,0));
	if (retIt != m.end())
	{
		cout<<"����ɹ���"<<endl;
	}
	else
	{
		cout<<"�����Ԫ���Ѿ����ڣ�����ʧ�ܣ�"<<endl;
	}
	PrintMap(m);

	//3������һ�ε��������䣬�޷���ֵ
	map<int,int> m1;
	m1.insert(make_pair(2,0));
	m1.insert(make_pair(9,0));
	m1.insert(make_pair(7,0));
	m1.insert(make_pair(5,0));
	m1.insert(make_pair(3,0));

	map<int,int>::iterator start = m1.begin();
	map<int,int>::iterator tail = --m1.end();
	m.insert(start,tail);
	PrintMap(m);

	//map��ɾ��
	//1��ɾ��ָ��λ�õ�Ԫ�أ��޷���ֵ
	m.erase(m.find(1));
	PrintMap(m);

	//2��ɾ��keyΪx��ĳ��ֵ��ɾ���ɹ�����1�����򷵻�0
	size_t r = m.erase(2);
	if (r == 1)
	{
		cout<<"ɾ���ɹ���"<<endl;
	} 
	else
	{
		cout<<"û��ɾ����Ԫ�أ�ɾ��ʧ�ܣ�"<<endl;
	}

	r = m.erase(20);
	if (r == 1)
	{
		cout<<"ɾ���ɹ���"<<endl;
	} 
	else
	{
		cout<<"û��ɾ����Ԫ�أ�ɾ��ʧ�ܣ�"<<endl;
	}
	PrintMap(m);

	//3��ɾ��һ�ε��������䣬�޷���ֵ
	m.erase(++m.begin(),m.end()--);
	PrintMap(m);
}

int main()
{
	map <string,int> count;
	string fruits[] = {"apple","banana","orange","pineapple","grape",
		"banana","orange","apple","apple","orange",
		"pineapple","grape","orange","pineapple","pear",
		"grapefruit","mango","mango juice","apple",
		"Hami melon","melon","peach","banana",
		"pineapple","grape","orange","pineapple","pear",
		"grapefruit","mango","apple","melon","peach","banana",
		"melon","peach","banana", "Hami melon",
		"pineapple","grape","orange","pineapple","pear",
		"grapefruit","mango","peach","peach"};
	size_t sz = sizeof(fruits)/sizeof(fruits[0]);
	//CountMap(fruits,sz);
	//sortMap(fruits,sz,count);
	//TestSet();
	TestMap();
	system("pause");
	return 0;
}
