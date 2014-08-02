#include<iostream>
#include<string.h>
using namespace std;
int N,M,K;
char board[52][60];
int dp[52][52][1001];
int f(int i,int j,int k){
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(board[i][j]=='*') {
        if(k>=0) return dp[i][j][k]=0;
        else return dp[i][j][k]=1000000;
    }
    if(k<0) return 1000000;
    int m = 1000000;
    char b = board[i][j];
    if(i!=1) m = min(m,(b!='U')+f(i-1,j,k-1));
    if(i!=N) m = min(m,(b!='D')+f(i+1,j,k-1));
    if(j!=1) m = min(m,(b!='L')+f(i,j-1,k-1));
    if(j!=M) m = min(m,(b!='R')+f(i,j+1,k-1));
    return dp[i][j][k]=m;
}
int main(){
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1;i<=N;i++)
        scanf("%s",board[i]+1);
    memset(dp,-1,sizeof(dp));
    int m = f(1,1,K);
    //printf("%d\n",f(2,1,0));
    //printf("%d\n",f(2,2,1));
    
    if(m==1000000) m=-1;
    printf("%d\n",m);
    return 0;
}
