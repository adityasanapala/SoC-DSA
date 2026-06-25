n=int(input())
a=[int(x) for x in input().split()]
s={0:[], 1:[]}
for i in range (n):
    if a[i]%2==0:
        s[0].append(i)
    else:
        s[1].append(i)
        
 
if len(s[0]) == 1:
    print(s[0][0]+1)
elif len(s[1]) == 1:
    print(s[1][0]+1)