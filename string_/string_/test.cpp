#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<assert.h>
#include<string>

using namespace std;  

namespace ghc
{
	class string
	{
	public:
		string(const char* str = "")
		{
			//构造string类对象，如果传入nullptr，程序非法，需要断言
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s) :_str(nullptr)
		{
			string tmp(s._str);
			//调用构造函数，用s._str初始化 创建一个临时tmp
			swap(_str, tmp._str);
		}
		string& operator=(string& s)
		{
			if (this != &s)
			{
				//string tmp(s);//拷贝构造
				string tmp(s._str);//构造函数
				swap(_str, tmp._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
void main()
{
	ghc::string s("abc");
	ghc::string s1 = s;
	ghc::string s2;
	s2 = s;
	
}
//////////////////////////////////////////////////
/*
void main()
{
	string s1 = "abc";
	string s2 = "xyz";
	string s3 = s1 + s2;
	if (s1 > s2)
		cout << "s1 > s2" << endl;
	else
		cout << "s1 <= s2" << endl;
	//比较大小也和字符串的比较方法一样，从第一个字符看起
	
	string str;
	//cin >> str; //cin写入就会导致空格截至 写 ni hao 只会进去ni
	//cout << "str = " << str << endl;
	getline(cin, str);
	//获取一行 不会从空格截至
	//getline(cin, str, ' ');//获取一行，从' '截至
	cout << "str = " << str << endl;
}

/*
void main()
{
	string s("string.cpp");
	s += 'c';
	//s += 'Python';//加的字符还不能太多
	cout << "s = " << s << endl;
}

/*
void main()
{
	string file("string.cpp");

	
	size_t pos = file.rfind('.'); //反向查找 返回正向位置
	cout << "pos = " << pos << endl;
	string suffiy(file.substr(pos + 1, file.size() - pos));
	//从pos开始 截取size()-pos个元素
	cout << suffiy << endl;
}

/*
void main()
{
	string s("abcvip");
	string ret = s.substr(2, 3);
	//从abcvip的第二个开始截取三个位置放入ret中
	cout << "ret = " << ret << endl;
	//s不变
	cout << "s = " << s << endl;
}

/*
void main()
{
	string s("lnmsst");
	//int pos = s.find('s');
	//int pos = s.find('s',4);
	//int pos = s.find("mss");
	//int pos = s.find("msy",3);
	int pos = s.find("msyjflalajflka", 2, 2);
	//意思是从lnmsst中的第二个位置开始找msyjflalajflka的2个字符
	if (pos == string::npos)//string::npos就是 -1
		cout << "没有找到" << endl;
	else
		cout << "pos = " << pos << endl;
}

/*
void main()
{
	string s1 = "abc";
	//用strlen计算长度得传入c_str
	int len = strlen(s1.c_str());
	cout << len << endl;
	string s2;
	s2.resize(10);//将s2的大小设置成十个
	cout << "s2 size = " << s2.size() << endl;
	len = strlen(s2.c_str());
	//因为在设置成10个个数的时候，初始化成0了，所以，len==0
	cout << "s2 size =" << len << endl;
}

/*
void main()//string的+
{
	string s1 = "abc";
	string s2 = "xyz";
	string s3 = s1 + s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;//将s2尾插给s1

	s1 += s2;//将s2尾插给s1
	cout << "s1 = " << s1 << endl; 
}
/*
void main()//尾插字符用push_back;尾插字符串用append
{
	string s("abc");
	s.push_back('x');
	cout << "s = " << s << endl;
	s.append("sjkgfh");
	cout << "s = " << s << endl;
}

/*
void main() //string的输出形式
{
	string s("sbcdef"); //写入字符串用""
	cout << s << endl;

	for (int i = 0; i < s.size(); ++i)//也可以用下标寻找
		cout << s[i];
	cout << endl;

	string::iterator it = s.begin();//当然还有迭代器咯
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	for (auto & e : s)
		cout << e;
	cout << endl;

	const string s1 = "aghkgaaf"; //常迭代器
	string::const_iterator cit = s1.cbegin();
	while (cit != s1.cend())
	{
		cout << *cit;
		++cit;
	}
	cout << endl;

	string::reverse_iterator rit = s.rbegin();//逆向迭代打印方式
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
}


/*
void main()
{
	string s;
	cout << "s = " << s << endl;

	char *pstr = "abc";
	string s1(pstr);
	cout << "s1 = " << s1 << endl;

	string s2("xyz");
	cout << "s2 = " << s2 << endl;

	string s3(11, 'a');
	cout << "s3 = " << s3 << endl;

	string s4 = s2;
	cout << "s4 = " << s4 << endl;

	cout << "s3 size = " << s3.size() << endl;//size=length
	cout << "s3 length = " << s3.length() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	s3.append("algfhjhagdlh"); //append用来尾插入字符串
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	s3.clear();
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	s3.reserve(100); //当创建100个时，不一定是100个他会多创建几个
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 length = " << s3.length() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	//因为size时元素个数  length是字符长度 所以从某种程度是一样的
	s3.resize(10, 's');
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 length = " << s3.length() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

}

/*
void main()
{
	string str[] = { "abc", "xyz", "pqr" };
	vector <string>  v; //创建一个类型为string的向量
	v.push_back(str[0]);
	v.push_back(str[1]);
	v.push_back(str[2]);
	for (auto & e : v)
		cout << e;
	cout << endl;
}

/*
void main()
{
	char* str[] = { "abc", "xyz", "pqr" };
	vector<char*> v;
	for (int i = 0; i < 3; ++i)
		v.push_back(str[i]);  //以下标访问向量元素
	for (auto & e : v)
		cout << e;
	cout << endl;
}

/*
void main()
{
	vector<char> v;
	for (int i = 0; i < 10; ++i)
		v.push_back('a' + i); //用向量方式呈现字符串
	for (auto & e : v)
		cout << e;
	cout << endl;
}
*/