#pragma once
#include"node.h"
/*
无效数字
*/
#define NUL -10000000
/**
* @brief 链表 \n(换行)
*/
typedef struct	LinkList
{
	Node *begin, *end;
};

/**
* @brief 初始化链表
* @param L    参数1  链表引用
*
* @return 无
*/
void InitList(LinkList &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}

/**
* @brief 清除链表(除了头节点)
* @param L    参数1  链表引用
*
* @return 无
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
* @brief 判断链表是否非空
*/
bool ListEmpty(LinkList &L) { return L.begin == L.end; }
/**
* @brief 销毁链表
* @param L    参数1  链表引用
*/
void dispose(LinkList &L)
{
	Clear(L.begin);
	delete L.begin;
	L.begin = L.end;
}
/**
* @brief 链表尾插入元素
* @param L    参数1  链表引用
* @param c    参数2  插入的值
* @return 无
*/
void PushList(LinkList &L, const ElemType& c)
{
	auto i = L.begin;
	//头节点判断
	if (i == nullptr)
	{
		L.begin = new Node();
		L.begin->data.coef = c.coef;
		L.begin->data.expn = c.expn;
		L.begin->next = L.end;
		L.begin->parent = nullptr;
		return;
	}
	//寻找一个孩子节点是空的节点用于添加
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
* @brief 链表头插入元素
* @param L    参数1  链表引用
* @param c    参数2  插入的值
* @return 返回说明
*     -<em>false</em> fail
*     -<em>true</em> succeed
*/
void PushFirstList(LinkList &L, const ElemType& c)
{
	auto i = L.begin;
	//头节点判断
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
* @brief 删除头节点
* @param L    参数1  链表引用
*
* @return 返回说明
*     -<em>clar</em> 被删除的元素
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
* @brief 返回头节点值
* @param L    参数1  链表引用
*
* @return 返回说明
*     -<em>clar</em> 头节点的元素
*/
ElemType TopList(LinkList&L)
{
	if (L.begin == L.end) { return error; }
	return L.begin->data;
}
// 原地逆置单向链表
void LinkList_reverse(LinkList &L)
{
	// 头节点为空， 直接返回
	if (L.begin == nullptr)
	{
		return;
	}
	Node *p = L.begin->next;
	// 只有头节点， 直接返回
	if (p == nullptr)
	{
		return;
	}
	Node *q = p->next;
	// 只有一个元素， 直接返回
	if (q == nullptr)
	{
		return;
	}
	// 第一项元素为逆置后的最后一个元素，其next的值为nullptr
	p->next = nullptr;
	Node *temp;

	while (q)
	{
		// 临时保存q的下一个节点
		temp = q->next;
		q->next = p;// 翻转指针，由后一个元素指向前一个元素
		p = q;// 向后移动一个元素
		q = temp;// 向后移动一个元素
	}
	L.begin->next = p;// 将头节点指向最后的节点
	PushList(L, PopList(L));
}

/**
*@brief 冒泡排序
* @param L    参数1  待排序的cvertor引用
*
* @return 无
*/
void Sort(LinkList&L)
{
	if (L.begin == nullptr)return;
	Node* p = L.begin;
	Node* pNext = p->next;

	if (pNext == NULL)//只有一个参数
	{
		return;
	}
	if (pNext->next == NULL && p->data.expn < pNext->data.expn)//只有两个参数
	{
		p->next = nullptr;
		p->parent = pNext;
		pNext->next = p;
		pNext->parent = nullptr;
		L.begin = pNext;
		return;
	}
		//按指数从大到小排序
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