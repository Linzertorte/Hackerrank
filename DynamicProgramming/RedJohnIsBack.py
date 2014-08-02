T = input()
#print T
for _ in xrange(T):
    n = input()
    #print n
    dp = [None]*(n+1)
    dp[0]=1
    for i in xrange(1,n+1):
        dp[i] = 0
        if i-4>=0:
            dp[i] += dp[i-4]
        dp[i] += dp[i-1]
        #print dp[i]
    M = dp[n]
    #print M
    isprime = [True]*(M+10)
    isprime[0] = isprime[1] = False
    i= 2
    while i*i<=M:
        if isprime[i]:
            j = 2
            while i*j<=M:
                isprime[i*j] = False
                j+=1
  
        i+=1
    
    cnt = 0
    for i in xrange(M+1):
        if isprime[i]:
            cnt += 1
    print cnt
    
    
