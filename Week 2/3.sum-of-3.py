import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    target = int(data[1])
    arr = [(int(data[i + 2]), i + 1) for i in range(n)]
    arr.sort()
    for i in range(0,n-2):
        left = i+1
        right = n - 1
        while left < right:
            current_sum = arr[left][0] + arr[right][0]+arr[i][0]

            if current_sum == target:
                print(f"{arr[i][1]} {arr[left][1]} {arr[right][1]}")
                return

            elif current_sum < target:
                left += 1

            else:
                right -= 1
    print("IMPOSSIBLE")

if __name__=="__main__":
    solve()