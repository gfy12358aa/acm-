#pragma once
#include<iostream>
#include<fstream>
#include<string>
struct Node
{
	int data;
	Node *L, *R;
};


std::vector<int> m{ 1,85,47,56,24,57,258,54,12,52,6,869 };
//��ʼ��
void Init(Node *N)
{
	for (int i = 1; i < m.size(); i++)
	{
		Node *n = N;
		while (true)
		{
			if (n->data < m[i])
			{
				if (n->R == nullptr)
				{
					n->R = new  Node(m[i]);
					break;
				}
				n = n->R;
			}
			else if (n->data > m[i])
			{
				if (n->L == nullptr)
				{
					n->L = new  Node(m[i]);
					break;
				}
				n = n->L;
			}
			else break;
		}
	}
}
//��
void Increase(Node *n, int i)
{
	Node *p = n;
	while (true)
	{
		if (p == nullptr)
		{
			p = new Node(i);
			break;
		}
		else
		{
			if (p->data < i)p = p->R;
			else if (p->data > i)p = p->L;
			else break;
		}
	}
}
void Clear(Node *n)
{
	if (n->L != nullptr)Clear(n->L);
	if (n->R != nullptr)Clear(n->R);
	delete n;
	n = nullptr;
}

//����
bool find(Node *tree, int i)
{
	//1.��b�ǿ�����������ʧ�ܣ�����
	if (tree == nullptr)
	{
		std::cout << "this is a not tree" << std::endl;
		return false;
	}
	//
	Node *p = tree;
	while (true)
	{
		if (p == nullptr)
		{
			break;
		}
		else
		{
			if (p->data < i)p = p->R;
			else if (p->data > i)p = p->L;
			else if (p->data == i)return true;
		}
	}
	return false;
}


void preprint(Node *tree)
{
	if (tree != nullptr)
	{
		preprint(tree->L);
		std::cout << tree->data << std::endl;
		preprint(tree->R);
	}
}
int main()
{
	Node* Tree = nullptr;
	Tree = new Node(m[0]);
	Init(Tree);
	preprint(Tree);
	Clear(Tree);
	return 0;
}#define MAX 7
#include<string>
//����
struct Link
{
	int data;
	Link* Left;
	Link* Right;
	Link(const int data) :data(data), Left(nullptr), Right(nullptr) {  }
};
int initdata[MAX]{ 1,2,3,4,5,6,7 };
void InsertTree(Link *m, int n)
{
	if (n * 2 + 1 < MAX)
	{
		m->Left = new  Link(initdata[n * 2 + 1]);
		InsertTree(m->Left, 2 * n + 1);
	}
	if (n * 2 + 2 < MAX)
	{
		m->Right = new  Link(initdata[n * 2 + 2]);
		InsertTree(m->Right, 2 * n + 2);
	}
}

/*
��Ȼ�������������Ч����O(n)������֧�ֶ�̬���ң����кܶ�Ľ���Ķ�������������ʹ����ΪO(logn)����AVL��������ȡ�
��Ԫ�������Ĳ����㷨
�ڶ�Ԫ������b�в���x�Ĺ���Ϊ��
1.��b�ǿ�����������ʧ�ܣ�����
2.��x����b�ĸ��ڵ��������ֵ֮������ҳɹ�������
3.��xС��b�ĸ��ڵ��������ֵ֮��������������������
4.������������
*/
bool FindTree(Link *m, int data)
{
	if (m == nullptr)
	{
		std::cout << "this is empty tree" << std::endl;
		return false;
	}
	//��ǰ������m
	Link *curr = m;
	while (curr != nullptr)
	{
		if (curr->data == m->data)return true;
		if (curr->data < m->data)curr = curr->Left;
		if (curr->data > m->data)curr = curr->Right;
	}
	return false;
}
void DeleteTree(Link *a)
{
	if (a->Left != nullptr)
	{
		DeleteTree(a->Left);
	}
	if (a->Right != nullptr)
	{
		DeleteTree(a->Right);
	}
	delete a;
	a = nullptr;
}



