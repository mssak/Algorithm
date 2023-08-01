a,b,c=map(int,input().split())

l=sorted([a,b,c])

if l[0]+l[1]<=l[2]:
    print((l[0]+l[1])*2-1)
else:
    print(sum(l))