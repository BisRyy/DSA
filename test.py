
from collections import defaultdict
def judge(n, trust):
    t = defaultdict(list)
    s = [0]*(n+1)
    a = []
    for i in trust:
        t[i[1]].append(i[0])
        s[i[0]]+=1
        if len(t[i[1]]) == n-1 and s[i[1]]==0:
            a.append(i[1])
    c = 0
    for i in s:
        if i == 0:
            c+=1

    if len(a)== n-1 and c == 1:
        return a[0]
    return -1

trust = [[1,3],[2,3],[3,1]]
print(judge(3,trust))

