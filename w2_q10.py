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

    def query(self, l, r):
        return self.sum(r) - self.sum(l - 1)


n, q = map(int, input().split())

row = [0] * (n + 1)
col = [0] * (n + 1)

bit_row = Fenwick(n)
bit_col = Fenwick(n)

for _ in range(q):
    query = list(map(int, input().split()))

    if query[0] == 1:
        _, x, y = query

        row[x] += 1
        if row[x] == 1:
            bit_row.add(x, 1)

        col[y] += 1
        if col[y] == 1:
            bit_col.add(y, 1)

    elif query[0] == 2:
        _, x, y = query

        row[x] -= 1
        if row[x] == 0:
            bit_row.add(x, -1)

        col[y] -= 1
        if col[y] == 0:
            bit_col.add(y, -1)

    else:
        _, x1, y1, x2, y2 = query

        rows = bit_row.query(x1, x2)
        cols = bit_col.query(y1, y2)

        if rows == x2 - x1 + 1 or cols == y2 - y1 + 1:
            print("Yes")
        else:
            print("No")