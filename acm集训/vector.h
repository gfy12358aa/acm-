#include"node.h"
typedef struct node
{
	Node* data;
	node *next, *parent;
};

/*
��Ч����
*/
#define NUL -10000000
/**
* @brief ���� \n(����)
*/
typedef struct	vector
{
	node *begin, *end;
};
/**
* @brief ��ʼ��
* @param L    ����1  ��������
*
* @return ��
*/
void Init(vector &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}
/**
* @brief ���(����ͷ�ڵ�)
* @param L    ����1  ��������
*
* @return ��
*/
void Clear(node *a)
{
	if (a == nullptr)return;
	if (a->next == nullptr)return;
	Clear(a->next);
	delete a->next;
	a->next = nullptr;
}
bool ListEmpty(vector &L) { return L.begin == L.end; }
void dispose(vector &L)
{
	Clear(L.begin);
	delete L.begin;
	L.begin = L.end;
}
/**
* @brief ����β����Ԫ��
* @param L    ����1  ��������
* @param c    ����2  �����ֵ
* @return ��
*/
void Pushvec(vector &L, Node* c)
{
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i == nullptr)
	{
		L.begin = new node();
		L.begin->data = c;
		L.begin->next = L.end;
		L.begin->parent = nullptr;
		return;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != nullptr)
		i = i->next;
	i->next = new node();
	i->next->data = c;
	auto child = i->next;
	child->parent = i;
	child->next = L.end;
}
/**
* @brief ɾ��ͷ�ڵ�
* @param L    ����1  ��������
*
* @return ����˵��
*     -<em>clar</em> ��ɾ����Ԫ��
*/
//
Node* Popvec(vector&L)
{
	if (L.begin == L.end) { return nullptr; }
	if (L.begin->next == nullptr)
	{
		Node* c = L.begin->data;
		delete L.begin;
		L.begin = L.end;
		return c;
	}
	Node* c = L.begin->data;
	auto i = L.begin->next;
	delete i->parent;
	L.begin = i;
	return c;
}
Node* Topvec(vector&L)
{
	if (L.begin == L.end) { return nullptr; }
	return L.begin->data;
}
//����n��n+1��Ԫ��
void vecSwap(vector&L, int n)
{
	if (L.begin->next == nullptr)return;
	auto q = L.begin->next;
	auto pre = L.begin;

}
void soap(vector&v,int n)
{

}
int getList(vector&L, int n)
{
	auto i = L.begin;
	if (i == nullptr)return 0;
	while (i != nullptr)
	{
		if (n == 0)return 0;
		n--;
		i = i->next;
	}
	return NUL;
}