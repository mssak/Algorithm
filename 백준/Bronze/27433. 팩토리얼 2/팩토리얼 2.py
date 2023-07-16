a = int(input())

def f(a):
    if a==0:
        return 1
    else:
        return a*f(a-1)
    
print(f(a))