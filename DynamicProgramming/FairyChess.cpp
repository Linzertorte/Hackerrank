#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int MOD = 1000000007;
int T,S,N,M;
char bd[300][300];
int dp[200][200][201];
int sum[200][200][201];
int l[200][200],r[200][200];
int getS(int x,int y,int k)
{   
	int res=0;
	for(int i=max(0,x-S);i<=min(N-1,x+S);i++)
	{
		int l=S-abs(x-i);
		for(int j=max(0,y-l);j<=min(N-1,y+l);j++)
			res=(res+dp[i][j][k])%MOD;
	}
	return res;
}
bool check(int x)
{
	return (x>=0 && x<N);
}
int getL(int i1,int j1,int i2,int j2)
{


	int sub=0;
	if(check(i1-1)&&check(j1+1)) sub=l[i1-1][j1+1];
	int sum=0;
	if(check(i2) && check(j2)) sum=l[i2][j2];
	else if(i2+j2>=0 && i2+j2<=N-1) sum=l[i2+j2][0];
	else if(i2+j2>N-1 && i2+j2<=2*N-2) sum=l[N-1][i2+j2-N+1];
	
	sum-=sub;
	if(sum<0) sum+=MOD;
	return sum;


}
int getR(int i1,int j1,int i2,int j2)
{
	int sub=0;
	if(check(i1-1) && check(j1-1)) sub=r[i1-1][j1-1];

	int sum=0;
	
	if(check(i2) && check(j2)) sum=r[i2][j2];
	else if(j2-i2>=1-N && j2-i2<=0) sum=r[N-1][j2-i2+N-1];
	else if(j2-i2>0 && j2-i2<= N-1) sum=r[N-1-j2+i2][N-1];

	sum-=sub;
	if(sum<0) sum+=MOD;
	return sum;

}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d\n",&N,&M,&S);
		for(int i=0;i<N;i++)
			scanf("%s",bd[i]);
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(bd[i][j]=='L') dp[i][j][0]=1;
		for(int k=1;k<=M;k++)
		{
			memset(l,0,sizeof(l));
			memset(r,0,sizeof(r));
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
				{
					if(!i || j==N-1) l[i][j]=dp[i][j][k-1];
					else l[i][j]=(dp[i][j][k-1]+l[i-1][j+1])%MOD;
					if(!i || !j) r[i][j]=dp[i][j][k-1];
					else r[i][j]=(dp[i][j][k-1]+r[i-1][j-1])%MOD;
				}
			sum[0][0][k]=getS(0,0,k-1);
			if(bd[0][0]!='P') dp[0][0][k]=sum[0][0][k];

			for(int i=1;i<N;i++)
			{
				//sum[i][0][k]=sum[i-1][0][k];

				sum[i][0][k]=sum[i-1][0][k];

				sum[i][0][k]-=getL(i-1-S,0,i-1,-S);
				if(sum[i][0][k]<0) sum[i][0][k]+=MOD;
				sum[i][0][k]%=MOD;

				sum[i][0][k]+=getL(i,S,i+S,0);

				if(sum[i][0][k]<0) sum[i][0][k]+=MOD;
				sum[i][0][k]%=MOD;
				
				sum[i][0][k]-=getR(i-1-S,0,i-1,S);

				if(sum[i][0][k]<0) sum[i][0][k]+=MOD;
				sum[i][0][k]%=MOD;

				sum[i][0][k]+=getR(i,-S,i+S,0);
				if(sum[i][0][k]<0) sum[i][0][k]+=MOD;
				sum[i][0][k]%=MOD;

				if(i-1-S>=0)
					sum[i][0][k]=(sum[i][0][k]+dp[i-1-S][0][k-1])%MOD;
					 
				if(i+S<=N-1)
				{
					sum[i][0][k]-=dp[i+S][0][k-1];
					if(sum[i][0][k]<0) sum[i][0][k]+=MOD;
				}


				
				
				if(bd[i][0]!='P') dp[i][0][k]=sum[i][0][k];

			}
			for(int i=0;i<N;i++)
				for(int j=1;j<N;j++)
				{
					sum[i][j][k]=sum[i][j-1][k];
					
					sum[i][j][k]-=getL(i-S,j-1,i,j-1-S);
					if(sum[i][j][k]<0) sum[i][j][k]+=MOD;
					sum[i][j][k]%=MOD;
					
					sum[i][j][k]+=getL(i,j+S,i+S,j);
					if(sum[i][j][k]<0) sum[i][j][k]+=MOD;
					sum[i][j][k]%=MOD;

					sum[i][j][k]-=getR(i,j-S-1,i+S,j-1);
					if(sum[i][j][k]<0) sum[i][j][k]+=MOD;
					sum[i][j][k]%=MOD;
					
					
					sum[i][j][k]+=getR(i-S,j,i,j+S);
					if(sum[i][j][k]<0) sum[i][j][k]+=MOD;
					sum[i][j][k]%=MOD;

					if(j-1-S>=0)
					sum[i][j][k]=(sum[i][j][k]+dp[i][j-1-S][k-1])%MOD;
					 
					if(j+S<=N-1)
					{
						sum[i][j][k]-=dp[i][j+S][k-1];
						if(sum[i][j][k]<0) sum[i][j][k]+=MOD;
					}

					if(bd[i][j]!='P') dp[i][j][k]=sum[i][j][k];
				}



		}
 /*       for(int k=0;k<=M;k++)
        {
            printf("K=%d\n",k);
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                    printf("%d ",dp[i][j][k]);
                printf("\n");
            }
            printf("\n");
        }*/
		
		int res=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				res=(res+dp[i][j][M])%MOD;
		printf("%d\n",res);
	}
	return 0;
}
