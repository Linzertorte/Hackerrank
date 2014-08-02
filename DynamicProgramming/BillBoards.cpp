//???
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#define MAX 150000
 
using namespace std;
 
typedef struct
{
	int l,r,fix;
	long long key;
}node;
 
class treap
{
public:
	node p[MAX];
	int size,root;
	treap()
	{
		srand(time(0));
		size=-1;
		root=-1;
	}
 
	void rot_l(int &x)
	{
		int y=p[x].r;
		p[x].r=p[y].l;
		p[y].l=x;
		x=y;
	}
 
	void rot_r(int &x)
	{
		int y=p[x].l;
		p[x].l=p[y].r;
		p[y].r=x;
		x=y;
	}
 
	void insert(int &k,long long tkey)
	{
		if (k==-1)
		{
			k=++size;
			p[k].l=p[k].r=-1;
			p[k].key=tkey;
			p[k].fix=rand();
		}
		else
		if (tkey<p[k].key)
		{
			insert(p[k].l,tkey);
			if (p[ p[k].l ].fix>p[k].fix)
				rot_r(k);
		}
		else
		{
			insert(p[k].r,tkey);
			if (p[ p[k].r ].fix>p[k].fix)
				rot_l(k);
		}
 
	}
 
	void remove(int &k,long long tkey)
	{
		if (k==-1) return;
		if (tkey<p[k].key)
			remove(p[k].l,tkey);
		else if (tkey>p[k].key)
			remove(p[k].r,tkey);
		else
		{
			if (p[k].l==-1 && p[k].r==-1)
				k=-1;
			else if (p[k].l==-1)
				k=p[k].r;
			else if (p[k].r==-1)
				k=p[k].l;
			else
			if (p[ p[k].l ].fix < p[ p[k].r ].fix)
			{
				rot_l(k);
				remove(p[k].l,tkey);
			}
			else
			{
				rot_r(k);
				remove(p[k].r,tkey);
			}
		}
	}
 
	long long getMax(int k)
	{
		if(k==-1) return 0;
		if (p[k].r==-1) return p[k].key;
		return getMax(p[k].r);
	}
};
 
treap T;
int N,K;
long long P[100000];
long long Que[100000]; 
int main()
{
 
	long long total=0LL;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%lld",P+i),total+=P[i];
	K++;
	int h=0,t=K-1;
	for(int i=0;i<K;i++)
	{
		Que[i]=0LL;
		T.insert(T.root,0LL);
	}
	for(int i=0;i<N;i++)
	{
		long long key=Que[h];
		h=(h+1)%K;
		long long newMax=T.getMax(T.root);
		Que[t=((t+1)%K)]=newMax-P[i];
		T.insert(T.root,newMax-P[i]);
		T.remove(T.root,key);
/*printf("%d----\n",i+1);
for(int j=0;j<K;j++) printf("%lld ",Que[(h+j)%K]);
printf("\n");
*/
	}
	printf("%lld\n",total+T.getMax(T.root));
	return 0;
}
