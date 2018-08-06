#define _CRT_SECURE_NO_WARNINGS
#include<memory>
#include<cstdio>
long long num[5005];
int main()
{
	num[1] = 1;
	num[2] = 7;
	for (long long  i =3; i < 4300; i++)
	{
		num[i] = num[i - 2] - (i - 1)*(i - 1)*(i - 1) + i*i*i;
	}
	int i = 0;
	while (true)
	{
		scanf("%d", &i);
		if (i == 0)break;
			printf("%d\n", num[i%4018] % 2009);
	}
	return 0;
}

//main.cpp
/*#define _CRT_SECURE_NO_WARNINGS
#include"Gragh.h"

int main()
{
	ALGraph G;
	CreateGraph(G);
	int ans = MinSpanTree(G, G.vertices[0].data);
	printf("��̹�����%d\n",ans);
	return 0;
}
*/
/*

/**
* @brief ��ӡ����ʽ
* @param n    ����1  ����Ĵ�С
*
* @return ����˵��
*     -<em>false</em> fail
*     -<em>true</em> succeed
**
int printList(LinkList &L, char c)
{
	LinkList_reverse(L);
	if (TopList (L) == error)return 0;
	ElemType val = PopList(L);
	if (val.coef != 0)
	{
		if (val.expn == 0)
		{
			if (val.coef < 0)
				printf("%d", val.coef);
			else
				printf("%d", val.coef);
		}
		else
			printf("%dx^%d", val.coef, val.expn);
	}
	while (!(TopList(L) == error))
	{
		val = PopList(L);
		if (val.coef == 0)continue;
		//������
		else if (val.expn == 0)
		{
		 if (val.coef < 0)
			printf("%d", val.coef);
		else
			printf("+%d", val.coef);
		}
		else if (val.coef < 0)
			printf("%dx^%d", val.coef, val.expn);
		else
			printf("+%dx^%d", val.coef, val.expn);
	}
	return 0;
}

int main()
{
	ElemType num;
	printf("��������������ʽ�����ж���ʽ���ڵ��ݻ�������֮���ʹ��','�ָ�\r\n��ʽ���£�1-5x^2+3x^3+1x^5��ʾΪ1,0,-5,2,3,3,1,5\n");
	//�Ƿ��ǵڶ�����
	bool isjia = false;
	//��ǰ��������ǲ��Ǹ���
	bool isfu=false;
	//��ǰ��������Ƿ��ǵ���
	bool isOne = true;
	//��������ʽ���������
	char fu;
	//����ʽջ
	LinkList s1, s2;
	InitList(s1);
	InitList(s2);
	char last='\0';
		int p=0;
	while (true)
	{
		char c;
		scanf("%c", &c);
		//�������= ��ʼ����
		if (c == '=')
		{
			//�жϵڶ�������ʽ�����һ�����ǲ��Ǹ���
			if (isOne == true)
			{
				num.coef = p;
				isOne = false;
				p = 0;	
				if (isfu == true)
					num.coef = -num.coef;
			}
			else//��������ָ��
			{
				num.expn = p;
				p = 0;
				isOne = true;
				if (isfu == true)
					num.expn = -num.expn;
				if (isjia == false)
				{
					PushFirstList(s1, num);
					isfu = false;
				}
				else
				{
					PushFirstList(s2, num);
					isfu = false;
				}
				num.coef = 0;
				num.expn = 0;
			}

			LinkList s3;
			InitList(s3);
			Sort(s1);
			Sort(s2);
			//����ʽջ�ĺϲ�
			while (!ListEmpty(s1) || !ListEmpty(s2))
			{
				ElemType a=error, b=error;
				if (!ListEmpty(s1))
					 a= TopList(s1);
				if (!ListEmpty(s2))
					 b= TopList(s2);
				//��a b�����ǿ�ֵ
				if (!(a == error) && !(b == error))
				{
					//���a b��ָ�����
					if (a.expn == b.expn)
					{
						PopList(s1);
						PopList(s2);
						if (fu == '+')
							a.coef += b.coef;
						else if (fu == '-')
							a.coef -= b.coef;
						PushFirstList(s3,a );
					}
					else if(a.expn>b.expn)
					{
						PopList(s1);
						PushFirstList(s3, a);
					}
					else if (a.expn < b.expn)
					{
						PopList(s2);
						if (fu == '+')
							a.coef = b.coef;
						else if (fu == '-')
							a.coef =-b.coef;
						a.expn = b.expn;
						PushFirstList(s3, a);
					}
				}
				//��a�ǿ�ֵ
				else if (a == error)
				{
					PopList(s2);
					if (fu == '+')
						a.coef = b.coef;
					else if (fu == '-')
						a.coef = -b.coef;
					a.expn = b.expn;
					PushFirstList(s3, a);
				}
				else if (b == error)
				{
					PopList(s1);
					PushFirstList(s3, a);
				}
			}
			printf("�����");
			printList(s3, fu);			//��ӡ�����
			dispose(s3);			//���ٶ���ʽջs3
			break;
		}
		else if (c == '+' || c == '-')
		{		
			//�����롰-��ʱ���ж���������-�Ż�����һ�����Ǹ���
			if ((isjia==false)&&(last=='\0'||last==','||last=='+'||last=='-')&&c=='-')
			{
				isfu = true;
				continue;
			}	
			else if ((isjia == true) &&(last == ',' || last == '+' || last == '-') && c == '-')
			{
				isfu = true;
				continue;
			}		
			//������ݵ���û������
			if (isOne == true)
			{
				num.coef = p;
				isOne = false;
				p = 0;
				if (isfu == true)
				{
					num.coef = -num.coef;
					isfu = false;
				}
			}
			else
			{
				num.expn = p;
				p = 0;
				isOne = true;
				if (isfu == true)
				{
					isfu = false;
					num.expn = -num.expn;
				}
				if (isjia == false)
				{
					PushFirstList(s1, num);
					isfu = false;
				}
				else
				{
					PushFirstList(s2, num);
					isfu = false;
				}
				num.coef = 0;
				num.expn = 0;
			}

			//�������������+-
			if (isjia == false)
			{
				fu = c;
				isjia = true;
			}
		}
		//,��һ������ʽ��Ԫ��ϵ����ָ�����зַ���
		else if (c == ',')
		{
			//������ݵ���û�����룬�������
			if (isOne == true)
			{
				num.coef = p;
				isOne = false;
				p = 0;
				if (isfu == true)
				{
					num.coef = -num.coef;
					isfu = false;
				}
			}
			else//��������ָ��
			{
				num.expn = p;
				p = 0;
				isOne = true;
				if (isfu == true)
				{
					num.expn = -num.expn;
					isfu = false;
				}
				if (isjia == false)
				{
					PushFirstList(s1, num);
					isfu = false;
				}
				else
				{
					PushFirstList(s2,num);
					isfu = false;
				}
				num.coef = 0;
				num.expn = 0;
			}
		}
		else if (c >= '0'&&c <= '9')
		{	
			int i = c - '0';
			p = p * 10 + i;
		}
		last = c;
	}
	//����s1 s2
	dispose(s1);
	dispose(s2);
	return 0;
}

*/

