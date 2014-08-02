import math
line = raw_input().rstrip()
le = len(line)
l = int(math.floor(math.sqrt(le)))
r = int(math.ceil(math.sqrt(le)))
area = float('inf')
best_h,best_w = None, None
for h in xrange(l,r+1):
    for w in xrange(h,r+1):
        if h*w>=le and h*w <area:
            area = h*w
            best_h = h
            best_w = w
result = []
for i in xrange(w):
    w = ""
    for j in xrange(h):
        if j*h+i<le:
            w+=line[j*h+i]
    result.append(w)
print ' '.join(result)
