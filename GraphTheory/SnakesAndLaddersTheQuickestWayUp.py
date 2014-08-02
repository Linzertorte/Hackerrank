

t = input()
for q in xrange(t):
    ladder_cnt, snake_cnt = map(int, raw_input().split(','))
    ladder_line = raw_input()
    snake_line = raw_input()
    snakes = {}
    ladders = {}
    for snake in snake_line.split(' '):
        a,b = map(int,snake.split(','))
        snakes[a] = b
    for ladder in ladder_line.split(' '):
        a,b = map(int, ladder.split(','))
        ladders[a] = b
    rolls = [None]*101
    rolls[100] = 0
    inf  = float('inf')
    for i in xrange(99,0,-1):
        if i in snakes:
            if snakes[i]>i:
                rolls[i] = rolls[snakes[i]]
            else:
                rolls[i] = inf
        elif i in ladders:
            if ladders[i]>i:
                rolls[i] = rolls[ladders[i]]
            else:
                rolls[i] = inf
        else:
            m = float("inf")
            for step in xrange(1,7):
                if i+step<=100:
                    m = min(m, rolls[i+step])
            rolls[i]=m+1
            #print i,rolls[i]
    #print rolls[99]
    print rolls[1]