/*

#define _CRT_SECURE_NO_WARNINGS
#include<memory>
#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define MAX_VERTEX_NUM 20 //ͼ����󶥵���
typedef struct Edge;
typedef struct GraghNode
{
int data;        //�ڵ�������Ϣ
Edge* firstEdge;            //ָ���һ���ߵ�Edgeָ��
bool visited;    //�ڱ���ʱ�ýڵ��Ƿ񱻷��ʹ�
GraghNode():firstEdge(nullptr), visited(false) {}
~GraghNode() {}
};
typedef struct Edge
{
int adjvex;              //�û���ָ��Ķ����λ��
Edge* nextEdge;//�ڱ��ﻹҪά��һ��ָ����һ���ߵ�Edgeָ��
int len;//�ߵĳ���
Edge():nextEdge(nullptr){}
};
typedef struct Gragh
{
GraghNode* nodes;            //���������������
int nodeCount;            //�������,Ҳ��ʾ��һ�����õĶ��������±�
int edgeCount;            //�߸���
int edgeCurrent;
Gragh():nodes(nullptr){}
};
//ջ
struct node
{
GraghNode* data;
node *next,*parent;
};
struct Stack
{
node *begin, *end;
};
//��ʼ��
void Init(Stack  &L)
{
L.begin = nullptr;
L.end = nullptr;
}
//���(����ͷ�ڵ�)
void Clear(node *a)
{
if (a == nullptr)return;
if (a->next == nullptr)return;
Clear(a->next);
delete a->next;
a->next = nullptr;
}
void Push(Stack &L, GraghNode* c)
{
auto i = L.begin;
//ͷ�ڵ��ж�
if (i == nullptr)
{
L.begin = new node();
//	L.begin = (node*)malloc(sizeof(node));
L.begin->data = c;
//L.begin = new Node(c);
L.begin->next = L.end;
return;
}
//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
while (i->next != nullptr)
i = i->next;
//i->next = (node*)malloc(sizeof(node));
i->next = new node();
i->next->data = c;
auto child = i->next;
child->parent = i;
child->next = L.end;
}
//ɾ��ǰһ���ڵ�
GraghNode* Pop(Stack&L)
{
if (L.begin == L.end) { printf("ջ�մ���"); return nullptr; }
//���ֻ��һ���ڵ�
if (L.begin->next == nullptr)
{
auto i = L.begin->data;
delete L.begin;
L.begin = L.end;
return i;
}
GraghNode* c = L.begin->data;
auto i = L.begin->next;
delete i->parent;
i->parent = nullptr;
L.begin = i;
return c;
}


void removeList(Stack &L, GraghNode* data)
{
if (L.begin == L.end) { printf("ջ�մ���"); return; }
if (L.begin->data == data)
{
auto i = L.begin->next;
delete L.begin;
L.begin = i;
}

for (node* i = L.begin->next ,*pre=L.begin; i != L.end; i=i->next,pre=pre->next)
{
if (i->data->data == data->data)
{
pre->next = i->next;
delete i;
i = pre->next;
return;
}
}
}

bool StackEmpty(Stack &L) { return L.begin == L.end; }
void print(Stack &L)
{
for (auto a = L.begin; a != L.end; a = a->next)
printf("%d ", a->data->data);
printf("\n");
}

int m[6];
//����������
int FindInDegree(Gragh& g, int i) { return m[i]; }
bool visit[6];
bool isNOEdge(Gragh &G)
{
return 	G.edgeCurrent<1;
}
void addEdgeToVNodeList(Gragh& G,int start,int end)
{
AdjList *node = G.Nodes;
if (G.edgeCurrent >= G.edgeCount)return;

if (node[start-1].firstEdge == nullptr)    //������ӵ�start����ı�������ȥ
{
node[start - 1].firstEdge = new ArcNode();
node[start - 1].firstEdge->next = nullptr;
node[start - 1].firstEdge->adjvex = end;
G.edgeCurrent++;
m[end-1]++;
}
else
{
ArcNode* temp = node[start - 1].firstEdge;
while (temp->next != nullptr)
temp = temp->next;    //���һ����
temp->next = new ArcNode();
temp->next->adjvex = end;
temp->next->next = nullptr;
G.edgeCurrent++;
m[end - 1]++;
}
}
ArcNode* removeEdgeFromVNodeList(Gragh& G, int start, int end)
{
ArcNode *temp = G.Nodes[start - 1].firstEdge;
if (temp == nullptr)return nullptr;
//ͬһ����ı������еıߵ���ʼ����ͬ
if (temp->next == nullptr)
{
if (temp->adjvex == end)
{
delete temp;
G.Nodes[start - 1].firstEdge = nullptr;
m[end - 1]--;
G.edgeCurrent--;
return nullptr;
}
}
//��������߲���Ҫɾ�ı�
else
{
if (temp->adjvex == end)
{
auto i = temp->next;
delete temp;
G.Nodes[start - 1].firstEdge = i;
m[end - 1]--;
G.edgeCurrent--;

return G.Nodes[start-1].firstEdge;
}
ArcNode *preTemp = temp;
temp = temp->next;
while (temp->next!=nullptr)
{
if (temp->adjvex == end)
{
preTemp->next = temp->next;
delete temp;
temp = nullptr;
m[end - 1]--;
G.edgeCurrent--;

return preTemp->next;
}
preTemp = temp;
temp = temp->next;
}
if (temp->adjvex == end)
{
G.edgeCurrent--;
preTemp->next = temp->next;
delete temp;
temp = nullptr;
m[end - 1]--;
return preTemp->next;
}
}
return nullptr;
}
void CreateGraph(Gragh& G)
{
printf("������ͼ�Ķ������ͻ���������,�ָ�:");
scanf("%d,%d", &G.nodeCount, &G.edgeCount); //����ͼ�Ķ������ͻ�
if (G.nodeCount > MAX_VERTEX_NUM)G.nodeCount = 20;
memset(m, 0, sizeof(int));memset(visit, false, sizeof(bool));
G.edgeCurrent = 0;
G.Nodes = new AdjList[G.nodeCount];
printf("����������ͼ�Ķ�����Ϣ��int�ͣ�");
for (int i = 0; i < G.nodeCount; i++)
{
scanf("%d", &G.Nodes[i].data);
G.Nodes[i].firstEdge = nullptr;
}
printf("���������, ��ʽ����β,��ͷ\n");
for (int i = 0; i < G.edgeCount; i++)
{
int start, end;
scanf("%d,%d", &start, &end);
addEdgeToVNodeList(G,start,end);
}
}
void Free(ArcNode* i)
{
if (i == nullptr)return;
if (i->next == nullptr) { return; }
free(i->next);
delete i->next;
i->next = nullptr;
}
void ClearGragh(Gragh& G)
{
for (int i = 0; i <G.nodeCount; i++)
{
if (G.Nodes[i].firstEdge != nullptr)
{
if (G.Nodes[i].firstEdge->next == nullptr)
{
delete G.Nodes[i].firstEdge;
G.Nodes[i].firstEdge = nullptr;
}
else
{
auto j = G.Nodes[i].firstEdge;
Free(j);
delete j;
j = nullptr;
}
}
}
if (G.Nodes != nullptr)
{
delete []G.Nodes;
}
}
bool  TopologicalSort(Gragh &G, Stack &L)
{
Stack S;
Init(S);
//��ȡ���Ϊ��Ķ���
for (int i = 0; i < G.nodeCount; i++)
{
if (visit[i] == false && FindInDegree(G,i) == 0)
{
Push(S, &G.Nodes[i]);
}
}

while (!StackEmpty(S))
{
auto s = Pop(S);
visit[s->data - 1] = true;
Push(L, s);
for (auto i = s->firstEdge; i != nullptr; )
{
auto n = removeEdgeFromVNodeList(G, s->data, i->adjvex);
if (n != nullptr) { i = n;  }
else
{
if (s->firstEdge == nullptr)break;
else i = i->next;
}
}
for (int i = 0; i < G.nodeCount; i++)
{
if (visit[i] == false &&m[i]==0)
{
Push(S, &G.Nodes[i]);
}
}
}
if (isNOEdge(G) == false)return false;
Clear(S.begin);
free(S.begin);
S.begin = nullptr;
return true;
}
int main()
{
Stack L;
Init(L);
Gragh g;
CreateGraph(g);
if (TopologicalSort(g, L))
{
print(L);
}
else
printf("���������޻�ͼ");
Clear(L.begin);
free(L.begin);
L.begin = nullptr;
ClearGragh(g);
return 0;
}
char *filename = "E:\\MST.txt";
int main()
{
fstream f(filename);
char buff[MAX_CHAR];
f >> buff;
while (!f.eof())
{
cout << buff<<"\n";
f >> buff;
}
cout << buff<<endl;
return 0;
}
*/

