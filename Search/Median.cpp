#include<iostream>
#include<stdio.h>

using namespace std;
const int inf=~0U>>1;
class treap
{
	struct node
	{
		int value,key,size,cnt;
		node(int v,node*n):value(v)
		{c[0]=c[1]=n;size=1;key=rand()-1;cnt=1;}
		void rz(){size=c[0]->size+c[1]->size+cnt;}
		node*c[2];
	}*root,*null;
	void rot(node*&t,bool d)
	{
		node*cc=t->c[d];
		t->c[d]=cc->c[!d];
		cc->c[!d]=t;
		t->rz();cc->rz();
		t=cc;
	}
	void insert(node*&t,int x)
	{
			if(t==null)	{t=new node(x,null);return;}
			if(x==t->value) {
				t->cnt++;
				t->rz();
				return;
			}
			bool d=x>t->value;
			insert(t->c[d],x);
			if(t->c[d]->key<t->key)
				rot(t,d);
			else
				t->rz();
	}
	bool Delete(node*&t,int x)
	{
		   if(t==null) return false;
		   if(t->value==x&&t->cnt>1)
		   {
			   t->cnt--;
			   t->rz();
			   return true;
		   }
		   if(t->value==x)
			{
				bool d=t->c[1]->key<t->c[0]->key;
				if(t->c[d]==null)
				{
					delete t;
					t=null;
					return true;
				}
				rot(t,d);
				if(!Delete(t->c[!d],x))return false;
                                t->rz();
			}
			else
			{
				bool d=x>t->value;
				if(!Delete(t->c[d],x))return false;
                                t->rz();
			}
			t->rz();
			return true;
	}
	int select(node*t,int k)
	{
		int r=t->c[0]->size;
		if(k>=r+1&&k<=r+t->cnt) return t->value;
		else if(k<=r) return select(t->c[0],k);
		else return select(t->c[1],k-r-t->cnt);
	}
	
	public:
	treap()
	{
		null=new node(0,0);null->size=0;null->key=inf,null->cnt=0;
		root=null;
	}
	void ins(int x)
	{
		insert(root,x);
	}
	int sel(int k)
	{
		if(k>root->size) return -inf;
		return select(root,k);
	}
	
	bool del(int x)
	{
		return Delete(root,x);
	}	
}T;
int main()
{
	//freopen("in","r",stdin);
	int m;
	cin>>m;
	char t;
	int x;
	int cnt=0;
	while(m--)
	{
		cin>>t>>x;
		switch(t)
		{
			case 'a':T.ins(x);
				cnt++;
				if(cnt%2) printf("%d\n",T.sel((1+cnt)/2));
				else 
				{
						long long tmp=(long long)T.sel(cnt/2)+(long long)T.sel(cnt/2+1);
						if(((tmp/2)*2)==tmp) printf("%lld\n",tmp/2);
						else printf("%.1f\n",(double)tmp/2.0);
				}
				break;
			case 'r':if(!T.del(x)) printf("Wrong!\n");
					 else {
						 cnt--;
						 if(!cnt) printf("Wrong!\n");
						 else {
							if(cnt%2) printf("%d\n",T.sel((1+cnt)/2));
							else 
								{
								long long tmp=(long long)T.sel(cnt/2)+(long long)T.sel(cnt/2+1);
						if(((tmp/2)*2)==tmp) printf("%lld\n",tmp/2);
						else printf("%.1f\n",(double)tmp/2.0);
							}
						 }
					 }
				break;
			
		}		
	}
}
