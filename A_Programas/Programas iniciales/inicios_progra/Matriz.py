'''
print("Matriz 3x3")
a =list()

for i in range(3):
    
    a.append(list())
    for j in range(3):
        a[i].append(input("Escribe valor en: : "))
        
  
for i in range(3):
    b=""
    
    for j in range(3):
        b+=str(a[i][j])+'\t'
    print(b)
    
print(a) 
'''


'''
for i in range(3):
    a.append(list())
    for j in range (3):
        c=i+1
        if i==j or j==3-c :
            a[i].append(1)
        
        else:
           a[i].append(0)
    
for i in range(3):
    b=""
    for j in range(3):
        
        b+=str(a[i][j])+'\t'
              
    print(b)    
'''
#Aburrido       
for i in range(1,5):
    b=""
    for j in range(i,0,-1):
        b+=str(i)
    print(b)      
'''
1
22
333
4444
'''