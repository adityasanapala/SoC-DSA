import sys

input = sys.stdin.readline


class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, idx, val):
        while idx <= self.n:
            self.bit[idx] += val
            idx += idx & -idx

    def sum(self, idx):
        res = 0
        while idx:
            res += self.bit[idx]
            idx -= idx & -idx
        return res


n = int(input())

ranges = []
ends = []

for i in range(n):
    l, r = map(int, input().split())
    ranges.append((l, r, i))
    ends.append(r)

# coordinate compression
vals = sorted(set(ends))
comp = {v: i + 1 for i, v in enumerate(vals)}

# sort by left ascending, right descending
ranges.sort(key=lambda x: (x[0], -x[1]))

contains = [0] * n
contained = [0] * n

m = len(vals)

# count how many ranges each range contains
bit = Fenwick(m)

for l, r, idx in reversed(ranges):
    p = comp[r]
    contains[idx] = bit.sum(p)
    bit.add(p, 1)

# count how many ranges contain each range
bit = Fenwick(m)

for l, r, idx in ranges:
    p = comp[r]
    contained[idx] = bit.sum(m) - bit.sum(p - 1)
    bit.add(p, 1)

print(*contains)
print(*contained)