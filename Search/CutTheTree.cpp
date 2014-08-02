//sum of subtree
//sum of all node
//traverse the tree twice
#include<iostream>
#include<vector>
#include<limits.h>
#include<stdlib.h>
using namespace std;
const int N = 100000;
vector<int> adj[N];
int n;
int val[N];
int subtree_sum[N];
void dfs1(int u,int f){
    int v;
    subtree_sum[u]=val[u];
    for(int i=0;i<adj[u].size();i++){
        v = adj[u][i];
        if(v!=f) dfs1(v,u),subtree_sum[u]+=subtree_sum[v];
    }
}

int main(){
    int u,v;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",val+i);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0,-1);
    int m = INT_MAX;
    for(int i=1;i<n;i++)
        m=min(m,abs(subtree_sum[0]-2*subtree_sum[i]));
    printf("%d\n",m);
    return 0;
    
}
