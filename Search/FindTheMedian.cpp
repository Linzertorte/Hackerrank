#include<iostream>
#include<queue>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int selectK(int s,int t,vector<int> &seq,int k){
    if(t-s==1) return seq[s];
    int key = seq[s];
    int j=s;
    for(int i=s+1;i<t;i++)
        if(seq[i]<=key)
            swap(seq[++j],seq[i]);
    
    swap(seq[s],seq[j]);
    ++j;
    //printf("(%d,%d,%d,%d)\n",s,t,j-1,k);
    if(j-s==k) return seq[j-1];
    else if(j-s>k) return selectK(s,j-1,seq,k);
    else return selectK(j,t,seq,k-j+s);
}

int main(){
    
    int n;
    scanf("%d",&n);
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    printf("%d\n",selectK(0,n,nums,(n+1)/2));
    
    return 0;
}
