#pragma once
#include"node.h"
/*
��Ч����
*/
#define NUL -10000000
/**
* @brief ���� \n(����)
*/
typedef struct	LinkList
{
	Node *begin, *end;
};

/**
* @brief ��ʼ������
* @param L    ����1  ��������
*
* @return ��
*/
void InitList(LinkList &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}

/**
* @brief �������(����ͷ�ڵ�)
* @param L    ����1  ��������
*
* @return ��
*/
void Clear(Node *a)
{
	if (a == nullptr)return;
	if (a->next == nullptr)return;
	Clear(a->next);
	delete a->next;
	a->next = nullptr;
}
/**
* @brief �ж������Ƿ�ǿ�
*/
bool ListEmpty(LinkList &L) { return L.begin == L.end; }
/**
* @brief ��������
* @param L    ����1  ��������
*/
void dispose(LinkList &L)
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
void PushList(LinkList &L, const ElemType& c)
{
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i == nullptr)
	{
		L.begin = new Node();
		L.begin->data.coef = c.coef;
		L.begin->data.expn = c.expn;
		L.begin->next = L.end;
		L.begin->parent = nullptr;
		return;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != nullptr)
		i = i->next;
	i->next = new Node();
	i->next->data.coef = c.coef;
	i->next->data.expn  = c.expn;
	auto child = i->next;
	child->parent = i;
	child->next = L.end;
}
/**
* @brief ����ͷ����Ԫ��
* @param L    ����1  ��������
* @param c    ����2  �����ֵ
* @return ����˵��
*     -<em>false</em> fail
*     -<em>true</em> succeed
*/
void PushFirstList(LinkList &L, const ElemType& c)
{
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i == nullptr)
	{
		L.begin = new Node();
		L.begin->data.coef = c.coef;
		L.begin->data.expn = c.expn;
		L.begin->next = L.end;
		return;
	}
	Node *m = new Node();
	m->data.coef = c.coef;
	m->data.expn = c.expn;
	auto child = L.begin;
	m->next = child;
	L.begin = m;
}
/**
* @brief ɾ��ͷ�ڵ�
* @param L    ����1  ��������
*
* @return ����˵��
*     -<em>clar</em> ��ɾ����Ԫ��
*/
ElemType PopList(LinkList&L)
{
	if (L.begin == L.end) { return error; }
	if (L.begin->next == nullptr)
	{
		ElemType c = L.begin->data;
		delete L.begin;
		L.begin = L.end;
		return c;
	}
	ElemType c = L.begin->data;
	auto i = L.begin->next;
	delete i->parent;
	L.begin = i;
	L.begin->parent = nullptr;
	return c;
}
/**
* @brief ����ͷ�ڵ�ֵ
* @param L    ����1  ��������
*
* @return ����˵��
*     -<em>clar</em> ͷ�ڵ��Ԫ��
*/
ElemType TopList(LinkList&L)
{
	if (L.begin == L.end) { return error; }
	return L.begin->data;
}
// ԭ�����õ�������
void LinkList_reverse(LinkList &L)
{
	// ͷ�ڵ�Ϊ�գ� ֱ�ӷ���
	if (L.begin == nullptr)
	{
		return;
	}
	Node *p = L.begin->next;
	// ֻ��ͷ�ڵ㣬 ֱ�ӷ���
	if (p == nullptr)
	{
		return;
	}
	Node *q = p->next;
	// ֻ��һ��Ԫ�أ� ֱ�ӷ���
	if (q == nullptr)
	{
		return;
	}
	// ��һ��Ԫ��Ϊ���ú�����һ��Ԫ�أ���next��ֵΪnullptr
	p->next = nullptr;
	Node *temp;

	while (q)
	{
		// ��ʱ����q����һ���ڵ�
		temp = q->next;
		q->next = p;// ��תָ�룬�ɺ�һ��Ԫ��ָ��ǰһ��Ԫ��
		p = q;// ����ƶ�һ��Ԫ��
		q = temp;// ����ƶ�һ��Ԫ��
	}
	L.begin->next = p;// ��ͷ�ڵ�ָ�����Ľڵ�
	PushList(L, PopList(L));
}

/**
*@brief ð������
* @param L    ����1  �������cvertor����
*
* @return ��
*/
void Sort(LinkList&L)
{
	if (L.begin == nullptr)return;
	Node* p = L.begin;
	Node* pNext = p->next;

	if (pNext == NULL)//ֻ��һ������
	{
		return;
	}
	if (pNext->next == NULL && p->data.expn < pNext->data.expn)//ֻ����������
	{
		p->next = nullptr;
		p->parent = pNext;
		pNext->next = p;
		pNext->parent = nullptr;
		L.begin = pNext;
		return;
	}
		//��ָ���Ӵ�С����
Node* q;
ElemType tmp;
	for (; p->next != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data.expn < q->data.expn)
			{
				tmp = q->data;
				q->data = p->data;
				p->data = tmp;
			}
		}
	}
}