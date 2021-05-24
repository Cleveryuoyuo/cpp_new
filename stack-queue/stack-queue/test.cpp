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
//��δ������������ҵ��� k ������Ԫ�ء�
//��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
class Solution 
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int> dq;  //Ĭ�ϴ�ѽṹ
		for (int i = 0; i<nums.size(); ++i)
			dq.push(nums[i]);//������Խ������С�������

		for (int i = 0; i<k - 1; ++i)
			dq.pop(); //���� k-1�� �Ϳ����ҵ�

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

	//greater��һ���º���
	make_heap(iv.begin(), iv.end(), greater<int>());
	//greater��һ�����ڵķº���
	//��Ϊ�ѽṹ���������У����ǴӴ�С���У������С��
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;
}

/*

//�º���
//plus  minus  multiplies  equal_to   less  greater
void main()
{
	plus<int> pl; //pl��һ������

	cout << pl(10, 30) << endl;//������С���ţ�����
	
	pl.operator()(10, 30);
	
}

/*
//make_heap;push_heap;pop_heap;sort_heapȫ�ֺ��������������κζ���
//�ѵ�Ĭ�������Ǵ�ѣ����Խ����ִ�С��������
void main()
{
	vector<int> iv{ 5, 3, 6, 8, 1, 90, 4 };
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	make_heap(iv.begin(), iv.end());
	//��Ϊ�ѽṹ���������У����ǴӴ�С����
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	iv.push_back(10);
	push_heap(iv.begin(), iv.end());//�ѵõ���
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	//sort_heap�����������ڶ�pop_heap��ѭ������
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
	//��Ϊ�ѽṹ���������У����ǴӴ�С����
	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;

	//����iv.size()-1�Σ��Ϳ��Դ�С�����ų�
	auto it = iv.end();
	for (int i = 0; i < iv.size() - 1; ++i)
	{
		//����������90��Ч�����Ƕ��ڶѽṹ90��Ч��
		//���Ե���--it�Ĳ���
		pop_heap(iv.begin(), it);
		--it;
	}

	//pop_heap(iv.begin(), iv.end());
	////���ӽṹ

	for (const auto & e : iv)
		cout << e << " ";
	cout << endl;
}



/* 
//���ȼ����о��Ǵ�С��  ��������Ϊ������ 
void main()
{
	vector<int> iv{ 1, 4, 6, 9, 456, 78, 3, 0 };
	priority_queue<int> pq;//��ѽṹ
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

//stack queue  ���������Ƶ����ݽṹ  ֻ����β���������ɾ��
//queue �� stack  �ķ���պ��෴
//˫�˶��в����������������ռ䣬������һ��������С�ռ�ƴ�ӳɣ������ڶ�̬��ά���� 
/*
namespace ghc
{
	//ջ�Ͷ��е�����������˫�˶��� 
	template<class _Ty,class Cont=deque<_Ty>>
	class stack
	{
	public:
		stack()//list�Լ�����
		{}
		~stack()//list�Լ�����
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
		Cont _C;  //���������� ��deque��Ϊstack�Ļ���  vectorҲ��������
	};
}
void main()
{
	ghc::stack<int, vector<int>> st; //������deque������������Ըĳ�vector����
}

//���ڷ���Ҫ��Ƚϸߣ��ö��У�����ͷ��β��Ƶ����˫�˶���
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
		st.push(i);//push���
	cout << st.size() << endl;
	while (!st.empty())
	{
		int value = st.front();//����ͷ��ֵ����value
		st.pop();//����ͷ������,��ȥ��û��
		cout << value << endl;
	}
}

/*
//���˶���
void main()
{
	queue<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);//push���
	cout << st.size() << endl;
	while (!st.empty())
	{
		int value = st.front();//����ͷ��ֵ����value
		st.pop();//����ͷ������,��ȥ��û��
		cout << value << endl;
	}
}

/*
	//stack���������� û�е����� ������auto top:ջ��  pop:��ջ
namespace ghc
{
	template<class _Ty>
	class stack
	{
	public:
		stack()//list�Լ�����
		{}
		~stack()//list�Լ�����
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
		list<_Ty> _C;  //���������� ��list��Ϊstack�Ļ���  vectorҲ��������
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
				//����
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
class MinStack     //��Сջ
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
		st.push(i);//push��ջ
	cout << st.size() << endl;
	while (!st.empty())
	{
		int value = st.top();//ջ��ֵ����value
		st.pop();//ջ����ջ,��ȥ��û��
		cout << value << endl;
	}
}
*/