/*
//������������
int main()
{
	char c_str[MAX_CHAR];
	gets_s(c_str);
	int m = initTree(c_str, strlen(c_str));
	for (int i = 0; i < m; i++)
		printf("%d    %c   %s\n", HuffmanCode[i].num, HuffmanCode[i].ch, HuffmanCode[i].bits);
	Free();
	return 0;
}

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct Hash
{
	//-1�ǿ�ֵ
	int key[10];
};
Hash h;
int getHash(int key)
{
	return key % 7;
}
bool InsertHash(int key)
{
	int location = getHash(key);
	while (true)
	{
		if(h.key[location]!=-1)
		{
			location++;
			if (location>9 )location -= 10;
		}
		else
		{
			h.key[location] = key;
			return true;
		}
	}
}
bool SearchHash(int key)
{
	int location = getHash(key);
	while (true)
	{
		if (h.key[location] != -1)
		{
			if (h.key[location] == key)return true;
			location++;
			if (location - 10 > 0)location -= 10;
		}
		else
		{
			return false;
		}
	}
}
int arr[] = { 61,13,20,27,55,6 };
void CreateHashTable()//������ϣ�����������ؼ��ִ��룻
{
	memset(h.key, -1, sizeof(h.key));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		InsertHash(arr[i]);
}
void print()
{
	for (int i = 0; i < 10; i++)
		printf("%d  ", h.key[i]);
	printf("\n");
}
int main()
{
	CreateHashTable();
	print();
	if(SearchHash(61))
	printf("TRUE\n");
	else
	printf("FALSE\n");
	return 0;
}

*/


