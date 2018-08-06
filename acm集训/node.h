#pragma once
//多项式中元素
typedef struct ElemType
{
	int coef;//系数
	int expn;//指数
};
bool operator ==(ElemType &a, ElemType&b) { return a.coef == b.coef &&a.expn == b.expn; }
/**
* @brief 链表节点
*/ 
typedef struct Node
{
	ElemType data;
	Node *next, *parent;
};
//多项式的空值
ElemType error{0,0};