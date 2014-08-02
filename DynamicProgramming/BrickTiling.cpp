#include<iostream>
#include<string.h>
using namespace std;
int T,N,M;
char grid[21][10];
const int MOD = 1000000007;
int dp[21][1<<16];
inline int getBit(int x,int i)
{
	return (x>>2*i)%4;
}
inline int setBit(int x,int i,int v)
{
	int v2=getBit(x,i);
	if(v>=v2) return x+((v-v2)<<2*i);
	else return x-((v2-v)<<2*i);
}
void print(int s)
{
	for(int i=0;i<M;i++)
		if(getBit(s,i)==0||getBit(s,i)==2) printf("@");
		else printf("#");
	printf("\n");
	for(int i=0;i<M;i++)
		if(getBit(s,i)<2) printf("@");
		else printf("#");
	printf("\n");
	printf("\n");
}
void dfs(int c,int s1,int s2,int j,int cnt)
{

//printf("----in row %d column %d\n",c,j);
//print(s1);
//print(s2);

/*TODO*/

// Four brick,  @@#  #@@   ##   ##
//				###  ###   @#   #@
//						   @#	#@

	if(j==M)
	{
		for(int i=0;i<M;i++)
			if(getBit(s1,i)==0 || getBit(s1,i)==2) return;
		dp[c+1][s2]=(dp[c+1][s2]+cnt)%MOD;
//printf("computed %d\n",dp[c+1][s2]);
//print(s2);
		return;
	}
	if(j>=1)  // the last two bricks
	{
		if(grid[c+1][j]!='#')
		{
		// s1 j-1 ?? s1 j=0 
			if((getBit(s1,j-1)==0 ||getBit(s1,j-1)==2) && !getBit(s1,j))
				dfs(c,s1+(1<<(2*j-2))+(3<<(2*j)),s2+(3<<(2*j)),j+1,cnt);

			// last brick
			if(!getBit(s1,j-1)&&!getBit(s2,j-1) &&(!getBit(s1,j) ||getBit(s1,j)==2 ))
			{
				if(!getBit(s1,j))
				dfs(c,s1+(3<<(2*j-2))+(1<<(2*j)),s2+(3<<(2*j-2))+(0<<(2*j)),j+1,cnt);
				else 
				dfs(c,s1+(3<<(2*j-2))+(1<<(2*j)),s2+(3<<(2*j-2))+(1<<(2*j)),j+1,cnt);


			}
		}
		else {
			// last brick
			if(!getBit(s1,j-1)&&!getBit(s2,j-1) &&(!getBit(s1,j) ||getBit(s1,j)==2 ))
			{
				if(!getBit(s1,j))
				dfs(c,s1+(3<<(2*j-2))+(1<<(2*j)),s2+(3<<(2*j-2))+(2<<(2*j)),j+1,cnt);
				else 
				dfs(c,s1+(3<<(2*j-2))+(1<<(2*j)),s2+(3<<(2*j-2))+(3<<(2*j)),j+1,cnt);
			}
		}
	}





	if(j>=2){     //|--
		if(!getBit(s2,j-2) && (!getBit(s2,j-1)||getBit(s2,j-1)==2) &&getBit(s1,j)<2) //can lay
		{
			//new state   s1  j-2 ->+2  j-1 ->+2  j->+2  
			//			  s2  j-2 ->3   j-1 ->+1  . ->1  #->3
			if(grid[c+1][j]=='#') dfs(c,s1+(2<<(2*j-4))+(2<<(2*j-2))+(2<<(2*j)),s2+(3<<(2*j-4))+(1<<(2*j-2))+(3<<(2*j)),j+1,cnt);
			else dfs(c,s1+(2<<(2*j-4))+(2<<(2*j-2))+(2<<(2*j)),s2+(3<<(2*j-4))+(1<<(2*j-2))+(1<<(2*j)),j+1,cnt);
		}
		if(grid[c+1][j]!='#')
		{
			//s2 j-2 <2  j-1 <2  
			//s1 j <2 
			if(getBit(s2,j-2)<2&&getBit(s2,j-1)<2 && getBit(s1,j)<2)
				dfs(c,s1+(2<<(2*j)),s2+(2<<(2*j-4))+(2<<(2*j-2))+(3<<(2*j)),j+1,cnt);
			// s2 j-2 0  ->3  s1 j-2 ->+2
			// s2 j-1 <2 ->+2
			if(!getBit(s2,j-2) && getBit(s2,j-1)<2)
			{
				if(getBit(s1,j)<2)
				dfs(c,s1+(2<<(2*j-4)),s2+(3<<(2*j-4))+(2<<(2*j-2))+(2<<(2*j)),j+1,cnt);
				else 
				dfs(c,s1+(2<<(2*j-4)),s2+(3<<(2*j-4))+(2<<(2*j-2))+(3<<(2*j)),j+1,cnt);
			}
		}

	}
	// not laying any brik
	if(grid[c+1][j]=='#') {// 3 or 2
		if(getBit(s1,j)==3||getBit(s1,j)==2) dfs(c,s1,s2+(3<<2*j),j+1,cnt);
		else dfs(c,s1,s2+(2<<2*j),j+1,cnt);
	}
	else 
	{
		if(getBit(s1,j)==3||getBit(s1,j)==2) dfs(c,s1,s2+(1<<2*j),j+1,cnt);
		else dfs(c,s1,s2,j+1,cnt);       // not laying

		if(j>=1)
		{
			if(getBit(s2,j-1)<=1&&getBit(s1,j)==0){
								   //_| 
				dfs(c,s1+(3<<2*j),s2+(2<<(2*j-2))+(3<<(2*j)),j+1,cnt);
			}
			if(getBit(s2,j-1)==0 && getBit(s1,j-1)==0)
			{
				// |_
				if(getBit(s1,j)<2)
				dfs(c,s1+(3<<(2*j-2)),s2+(3<<(2*j-2))+( 2<<(2*j)),j+1,cnt);
				else dfs(c,s1+(3<<(2*j-2)),s2+(3<<(2*j-2))+( 3<<(2*j)),j+1,cnt);

			}

		}
		if(j>=2)
		{
			if( (getBit(s2,j-2)==0||getBit(s2,j-2)==2) &&(getBit(s2,j-1)==0||getBit(s2,j-1)==2) && getBit(s1,j)<2)
				//-|
				dfs(c,s1+(2<<(2*j-4))+(2<<(2*j-2))+(2<<(2*j)),s2+(1<<(2*j-4))+(1<<(2*j-2))+(3<<(2*j)),j+1,cnt);
		}

	}

	
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d\n",&N,&M);
		for(int i=1;i<=N;i++)
		scanf("%s",grid[i]);
		memset(dp,0,sizeof(dp));
		dp[0][(1<<2*M)-1]=1;
		for(int i=0;i<N;i++)
			for(int s=0;s<(1<<2*M);s++)
				if(dp[i][s])
				{
					dfs(i,s,0,0,dp[i][s]);
				}
		printf("%d\n",dp[N][(1<<2*M)-1]);
	}
}
