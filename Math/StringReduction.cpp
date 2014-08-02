/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<stdio.h>
#include<string.h>
#define REP(n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&(n))
#define inf 0x7f7f7f7f
using namespace std;
char str[105];
int dp[101][101][3];
int mk[101][101];
void compute(int s,int t)
{
	if(mk[s][t]) return;
	mk[s][t]=1;
	if(s+1==t) 
	{
		dp[s][t][str[s]-'a']=1;
		return;
	}
	for(int i=s+1;i<t;i++)
		compute(s,i),compute(i,t);
	for(int i=s+1;i<t;i++)
		//a
		//b
		//c
	{
		if(dp[s][i][0]!=inf&&dp[i][t][0]!=inf) dp[s][t][0]=min(dp[s][t][0],dp[s][i][0]+dp[i][t][0]);
		if(dp[s][i][1]!=inf&&dp[i][t][2]!=inf&&dp[s][i][1]%2&&dp[i][t][2]%2) dp[s][t][0]=1;
		if(dp[s][i][2]!=inf&&dp[i][t][1]!=inf&&dp[s][i][2]%2&&dp[i][t][1]%2) dp[s][t][0]=1;


		
		if(dp[s][i][1]!=inf&&dp[i][t][1]!=inf) dp[s][t][1]=min(dp[s][t][1],dp[s][i][1]+dp[i][t][1]);
		if(dp[s][i][0]!=inf&&dp[i][t][2]!=inf&&dp[s][i][0]%2&&dp[i][t][2]%2) dp[s][t][1]=1;
		if(dp[s][i][2]!=inf&&dp[i][t][0]!=inf&&dp[s][i][2]%2&&dp[i][t][0]%2) dp[s][t][1]=1;
			
			
		if(dp[s][i][2]!=inf&&dp[i][t][2]!=inf) dp[s][t][2]=min(dp[s][t][2],dp[s][i][2]+dp[i][t][2]);
		if(dp[s][i][1]!=inf&&dp[i][t][0]!=inf&&dp[s][i][1]%2&&dp[i][t][0]%2) dp[s][t][2]=1;
		if(dp[s][i][0]!=inf&&dp[i][t][1]!=inf&&dp[s][i][0]%2&&dp[i][t][1]%2) dp[s][t][2]=1;
		


		if((dp[s][i][0]!=inf)&&((dp[i][t][1]!=inf&&dp[i][t][1]%2==0)||(dp[i][t][2]!=inf&&dp[i][t][2]%2==0))) 
			dp[s][t][0]=min(dp[s][t][0],dp[s][i][0]);
		if((dp[i][t][0]!=inf)&&((dp[s][i][1]!=inf&&dp[s][i][1]%2==0)||(dp[s][i][2]!=inf&&dp[s][i][2]%2==0))) 
			dp[s][t][0]=min(dp[s][t][0],dp[i][t][0]);

		if((dp[s][i][1]!=inf)&&((dp[i][t][0]!=inf&&dp[i][t][0]%2==0)||(dp[i][t][2]!=inf&&dp[i][t][2]%2==0))) 
			dp[s][t][1]=min(dp[s][t][1],dp[s][i][1]);

		if((dp[i][t][1]!=inf)&&((dp[s][i][0]!=inf&&dp[s][i][0]%2==0)||(dp[s][i][2]!=inf&&dp[s][i][2]%2==0))) 
			dp[s][t][1]=min(dp[s][t][1],dp[i][t][1]);

		
		if((dp[s][i][2]!=inf)&&((dp[i][t][0]!=inf&&dp[i][t][0]%2==0)||(dp[i][t][1]!=inf&&dp[i][t][1]%2==0))) 
			dp[s][t][2]=min(dp[s][t][2],dp[s][i][2]);

		if((dp[i][t][2]!=inf)&&((dp[s][i][0]!=inf&&dp[s][i][0]%2==0)||(dp[s][i][1]!=inf&&dp[s][i][1]%2==0))) 
			dp[s][t][2]=min(dp[s][t][2],dp[i][t][2]);


	}

}
int main()
{
	int T,n;
	read(T);
	while(T--)
	{
		scanf("%s",str);
		n=strlen(str);
		memset(mk,0,sizeof(mk));
		memset(dp,0x7f,sizeof(dp));
		compute(0,n);
		/*(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++)
				{
					compute(i,j);
					printf("(%d,%d)",i,j);
					for(int k=0;k<3;k++)
						printf("%d ",dp[i][j][k]);
					puts("");
				}*/
			
		printf("%d\n",min(dp[0][n][0],min(dp[0][n][1],dp[0][n][2])));
	}
}
