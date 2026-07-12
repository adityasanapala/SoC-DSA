import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    t = int(data[1])
    k = list(map(int, data[2:]))
    
    low = 0
    high = 10**18 
    ans = high

    def num_p(time: int):
        p = 0
        for i in range(n):
            p += time // k[i]
            if p >= t:
                break 
        return p

    while low <= high:
        mid = (low + high) // 2
        
        if num_p(mid) >= t:
            ans = mid        
            high = mid - 1   
        else:
            low = mid + 1    
    print(ans)

if __name__ == "__main__":
    solve()