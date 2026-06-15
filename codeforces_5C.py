s = input().strip()
 
stack = []
last = -1
 
max_len = 0
count = 0
 
for i in range(len(s)):
    if s[i] == '(':
        stack.append(i)
    else:
        if stack:
            stack.pop()
 
            if stack:
                cur_len = i - stack[-1]
            else:
                cur_len = i - last
 
            if cur_len > max_len:
                max_len = cur_len
                count = 1
            elif cur_len == max_len:
                count += 1
        else:
            last = i
 
if max_len == 0:
    print("0 1")
else:
    print(max_len, count)
