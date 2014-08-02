/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define REP(n) for(int i=0;i<n;i++)
using namespace std;
int n[100001];
int N,K;
bool bs(int k)
{
	int l=0,r=N+1;
	int mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(n[mid]>=k) r=mid;
		else l=mid;
	}
	if(n[r]==k) return true;
	else return false;
}
int main()
{
	scanf("%d%d",&N,&K);
	REP(N) scanf("%d",n+i);
	sort(n,n+N);
	int ans=0;
	REP(N) if(bs(n[i]+K)) ans++;
	printf("%d\n",ans);
	return 0;
}
