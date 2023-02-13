# import sys
# input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
    


n=int(input())
if n > 3 and (n - 2) % 2 == 0:
    print("YES")
else:
    print("NO")

if n % 2 == 0:
    if (n // 2) * 2 == n:
        print("YES")
else:
    print("NO")

if n % 2 == 0:
    if n // 2 == int(n/2):
        print("YES")
else:
    print("NO")