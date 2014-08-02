
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define REP(n) for(int i=0;i<n;i++)
using namespace std;
int N,K;
int c[100];
int main()
{
	scanf("%d%d",&N,&K);
	REP(N) scanf("%d",c+i);
	sort(c,c+N);
	int k=1,cnt=0;
	long long cost=0;
	for(int i=N-1;i>=0;i--)
	{
		cnt+=1;
		cost+=k*c[i];
		if(cnt==K) k++,cnt=0;
	}
	printf("%lld\n",cost);
	return 0;
}

