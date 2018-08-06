#define MAX_CHAR 400
#include<fstream>
#include<cstdio>
using namespace std;
const int inf = 65535;
char m[MAX_CHAR][MAX_CHAR];
typedef struct arcnode
{///存边
	int adjvex;
	int weight;
	arcnode *nextarc;///指向下一条边的指针
}arcnode;

typedef struct vnode
{///存点
	int data;
	arcnode *firstarc;
}vnode, Adjvex[20];

typedef struct ALGraph
{
	int vexnum, arcnum;///节点数 和 边数
	Adjvex vertices;///存放图中节点信息的数组
};
int getint(char *b,int v)
{
	for (int i = 0; i < v; i++)
		if (strcmp(m[i], b) == 0)return i;
	return -1;
}
int LocateVex(ALGraph G, int u) 
{
	for (int i = 0; i < G.vexnum; i++) 
	{
		if (G.vertices[i].data == u)
			return i;
	}
	return 0;
}
//存各节点的最小权值信息
typedef struct Minimum 
{
	int data;      
	int lowcost;
	int flag;
}Minimum, closedge[20];
char* filename = "E:\\MST.txt";

void CreateGraph(ALGraph &G)
{
	int w;
	arcnode *p, *q;
	std::fstream f(filename);
	char buff[MAX_CHAR];
	f.getline(buff, MAX_CHAR);
	sscanf(buff, "%d,%d", &G.vexnum, &G.arcnum);
	for (int i = 0; i<G.vexnum; i++) 
	{
		f.getline(buff,MAX_CHAR);
		strcpy(m[i], buff);
		G.vertices[i].data=i;
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i<G.arcnum; i++) 
	{
		p = new arcnode;
		q = new arcnode;
		if (p == NULL || q == NULL) 
		{
			return;
		}
		int k, j;
		f >> buff;
		k = getint(buff,G.vexnum);
		f >> buff;
		j = getint(buff, G.vexnum);
		f >> w;
		p->nextarc = G.vertices[k].firstarc;
		q->nextarc = G.vertices[j].firstarc;
		G.vertices[k].firstarc = p;
		p->weight = w;///e.cost
		p->adjvex = j;///相当于之前写的 e.to
		G.vertices[j].firstarc = q;
		q->weight = w;
		q->adjvex = k;
	}
}
//获得最短边
int minimum(ALGraph G, closedge MinEdge) 
{
	int first;
	int k;
	int i;
	int min;
	for (i = 0; i<G.vexnum; i++) 
	{
		if (MinEdge[i].lowcost != 0)
		{
			min = MinEdge[i].lowcost;
			first = i;
			break;
		}
	}
	k = i;
	for (i = first; i<G.vexnum; i++)
	{
		if (min>MinEdge[i].lowcost && MinEdge[i].lowcost != 0)
		{
			min = MinEdge[i].lowcost;
			k = i;
		}
	}
	return k;
}
//最小生成树
int MinSpanTree(ALGraph G, int u)
{
	int ans = 0;
	arcnode *p;
	closedge MinEdge;
	int k = LocateVex(G, u);
	for (int i = 0; i<G.vexnum; i++)
		MinEdge[i].flag = 0;
	for (int i = 0; i<G.vexnum; i++) 
	{
		if (i != k) 
		{
			MinEdge[i].data = u;
			for (p = G.vertices[i].firstarc; p != NULL; p = p->nextarc) 
			{
				if (p->adjvex == k)
				{
					MinEdge[i].lowcost = p->weight;
					MinEdge[i].flag = 1;
				}
				else if (MinEdge[i].flag == 0) 
				{
					MinEdge[i].lowcost = inf;
				}
			}
		}
		MinEdge[k].data = G.vertices[k].data;
		MinEdge[k].lowcost = 0;
	}
	for (int i = 1; i<G.vexnum; i++) 
	{
		k = minimum(G, MinEdge);
		printf("%s %s %d\n",m[G.vertices[k].data],m[ MinEdge[k].data], MinEdge[k].lowcost);
		ans += MinEdge[k].lowcost;
		MinEdge[k].lowcost = 0; 
		//将结点加入U中
		for (p = G.vertices[k].firstarc; p != NULL; p = p->nextarc)
		{
			if (MinEdge[p->adjvex].lowcost>p->weight)
			{
				MinEdge[p->adjvex].lowcost = p->weight;
				MinEdge[p->adjvex].data = G.vertices[k].data;
			}
		}
	}
	return ans;
}