/*
#define _CRT_SECURE_NO_WARNINGS
 #include<stdio.h>
 #include<stdlib.h>
 int max(int a, int b)
 {
 return a > b ? a : b;
 }
 struct BiTree
 {
 char data;
 BiTree *L, *R;
 int depth;
 BiTree() :L(nullptr), R(nullptr) {}
 };
 //"abd**e*h**c*f**";

 //�������������������һ�ö�����
 void CreateBiTree(BiTree *&N,int depth=1)
 {
 char c;
 scanf("%c", &c);
 BiTree* n = (BiTree*)malloc(sizeof(BiTree));
 n->data = c;
 n->depth = depth;
 if (n->data =='*')
 {
 N = NULL;
 }
 else
 {
 N = n;
 CreateBiTree(N->L,depth+1);
 CreateBiTree(N->R,depth+1);
 }
 }

 //Node Tree;
 BiTree* T;
 int Depth(BiTree *&N)//��˶����������
 {
 if (N->R == NULL&&N->L == NULL)
 return N->depth;
 if (N->R != NULL&&N->L== NULL)
 return Depth(N->R);
 else if (N->R == NULL&&N->L != NULL)
 return Depth(N->L);
 else
 return  max(Depth(N->R),Depth(N->L));
 }
 int	CountLeaf(const BiTree *N)//ͳ�Ƹö�������Ҷ�ӽ��ĸ���
 {
 if (N->R == NULL&&N->L == NULL)
 return 1;
 if (N->R != NULL&&N->L == NULL)
 return CountLeaf(N->R);
 else if (N->R == NULL&&N->L != NULL)
 return CountLeaf(N->L);
 else
 return  CountLeaf(N->R)+ CountLeaf(N->L);
 }
 void InOrderTraverse(const BiTree *N)//�������������
 {
 if (N == NULL)return;

 InOrderTraverse(N->L);
 printf("%c", N->data);
 InOrderTraverse(N->R);
 }
 void PostOrderTraverse(const BiTree *N)//�������������
 {
 if (N == NULL)return;

 InOrderTraverse(N->L);
 InOrderTraverse(N->R);
 printf("%c", N->data);
 }
 void Clear(BiTree *n)
 {
 if (n->L != NULL)Clear(n->L);
 if (n->R != NULL)Clear(n->R);
 free(n);
 n = nullptr;
 }

 int main()
 {
 CreateBiTree(T);
 int d = Depth(T);
 printf("���Ϊ%d\n", d);
 int num = CountLeaf(T);
 printf("Ҷ�ӽ�����Ϊ%d\n", num);
 printf("���������");
 InOrderTraverse(T);
 printf("\n���������");
 PostOrderTraverse(T);
 printf("\n");
 Clear(T);
 return 0;
 }

/*
 */

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct BiTree
{
	char data;
	BiTree *L, *R;
	BiTree()  {}
};
int m = 0;
//std::vector<int> m{ 1,85,47,56,24,57,258,54,12,52,6,869 };
//�������������������һ�ö�����

