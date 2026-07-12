import sys
def solve():
    data = sys.stdin.read().strip()
    if not data:
        return
    stack=[-1]
    max_len=0
    count=1
    for i in range(len(data)):
        if data[i]=="(":
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                Current_len=i-stack[-1]
                if Current_len>max_len:
                    max_len=Current_len
                    count=1
                elif Current_len==max_len and max_len>0:
                    count+=1
    print(f"{max_len} {count}")                    
 
if __name__=="__main__" :
    solve()