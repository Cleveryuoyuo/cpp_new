#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


template <class Type>
class AVLTree;

template <class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode() :data(Type()), leftChild(nullptr), rightChild(nullptr), bf(0)
	{}
	AVLNode(Type d,AVLNode* left=nullptr,AVLNode* right=nullptr) 
		:data(d), leftChild(left), rightChild(right), bf(0)
	{}
	~AVLNode()
	{}
private:

private:
	Type data;
	AVLNode* leftChild;
	AVLNode* rightChild;
	int      bf;
};

template <class Type>
class AVLTree
{
public:
	AVLTree() :root(nullptr)
	{}
	~AVLTree()
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &x)
	{
		return Remove(root, x);
	}
protected:
	bool Insert(AVLNode<Type>* &t, const Type &x);
	bool Remove(AVLNode<Type>* &t, const Type &key);
protected:
	void RotateL(AVLNode<Type>* &ptr)
	{
		AVLNode<Type>* subL = ptr;
		ptr = ptr->rightChild;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		subL->bf = ptr->bf = 0;
	}
	void RotateR(AVLNode<Type>* &ptr)
	{
		AVLNode<Type>* subR = ptr;
		ptr = ptr->leftChild;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
	}
	void RotateLR(AVLNode<Type>* &ptr)
	{
		AVLNode<Type>* subL, *subR;
		subR = ptr;
		subL = ptr->leftChild;
		ptr = subL->rightChild;

		//L
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//����subL->bf
		if (ptr->bf <= 0)
			subL->bf = 0;
		//R
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//����subR->bf
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
	}
	void RotateRL(AVLNode<Type>* &ptr)
	{
		AVLNode<Type>* subL, *subR;
		subL = ptr;
		subR = ptr->rightChild;
		ptr = subR->leftChild;

		//R
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//����bf
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;
		
		//L
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//����bf
		if (ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		ptr->bf = 0;

	}
private:
	AVLNode<Type>* root;
};

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type>* &t, const Type &x)
{
	//1.�Ȱ���BST����
	AVLNode<Type>* p = t;
	AVLNode<Type>* pr = nullptr;

	stack<AVLNode<Type>*> st;

	while (p != nullptr)
	{
		if (x == p->data)
			return false;

		pr = p;
		st.push(pr);

		if (x < p->data)
			p = p->leftChild;
		else if (x>p->data)
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);

	if (pr == nullptr)
	{
		t = p;
		return true;
	}

	if (p->data < pr->data)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//2.����ƽ��

	while (!st.empty())
	{
		pr = st.top();//ȡջ��Ԫ��
		st.pop();
		if (pr->leftChild == p)
			pr->bf--;
		else
			pr->bf++;

		if (pr->bf == 0)
			break;//��ƽ�� ��������
		else if (pr->bf == 1 || pr->bf == -1)
			p = pr;//���ݵ����ڵ�ĸ��ڵ� ����ү��ڵ�Ĳ��
		else
		{
			//��ƽ�� Ҫ����
			if (pr->bf < 0)
			{
				if (p->bf < 0)  //  /
				{
					//cout << "RotateR." << endl;
					RotateR(pr);
				}
				else   //   <
				{
					//cout << "RotateLR" << endl;
					RotateLR(pr);
				}
			}
			else
			{
				if (p->bf > 0)  //  "\"
				{
					//cout << "RotateL." << endl;
					RotateL(pr);
				}
				else  //  >
				{
					//cout << "RotateRL" << endl;
					RotateRL(pr);
				}
			}
			break;
		}
	}
	if (st.empty())
		t = pr;
	else
	{
		AVLNode<Type>* q = st.top();
		if (q->data < pr->data)
			q->rightChild = pr;
		else
			q->leftChild = pr;
	}
	return true;
}

template<class Type>
bool AVLTree<Type>::Remove(AVLNode<Type>* &t, const Type &key)
{
	//1.����BSTɾ��key�ڵ�
	AVLNode<Type>* pr = nullptr;
	AVLNode<Type>* p = t, *q = nullptr;

	stack<AVLNode<Type>*> st;

	while (p != nullptr) // �ҵ�Ҫɾ����p�ڵ�
	{
		if (p->data == key)
			break;

		pr = p;
		st.push(pr);

		if (p->data < key)
			p = p->rightChild;

		if (p->data>key)
			p = p->leftChild;
	}

	if (p == nullptr)
		return false;

	if (p->leftChild != nullptr&&p->rightChild != nullptr)
	{
		q = p->leftChild;
		pr = p;
		st.push(pr);
		while (q->rightChild != nullptr)
		{
			pr = q;
			st.push(pr);
			q = q->rightChild;
		}
		p->data = q->data;
		p = q;//pָ����q  q�����ҵ����Ǹ��滻�˵�ֵ
	}

	//p��Ҫɾ���Ľڵ㣬q��p�ڵ����Ů�ڵ�
	if (p->leftChild != nullptr)
		q = p->leftChild;
	else
		q = p->rightChild;



	if (pr == nullptr)
		t = q;
	else
	{
		//�Ͽ�p�ڵ�

		if (p == pr->leftChild)
			pr->leftChild = q;
		else
			pr->rightChild = q;

	}


	//2. ƽ��BST
	bool is_break_flag = false;
	while (!st.empty())
	{
		pr = st.top();
		st.pop();

		if (p->data < pr->data)
			pr->bf++;
		else
			pr->bf--;


		////////////////////////
		if (pr->bf == 1 || pr->bf == -1)//���������ƽ�Ĳ��ܳ�1����-1 ˵����Ӱ�������bf
			break;
		if (pr->bf == 0) //bf==0�� ˵�������Ĳ�ƽ��ƽ�ⱻ�����ˣ����Եÿ�������Ľڵ��bf
			q = pr;
		else
		{
			// pr->|bf|==2
			//��qָ��pr�Ľϸ�����(��������)
			if (pr->bf < 0)
				q = pr->leftChild;
			else
				q = pr->rightChild;

			if (q->bf == 0)//����ת
			{
				if (pr->bf < 0)
				{
					RotateR(pr);
					pr->bf = 1;
					pr->rightChild->bf = -1;
				}
				else
				{
					RotateL(pr); 
					pr->bf = -1;
					pr->leftChild->bf = 1;
				}
			}
			else if (pr->bf < 0)
			{
				if (q->bf < 0)  //  /
				{
					RotateR(pr);
				}
				else
				{
					RotateLR(pr);    // <
				}
			}
			else if (pr->bf>0)
			{
				if (q->bf > 0)     //   '\'
				{
					RotateL(pr);
				}
				else
				{
					RotateRL(pr);  //   >
				}
			}

			//�������� 
			if (st.empty())
				t = pr;
			else
			{
				q = st.top();
				if (pr->data < q->data)
					q->leftChild = pr;
				else
					q->rightChild = pr;
			}
			if (is_break_flag)
				break;
		}

	}

	delete p;
	return true;
}


int main()
{
	vector<int> iv{ 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int> avl;
	for (const auto &e : iv)
		avl.Insert(e);

	avl.Remove(3);
	avl.Remove(9);

	return 0;
}