void CreateBST(BiTree *&N,char &c)
{
	if (N == NULL)
	{	
		//BiTree*	n = new BiTree();
		BiTree* n = (BiTree*)malloc(sizeof(BiTree));
		n->data = c;
		m++;
		n->L = NULL;
		n->R = NULL;
		N = n;
	}
	else
	{
		if (N->data >c)	CreateBST(N->L,c);
		else if (N->data < c)	CreateBST(N->R,c);
		else { m++; return; }
	}
}

void InOrderTraverse(BiTree *N)//�������������
{
	if (N == NULL)return;

	InOrderTraverse(N->L);
	printf("%c", N->data);
	InOrderTraverse(N->R);
}
void Clear(BiTree *n)
{
	if (n->L != NULL)Clear(n->L);
	if (n->R != NULL)Clear(n->R);
	free(n);
	n = NULL;
}
BiTree *T;

int main()
{
	m = 0;
	int n = 0;
	scanf("%d", &n);
	while (m < n)
	{
		char c;
		scanf("%c", &c);
		CreateBST(T, c);
	}
	printf("���������");
	InOrderTraverse(T);
	printf("\n");
	Clear(T);
	return 0;
}
*/

/*#define MAX 7

 
 
 


/*#include<vector>
#include<iostream>
using namespace std;
//1097
//��һ�α�����ʱ�ˣ�
int main()
{
	int a, b;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		vector<int>m;
		if(a==0&&b==0)break;
		int c = a,d=a%10;
		m.push_back(c);
		for (int i = 0; i < b - 1; i++)
		{
			c = (c*d) % 10;
			if (c == m[0])
			{
				printf("%d\n",m[(b-1)%m.size()]);
				goto e;
			}
			m.push_back(c);
		}
		printf("%d\n", c);
	e:;
	}
	return 0;
}

*/
/*#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stdlib.h>
struct Node
{
	char data;
	Node *next, *parent;
Node(char data) :data(data), next(nullptr), parent(nullptr) {}
Node() :next(nullptr), parent(nullptr) {}
};
struct LinkList
{
	Node *begin, *end;
};
//��ʼ��
void Init(LinkList &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}
//���(����ͷ�ڵ�)
void Clear(Node *a)
{
	if (a == nullptr)return;
	if (a->next == nullptr)return;
	Clear(a->next);
	//delete a->next;
	free(a->next);
	a->next = nullptr;
}
bool isEmpty(LinkList &L)
{
	if (L.begin == L.end)return true;
	return false;
}
bool isBracket(char c)
{
	if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
		return true;
	return false;
}
bool PushList(LinkList &L, const char& c)
{
	//Խ����
	//if (!isBracket(c))return false;
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i == nullptr)
	{
		L.begin = (Node*)malloc(sizeof(Node));
		L.begin->data = c;
		//L.begin = new Node(c);
		L.begin->next = L.end;
		L.begin->parent = nullptr;
		return true;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != nullptr)
		i = i->next;
	i->next = (Node*)malloc(sizeof(Node));
	i->next->data = c;
	//i->next = new Node(c);
	auto child = i->next;
	child->parent = i;
	child->next = L.end;
	return true;
}
//�鿴���һ���ڵ�
char TopList(LinkList&L)
{
	if (L.begin == L.end) { printf("ջ�մ���"); return '\0'; }
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i->next == nullptr)
	{
		char c = L.begin->data;
		return c;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next->next != nullptr)
		i = i->next;

	char c = i->next->data;
	return c;
}

//ɾ�����һ���ڵ�
char PopList(LinkList&L)
{
	if (L.begin == L.end) { printf("ջ�մ���"); return '\0'; }
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i->next == nullptr)
	{
		char c = L.begin->data;
		delete i;
		i = nullptr;
		L.begin = L.end;
		return c;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next->next != nullptr)
		i = i->next;

	char c = i->next->data;
	delete i->next;
	i->next = L.end;
	return c;
}
//��ʾ����������Ԫ��
void ListPrint(LinkList &L)
{
	for (auto i = L.begin; i != L.end; i = i->next)
		printf("%c", i->data);
	printf("\n");
}
bool  Matching(LinkList &L,int n)
{
	LinkList S;
	Init(S);
	while (true)
	{
		char c;
		scanf("%c", &c);
		if (!isBracket(c))continue;
		n--;
		if (c == '[' || c == '{' || c == '(')
		{
			PushList(L, c);
		}
		else if (c == ']' || c == '}' || c == ')')
		{
			if(isEmpty(L))return false;
			auto m = PopList(L);
			if((c==']'&&m=='[')|| (c == ')'&&m == '(') ||  c == '}'&&m == '{' )
			{
				if (L.begin == L.end&&n==0)break;
			}
			else
			{
				return false;
			}
		}
	};
	return true;
}
//�ж��Ƿ�Ϊ��������
bool Pal(LinkList &L, int n)
{
	LinkList S;
		Init(S);
	while (n>0)
	{
		char c;
		scanf("%c", &c);
		if (c >= 'A'&&c <= 'Z')
			c -= ('A' - 'a');
		if (c >= 'a'&&c <= 'z')
		{
			PushList(S,c);
			n--;
			if (isEmpty(L))
			{
				PushList(L, c);
				continue;
			}
			char last = TopList(L);
			if (c == last)
			{
				PopList(L);
			}
			else
			{
				PushList(L,c);
			}
		}
	};
	
	ListPrint(S);
	if(isEmpty(L)) return true;
	else return false;
}
int  main()
{
	int N = 3;
	while (N--)
	{
		printf("\n\n��������Ҫ�������ŵĸ���");
		int n;
		scanf("%d", &n);
		LinkList L;
		Init(L);
		if (Matching(L, n))
		{
			printf("��ƥ������");
		}
		else
		{
			printf("����ƥ������");
		}
		Clear(L.begin);
		free(L.begin);
		//delete	L.begin;
		L.begin = nullptr;
	}
	return 0;
}
*/
/*#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stdlib.h>
struct Node
{
	char data;
	Node *next, *parent;
	Node(char data) :data(data), next(nullptr), parent(nullptr) {}
	Node() :next(nullptr), parent(nullptr) {}
};
struct LinkList
{
	Node *begin, *end;
};
void s(Node &a, Node &b)
{
	char c = a.data;
	a.data = b.data;
	b.data = c;
}
//��ʼ��
void Init(LinkList &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}
//���(����ͷ�ڵ�)
void Clear(Node *a)
{
	if (a == nullptr)return;
	if (a->next == nullptr)return;
	Clear(a->next);
	//delete a->next;
	free(a->next);
	a->next = nullptr;
}
bool PushList(LinkList &L, const char& c)
{
	//Խ����
	if (c<'A' || c>'Z')return false;
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i == nullptr)
	{
		L.begin = (Node*)malloc(sizeof(Node));
		L.begin->data = c;
		//L.begin = new Node(c);
		L.begin->next = L.end;
		return true;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != nullptr)
		i = i->next;
	i->next = (Node*)malloc(sizeof(Node));
	i->next->data = c;
	//i->next = new Node(c);
	auto child = i->next;
	child->parent = i;
	child->next = L.end;
	return true;
}
//ɾ��ǰһ���ڵ�
char PopList(LinkList&L)
{
	if (L.begin == L.end) { printf("ջ�մ���"); return '\0'; }
	char c = L.begin->data;
	auto i = L.begin->next;
	free(i->parent);
	//delete i->parent;
	i->parent = nullptr;
	L.begin = i;
	return c;
}
//������һ��������ͷ���ģ������������ڼ����ϰ�˳������26����дӢ����ĸA����Z������������ĸZ������ͷ���֮�󣻵�һ���������ĸA���ڵ������ĩβ��
void CreateList(LinkList &L, int n)
{
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf("%c", &c);
		if(!PushList(L, c))i--;
	}
}
// ԭ�����õ�������
void a(LinkList &L)
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
	// ֻ��һ��Ԫ�أ� ֱ�ӷ���
	Node *q = p->next;
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
//������ڵ������е�������ĸ��ǰ��n��λ��
void EncryptList(LinkList &L, int n)
{
	for (int i = 0; i < n; i++)
		PushList(L, PopList(L));
}
//��ʾ����������Ԫ��
void ListPrint(LinkList &L)
{
	for (auto i = L.begin; i != L.end; i = i->next)
		printf("%c", i->data);
	printf("\n");
}

int  main()
{
	LinkList L;
	int n;
	scanf("%d", &n);
	Init(L);
	CreateList(L, n);
	ListPrint(L);
	a(L);
	ListPrint(L);
	Clear(L.begin);
	free(L.begin);
	//delete	L.begin;
	L.begin = nullptr;
}*/


