def Fibonacci():
    
    print("Codigo fibonacci")
    t=int(input("Hasta que numero quieres ver la serie fibonacci: "))
    
    i=0
    a=[0,1]
    for i in range(t):
        
        e=a[i]+a[i+1]
        a.append(e)
    for i in range(t):

        
        print("position: {} and number {}".format(i+1,a[i]))
    print("Busca la posicion de codigo fibonacci\n")
    o=int(input("Busca la posicion del numero: "))
    a.index(o)
        
    



    
