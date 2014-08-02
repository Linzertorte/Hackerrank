/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<stdio.h>
#include<string.h>
#define REP(n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&(n))
#define inf 0x7f7f7f7f
using namespace std;
int M,N;
int g[105][105];
int cnt[105];
int ans;
void dfs(int u,int f)
{
	cnt[u]++;
	for(int v=1;v<=N;v++)
		if(v!=f&&g[u][v]) dfs(v,u),cnt[u]+=cnt[v];
	for(int v=1;v<=N;v++)
		if(v!=f&&g[u][v]) if(!(cnt[v]%2)) ans++;

}
int main()
{
	read(N),read(M);
	int u,v;
	REP(M) read(u),read(v), g[u][v]=g[v][u]=1;
	
	dfs(1,0);
/*for(int i=1;i<=N;i++)
	printf("%d ",cnt[i]);*/
	printf("%d\n",ans);

	return 0;
}