/*int main()
{
	float c = 1.568;
	printf("ԭʼ����%lf\nǿ��cpu�ɸ������Ĵ洢��Ԫ�����������ͣ�%d\n",c,*(int*)&c);
	return 0;
}
*/

/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double pairSum(double n)
{
	if (n < 2)return 1;
	return n*pairSum(n - 1);
}
int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		printf("%.2f\n", pairSum(n - 1) / pairSum(n));
	}
	return 0;
}


*/

/*
#define MAX 100
#include<deque>
#include<memory>
int hight[102][102];
int len[102][102];
int dir[4][2]={ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int maxpath = 0;
struct Node
{
	int x, y,max;
	Node& operator=(Node& a)
	{
		this->x = a.x;
		this->y = a.y;
		this->max = a.max;
		return *this;
	}
};
Node start;
int bfs(int y, int x)
{
	int max = 0;
	memset(hight, 0, sizeof(hight));
	memset(len, 0, sizeof(len));
	Node curr, pre;
	len[start.y][start.x] = 0;
	std::deque<Node> path;
	path.push_back(start);
	while (path.size() > 0)
	{
		pre = path[0];
		path.pop_front();

		for (int i = 0; i < 4; i++)
		{
			curr = pre;
			curr.x += dir[i][0];
			curr.y += dir[i][1];
			int k = len[pre.y][pre.x] + 1;
			//Խ��
			if (curr.x < 1 || curr.x > x || curr.y < 1 || curr.y > y)
				continue;
			if (len[curr.y][curr.x] >= k || hight[curr.y][curr.x] >= hight[pre.y][pre.x])
				continue;

			len[curr.y][curr.x] = k;
			if (k > max)max = k;
			curr.max = k;
			path.push_back(curr);
		}
	}
	return max;
}

int main()
{
	memset(hight, 0, sizeof(hight));

	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			scanf("%d", &hight[i][j]);
	}
	int h=hight[1][1];
	start.x = 1; start.y = 1;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (h < hight[i][j])
			{
				h = hight[i][j];
				start.x = j; start.y = i;
			}
	printf("%d", bfs(R,C));
	return 0;
}
*/


