#pragma once
#define MAX_CHAR 400
#include<memory.h>
#include<stdlib.h>
#include<string.h>
/**
* @brief ���������Ľڵ�
*/
typedef struct HTNode
{	
	char data;
	int weight;  //���Ȩֵ 
	char code[MAX_CHAR];
	HTNode*parent; //��ָ��
	HTNode*lchild; //����ָ��
	HTNode*rchild; //�Һ���ָ�� 
};
typedef HTNode* HuffmanTree;
/**
*@brief ����洢�����������ַ������λ��
*/
struct CodeNode
{  
	int num;
	char ch;//�洢����  
	char bits[MAX_CHAR];//��ű���λ�� ��nΪ����������Ҷ�ӽ����� 
};
/**
* @brief vec����ڵ�
*/
typedef struct node
{
	HTNode* data;
	node *next, *parent;
};
/**
* @brief ���� \n(����)
*/
typedef struct	cvector
{
	node *begin, *end;
};
/**
* @brief ��ʼ��
* @param L    ����1  ��������
*
* @return ��
*/
void Init(cvector &L)
{
	L.begin = NULL;
	L.end = NULL;
}
/**
* @brief ���(����ͷ�ڵ�)
* @param L    ����1  ��������
*
* @return ��
*/
void Clear(node *a)
{
	if (a == NULL)return;
	if (a->next == NULL)return;
	Clear(a->next);
	delete a->next;
	a->next = nullptr;
}
/**
* @brief �ж�cvector�Ƿ�Ϊ��
* @param L    ����1  ��������
*
* @return ����˵��
*     -<em>true</em> Ϊ��
*     -<em>false</em> ��Ϊ��
*/
bool ListEmpty(cvector &L) { return L.begin == L.end; }
/**
* @brief ����cvector
* @param L    ����1  ��������
* @param c    ����2  �����ֵ
* @return ��
*/
void dispose(cvector &L)
{
	Clear(L.begin);
	delete L.begin;
	L.begin = L.end;
}
/**
* @brief cvertorβ����Ԫ��
* @param L    ����1  cvector����
* @param c    ����2  �����ֵ
* @return ��
*/
void Pushvec(cvector &L, HTNode* c)
{
	//�ж������Ƿ�Ϊ��
	if (ListEmpty(L))
	{
		L.begin = new node();
		L.begin->data = c;
		L.begin->next = L.end;
		L.begin->parent = NULL;
		return;
	}
	auto i = L.begin;
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != NULL)
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
*     -<em>HTNode*</em> ��ɾ����Ԫ��
*/
HTNode* Popvec(cvector&L)
{
	if (ListEmpty(L)) { return NULL; }
	if (L.begin->next == NULL)
	{
		HTNode* c = L.begin->data;
		delete L.begin;
		L.begin = L.end;
		return c;
	}
	HTNode* c = L.begin->data;
	auto i = L.begin->next;
	delete i->parent;
	L.begin = i;
	L.begin->parent = NULL;
	return c;
}/**
* @brief ��ȡ��һ��Ԫ��
* @param L    ����1  ��������
*
* @return ����˵��
*     -<em>HTNode*</em> ��ɾ����Ԫ��
*/
HTNode* Topvec(cvector&L)
{
	if (ListEmpty(L)) { return NULL; }
	return L.begin->data;
}
/**
* @brief ɾ��cvertor�е�n��Ԫ��
* @param L    ����1  ��������
* @param n    ����2  ��ɾ��Ԫ�����
* @return ����˵��
*     -<em>HTNode*</em> ��ɾ����Ԫ��
*/
HTNode* DeleteListElement(cvector &L, int n)
{
	if (ListEmpty(L))return NULL;
	node* i = L.begin;
	if (n == 0)
		return Popvec(L);
	while (i != NULL)
	{
		if (n == 0)
		{
			if (i->next == NULL)
			{
				auto j = i->parent;
				HTNode* data = i->data;
				delete j->next;
				j->next = NULL;
				return data;
			}
			auto j = i->parent;
			auto k = i->next;
			HTNode* data = i->data;
			delete i;
			i = NULL;
			j->next = k;
			k->parent = j;
			return data;
		}
		n--;
		i = i->next;
	}
}
/**
*@brief ð������
* @param L    ����1  �������cvertor����
*
* @return ��
*/
void Sort(cvector&L)
{
	node* p = L.begin;
	node* pNext = p->next;

	if (pNext == NULL)//ֻ��һ������
	{
		return;
	}
	if (pNext->next == NULL && p->data->weight > pNext->data->weight)//ֻ����������
	{
		p->next = nullptr;
		p->parent = pNext;
		pNext->next = p;
		pNext->parent = nullptr;
		L.begin = pNext;
		return;
	}
	node* q;
	HTNode* tmp;
	for (; p->next != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (q->data->weight < p->data->weight)
			{
				tmp = q->data;
				q->data = p->data;
				p->data = tmp;
			}
		}
	}
}
/**
* @brief cvertor��Ԫ�صĳ���
* @param L    ����1  cvertor����
*
* @return ����˵��
*     -<em>int</em> cvertor����
*/
int lengthVec(cvector &L)
{
	int temp = 0;
	for (node* i = L.begin; i != L.end; i = i->next)
	temp++;
	return temp;
}
//���������ĸ��ڵ�
HuffmanTree head;
//�ֵ���Ϣ�洢
CodeNode* HuffmanCode;
//���������ĳ�ʼ��
HTNode *dic;
/**
* @brief�����������
* @param root    ����1  �����������ڵ�
*
* @return ��
*/
void freeHuffmen(HTNode * root)
{
	if (root == NULL)		return;
	if (root->data != '\0')return;
	freeHuffmen(root->lchild);
	freeHuffmen(root->rchild);
	if (root->rchild != NULL)
	{
		if (root->rchild->data != '\0')return;

		delete root->rchild;
		root->rchild = NULL;
	}
	if (root->lchild != NULL)
	{
		if (root->lchild->data != '\0')return;

		delete root->lchild;
		root->lchild = NULL;
	}
}/**
* @brief �ݹ��ʼ������������ÿ��Ԫ���ַ�������
* @param root    ����1  �����������ڵ�
* @param c       ����2  ��һ��ڵ�Ĺ���������
*
* @return ��
*/
void print(HTNode* root,char c[MAX_CHAR])
{
	if (root != NULL)
	{
		int i = 0;
		char m[MAX_CHAR]{ '\0','\0' };
		char n[MAX_CHAR]{'\0','\0'};
		for (i = 0; i < strlen(c); i++)
		{
			root->code[i] = c[i];
			m[i]=c[i];
			n[i] = c[i];
		}
		m[i] = '1';
		print(root->rchild, m);
		n[i] = '0';
		print(root->lchild, n);
	}
}
/**
* @brief ��ʼ����������
* @param d    ����1  ��������������ַ�����Ϣ
* @param str_Length    ����2 �ַ�������
*
* @return ����˵��
*     -<em>int</em> cvertor����
*/
int initTree(char * d, int str_Length)
{
	dic = new HTNode[27];
	dic[0].data = ';';
	for (int j = 0; j < 400; j++)
		dic[0].code[j] = '\0';
	dic[0].weight = 0;
	dic[0].rchild = NULL;
	dic[0].lchild = nullptr;
	dic[0].parent = nullptr;
	for (int i = 1; i < 27; i++)
	{
		dic[i].data = 'A' + i - 1;
		for (int j = 0; j < 400; j++)
			dic[i].code[j] = '\0';
		dic[i].weight = 0;
		dic[i].rchild = NULL;
		dic[i].lchild = NULL;
		dic[i].parent = NULL;
	}
	for (int i = 0; i < str_Length; i++)
	{
		if (d[i] == ';')dic[0].weight++;
		dic[d[i] - 'A' + 1].weight++;
	}	
	cvector tree;
	Init(tree);
	int num = 0;
		//��ʼ��ɭ��
	for (int i = 0; i < 27; i++)
	{
		if (dic[i].weight > 0)
		{
			Pushvec(tree, dic + i);
			num++;
		}
	}
	for (;;)
	{
		if (lengthVec(tree) < 2)break;
		Sort(tree);
		auto first = Popvec(tree);
		auto last = Popvec(tree);
		auto c = new HTNode();
		c->weight = first->weight + last->weight;
		c->data = '\0';
		c->lchild = first;
		c->rchild = last;
		c->parent = NULL;
		first->parent = c;
		last->parent = c;
		Pushvec(tree, c);
	}
	head = Popvec(tree);
	print(head,head->code);
	HuffmanCode = new CodeNode[num];
	int temp = 0;
	for (int i = 0; i < 27; i++)
	{
		if (dic[i].weight > 0)
		{
			memset(HuffmanCode[temp].bits, '\0', sizeof(HuffmanCode[temp].bits));
			HuffmanCode[temp].num = dic[i].weight;
			HuffmanCode[temp].ch = dic[i].data;
			for(int j=0;j<strlen(dic[i].code);j++)
				HuffmanCode[temp].bits[j] = dic[i].code[j];
			temp++;
		}
	}
	return temp;
}
/**
* @brief ���ȫ������ռ�
*
* @return ��
*/
void Free()
{
	freeHuffmen(head);
	delete head;
	head = NULL;
	delete[] dic;
	delete[] HuffmanCode;
}