#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

template<class _Ty>
class BSTree;

template<class _Ty>
class BSTNode
{
	friend class BSTree<_Ty>;
public:
	BSTNode() :data(_Ty()), leftChild(nullptr), rightChile(nullptr)
	{}
	BSTNode(_Ty val, BSTNode* left = nullptr, BSTNode* right = nullptr)
		:data(val), leftChild(left), rightChild(right)
	{}
	~BSTNode()
	{}
private:
	_Ty data;
	BSTNode* leftChild;
	BSTNode* rightChild;
};

///////////////////////////////////////////////////////////////////
template<class _Ty>
class BSTree //想使用BSTNode 得让其成为友元类
{
public:
	BSTree() :root(nullptr)
	{}
	BSTree(vector<_Ty> &nums) :root(nullptr)
	{
		for (auto &e : nums)
			Insert(e);
	}
public:
	void Order()const
	{
		Order(root);
	}

	BSTNode<_Ty>* Min()const
	{
		return Min(root);
	}

	BSTNode<_Ty>* Max()const
	{
		return Max(root);
	}

	BSTNode<_Ty>* Search(const _Ty &key)const
	{
		return Search(root, key);
	}

	BSTNode<_Ty>* Parent(const _Ty &key)const
	{
		return Parent(root, key);
	}

	bool Insert(const _Ty& x)
	{
		return Insert(root, x);
	}
	bool Remove(const _Ty& key)
	{
		return Remove(root, key);
	}
protected:
	void Order(BSTNode<_Ty>* t)const
	{
		if (t != nullptr)
		{
			Order(t->leftChild);
			cout << t->data << " ";
			Order(t->rightChild);
		}
	}

	BSTNode<_Ty>* Min(BSTNode<_Ty>* t)const
	{
		while (t && t->leftChild != nullptr)
		{
			t = t->leftChild;
		}
		return t;
	}

	BSTNode<_Ty>* Max(BSTNode<_Ty>* t)const
	{
		while (t && t->rightChild != nullptr)
		{
			t = t->rightChild;
		}
		return t;
	}

	BSTNode<_Ty>* Search(BSTNode<_Ty>* t, const _Ty &key)const
	{
		if (t == nullptr)
			return t;
		if (key < t->data)
			return Search(t->leftChild, key);
		if (key>t->data)
			return Search(t->rightChild, key);
		return t;
	}

	BSTNode<_Ty>* Parent(BSTNode<_Ty>* t, const _Ty &key)const
	{
		if (t == nullptr || key == t->data)
			return nullptr;
		if (key == t->leftChild->data || key == t->rightChild->data)
			return t;
		if (key < t->data)
			return Parent(t->leftChild, key);
		else if (key>t->data)
			return Parent(t->rightChild, key);
	}

	bool Insert(BSTNode<int>* &t, int x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<_Ty>(x);
			return true;
		}
		if (x < t->data)
			return Insert(t->leftChild, x);
		else if (x > t->data)
			return Insert(t->rightChild, x);

		return false;
	}

	bool Remove(BSTNode<int>* &t, const _Ty& key)
	{
		if (p == nullptr)
			return false;
		if (key < t->data)
			return Remove(t->leftChild, key);
		else if (key>t->data)
			return Remove(t->rightChild, key);
		else
		{
			BSTNode<_Ty>* p = nullptr;
			if (t->leftChild != nullptr&&t->rightChild != nullptr)
			{
				p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;
				t->data = p->data;
				Remove(t->leftChild, p->data);
			}
			else
			{
				p = t;
				if (t->leftChild != nullptr)
					t = t->leftChild;
				else
					t = t->rightChild;
				delete p;
			}
		}
		return true;
	}

private:
	BSTNode<_Ty>* root;
};
int main()
{
	vector<int> iv{ 50, 30, 40, 10, 70, 80, 2, 60, 90};
	BSTree<int> bst(iv);

	bst.Remove(30);
	return 0;
} 


/*
if (p == nullptr)
return false;
if (key < t->data)
	return Remove(t->leftChild, key);
else if (key>t->data)
return Remove(t->rightChild, key);


else
{
	BSTNode<_Ty>* p = nullptr;
	if (t->leftChild != nullptr&&t->rightChild != nullptr)
	{
		p = t->leftChild;
		while (p->rightChild != nullptr)
			p = p->rightChild;
		t->data = p->data;
		Remove(t->leftChild, p->data);
	}
	else
	{
		p = t;
		if (t->leftChild != nullptr)
			t = t->leftChild;
		else
			t = t->rightChild;
		delete p;
	}
}
return true;


//这个是对于删除操作的复杂的 思路
if (p == nullptr)
return false;
if (key < t->data)
return Remove(t->leftChild, key);
else if (key>t->data)
return Remove(t->rightChild, key);
if (p == nullptr)
return false;
if (key < t->data)
return Remove(t->leftChild, key);
else if (key>t->data)
return Remove(t->rightChild, key);
else
{
BSTNode<_Ty>* p;
//用递归找到的t记录的父节点子指针，所以不用Search
//找到了，删除
if (t->leftChild == nullptr&&t->rightChild == nullptr)
{
//找到的节点没有左右子树
delete t;
t = nullptr;
}
else if (t->leftChild != nullptr&&t->rightChild == nullptr)
{
p = t;
t = t->leftChild;
delete p;
}
else if (t->leftChild == nullptr&&t->rightChild != nullptr)
{
p = t;
t = t->rightChild;
delete p;
}
else
{
p = t->leftChild;
while (p->rightChild != nullptr)
p = p->rightChild;
t->data = p->data;
Remove(t->leftChild, p->data);//将有两个节点的要删除的数字改成只删除只有一个节点的数字
}

return true;
}

/*
int main()
{
	vector<int> iv{ 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (int i = 0; i < iv.size(); ++i)
		bst.Insert(iv[i]);
	return 0;
}

*/