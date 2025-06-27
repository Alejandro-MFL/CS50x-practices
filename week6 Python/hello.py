#Pruebas de elementos similares en python
#Hello word con nombre
answer = input("what's your name? ")
print(f"hello, {answer}")

#Prueba de comparadores de int con if
x = int(input("x = "))
y = int(input("y = "))

if x < y:
    print("x is less than y")
elif x > y:
    print("x is more than y")
else:
    print("x is equal to y")

#Comparadores de string con in

s = input("Do you agree? ")

if s == 'y' or s == 'Y':
    print("Agreed.")
elif s in ['N','n']:
    print("Not agreed.")
else:
    print("Please answer only with \"y\" or \"n\"")
