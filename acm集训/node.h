#pragma once
//����ʽ��Ԫ��
typedef struct ElemType
{
	int coef;//ϵ��
	int expn;//ָ��
};
bool operator ==(ElemType &a, ElemType&b) { return a.coef == b.coef &&a.expn == b.expn; }
/**
* @brief ����ڵ�
*/ 
typedef struct Node
{
	ElemType data;
	Node *next, *parent;
};
//����ʽ�Ŀ�ֵ
ElemType error{0,0};