/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<stack>
#define MAXROAD 10000
//-1��ʾ��ͨ
int road[1002][1002];
bool visit[1002];
int num[1002];
int dij(int n)
{
	memset(visit, false, sizeof(visit));
	memset(num, MAXROAD, sizeof(num));
	std::stack<int> S;
	S.push(1);
	visit[1] = true;
	num[1] = 0;
	while (!S.empty())
	{
		int p = S.top(); S.pop();

		for (int i = 1; i <= n; i++)
		{
			if (road[p][i] != -1)
			{
				if (visit[i] != true)
				{
					S.push(i);
					num[i] = road[p][i] + num[p];
						visit[i] = true;
}

				else
				{
					if (num[i] > road[p][i] + num[p])
						num[i] = road[p][i] + num[p];
				}
			}
		}
	}
	return num[n];
}
int main()
{
	int N, M;
	dij(5);
while (scanf("%d %d", &N, &M) != EOF)
	{
		if (N == 0 && M == 0)break;

		memset(visit, false, sizeof(visit));
			for (int i = 0; i <=N; i++)
		memset(road[i], -1, sizeof(road[i]));
for (int i = 0; i < M; i++)
		{
			int A,B,V;
			scanf("%d %d %d", &A, &B, &V);
			road[A][B] = V;
		}
printf("%d\n", dij(N));
	}
	return 0;
}*/

