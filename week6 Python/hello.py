#Pruebas de elementos similares en python, son pruebas sencillas por lo que no estan comentadas y los valores tienen nombres no descriptivos
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
s = input("Do you agree? ").lower()

if s == 'y' or s == 'yes':
    print("Agreed.")
elif s in ['no','n']:
    print("Not agreed.")
else:
    print("Please answer only with \"y\" or \"n\"")
    #Añadir recursion cuando vea creacion de funciones(lo siento si se me olvida)

#copia de strings
s = input("s: ")

t = s.capitalize()

print(s)
print(t)

#bucles de while y for
i = 0
while i < 3:
    print("meaw")
    i +=1
    #el bucle for es definido por rango desde el inicio normalmente con rango pero funciona con listas y similares
for j in range(3):
    print("meaw")
