n = input()
A = map(int,raw_input().split(' '))
m = input()
B = map(int,raw_input().split(' '))
X_min = min(B)
#print X_min
cntA = [0]*200
cntB = [0]*200
result = []
for i in A:
    cntA[i-X_min]+=1
for i in B:
    cntB[i-X_min]+=1
for i in xrange(200):
    if cntB[i]>cntA[i]:
        result.append(i+X_min)
print ' '.join(map(str,result))
