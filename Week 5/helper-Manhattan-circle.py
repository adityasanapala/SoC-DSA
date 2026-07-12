import sys


def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    result = []

    for _ in range(t):
        n = int(data[idx])
        m = int(data[idx + 1])
        idx += 2

        grid = []
        for _ in range(n):
            grid.append(data[idx])
            idx += 1
        row_min, row_max = float("inf"), 0
        col_min, col_max = float("inf"), 0
        for i in range(n):
            for j in range(m):
                if "#" == grid[i][j]:
                    if i > row_max:
                        row_max = i
                    if i < row_min:
                        row_min = i
                    if j > col_max:
                        col_max = j
                    if j < col_min:
                        col_min = j

        r = (row_max + row_min) // 2 + 1
        c = (col_max + col_min) // 2 + 1
        result.append(str(r) + " " + str(c))
    print("\n".join(result))


if __name__ == "__main__":
    solve()
