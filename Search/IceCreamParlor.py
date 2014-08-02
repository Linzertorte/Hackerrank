t = input()
for _ in xrange(t):
    m = input()
    n= input()
    arr = map(int,raw_input().split(' '))
    index = [None]*10001
    for i in xrange(n):
        
        a = arr[i]
        b = m-a
        if index[b]:
            print min(i+1,index[b]),max(i+1,index[b])
            break
        index[arr[i]]=i+1
