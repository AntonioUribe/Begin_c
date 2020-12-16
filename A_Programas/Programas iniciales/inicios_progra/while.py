print("ARROJAR NUMERO")
numero=int(input("Escribe un numero"))
i=0
j=1
while numero != 0:
   i+=1  
   print("llevamos",i)
   while j>0 and j<11 and numero!=0:
        
              print(numero,"x",j,"=",numero*j)
              j+=1
        
   else:
               j=1
               numero=int(input("Escribe otro numero"))
            

         
            
else:
    print("Numeros de tablas fueron",i)
    
