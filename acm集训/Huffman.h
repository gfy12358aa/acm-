#pragma once
#define MAX_CHAR 400
#include<memory.h>
#include<stdlib.h>
#include<string.h>
/**
* @brief 哈夫曼树的节点
*/
typedef struct HTNode
{	
	char data;
	int weight;  //结点权值 
	char code[MAX_CHAR];
	HTNode*parent; //父指针
	HTNode*lchild; //左孩子指针
	HTNode*rchild; //右孩子指针 
};
typedef HTNode* HuffmanTree;
/**
*@brief 数组存储哈夫曼树的字符与编码位串
*/
struct CodeNode
{  
	int num;
	char ch;//存储单词  
	char bits[MAX_CHAR];//存放编码位串 ，n为哈夫曼树中叶子结点个数 
};
/**
* @brief vec链表节点
*/
typedef struct node
{
	HTNode* data;
	node *next, *parent;
};
/**
* @brief 链表 \n(换行)
*/
typedef struct	cvector
{
	node *begin, *end;
};
/**
* @brief 初始化
* @param L    参数1  链表引用
*
* @return 无
*/
void Init(cvector &L)
{
	L.begin = NULL;
	L.end = NULL;
}
/**
* @brief 清除(除了头节点)
* @param L    参数1  链表引用
*
* @return 无
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
* @brief 判断cvector是否为空
* @param L    参数1  链表引用
*
* @return 返回说明
*     -<em>true</em> 为空
*     -<em>false</em> 不为空
*/
bool ListEmpty(cvector &L) { return L.begin == L.end; }
/**
* @brief 销毁cvector
* @param L    参数1  链表引用
* @param c    参数2  插入的值
* @return 无
*/
void dispose(cvector &L)
{
	Clear(L.begin);
	delete L.begin;
	L.begin = L.end;
}
/**
* @brief cvertor尾插入元素
* @param L    参数1  cvector引用
* @param c    参数2  插入的值
* @return 无
*/
void Pushvec(cvector &L, HTNode* c)
{
	//判断容器是否为空
	if (ListEmpty(L))
	{
		L.begin = new node();
		L.begin->data = c;
		L.begin->next = L.end;
		L.begin->parent = NULL;
		return;
	}
	auto i = L.begin;
	//寻找一个孩子节点是空的节点用于添加
	while (i->next != NULL)
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
*     -<em>HTNode*</em> 被删除的元素
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
* @brief 获取第一个元素
* @param L    参数1  链表引用
*
* @return 返回说明
*     -<em>HTNode*</em> 被删除的元素
*/
HTNode* Topvec(cvector&L)
{
	if (ListEmpty(L)) { return NULL; }
	return L.begin->data;
}
/**
* @brief 删除cvertor中第n个元素
* @param L    参数1  链表引用
* @param n    参数2  被删除元素序号
* @return 返回说明
*     -<em>HTNode*</em> 被删除的元素
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
*@brief 冒泡排序
* @param L    参数1  待排序的cvertor引用
*
* @return 无
*/
void Sort(cvector&L)
{
	node* p = L.begin;
	node* pNext = p->next;

	if (pNext == NULL)//只有一个参数
	{
		return;
	}
	if (pNext->next == NULL && p->data->weight > pNext->data->weight)//只有两个参数
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
* @brief cvertor中元素的长度
* @param L    参数1  cvertor引用
*
* @return 返回说明
*     -<em>int</em> cvertor长度
*/
int lengthVec(cvector &L)
{
	int temp = 0;
	for (node* i = L.begin; i != L.end; i = i->next)
	temp++;
	return temp;
}
//哈夫曼树的根节点
HuffmanTree head;
//字典信息存储
CodeNode* HuffmanCode;
//哈夫曼树的初始化
HTNode *dic;
/**
* @brief清除哈夫曼树
* @param root    参数1  哈夫曼树根节点
*
* @return 无
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
* @brief 递归初始化哈夫曼树的每个元素字符串编码
* @param root    参数1  哈夫曼树根节点
* @param c       参数2  下一层节点的哈夫曼编码
*
* @return 无
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
* @brief 初始化哈夫曼树
* @param d    参数1  待哈夫曼编码的字符串信息
* @param str_Length    参数2 字符串长度
*
* @return 返回说明
*     -<em>int</em> cvertor长度
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
		//初始化森林
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
* @brief 清除全部申请空间
*
* @return 无
*/
void Free()
{
	freeHuffmen(head);
	delete head;
	head = NULL;
	delete[] dic;
	delete[] HuffmanCode;
}