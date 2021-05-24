#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<functional>
#include<assert.h>
using namespace std;



/*
//在未排序的数组中找到第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
class Solution 
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int> dq;  //默认大堆结构
		for (int i = 0; i<nums.size(); ++i)
			dq.push(nums[i]);//这里可以将数组从小到大入堆

		for (int i = 0; i<k - 1; ++i)
			dq.pop(); //出堆 k-1次 就可以找到

		return dq.top();
	}
};

/*
void main()
{
	vector<int> iv{ 5, 3, 6, 8, 1, 90, 4 };
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	//greater是一个仿函数
	make_heap(iv.begin(), iv.end(), greater<int>());
	//greater是一个大于的仿函数
	//成为堆结构的样子排列，不是从大到小排列，这个是小堆
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;
}

/*

//仿函数
//plus  minus  multiplies  equal_to   less  greater
void main()
{
	plus<int> pl; //pl是一个对象

	cout << pl(10, 30) << endl;//重载了小括号，如下
	
	pl.operator()(10, 30);
	
}

/*
//make_heap;push_heap;pop_heap;sort_heap全局函数，不依赖于任何对象
//堆的默认排序是大堆，可以将数字从小到大排序
void main()
{
	vector<int> iv{ 5, 3, 6, 8, 1, 90, 4 };
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	make_heap(iv.begin(), iv.end());
	//成为堆结构的样子排列，不是从大到小排列
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	iv.push_back(10);
	push_heap(iv.begin(), iv.end());//堆得调整
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	//sort_heap的作用类似于对pop_heap的循环操作
	sort_heap(iv.begin(), iv.end());
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	vector<int> iv{ 5, 3, 6, 8, 1, 90, 4 };
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	make_heap(iv.begin(), iv.end());
	//成为堆结构的样子排列，不是从大到小排列
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	//出队iv.size()-1次，就可以从小到大排成
	auto it = iv.end();
	for (int i = 0; i < iv.size() - 1; ++i)
	{
		//整个向量，90有效，但是对于堆结构90无效，
		//所以得有--it的操作
		pop_heap(iv.begin(), it);
		--it;
	}

	//pop_heap(iv.begin(), iv.end());
	////出队结构

	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;
}



/* 
//优先级队列就是大小堆  用向量作为适配器 
void main()
{
	vector<int> iv{ 1, 4, 6, 9, 456, 78, 3, 0 };
	priority_queue<int> pq;//大堆结构
	for (int i = 0; i < iv.size(); ++i)
		pq.push(iv[i]);
	cout << pq.size() << endl;
	cout << pq.top() << endl;
	cout << pq.top() << endl;
	for (int i = 0; i < iv.size(); ++i)
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

//stack queue  操作受限制的数据结构  只能在尾部插入或者删除
//queue 和 stack  的方向刚好相反
//双端队列并不是真正的连续空间，而是由一段连续的小空间拼接成，类似于动态二维数组 
/*
namespace ghc
{
	//栈和队列的适配容器是双端队列 
	template<class _Ty,class Cont=deque<_Ty>>
	class stack
	{
	public:
		stack()//list自己会做
		{}
		~stack()//list自己会做
		{}
	public:
		bool empty()const
		{
			return _C.empty();
		}
		size_t size()const
		{
			return _C.size();
		}
		_Ty& top()
		{
			return _C.back();
		}
		void push(const _Ty &x)
		{
			_C.push_back(x);
		}
		void pop()
		{
			_C.pop_back();
		}
	private:
		Cont _C;  //容器适配器 用deque作为stack的基础  vector也可以做到
	};
}
void main()
{
	ghc::stack<int, vector<int>> st; //本来是deque，但是这里可以改成vector操作
}

//对于访问要求比较高，用队列；对于头插尾插频繁用双端队列
/*
void main()
{
	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_front(10);
	dq.push_front(20);
	dq.push_front(30);
	for (const auto & e : dq)
		cout << e << " ";
	deque<int>::iterator it = dq.begin();
	while (it != dq.end())
	{
		cout << *it << " ";
		++it;
	}
}

/*
void main()
{
	queue<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);//push入堆
	cout << st.size() << endl;
	while (!st.empty())
	{
		int value = st.front();//堆列头部值付给value
		st.pop();//堆列头部出堆,出去就没了
		cout << value << endl;
	}
}

/*
//单端队列
void main()
{
	queue<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);//push入堆
	cout << st.size() << endl;
	while (!st.empty())
	{
		int value = st.front();//堆列头部值付给value
		st.pop();//堆列头部出堆,出去就没了
		cout << value << endl;
	}
}

/*
	//stack容器适配器 没有迭代器 不能用auto top:栈顶  pop:出栈
namespace ghc
{
	template<class _Ty>
	class stack
	{
	public:
		stack()//list自己会做
		{}
		~stack()//list自己会做
		{}
	public:
		bool empty()const
		{
			return _C.empty();
		}
		size_t size()const
		{
			return _C.size();
		}
		_Ty& top()
		{
			return _C.back();
		}
		void push(const _Ty &x)
		{
			_C.push_back(x);
		}
		void pop()
		{
			_C.pop_back();
		}
	private:
		list<_Ty> _C;  //容器适配器 用list作为stack的基础  vector也可以做到
	};
}
/*
namespace ghc
{
	template<class _Ty>
	class stack
	{
	public:
		stack()
		{
			capacity = STACK_DEFAULT_SIZE;
			tp = 0;
			base = new _Ty[capacity];
		}
		~stack()
		{
			delete[]base;
			bast = nullptr;
			capacity = 0;
			tp = 0;
		}
	public:
		bool empty()const
		{
			return tp == 0;
		}
		size_t size()const
		{
			return tp;
		}
		_Ty& top()
		{
			assert(tp != 0);
			return base[tp - 1];
		}
		void push(const _Ty &x)
		{
			if (tp >= capacity)
			{
				//扩容
			}
			base[tp++] = x;
		}
		void pop()
		{
			assert(tp != 0);
			tp--;
		}
	private:
		enum{STACK_DEFAULT_SIZE=8};
		_Ty* base;
		size_t capacity;
		size_t tp;
	};
}
void main()
{
	ghc::stack<int> st;
}
/*
class MinStack     //最小栈
{
public:
	MinStack()
	{}
	void push(int val)
	{
		data_st.push(val);
		if (min_st.empty() || val <= min_st.top())
			min_st.push(val);
	}
	void pop()
	{
		int val = data_st.top();
		data_st.pop();
		if (val == min_st.top())
			min_st.pop();
	}
	int top()
	{
		return data_st.top();
	}
	int getmin()
	{
		return min_st.top();
	}
private:
	stack<int> data_st;
	stack<int> min_st;

};
/*
void main()
{
	stack<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);//push入栈
	cout << st.size() << endl;
	while (!st.empty())
	{
		int value = st.top();//栈顶值付给value
		st.pop();//栈顶出栈,出去就没了
		cout << value << endl;
	}
}
*/