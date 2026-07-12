import sys


def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    result = []
    for _ in range(t):
        min_moves = float("inf")
        a, b = int(data[idx]), int(data[idx + 1])
        idx += 2
        for m in range(1, 100001):

            jumps_a = (a + m - 1) // m
            jumps_b = (b + m - 1) // m

            current_moves = (m - 1) + jumps_a + jumps_b

            if current_moves < min_moves:
                min_moves = current_moves

        result.append(str(min_moves))

    # Print all results separated by a newline for fast I/O
    print("\n".join(result))


if __name__ == "__main__":
    solve()
