T=input()
for _ in xrange(T):
    n = input()
    a,b,c,d = map(int,raw_input().split(' '))
    dp = [0]*(n+1)
    dp[0] = 1
    
    for j in xrange(0,1):
        for i in xrange(1,a+1):
            if dp[j]!=0 and j+i<=n:
                dp[j+i] += dp[j]
    for j in xrange(n-1,-1,-1):
        for i in xrange(1,b+1):
            if dp[j]!=0 and j+2*i<=n:
                dp[j+2*i] += dp[j]
    for j in xrange(n-1,-1,-1):
        for i in xrange(1,c+1):
            if dp[j]!=0 and j+5*i<=n:
                dp[j+5*i] += dp[j]
    for j in xrange(n-1,-1,-1):
        for i in xrange(1,d+1):
            if dp[j]!=0 and j+10*i<=n:
                dp[j+10*i] += dp[j]
    
    
    print dp[n]
