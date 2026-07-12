import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    
    for _ in range(t):
        n = int(data[idx])
        k = int(data[idx + 1])
        idx += 2
        a = [int(x) for x in data[idx : idx + n]]
        idx += n 
        ans = 0
        streak = 0
        for i in range(n - 1):
            if a[i] < 2 * a[i + 1]:
                streak += 1
            else:
                streak = 0 
            if streak >= k:
                ans += 1
        print(ans)


if __name__ == '__main__':
    solve()