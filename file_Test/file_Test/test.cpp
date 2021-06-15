#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;


/*
//普通写法
//class IntArry
//{
//public:
//	IntArry()
//	{
//		for (int i = 1; i <= 10; ++i)
//		{
//			a[i - 1] = i;
//		}
//	}
//	int GetSum()
//	{
//		int sum = 0;
//		for (int i = 0; i < 10; ++i)
//		{
//			sum += a[i];
//		}
//		return sum;
//	}
//private:
//	int a[10];
//};
//class FloatArry
//{
//public:
//	FloatArry()
//	{
//		for (int i = 0; i < 10; ++i)
//		{
//			a[i] = i + 0.11;
//		}
//	}
//	float GetSum()
//	{
//		float sum = 0.0f;
//		for (int i = 0; i < 10; ++i)
//		{
//			sum += a[i];
//		}
//		return sum;
//	}
//private:
//	float a[10];
//};

///////////////////////////////////////////////////

class IntArry
{
public:
	IntArry()
	{
		for (int i = 1; i <= 10; ++i)
		{
			a[i - 1] = i;
		}
	}
	int GetSum(int time)
	{
		int sum = 0;
		for (int i = 0; i < 10; ++i)
		{
			sum += a[i];
		}
		return sum *time;
	}
private:
	int a[10];
};
class FloatArry
{
public:
	FloatArry()
	{
		for (int i = 0; i < 10; ++i)
		{
			a[i] = i + 0.11;
		}
	}
	float GetSum(float time)
	{
		float sum = 0.0f;
		for (int i = 0; i < 10; ++i)
		{
			sum += a[i];
		}
		return sum *time;
	}
private:
	float a[10];
};

//模板写法
template<class Type>
class NumTraits
{};

template<>
class NumTraits<IntArry>
{
public:
	typedef int return_type;
	typedef int arg_type;
};
template<>
class NumTraits<FloatArry>
{
public:
	typedef float return_type;
	typedef float arg_type;
};
template<class Type>

class CApply
{
public:
	typename NumTraits<Type>::return_type GetSum(Type &obj,
		typename NumTraits<Type>::arg_type time)
	{
		return obj.GetSum(time);
	}
};

void  main()
{
	IntArry intA;
	FloatArry floatA;  //

	CApply<IntArry> obj;
	cout << obj.GetSum(intA, 3) << endl;
	CApply<FloatArry> obj1;
	cout << obj1.GetSum(floatA, 2.3) << endl;
}

//void main()
//{
//	IntArry intA;
//	cout << "sum = " << intA.GetSum() << endl;
//
//	FloatArry floatA;
//	cout << "sum = " << floatA.GetSum() << endl;
//}

/*
//类的模板特化泛化
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 d1;
	T2 d2;
};

//得先有泛化 才会有偏特化，全特化 必须有泛化
//全特化
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
private:
	int d1;
	char d2;
};
//偏特化
template<class T>
class Data<T, T>
{
public:
	Data()
	{
		cout << "Data<T11,T22>" << endl;
	}
private:
	T d1;
	T d2;
};

template<class T>
class Data<T, int>
{
public:
	Data()
	{
		cout << "Data<T,int>" << endl;
	}
private:
	T d1;
	T d2;
};

template<class T1,class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1 d1;
	T2 d2;
};

void main()
{
	Data <int*, char*> dt;
	Data<int, char> dt1;
	Data<char, char> dt2;
	Data<char*, int*> dt3;
}


/*
//所以得有模板的特化，不然操作不成
//模板的泛化
template<class T>
bool IsEqual(T left, T right)
{
	return left == right;
}

//这个是上面的函数模板的特化 有泛化才有特化
//如果是数组，就得用这样的模板，不然传过去比较地址就不等了
template<>
bool IsEqual<char*>(char* left, char* right)
{
	return strcmp(left, right) == 0;
}
void Test()
{
	//int p1 = 10;
	//int p2 = 20;
	char p1[] = "nihao";
	char p2[] = "nihao";

	if (IsEqual(p1, p2))
		cout << "p1 = p2" << endl;
	else
		cout << "p1 != p2" << endl;
}
void main()
{
	Test();
}


/*
template<typename Type, size_t _N=8>
class SeqList
{
public:
	SeqList(int sz = SZ_SZIE)
	{
		capacity = sz > SZ_SIZE ? sz : SZ_SIZE;
		base = new Type[capacity];
		size = 0;
	}
private:
	enum{SZ_SIZE = 8};
private:
	Type* base;
	size_t capacity;
	size_t size;
};

void main()
{
	SeqList<int,100> list(10);
}

*/