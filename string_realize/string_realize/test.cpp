#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

namespace ghc
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string &s);
	public:
		static int npos;
		typedef char* iterator;
	public:
		string() :_str(nullptr), _size(0), _capacity(0)
		{}
		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			string tmp(s._str);
			this->swap(tmp);
			//swap(*this,tmp);
		}
		string& operator=(string& s)
		{
			string tmp(s._str);
			std::swap(_str, tmp._str);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
	public:
		size_t size()const
		{return _size;}
		size_t capacity()const
		{return _capacity;}
		bool empty()const
		{return _size == 0;}//相等 空 不等 不空
	public:
		iterator begin()
		{return _str;}
		iterator end()
		{return _str + _size;}
	public:
		void push_back(char c)
		{
			if (_size + 1 > _capacity)
			{
				int n = _capacity == 0 ? 1 : _capacity * 2;
				reserve(n);
			}    
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			int sz = strlen(str);
			if (sz + _size > _capacity)
				reserve(sz + _size);
			strcat(_str, str);
			//strcat链接的时候，连接到\0所在的位置
			//所以，必须找到\0
			_size += sz;
		}
		string& operator+=(char c)
		{
			push_back(c);
			return*this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const string& s)
		{
			append(s._str);
			return *this; 
		}
		const char* c_str()const
		{return _str;}
		char& operator[](int i)//想要修改必须要用引用
		{
			assert(i >= 0 && i <= _size);
			return _str[i];
		}
	public:
		void resize(int new_size, char c = '\0')
		{
			if (new_size > _capacity)
			{
				reserve(new_size);
				for (int i = _size; i < new_size; ++i)
					_str[i] = c;
			}
			_size = new_size;
			_str[_size] = '\0';
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* new_str = new char[n + 1];
				memset(new_str, 0, n + 1);
				if (_str!=nullptr)
					strcpy(new_str, _str);				
				_capacity = n;
				delete[]_str;
				_str = new_str;
			}
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//static void swap(string& s1, string& s2)
		//{
		//	std::swap(s1._str, s2._str);
		//	std::swap(s1._size, s2._size);
		//	std::swap(s1._capacity, s2._capacity);
		//}
	public:
		//返回c在string中第一次出现的位置
		int find(char c, int pos = 0)const
		{
			for (int i = pos; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return npos;
		}
		int rfind(char c, int pos = npos)const
		{
			if (pos == npos)
			{
				for (int i = _size - 1; i >= 0; --i)
				{
					if (_str[i] == c)
						return i;
				}
				return npos;
			}
			else
			{
				int new_pos = pos;
				for (int i = _size - 1 - new_pos; i >= 0; --i)
				{
					if (_str[i] == c)
						return i;
				}
				return npos;
			}			
		}
		//返回字串s在string中第一次出现的位置
		int find(const char* s, int pos = 0)const   //方法一
		{
			char* ps = _str+pos;
			int len = strlen(s);
			int i = 0;
			while (*ps != '\0')
			{
				if (*ps != *s)
				{
					ps++;
					i++;
				}
					
				else
				{
					char tmp = ps[len];
					ps[len] = '\0';
					if (strcmp(ps, s)>=0)
						return pos + i;
					else
					{
						ps[len] = tmp;
						ps++;
						i++;
					}
				}
			}
			return string::npos;
		}
		//int find(const char* s, int pos = 0)const  //方法2
		//{
		//	int i = pos;
		//	int j = 0;
		//	while (i < _size&&j < strlen(s))
		//	{
		//		if (_str[i] == s[j])
		//		{
		//			i++;
		//			j++;
		//		}
		//		else
		//		{
		//			j = 0;
		//			i = i - j + 1;
		//		}
		//	}
		//	if (j >= strlen(s))
		//		return i - strlen(s);
		//	return string::npos;
		//}
		//int find(const char* s, int pos = 0)const    //方法3
		//{
		//	const char* ps = s;
		//	char* t = _str + pos;
		//	while (*ps != '\0'&&*t != '\0')
		//	{
		//		if (*ps != *t)
		//		{
		//			ps = s;
		//		}
		//		else
		//		{
		//			ps++;
		//		}
		//		t++;
		//	}
		//	if (*ps == '\0')
		//		return t - _str - strlen(s);
		//	return string::npos;
		//}
		//在pos位置插入字符c/字符串str,并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			for (int i = _size; i > pos; --i)
				_str[i] = _str[i - 1];
			_str[pos] = c;
			_size++;
			return *this;
		}
		string& insert(size_t pos,const char* s)
		{
			int len = strlen(s);
			if (_size + len > _capacity)
				reserve(_size + len);
			for (int i = _size-1; i > pos; --i)
			{
				_str[i + len] = _str[i];
			}
			for (int i = pos; i < pos + len; ++i)
			{
				_str[i] = *s;
				++s;
			}
			_size += len;
			return *this;
		}
		//删除pos位置上的元素，并返回下一个元素的位置
		string& erase(size_t pos, size_t len)
		{
			for (int i = pos; i < _size; ++i)
			{
				_str[i] = _str[i + len];
			}
			_size -= len;
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	int ghc::string::npos = -1;

	ostream& operator<<(ostream& out, const string &s)
	{
		out << s._str;
		return out;
	}
}

void main()
{
	ghc::string s("ghcghcfizhkf");
	int pos = s.find('f');
	s.insert(pos, "*&^%");
	cout << s << endl;
	cout << s.size() << endl;
	pos = s.find('*');
	s.erase(pos, 1);
	cout<<s<<endl;
	cout << s.size() << endl;
}

/*
void main()
{
	ghc::string s("ghc");
	s.resize(10,'t');
	cout << "s = " << s << endl;
	cout << "_size = " << s.size() << endl;
	cout << "_capacity = " << s.capacity() << endl;
	ghc::string s1("ghcdfaf");
	ghc::string s2;
	s2 = s1;
	cout << "s2 = " << s2 << endl;
	ghc::string s3 = s1;
}
/*
void main()
{
	ghc::string s("ghc");
	for (auto & e : s)
		cout << e;
	cout << endl;
	ghc::string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

/*
void main()
{
	ghc::string s("ghc");
	s.append("kjsadfghb");
	cout << "s = " << s << endl;
	cout << "_size = " << s.size() << endl;
	cout << "_capacity = " << s.capacity() << endl;
	s += "nishizhu";
	cout << "s = " << s << endl;
	cout << "_size = " << s.size() << endl;
	cout << "_capacity = " << s.capacity() << endl;
	ghc::string s1("GHC");
	s += s1;
	cout << "s = " << s << endl;
	cout << "_size = " << s.size() << endl;
	cout << "_capacity = " << s.capacity() << endl;
}

/*
void main()
{
	ghc::string s1;

	//cout << "s1 = " << s1 << endl;//空 打印不成
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;

	s1.push_back('H');
	cout << "s1 = " << s1 << endl;
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;

	s1 += 'Q';
	cout << "s1 = " << s1 << endl;
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;

}

/*
void main()
{
	ghc::string s1("hello nihao");
	cout << "s1 = " << s1 << endl;
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;

	s1.push_back('H');
	cout << "s1 = " << s1 << endl;
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;
	cout << endl;
	s1.push_back('R');
	cout << "s1 = " << s1 << endl;
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;

	s1.reserve(100);
	cout << "s1 = " << s1 << endl;
	cout << "_size = " << s1.size() << endl;
	cout << "_capacity = " << s1.capacity() << endl;
}
*/
