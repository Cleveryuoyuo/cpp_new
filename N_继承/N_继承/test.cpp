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
	//cout << d.ma << endl;  钻石继承不能这样访问第一任元素。若想访问得给B C加上虚拟继承 virtual
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
	b.fun();//理论上 B中有A所以有A中的fun 但是打印B中的fun 重名函数 子类掩盖父类
	b.A::fun(); // 但是也可以强制访问A的 fun
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
//赋值兼容原则 必须用子类对象兼容父类
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
//派生类
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
	d.list();//可以调用自己，用自己来调用父类的保护
	//d.fun();  不可以直接调用父类的保护
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
class student :public person//(公有继承)
{

};

void main()
{
	student st;
	st.Print();
}
*/