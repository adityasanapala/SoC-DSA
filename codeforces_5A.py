n=[]
 
space=0
 
while(True):
    try:
        
        str=input()
        l=len(str)
        if(str[0]=='+'):
            if str[1:l] not in n:
                n.append(str[1:l])
                
        elif(str[0]=='-'):
            if str[1:l] in n:
                n.remove(str[1:l])
                
        else:
            name,msg=str.split(":",1)
            msg_len=len(msg)
            
            space+=msg_len*len(n)
 
    except EOFError:
 
        break
 
 
print(space)