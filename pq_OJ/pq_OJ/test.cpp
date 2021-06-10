#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
using namespace std;

void main()
{
	string str = "7893173";
	cout << str << endl;
	reverse(str.begin(), str.end());//反转加区间
	cout << str << endl;

}

/*
//优先级队列的创建
namespace ghc
{
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue(const T* first, const T* last, const Compare& pr = Compare())
			:c(first, last), comp(pr)
		{
			//最后一个分支的位置
			int curpos = c.size() / 2 - 1;
			while (curpos >= 0)
			{
				_adjustdown(curpos);
				curpos--;
			}
		}

		bool empty()const
		{
			return c.empty();
		}

		size_t size() const
		{
			return c.size();
		}
		T& top()
		{
			return c.front();
		}
		void push(const T& x)
		{
			c.push_back(x);
			_adjustup(c.size() - 1);
		}

	protected:
		void _adjustdown(int start)
		{
			int n = c.size();
			int i = start;
			int j = 2 * i + 1;  //指向最后一个分支的第一个子树
			while (j < n)
			{
				//如果最后一个分支的第一个位置的数字小于第二个分支的数字，则j++
				if (j + 1 < n && comp(c[j], c[j + 1]))
					j++;
				//最后一个分支的值和相比较子树大的那个比较
				if (comp(c[i], c[j]))//ture
				{
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;

					i = j;
					j = 2 * i + 1;
				}
			}
			else
				break;
		}
		void _adjustup(int x)
		{
			int j = start;
			int i = (j - 1) / 2;
			while (j > 0)
			{
				if (comp(c.[i]), c[j])
				{
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;

					j = i;
					i = (j - 1) / 2;
				}
				else
					break;
			}
		}
	private:
		Container c;
		Compare comp;
	};
}


/*
namespace ghc
{
	template<class T, class Cont = vector<T>, class Pred = less<T> >
	class priority_queue
	{
	public:
		typedef T value_type;
		typedef size_t size_type;
	public:
		explicit priority_queue(const Pred& pr = Pred()) :sz(0)
		{}

		priority_queue(const value_type* first, const value_type* last,
						const Pred& pr = Pred()) :c(first, lsat)
		{
			//less 大   greater 小
			make_heap(c.begin(), c.end(), pr);
			sz = c.size();
		}
		bool empty() const
		{
			return sz == 0;
		}
		size_type size()const
		{
			return sz;
		}
		value_type& top()
		{
			return c.front();
		}
		void pop()
		{
			pop_heap(c.begin(), c.end());
			sz--;
		}
		void push(const value_type&x)
		{
			c.push_back(x);
			push_heap(c.begin(), c.end());
			sz++;
		}
		void show()const
		{
			for (int i = 0; i < c.size(); ++i)
				cout << c[i] << " ";
			cout << endl;
		}
	protected:
		Cont c;
		Pred comp;
		size_t sz;
	};
}

void main()
{
	ghc::priority_queue<int> pq;
	//5 9 2 4 1
	pq.push(5);
	pq.push(9);
	pq.push(2);
	pq.push(4);
	pq.push(1);
	cout << "size = " << pq.size() << endl;
	pq.show();
	pq.pop();
	cout<<pq.top()<<endl;
	cout << "size = " << pq.size() << endl;
}

*/