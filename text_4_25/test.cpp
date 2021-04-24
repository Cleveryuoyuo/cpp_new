#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
//#include<vld.h>         //用来查看有没有内存泄漏的头文件
using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	for (auto & e : v)
		cout << e << " ";
	cout << endl;
	return 0;
}

/*
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	v.erase(pos);
	//cout << *pos << endl; // pos位置的元素删除了 所以有非法访问
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	return 0;

}

/*
void main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	vector<int> iv(ar, ar + n);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	auto it = find(iv.begin(), iv.end(), 6);
	cout << "*it = " << *it << endl;//
	iv.push_back(20);
	it = find(iv.begin(), iv.end(), 6);
	cout << "*it = " << *it << endl;
}


/*
void main()
{
	vector<int> iv;
	iv.push_back(1);
	iv.push_back(2);

	iv.insert(iv.begin(), 10);
	auto pos = find(iv.begin(), iv.end(), 1);
	iv.insert(pos, 100);

	for (int i = 0; i <= iv.size(); ++i)
		cout << iv.at(i) << " ";
		//cout<<iv[i]<<" ";
	cout << endl;

	//也可以这样写
	//for (auto &e : iv)
	//	cout << e << " ";
	//cout << endl;
}


/*
void main()
{
	vector<int> iv(5, 1);
	iv.reserve(100);//将capacity变成100
	for (int i = 1; i <= 100; ++i)
	{
		iv.push_back(i);
		cout << iv[i] << " ";
	}
	cout << endl;
}
*/