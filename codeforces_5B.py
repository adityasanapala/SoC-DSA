n=[]
m=[]
 
 
 
while(True):
    try:
        sen=input()
        n.append(sen)
        m.append(len(sen))
    
    except EOFError:
 
        break
 
h=max(m)
for i in range(0,h+2):
    print('*',end="")
print()
d=0
g=0
while(d<len(m)):
    if (h-len(n[d]))%2 !=0:
        g=g+1
    if(g%2==0 ):
        print('*',end="")
        
        for i in range(0,(h-len(n[d])+1)//2):
            print(' ',end="")
        print(n[d],end="")
        for i in range(0,(h-len(n[d]))//2):
            print(' ',end="")
        print('*')
    else:
        print('*',end="")
        
        for i in range(0,(h-len(n[d]))//2):
            print(' ',end="")
        print(n[d],end="")
        for i in range(0,(h-len(n[d])+1)//2):
            print(' ',end="")
        print('*')
 
    d=d+1
 
for i in range(0,h+2):
    print('*',end="")
print()
 