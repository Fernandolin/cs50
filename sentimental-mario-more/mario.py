from cs50 import get_int

while(True):
    altura = get_int("Height: ")
    if((altura<1)or(altura>=9)):
        continue
    if(type(altura) is int):
        break
    else:
        continue

for x in range(1,altura+1):
    print(" "*(altura-x)+"#"*(x)+"  "+"#"*(x))
