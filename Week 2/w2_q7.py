import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    good = [0] * (n - 1)

    for i in range(n - 1):
        if a[i] < 2 * a[i + 1]:
            good[i] = 1

    ans = 0
    cnt = 0

    for x in good:
        if x:
            cnt += 1
        else:
            cnt = 0

        if cnt >= k:
            ans += 1

    print(ans)