void start()
{
	Link*start = new Link(5);
	InsertTree(start, 0);
	DeleteTree(start);
}
/*����������
�����������ֳơ������������������������������

������������������һ�ÿ����������Ǿ����������ʵĶ�������
1. ���������������գ��������������н���ֵ��С�����ĸ����ֵ��
2. ���������������գ��������������н���ֵ���������ĸ�����ֵ��
3. ������������Ҳ�ֱ�Ϊ������������
����������ͨ�����ö���������Ϊ�洢�ṹ��������������������ɵõ�һ�����ݹؼ��ֵ��������У�һ���������п���ͨ������һ�ö������������һ���������У��������Ĺ��̼��Ƕ��������н�������Ĺ��̡�ÿ�β�����µĽ�㶼�Ƕ������������µ�Ҷ�ӽ�㣬�ڽ��в������ʱ�������ƶ�������㣬ֻ��Ķ�ĳ������ָ�룬�ɿձ�Ϊ�ǿռ��ɡ����������롢ɾ����ʱ�临�Ӷȵ������ߣ�����O(logn)���O(n)�������������˻������Ա�����б������
*/
/*
�����������Ĳ����㷨
���ò��Һ��������ؼ��ַŵ����еĺ���λ�á�
/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� *
/*  ����key������TRUE�����򷵻�FALSE *
Status InsertBST(BiTree *T, int key)
{
BiTree p, s;
if (!SearchBST(*T, key, NULL, &p)) /* ���Ҳ��ɹ� *
{
s = (BiTree)malloc(sizeof(BiTNode));
s->data = key;
s->lchild = s->rchild = NULL;
if (!p)
*T = s;            /*  ����sΪ�µĸ���� *
else if (key<p->data)
p->lchild = s;    /*  ����sΪ���� *
else
p->rchild = s;  /*  ����sΪ�Һ��� *
return TRUE;
}
else
return FALSE;  /*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� *
}
���ƴ���
������������ɾ���㷨

�ڶ�����������ɾȥһ����㣬������������ۣ�

1.��*p���ΪҶ�ӽ�㣬��PL(������)��PR(������)��Ϊ����������ɾȥҶ�ӽ�㲻�ƻ��������Ľṹ����ֻ���޸���˫�׽���ָ�뼴�ɡ�

2.��*p���ֻ��������PL��������PR����ʱֻҪ��PL��PRֱ�ӳ�Ϊ��˫�׽��*f������������*p����������������������*p�������������ɣ������޸�Ҳ���ƻ����������������ԡ�

3.��*p�����������������������ա���ɾȥ*p֮��Ϊ��������Ԫ��֮������λ�ò��䣬�ɰ������������������е������ȽϺõ������ǣ��ҵ�*p��ֱ��ǰ������ֱ�Ӻ�̣�*s����*s���滻���*p��Ȼ����ɾ�����*s��





���ƴ���
/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��, */
/* ������TRUE�����򷵻�FALSE�� *
Status DeleteBST(BiTree *T, int key)
{
if (!*T) /* �����ڹؼ��ֵ���key������Ԫ�� *
return FALSE;
else
{
if (key == (*T)->data) /* �ҵ��ؼ��ֵ���key������Ԫ�� *
return Delete(T);
else if (key<(*T)->data)
return DeleteBST(&(*T)->lchild, key);
else
return DeleteBST(&(*T)->rchild, key);

}
}

/* �Ӷ�����������ɾ�����p�����ؽ���������������� *
Status Delete(BiTree *p)
{
BiTree q, s;
if ((*p)->rchild == NULL) /* ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧) *
{
q = *p; *p = (*p)->lchild; free(q);
}
else if ((*p)->lchild == NULL) /* ֻ���ؽ����������� *
{
q = *p; *p = (*p)->rchild; free(q);
}
else /* �������������� *
{
q = *p; s = (*p)->lchild;
while (s->rchild) /* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ���� *
{
q = s;
s = s->rchild;
}
(*p)->data = s->data; /*  sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ�� *
if (q != *p)
q->rchild = s->lchild; /*  �ؽ�q�������� *
else
q->lchild = s->lchild; /*  �ؽ�q�������� /
free(s);
}
return TRUE;
}*/