/*

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stdlib.h>
struct Node
{
	char data;
	Node *next, *parent;
	Node(char data) :data(data), next(nullptr), parent(nullptr) {}
	Node() :next(nullptr), parent(nullptr) {}
};
struct LinkList
{
	Node *begin, *end;
};
//��ʼ��
void Init(LinkList &L)
{
	L.begin = nullptr;
	L.end = nullptr;
}
//���(����ͷ�ڵ�)
void Clear(Node *a)
{
	if (a == nullptr)return;
	if (a->next == nullptr)return;
	Clear(a->next);
	free(a->next);
	a->next = nullptr;
}
bool isEmpty(LinkList &L)
{
	if (L.begin == L.end)return true;
	return false;
}
bool isBrack(char c) { return '(' || ')' || '[' || ']' || '{' || '}'; }
bool PushList(LinkList &L, const char& c)
{
	if (!isBrack(c))return;
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i == nullptr)
	{
		L.begin = (Node*)malloc(sizeof(Node));
		L.begin->data = c;
		L.begin->next = L.end;
		L.begin->parent = nullptr;
		return true;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != nullptr)
		i = i->next;
	i->next = (Node*)malloc(sizeof(Node));
	i->next->data = c;
	auto child = i->next;
	child->parent = i;
	child->next = L.end;
	return true;
}
//�鿴���һ���ڵ�
char TopList(LinkList&L)
{
	if (L.begin == L.end) { printf("ջ�մ���"); return '\0'; }
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i->next == nullptr)
	{
		char c = L.begin->data;
		return c;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next->next != nullptr)
		i = i->next;
	char c = i->next->data;
	return c;
}
//ɾ�����һ���ڵ�
char PopList(LinkList&L)
{
	if (L.begin == L.end) { printf("ջ�մ���"); return '\0'; }
	auto i = L.begin;
	//ͷ�ڵ��ж�
	if (i->next == nullptr)
	{
		char c = L.begin->data;
		delete i;
		i = nullptr;
		L.begin = L.end;
		return c;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next->next != nullptr)
		i = i->next;
	char c = i->next->data;
	delete i->next;
	i->next = L.end;
	return c;
}
//��ʾ����������Ԫ��
void ListPrint(LinkList &L)
{
	for (auto i = L.begin; i != L.end; i = i->next)
		printf("%c", i->data);
	printf("\n");
}


//�ж��Ƿ�Ϊ��������
bool Matching(LinkList &L, int n)
{
	LinkList S;
	Init(S);
	while (n>0)
	{
		char c;
		scanf("%c", &c);
		if (!isBrack(c))continue;
		if (isBrack(c))
		{
			PushList(S, c);
			n--;
			if (isEmpty(L))
			{
				PushList(L, c);
				continue;
			}
			char last = TopList(L);
			if ( true)
			{
				PopList(L);
			}
			else
			{
				PushList(L, c);
			}
		}
	};
	ListPrint(S);
	if (isEmpty(L)) return true;
	else return false;
}
int  main()
{
	int N = 3;
	while (N--)
	{
		printf("\n\n��������Ҫ������ĸ�ĸ���");
		int n;
		scanf("%d", &n);
		LinkList L;
		Init(L);
		if (Pal(L, n))
		{
			printf("�ǻ�������");
		}
		else
		{
			printf("���ǻ�������");
		}
		Clear(L.begin);
		free(L.begin);
		//delete	L.begin;
		L.begin = nullptr;
	}
	return 0;
}
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct Node
{
	char data;
	Node *next, *parent;
};
struct	LinkList
{
	Node *begin, *end;
};

//��ʼ��
void Init(LinkList &L)
{
	L.begin = NULL;
	L.end = NULL;
}
//���(����ͷ�ڵ�)
void Clear(Node *a)
{
	if (a == NULL)return;
	if (a->next == NULL)return;
	Clear(a->next);
	free(a->next);
	a->next = NULL;
}
void PushList(LinkList &L, char c)
{
	//Խ����
	if (c<'A' || c>'Z')return;
	Node* i = L.begin;
	//ͷ�ڵ��ж�
	if (i == NULL)
	{
		L.begin = (Node*)malloc(sizeof(Node));
		L.begin->next = L.end;
		return;
	}
	//Ѱ��һ�����ӽڵ��ǿյĽڵ��������
	while (i->next != NULL)
		i = i->next;
	i->next = (Node*)malloc(sizeof(Node));
	Node* child = i->next;
	child->parent = i;
	child->next = L.end;
}
//ɾ��ǰһ���ڵ�
char PopList(LinkList&L)
{
	if (L.begin == L.end) { printf("ջ�մ���"); return '\0'; }
	char c = L.begin->data;
	Node* i = L.begin->next;
	free(i->parent);
	L.begin = i;
	return c;
}
//������һ��������ͷ���ģ������������ڼ����ϰ�˳������26����дӢ����ĸA����Z������������ĸZ������ͷ���֮�󣻵�һ���������ĸA���ڵ������ĩβ��
void CreateList(LinkList &L, int n)
{
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf("%c", &c);
		PushList(L, c);
	}
}

void LinkList_reverse(LinkList &L)
{
	if (L.begin  == NULL)		return;
	Node* reverse= NULL;
	Node* node = L.begin;
	Node* pre = NULL;
	while (node != NULL)
	{
		Node* next =node->next;
		if (next == NULL)
		{
			reverse= node;
		}
		node->next = pre;
		pre = node;
		node = next;
	}
	L.begin = reverse;
}  
//��ʾ����������Ԫ��
void ListPrint(LinkList &L)
{
	for (auto i = L.begin; i != L.end; i = i->next)
		printf("%c", i->data);
	printf("\n");
}

int  main()
{
	LinkList L;
	int n;
	scanf("%d", &n);
	Init(L);
	CreateList(L, n);
	ListPrint(L);
	LinkList_reverse(L);
	ListPrint(L);
	Clear(L.begin);
	free(L.begin);
	L.begin = NULL;
	return 0;
}*/