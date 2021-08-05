#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map> //映射
#include <set> //集合
#include <functional> //仿函数 用来控制从大到小还是从小到大排序（集合中《set》）
#include <string>
#include <unordered_map>
using namespace std;


template <class Type>
class HashTable;

template <class Type>
class HashNode
{
	friend class HashTable<Type>;
public:
	HashNode(Type d) :data(d), link(nullptr)
	{}
private:
	Type data;
	HashNode* link;
};

template <class Type>
class HashTable
{
public:
	HashTable()
	{
		memset(hashtable, 0, sizeof(HashNode<Type>*)*HASH_DEFAULT_SIZE);
	}
public:
	void Insert(const Type &x)
	{
		int index = Hash(x);
		HashNode<Type>* s = new HashNode<Type>(x);
		s->link = hashtable[index];
		hashtable[index] = s;
	}
	void Show()const
	{
		for (int i = 0; i < HASH_DEFAULT_SIZE; ++i)
		{
			cout << i << " : ";
			HashNode<Type>* p = hashtable[i];
			while (p != nullptr)
			{
				cout << p->data << "->";
				p = p->link;
			}
			cout << "Nul"<<endl;
		}
	}

	void Remove(const Type& key)
	{
		int index = Hash(key);
		HashNode<Type>* prev = nullptr;
		HashNode<Type>* p = hashtable[index];
		while (p != nullptr&&p->data != key)
		{
			prev = p;
			p = p->link; 
		}
		if (p == nullptr)
			return;
		if (prev == nullptr)
			hashtable[index] = p->link;
		else
			prev->link = p->link;
		delete p;
	}

protected:
	int Hash(const Type& key)
	{
		return key % HASH_DEFAULT_SIZE;
	}
private:
	enum {HASH_DEFAULT_SIZE = 7};
	HashNode<Type>* hashtable[HASH_DEFAULT_SIZE];
};
void main()
{
	HashTable<int> ht;
	vector<int> iv = { 37, 2, 5, 9, 1, 13, 8, 3, 6, 12 };
	for (const auto & e : iv)
		ht.Insert(e);

	ht.Show();
	ht.Remove(9);
	ht.Show();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void main()
{
	//hash  离散排布 不排序
	//hash_map == unordered_map 一个东西
	unordered_map<int, string> mp = { { 5, "qwe" }, { 3, "asd" }, { 7, "zxc" }, { 6, "iop" } };

	for (auto & e : mp)
		cout << e.first << " : " << e.second<<endl;
}


/*
void main()
{
	//从大到小  mult可重复
	multiset<int, greater<int>> s = { 3, 2, 6, 9, 5, 7, 1 ,1,1,1,1};
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	multimap<int, int> mp = { { 1, 400 }, { 1, 145 }, { 5, 300 }, { 2, 700 }, { 8, 100 } };
	map<int, int>::iterator itt = mp.begin();
	while (itt != mp.end())
	{
		cout << itt->first << " : " << itt->second<<" ";
		++itt;
	}
	cout << endl;
}

/*
void main()
{
	//从大到小
	set<int, greater<int>> s = { 3, 2, 6, 9, 5, 7, 1 };
	s.insert(4);
	s.insert(4); // 也不能重复

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

/*
void main()
{
	set<int> s = { 3, 2, 6, 9, 5, 7, 1 };
	s.insert(4);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////
/*
void main()
{
	// map.单重映射就是不允许重复相同键值位置的实值的重定义
									//重复插入的不会进去			
	map<int, int> mp = { { 1, 400 }, {1,145}, { 5, 300 }, { 2, 700 }, { 8, 100 }  };
	
	//插入的值得是make_pair<... ...>
	//mp.insert(make_pair<int, int>(10, 200));
	for (auto & e : mp)
		cout << e.first << " : " << e.second << endl;
}


/*
void main()
{
	                    //关键值  实值
	pair<int, int> va[] = { { 1, 400 }, { 5, 300 }, { 2, 700 }, { 8, 100 } };
	int n = sizeof(va) / sizeof(va[0]);
	map<int, int> mp;
	for (int i = 0; i < n; ++i)
		mp.insert(va[i]);
	mp[2] = 600;//不存在2，所以相当于插入2位置的600
	for (int i = 0; i < mp.size(); ++i)
		cout << mp[i] << endl;//mp[i]就是对应的实际值 
}

/*
void main()
{
	pair<int, int> va[] = { { 1, 400 }, { 5, 300 }, { 2, 700 }, { 8, 100 } };
	int n = sizeof(va) / sizeof(va[0]);
	map<int, int> mp;
	for (int i = 0; i < n; ++i)
		mp.insert(va[i]);
	map<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << " : " << it->second << endl;
		++it;
	}
	//map的插入得是pair类型的数据
	//mp的插入会自动排序，根据第一个数字的大小排序
	//for (auto & e : mp)
		//cout << e.first << " : " << e.second << endl;
}
*/