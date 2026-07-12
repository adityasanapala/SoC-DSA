import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return

    n = int(data[0])
    k = int(data[1])
    a = [int(data[i + 2]) for i in range(n)]
    l,best_r,best_l=0,0,0
    freq_map=[0]*1000005
    unique_count=0
    max_len=0
    for r in range(n):
        num = a[r]
        if freq_map[num]==0:
            unique_count+=1
        freq_map[num]+=1
        while unique_count > k:
            left_num = a[l]
            freq_map[left_num] -= 1    
            if freq_map[left_num]==0:
                unique_count-=1
            l+=1
        current_len = r - l + 1
        if current_len > max_len:
            max_len = current_len
            best_l = l
            best_r = r            
    print(f"{best_l + 1} {best_r + 1}")    

if __name__=="__main__":
    solve()