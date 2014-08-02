T=input()
for _ in xrange(T):
    n = input()
    bricks = map(int,raw_input().split(' '))
    if n<=3:
        print sum(bricks)
        continue
    
    dp0 = [0]*n
    dp1 = [0]*n
    dp0[n-1] = bricks[n-1]
    dp0[n-2] = bricks[n-2]+bricks[n-1]
    dp0[n-3] = bricks[n-3]+bricks[n-2]+bricks[n-1]
    dp1[n-1] = 0
    dp1[n-2] = 0
    dp1[n-3] = 0
    for i in xrange(n-4,-1,-1):
        m = -float('inf')
        j = 0
        if bricks[i]+dp1[i+1]>m:
            m = bricks[i]+dp1[i+1]
            j = 1
        if bricks[i]+bricks[i+1]+dp1[i+2]>m:
            m = bricks[i]+bricks[i+1]+dp1[i+2]
            j = 2
        if bricks[i]+bricks[i+1]+bricks[i+2]+dp1[i+3]>m:
            m = bricks[i]+bricks[i+1]+bricks[i+2]+dp1[i+3]
            j = 3
        dp0[i] = m
        dp1[i] = dp0[i+j]
    print dp0[0]
