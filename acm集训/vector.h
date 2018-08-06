#include"node.h"
typedef struct node
{
	Node* data;
	node *next, *parent;
};

/*
无效数字
*/
#define NUL -10000000
/**
* @brief 链表 \n(换行)
*/
typedef struct	vector
{
	node *begin, *end;
};
/**
* @brief 初始化
* @param L    参数1  链表引用
*
* @return 无
*/
void Init(vector &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}
/**
* @brief 清除(除了头节点)
* @param L    参数1  链表引用
*
* @return 无
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
* @brief 链表尾插入元素
* @param L    参数1  链表引用
* @param c    参数2  插入的值
* @return 无
*/
void Pushvec(vector &L, Node* c)
{
	auto i = L.begin;
	//头节点判断
	if (i == nullptr)
	{
		L.begin = new node();
		L.begin->data = c;
		L.begin->next = L.end;
		L.begin->parent = nullptr;
		return;
	}
	//寻找一个孩子节点是空的节点用于添加
	while (i->next != nullptr)
		i = i->next;
	i->next = new node();
	i->next->data = c;
	auto child = i->next;
	child->parent = i;
	child->next = L.end;
}
/**
* @brief 删除头节点
* @param L    参数1  链表引用
*
* @return 返回说明
*     -<em>clar</em> 被删除的元素
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
//交换n与n+1的元素
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