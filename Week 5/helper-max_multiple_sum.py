import sys


def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    t = int(input_data[0])
    idx = 1
    result = []
    for _ in range(t):
        n = int(input_data[idx])
        idx += 1
        maximum = 0
        for x in range(2, n + 1):
            k = n // x
            su = ((k) * (k + 1) * x) // 2
            # print(su)
            if su > maximum:
                maximum = su
                max_no = x
        result.append(str(max_no))
    print("\n".join(result))


if __name__ == "__main__":
    solve()
