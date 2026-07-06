import sys


def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    t = int(input_data[0])
    idx = 1
    out = []

    for _ in range(t):
        a = str(input_data[idx])
        b = str(input_data[idx + 1])
        idx += 2

        out.append(str(b[0] + a[1:3] + " " + a[0] + b[1:3]))
    print("\n".join(out))


if __name__ == "__main__":
    solve()
