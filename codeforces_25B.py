
n=int(input())
m=str(input())
 
    #grouping them into 2s
 
if n%2==0:
    for i in range (0,n,2):
        print(f"{m[i]}{m[i+1]}",end="" )
        if i+1!=n-1:
            print("-",end="")
else:
    for i in range (0,n-1,2):
        print(f"{m[i]}{m[i+1]}",end="" )
        if i+1!=n-2 and n%2==1:
            print("-",end="")
if n%2==1:
    print(m[n-1])