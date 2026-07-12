def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        li = list(map(int, input().split()))
        pos = {}
        for i in range(n):
            pos[li[i]] = i
        ops = n // 2 
        left = (n + 1) // 2
        right = (n + 2) // 2
        
        if left != right: 
            if pos[left] > pos[right]:
                print(ops)
                continue 
            ops -= 1
            left -= 1
            right += 1
        else:
            left -= 1
            right += 1
            
      
        while left >= 1 and right <= n:
            if pos[left] < pos[left + 1] and pos[right - 1] < pos[right]:
                ops -= 1
                left -= 1
                right += 1
            else:
                break 
                
        print(ops)

if __name__ == "__main__":
    solve()