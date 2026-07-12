import sys


def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n, k = int(input_data[0]), int(input_data[1])
    a = list(map(int, input_data[2:]))
    minimum_val = float('inf')

    for l in range(n + 1 - k):
        odd_max, even_max = 0, 0
        for i in range(k):
            if (l + i) % 2:
                if odd_max < a[l + i]:
                    odd_max = a[l + i]
            else:
                if even_max < a[l + i]:
                    even_max = a[l + i]
        seq_val = min(odd_max, even_max)
        if seq_val < minimum_val:
            minimum_val = seq_val
    print(minimum_val)


if __name__ == "__main__":
    solve()
