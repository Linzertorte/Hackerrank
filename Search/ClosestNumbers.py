n = input()
A = map(int,raw_input().split(' '))
A = sorted(A)
diff = float('inf')
for i in xrange(1,n):
    diff = min(diff,A[i]-A[i-1])
result = []
for i in xrange(1,n):
    if A[i]-A[i-1] == diff:
        result.append(A[i-1])
        result.append(A[i])
print ' '.join(map(str,result))
