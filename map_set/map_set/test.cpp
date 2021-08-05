#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map> //ӳ��
#include <set> //����
#include <functional> //�º��� �������ƴӴ�С���Ǵ�С�������򣨼����С�set����
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
	//hash  ��ɢ�Ų� ������
	//hash_map == unordered_map һ������
	unordered_map<int, string> mp = { { 5, "qwe" }, { 3, "asd" }, { 7, "zxc" }, { 6, "iop" } };

	for (auto & e : mp)
		cout << e.first << " : " << e.second<<endl;
}


/*
void main()
{
	//�Ӵ�С  mult���ظ�
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
	//�Ӵ�С
	set<int, greater<int>> s = { 3, 2, 6, 9, 5, 7, 1 };
	s.insert(4);
	s.insert(4); // Ҳ�����ظ�

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
	// map.����ӳ����ǲ������ظ���ͬ��ֵλ�õ�ʵֵ���ض���
									//�ظ�����Ĳ����ȥ			
	map<int, int> mp = { { 1, 400 }, {1,145}, { 5, 300 }, { 2, 700 }, { 8, 100 }  };
	
	//�����ֵ����make_pair<... ...>
	//mp.insert(make_pair<int, int>(10, 200));
	for (auto & e : mp)
		cout << e.first << " : " << e.second << endl;
}


/*
void main()
{
	                    //�ؼ�ֵ  ʵֵ
	pair<int, int> va[] = { { 1, 400 }, { 5, 300 }, { 2, 700 }, { 8, 100 } };
	int n = sizeof(va) / sizeof(va[0]);
	map<int, int> mp;
	for (int i = 0; i < n; ++i)
		mp.insert(va[i]);
	mp[2] = 600;//������2�������൱�ڲ���2λ�õ�600
	for (int i = 0; i < mp.size(); ++i)
		cout << mp[i] << endl;//mp[i]���Ƕ�Ӧ��ʵ��ֵ 
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
	//map�Ĳ������pair���͵�����
	//mp�Ĳ�����Զ����򣬸��ݵ�һ�����ֵĴ�С����
	//for (auto & e : mp)
		//cout << e.first << " : " << e.second << endl;
}
*/