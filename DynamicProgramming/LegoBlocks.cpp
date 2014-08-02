#include<iostream>
#include<string.h>
#define MOD 1000000007
using namespace std;

long long dp1[1001];
long long dp2[1001];
long long dp3[1001];
int T,N,M;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));

		dp1[0]=1;
		for(int i=0;i<=M;i++)
			for(int j=1;j<=4;j++)
				if(i+j<=M) dp1[i+j]=(dp1[i+j]+dp1[i])%MOD;
/*puts("dp1---\n");
for(int i=0;i<=M;i++)
	printf("%d ",dp1[i]);
printf("\n"); */

		for(int i=1;i<=M;i++)
		{
			dp2[i]=dp3[i]=1;
			for(int j=0;j<N;j++) dp2[i]=(dp2[i]*dp1[i])%MOD;
			dp3[i]=dp2[i];
			
			int sub=0;

			for(int j=1;j<i;j++) sub=(sub+dp2[j]*dp3[i-j])%MOD;

			dp2[i]=(dp2[i]-sub)%MOD;
			if(dp2[i]<0) dp2[i]+=MOD;

		}

		printf("%lld\n",dp2[M]);

	}
	return 0;
}
