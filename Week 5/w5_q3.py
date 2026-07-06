import sys


def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    result = []
    for _ in range(t):
        n = data[idx]
        idx += 1

        if n[0] != "1":
            result.append('NO')
            continue
        if n[-1] == "9":
            result.append('NO')
            continue
        if "0" in n[1:-1]:
            result.append('NO')
        else:
            result.append('YES')
    sys.stdout.write('\n'.join(result) + '\n')


if __name__ == "__main__":
    solve()
