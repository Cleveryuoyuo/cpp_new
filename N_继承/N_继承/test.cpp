#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	int ma = 1;
};
class B :virtual public A
{
public:
	int mb = 2;
};
class C :virtual public A
{
public:
	int mc = 3;
};
class D :public B, public C
{
public:
	int md = 4;
};
void main()
{
	D d;
	cout << d.mb << endl;
	cout << d.mc << endl;
	cout << d.md << endl;
	cout << d.ma << endl; 
}

/*
class A
{
public:
	int ma = 1;
};
class B :public A
{
public:
	int mb = 2;
};
class C :public A
{
public:
	int mc = 3;
};
class D :public B, public C
{
public:
	int md = 4;
};
void main()
{
	D d;
	cout << d.mb << endl;
	cout << d.mc << endl;
	cout << d.md << endl;
	//cout << d.ma << endl;  ��ʯ�̳в����������ʵ�һ��Ԫ�ء�������ʵø�B C��������̳� virtual
}

/*
class A
{
public:
	void fun()
	{
		cout << "A.fun()" << endl;
	}
private:
	int ma;
};
class B :public A
{
public:
	void fun()
	{
		cout << "B.fun()" << endl;
	}
private:
	int mb;
};
void main()
{
	B b;
	b.fun();//������ B����A������A�е�fun ���Ǵ�ӡB�е�fun �������� �����ڸǸ���
	b.A::fun(); // ����Ҳ����ǿ�Ʒ���A�� fun
}
/*
class A
{
private:
	int ma;
};
class B :public A
{
private:
	int mb = 3;
};
//��ֵ����ԭ�� ���������������ݸ���
void main()
{
	A a;
	B b;
	a = b;
	A* pb = &b; 
	A &pc = b;
}

/*
class A
{
public:
	A(int a = 0) : m_a(a)
	{
		cout << "A::A()" << endl;
	}

	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
protected:
	void show()
	{
		cout << "This is A::show()" << endl;
	}
private:
	void print()
	{
		cout << "This is A::print()" << endl;
	}
private:
	int m_a;
};
//������
class D : protected A
{
public:
	D(int d = 0) :m_d(d)
	{
		cout << "D::D()" << endl;
	}
public:
	void list()
	{
		fun();
		show();
		//print();
	}
private:
	int m_d;
};

void main()
{
	D d;
	d.list();//���Ե����Լ������Լ������ø���ı���
	//d.fun();  ������ֱ�ӵ��ø���ı���
}

/*
class person
{
public:
	void Print() 
	{
		cout << m_name << ":" << m_age << endl;
	}
private:
	string m_name = "youyou";
	int m_age = 6;
};
class student :public person//(���м̳�)
{

};

void main()
{
	student st;
	st.Print();
}
*/