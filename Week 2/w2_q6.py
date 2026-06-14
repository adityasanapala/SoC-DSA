import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))

    pos = [0] * (n + 1)

    for i, x in enumerate(p):
        pos[x] = i

    l = (n + 1) // 2
    r = (n + 2) // 2

    while l > 0 and (
        l == r or
        (pos[l] < pos[l + 1] and pos[r - 1] < pos[r])
    ):
        l -= 1
        r += 1

    print((n - r + l + 1) // 2)