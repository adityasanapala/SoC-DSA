n = int(input())
a = list(map(int, input().split()))
 
m = int(input())
b = list(map(int, input().split()))
 
dp = [0] * m
parent = [-1] * m
 
for i in range(n):
    current = 0
    last = -1
 
    for j in range(m):
        if a[i] == b[j]:
            if current + 1 > dp[j]:
                dp[j] = current + 1
                parent[j] = last
 
        elif a[i] > b[j]:
            if dp[j] > current:
                current = dp[j]
                last = j
 
length = max(dp, default=0)
 
print(length)
 
if length == 0:
    print()
else:
    pos = dp.index(length)
    ans = []
 
    while pos != -1:
        ans.append(b[pos])
        pos = parent[pos]
 
    ans.reverse()
    print(*ans)
