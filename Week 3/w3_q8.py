n = int(input())
a = list(map(int, input().split()))

vals = sorted(set(a))
m = len(vals)

prev = [abs(a[0] - x) for x in vals]

for i in range(1, n):
    pref = [0] * m
    pref[0] = prev[0]

    for j in range(1, m):
        pref[j] = min(pref[j - 1], prev[j])

    cur = [0] * m

    for j in range(m):
        cur[j] = pref[j] + abs(a[i] - vals[j])

    prev = cur

print(min(prev))