#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;


typedef enum{RED=0, BLACK}Color_Type;


template <class Type>
class RBTree;

template <class Type>
class RBNode
{
	friend class RBTree<Type>;
public:
	RBNode()
		:data(Type()), leftChild(nullptr), rightChild(nullptr),
		parent(nullptr), color(RED)
	{}
	RBNode(Type d)
		:data(d), leftChild(nullptr), rightChild(nullptr), 
		parent(nullptr), color(RED)
	{}
	~RBNode()
	{}
private:
	Type data;
	RBNode<Type>* leftChild;
	RBNode<Type>* rightChild;
	RBNode<Type>* parent;
	Color_Type  color;
};



template <class Type>
class RBTree
{
public:
	RBTree() :root(Nil), Nil(_Buynode())
	{
		Nil->leftChild = Nil->rightChild = Nil->parent = nullptr;
		Nil->color = BLACK;
	}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type& key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(RBNode<Type>*& t, const Type& x);
	bool Remove(RBNode<Type>*& t, const Type& key);
protected:
	void Insert_Fixup(RBNode<Type>*& t, RBNode<Type>* x);
	void Remove_fixup(RBNode<Type>*& t, RBNode<Type>* x);
protected:
	//��ת����
	void RotateR(RBNode<Type>*& t, RBNode<Type>* x)
	{
		RBNode<Type>* y = x->leftChild;
		x->leftChild = y->rightChild;
		if (y->rightChild != Nil)
			y->rightChild->parent = x;
		
		if (x == t)
			t = y;
		else if (x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		y->parent = x->parent;
		
		y->rightChild = x;
		x->parent = y;
	}
	void RotateL(RBNode<Type>*& t, RBNode<Type>* x)
	{
		RBNode<Type>* y = x->rightChild;
		x->rightChild = y->leftChild;
		if (y->leftChild != Nil)
			y->leftChild->parent = x;

		if (x == t)
			t = y;
		else if (x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		y->parent = x->parent;

		y->leftChild = x;
		x->parent = y;
	}
protected:
	RBNode<Type>* _Buynode(const Type& x=Type())
	{
		RBNode<Type>* s = new RBNode<Type>(x);
		s->leftChild = s->rightChild = s->parent = Nil;
		return s;

	}
private:
	RBNode<Type>* Nil;
	RBNode<Type>* root; 
};



template<class Type>
bool RBTree<Type>::Insert(RBNode<Type>*& t, const Type& x)
{
	//��bst�Ĺ������ڵ�
	RBNode<Type>* s = t;
	RBNode<Type>* pr = Nil;
	while (s != Nil)
	{
		if (s->data == x)
			return false;
		pr = s;
		if (s->data > x)
			s = s->leftChild;
		else
			s = s->rightChild;
	}
	//����xֵ�ڵ�
	s = _Buynode(x);
	
	//����ڵ�
	if (pr == Nil)
		t = s; 
	else if (x < pr->data)
		pr->leftChild = s;
	else
		pr->rightChild = s;
	s->parent = pr;

	Insert_Fixup(t, s);
	return true;
}


template<class Type>
bool RBTree<Type>::Remove(RBNode<Type>*& t, const Type& key)
{
	RBNode<Type>*p = t, *c;  // c-----Child
	while (p != Nil)
	{
		if (p->data == key)
			break;
		if (key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if (p == Nil)
		return false;
	
	if (p->leftChild != Nil&&p->rightChild != Nil)
	{
		//�ҵ�Ҫ�滻��ֵ�Ľڵ�λ��
		RBNode<Type>*q;
		q = p->rightChild;
		while (q->leftChild != Nil)
			q = q->leftChild;

		p->data = q->data;
		p = q;
	}


	if (p->leftChild != Nil)
		c = p->leftChild;
	else
		c = p->rightChild;
	
	c->parent = p->parent;

	if (p->parent == Nil)//ֻ�и��ڵ�ĸ���Ϊ��
		t = c;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = c;
	else
		p->parent->rightChild = c;

	//����ƽ��
	if (p->color == BLACK)
		Remove_fixup(t, c);


	delete p;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Type>
void RBTree<Type>::Insert_Fixup(RBNode<Type>*& t, RBNode<Type>* x)
{
	while (x->parent->color == RED)
	{
		RBNode<Type>*s = Nil;
		if (x->parent == x->parent->parent->leftChild)//���֧
		{
			s = x->parent->parent->rightChild;//�ҵ��岮�ڵ�
			//3.
			if (s != Nil && s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			//2.�ڲ���� �������  ��<��
			else
			{
				if (x == x->parent->rightChild)  //�ȱ�� ��/��
				{
					//x->parent->parent->color = RED;
					//x->color = BLACK;
					x = x->parent;
					RotateL(t, x);
				}
				//1.ֱ�߲���  ���� PG����ɫ  
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RotateR(t, x->parent->parent);
			}
		}
		else//�ҷ�֧
		{
			s = x->parent->parent->leftChild;//�ҵ��鲩�ڵ�
			//3.
			if (s != Nil&&s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else
			{
				//2.
				if (x == x->parent->leftChild)
				{
					x = x->parent;
					RotateR(t, x);
				}
				//1.
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RotateL(t, x->parent->parent);
			}
		}
	}
	t->color = BLACK;
}

//////////////////////////////////////////////////////////////////////////
template<class Type>
void RBTree<Type>::Remove_fixup(RBNode<Type>*& t, RBNode<Type>* x)
{
	RBNode<Type>* w;
	while (x != t && x->color == BLACK)
	{
		w = x->parent->rightChild;  //w��ɾ���Ľڵ���ֵܽڵ�
		//�ڶ������1 2 3
		if (x == x->parent->leftChild)//���
		{
			//4.
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				w = w->leftChild;
				RotateL(t, x->parent);
			}
			//3.
			if (w->leftChild->color != RED&&w->rightChild->color != RED)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{

				//2.
				if (w->leftChild != Nil)//�Ƚ�'>'��� '\'
				{
					w->leftChild->color = BLACK;
					w->color = RED;
					w = w->leftChild;
					RotateR(t, w->parent);
				}
				//1.
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->rightChild->color = BLACK;
				RotateL(t, x->parent);
				x = t;
			}
		}
		else
		{
			//4.
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				w = w->rightChild;
				RotateR(t, x->parent);
			}
			//3.
			if (w->leftChild->color != RED&&w->rightChild->color != RED)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{

				//2.
				if (w->rightChild != Nil)//�Ƚ�'>'��� '\'
				{
					w->rightChild->color = BLACK;
					w->color = RED;
					w = w->rightChild;
					RotateL(t, w->parent);
				}
				//1.
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->leftChild->color = BLACK;
				RotateR(t, x->parent);
				x = t;
			}
		}
	}
	x->color = BLACK;
}



int main()
{
	vector <int> iv{ 10, 7,  8, 15, 5, 6, 11, 13, 12};
	//vector <int> iv{ 10, 7, 8, 15, 5, 6, 11, 13};
	RBTree<int> rb;
	for (const auto & e : iv)
		rb.Insert(e);
	rb.Remove(6);
	rb.Remove(7);
	return 0;
}