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
			//����string������������nullptr������Ƿ�����Ҫ����
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
			//���ù��캯������s._str��ʼ�� ����һ����ʱtmp
			swap(_str, tmp._str);
		}
		string& operator=(string& s)
		{
			if (this != &s)
			{
				//string tmp(s);//��������
				string tmp(s._str);//���캯��
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
	//�Ƚϴ�СҲ���ַ����ıȽϷ���һ�����ӵ�һ���ַ�����
	
	string str;
	//cin >> str; //cinд��ͻᵼ�¿ո���� д ni hao ֻ���ȥni
	//cout << "str = " << str << endl;
	getline(cin, str);
	//��ȡһ�� ����ӿո����
	//getline(cin, str, ' ');//��ȡһ�У���' '����
	cout << "str = " << str << endl;
}

/*
void main()
{
	string s("string.cpp");
	s += 'c';
	//s += 'Python';//�ӵ��ַ�������̫��
	cout << "s = " << s << endl;
}

/*
void main()
{
	string file("string.cpp");

	
	size_t pos = file.rfind('.'); //������� ��������λ��
	cout << "pos = " << pos << endl;
	string suffiy(file.substr(pos + 1, file.size() - pos));
	//��pos��ʼ ��ȡsize()-pos��Ԫ��
	cout << suffiy << endl;
}

/*
void main()
{
	string s("abcvip");
	string ret = s.substr(2, 3);
	//��abcvip�ĵڶ�����ʼ��ȡ����λ�÷���ret��
	cout << "ret = " << ret << endl;
	//s����
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
	//��˼�Ǵ�lnmsst�еĵڶ���λ�ÿ�ʼ��msyjflalajflka��2���ַ�
	if (pos == string::npos)//string::npos���� -1
		cout << "û���ҵ�" << endl;
	else
		cout << "pos = " << pos << endl;
}

/*
void main()
{
	string s1 = "abc";
	//��strlen���㳤�ȵô���c_str
	int len = strlen(s1.c_str());
	cout << len << endl;
	string s2;
	s2.resize(10);//��s2�Ĵ�С���ó�ʮ��
	cout << "s2 size = " << s2.size() << endl;
	len = strlen(s2.c_str());
	//��Ϊ�����ó�10��������ʱ�򣬳�ʼ����0�ˣ����ԣ�len==0
	cout << "s2 size =" << len << endl;
}

/*
void main()//string��+
{
	string s1 = "abc";
	string s2 = "xyz";
	string s3 = s1 + s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;//��s2β���s1

	s1 += s2;//��s2β���s1
	cout << "s1 = " << s1 << endl; 
}
/*
void main()//β���ַ���push_back;β���ַ�����append
{
	string s("abc");
	s.push_back('x');
	cout << "s = " << s << endl;
	s.append("sjkgfh");
	cout << "s = " << s << endl;
}

/*
void main() //string�������ʽ
{
	string s("sbcdef"); //д���ַ�����""
	cout << s << endl;

	for (int i = 0; i < s.size(); ++i)//Ҳ�������±�Ѱ��
		cout << s[i];
	cout << endl;

	string::iterator it = s.begin();//��Ȼ���е�������
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	for (auto & e : s)
		cout << e;
	cout << endl;

	const string s1 = "aghkgaaf"; //��������
	string::const_iterator cit = s1.cbegin();
	while (cit != s1.cend())
	{
		cout << *cit;
		++cit;
	}
	cout << endl;

	string::reverse_iterator rit = s.rbegin();//���������ӡ��ʽ
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

	s3.append("algfhjhagdlh"); //append����β�����ַ���
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	s3.clear();
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	s3.reserve(100); //������100��ʱ����һ����100������ഴ������
	cout << "s3 = " << s3 << endl;
	cout << "s3 size = " << s3.size() << endl;
	cout << "s3 length = " << s3.length() << endl;
	cout << "s3 capacity = " << s3.capacity() << endl;

	//��ΪsizeʱԪ�ظ���  length���ַ����� ���Դ�ĳ�̶ֳ���һ����
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
	vector <string>  v; //����һ������Ϊstring������
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
		v.push_back(str[i]);  //���±��������Ԫ��
	for (auto & e : v)
		cout << e;
	cout << endl;
}

/*
void main()
{
	vector<char> v;
	for (int i = 0; i < 10; ++i)
		v.push_back('a' + i); //��������ʽ�����ַ���
	for (auto & e : v)
		cout << e;
	cout << endl;
}
*/