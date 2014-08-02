#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int T,N;
long long P[50000];
bool peak[50000];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%lld",P+i);
		memset(peak,0,sizeof(peak));
		int ptr=N-1;
		for(int i=N-1;i>=0;i--)
			if(P[i]>=P[ptr])
			{
				ptr=i;
				peak[ptr]=true;
			}
		long long subtot=0;
		int cnt=0;
		long long total=0;

		for(int i=0;i<N;i++)
		if(peak[i])
		{
			total+=cnt*P[i]-subtot;
			subtot=cnt=0;
		}
		else
		{
			subtot+=P[i];
			cnt++;
		}
		printf("%lld\n",total);
	}
	return 0;
}
