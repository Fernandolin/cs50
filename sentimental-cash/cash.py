from cs50 import get_float

valor = get_float("Change owed: ")
moeda=0
valor_int = int(valor*100)
a=25
b=10
c=5
d=1
while(True):
    if(valor_int>=a):
        valor_int = (valor_int-a)
        moeda += 1
    elif(valor_int>=b):
        valor_int = valor_int-b
        moeda +=1

    elif(valor_int>=c):
        valor_int = valor_int-c
        moeda +=1
    elif(valor_int>=d):
        valor_int = valor_int-d
        moeda +=1
    elif(valor_int==0):
        break

print(moeda)