#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

template <typename K,typename V>
void sortMap(string fruits[],size_t sz,const map<K,V> &m)//统计出现最多的前k种水果（降序）
{
	map <string,int> count;
	
	for (size_t i = 0; i < sz; ++i)
	{
		count[fruits[i]]++;
	}
	//将迭代器导入vector
	vector<map<string,int>::iterator> heap;
	map<string,int>::iterator mapIt = count.begin();
	while(mapIt != count.end())
	{
		heap.push_back(mapIt);
		++mapIt;
	}
	//建小堆
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
	////向下调整
	//while(diff--)
	//{
	//	pop_heap(heap.begin(),heap.end(),Com());
	//	heap.pop_back();
	//}
	//输出结果
	while(heap.size() != 0)
	{
		cout<<heap.back()->first<<":"<<heap.back()->second<<endl;
		heap.pop_back();
	}
}

void CountMap(string fruits[],size_t sz)//统计水果出现的次数
{
	map <string,int> count;

	for (size_t i = 0; i < sz; ++i)
	{
    ////方法1
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

		////方法2
		//pair <map<string,int>::iterator,bool> ret;
		//ret = count.insert(pair<string,int>(fruits[i],1));
		//if (ret.second == false)
		//{
		//	ret.first->second++;
		//}

		//方法3
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

	//1普通插入，返回pair类型
	pair<set<int>::iterator,bool> ret;

	ret = s.insert(2);
	if (ret.second == true)
	{
		cout<<"插入成功!"<<endl;
	}
	else
	{
		cout<<"插入的值已存在，插入失败！"<<endl;
	}

	ret = s.insert(4);
	if (ret.second == true)
	{
		cout<<"插入成功!"<<endl;
	}
	else
	{
		cout<<"插入的值已存在，插入失败！"<<endl;
	}

	ret = s.insert(2);
	if (ret.second == true)
	{
		cout<<"插入成功!"<<endl;
	}
	else
	{
		cout<<"插入的值已存在，插入失败！"<<endl;
	}
	PrintSet(s);
	
	//2、根据迭代器位置进行插入，返回一个迭代器
	set<int>::iterator it = s.find(2);
	set<int>::iterator retIt = s.insert(it,3);

	if (retIt == s.end())
	{
		cout<<"插入的值已存在，插入失败"<<endl;
	}
	else
	{
		cout<<"插入成功!"<<endl;
	}

	retIt = s.insert(it,4);

	if (retIt == s.end())
	{
		cout<<"插入的值已存在，插入失败"<<endl;
	}
	else
	{
		cout<<"插入成功!"<<endl;
	}
	PrintSet(s);
	
	//3、插入一段迭代器区间，无返回值
	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	vector<int>::iterator start = v.begin();
	vector<int>::iterator tail = v.end();

	s.insert(start,tail);
	PrintSet(s);

	//set的删除
	s.insert(0);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	PrintSet(s);

	//1.通过迭代器位置删除,无返回值
	set<int>::iterator eraseIt = s.find(0);
	s.erase(eraseIt);
	PrintSet(s);

	//2.通过值删除,删除成功返回1,不存在返回0
	size_t a = s.erase(0);
	PrintSet(s);

	//3.删除迭代器区间,无返回值
	s.erase(++s.begin(),--s.end());//只留下第一个和最后一个,其余全部删除
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

	//1、直接插入，返回一个pair类型的值
	ret = m.insert(make_pair(1,0));
	if (ret.second == true)
	{
		cout<<"插入成功!"<<endl;
	}
	else
	{
		cout<<"插入的值已存在，插入失败！"<<endl;
	}
	
	ret = m.insert(make_pair(1,0));
	if (ret.second == true)
	{
		cout<<"插入成功!"<<endl;
	}
	else
	{
		cout<<"插入的值已存在，插入失败！"<<endl;
	}
	PrintMap(m);

	//2、在指定位置插入，返回一个迭代器
	map<int,int>::iterator it = m.find(1);

	map<int,int>::iterator retIt;
	retIt = m.insert(it,make_pair(2,0));

	if (retIt != m.end())
	{
		cout<<"插入成功！"<<endl;
	}
	else
	{
		cout<<"插入的元素已经存在，插入失败！"<<endl;
	}

	it = m.find(2);
	retIt = m.insert(it,make_pair(2,0));
	if (retIt != m.end())
	{
		cout<<"插入成功！"<<endl;
	}
	else
	{
		cout<<"插入的元素已经存在，插入失败！"<<endl;
	}
	PrintMap(m);

	//3、插入一段迭代器区间，无返回值
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

	//map的删除
	//1、删除指定位置的元素，无返回值
	m.erase(m.find(1));
	PrintMap(m);

	//2、删除key为x的某个值，删除成功返回1，否则返回0
	size_t r = m.erase(2);
	if (r == 1)
	{
		cout<<"删除成功！"<<endl;
	} 
	else
	{
		cout<<"没有删除的元素，删除失败！"<<endl;
	}

	r = m.erase(20);
	if (r == 1)
	{
		cout<<"删除成功！"<<endl;
	} 
	else
	{
		cout<<"没有删除的元素，删除失败！"<<endl;
	}
	PrintMap(m);

	//3、删除一段迭代器区间，无返回值
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
