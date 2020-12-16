print("\n\n\t\t'Calculadora de montos'\n")
print("\nEscribe el monto para que saber la cantidad de billetes de 500,200,100,50,20 y de monedas de 10,5,2,1\n")
monto_inicial=int(input("Monto: "))






if(monto_inicial>=500):
    billete_500=monto_inicial/500
    monto_inicial%=500
elif(monto_inicial>=200):
    billete_200=monto_inicial/200
    monto_inicial%=200
elif(monto_inicial>=100):
    lel=monto_inicial/100
    monto_inicial%=100
elif(monto_inicial>=50):
    billete_50=monto_inicial/50
    monto_inicial%=50
elif(monto_inicial>=20):
    billete_v=monto_inicial/20
    monto_inicial%=20
elif(monto_inicial>=10):
    monedas_10=monto_inicial/10
    monto_inicial%=10
elif(monto_inicial>=5):
    monedas_5=monto_inicial/5
    monto_inicial%=5
elif(monto_inicial>=2):
    monedas_2=monto_inicial/2
    monto_inicial%=2
elif(monto_inicial>=1):
    monedas_1=monto_inicial/1
    monto_inicial%=1

#print("\n\tCantidad: {}  \n billetes de 500: {}\n\tBilletes de 200: {}\n\tBilletes de 100: {}\n\tBilletes de 50: {}\n\tBilletes de 20: {}\n\tMonedas de 10: {}\n\tMonedas de 5: {}\n\tBilletes de 2: {}\n\tMonedas de 1: {}".format(int(billete_500),billete_200,billete_100,billete_50,billete_v,monedas_10,monedas_5,monedas_2,monedas_1))
 
    
print("Cantidad:",lel)