#Pruebas de elementos similares en python, son pruebas sencillas por lo que no estan comentadas y los valores tienen nombres no descriptivos
def main():        
    #Hello word con nombre
    answer = input("what's your name? ")
    print(f"hello, {answer}")

    #Prueba de comparadores de int con if
    #try es muy interesante, expandir conocimiento sobre ello
    try:    
        x = float(input("x = "))
        y = float(input("y = "))
        numComparator(x, y)
    except ValueError:
        print("Need numbers")  

    #Comparadores de string con in    
    agreed()
        
    #copia de strings mas mayusculas
    s = input("s: ")
    capitalizacion(s)

    #bucles de while y for
    meaw(3)
    return 0

#Fin de main y declarafion de funciones
def numComparator(x, y):  
         
    if isinstance(x, int) and isinstance(x, int) or isinstance(x, float) and isinstance(x, float):              
        if x < y:
            print("x is less than y")
        elif x > y:
            print("x is more than y")
        else:
            print("x is equal to y")
    else:
        print("Need only numbers, sorry")

def capitalizacion(word): 
    t = word.capitalize()

    print(word)
    print(t)

def meaw(n):
    #''' es lo mas parecido a /**/, una lastima, pero la mejor opcion para desactivar funciones temporalmente y similares
    '''
    i = 0
    while i < 3:
        print("meaw")
        i +=1
    '''
        #el bucle for es definido por rango desde el inicio normalmente con rango pero funciona con listas y similares
    for j in range(3):
        print("meaw")
    

def agreed():
        s = input("Do you agree? ").lower()

        if s == 'y' or s == 'yes':
            print("Agreed.")
        elif s in ['no','n']:
            print("Not agreed.")
        else:
            print("Please answer only with \"y\" or \"n\"")
            agreed()


main()