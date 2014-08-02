c = [[None]*(300+1) for i in xrange(300+1)]

def C(n,m):
    if m==0 or n==m:
        return 1
    if c[n][m] is not None:
        return c[n][m]
    c[n][m] = C(n-1,m)+C(n-1,m-1)
    return c[n][m]

MOD = 1000000007
T=input()
for _ in xrange(T):
    n,m = map(int, raw_input().split(' '))
    xs=[0]+map(int,raw_input().split(' '))
    ds=[0]+map(int, raw_input().split(' '))
    dp=[[0]*(m+1) for i in xrange(n+1)] #final result dp[n][m]
    dp[0][0] = 1
    for i in xrange(1,n+1):
        dp[i][0] = 1
        d = [[0]*(ds[i]+1) for j in xrange(m+1)]
        #compute d[0...m][x]
        d[0][xs[i]] = 1
        for j in xrange(1,m+1):
            for k in xrange(1,ds[i]+1):
                if k>1:
                    d[j][k]+=d[j-1][k-1]
                    d[j][k] %= MOD
                if k+1<=ds[i]:
                    d[j][k]+=d[j-1][k+1]
                    d[j][k] %= MOD
        for j in xrange(1,m+1):
            for k in xrange(j+1): #last i-1 dimision use k step
                dp[i][j] += dp[i-1][k]*C(j,k)*sum(d[j-k])
                dp[i][j] %= MOD
    print dp[n][m]
