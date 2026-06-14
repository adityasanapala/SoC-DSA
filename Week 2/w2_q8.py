import sys
from collections import defaultdict

input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))

freq = defaultdict(int)

l = 0
distinct = 0

best_l = 0
best_r = 0

for r in range(n):
    if freq[a[r]] == 0:
        distinct += 1
    freq[a[r]] += 1

    while distinct > k:
        freq[a[l]] -= 1
        if freq[a[l]] == 0:
            distinct -= 1
        l += 1

    if r - l > best_r - best_l:
        best_l = l
        best_r = r

print(best_l + 1, best_r + 1)