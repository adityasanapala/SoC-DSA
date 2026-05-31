n=int(input())
map={}
 
rounds=[]
for i in range(n):
   
    name,score =input().split()
    score=int(score)
    rounds.append((name,score))
    if name not in map :
        map[name]=0
    map[name]=map[name]+int(score)
    
max_score=max(map.values())
 
poss_winners=[]
for name in map.keys():
    if map[name]==max_score:
        poss_winners.append(name)
 
current={}
for name, score in rounds:
 
    if name not in current:
        current[name] = 0
 
    current[name] += score
 
    if current[name] >= max_score and name in poss_winners:
        print(name)
        break
    