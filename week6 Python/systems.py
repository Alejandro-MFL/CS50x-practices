import sys
import csv

#Ejemplo de class, es relativamente nuevo respecto a C pero muy similar a las class que usaba en C#. self es nuevo
#Init es un similar awake y le da los valores deseados, y se le pueden añadir distintas funciones

class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id
    
    def changeID(self,id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))


a = Student("a",1)
a.print()
a.changeID(2)
a.print()





#Es un mero ejemplo de modificacion de archivos desde un .py
#es un ejemplo para poder desarrollar y extrapolar
def writeInFile():
    name = "a"
    number = "1"
    with open("phonebook.csv","a") as file:

        writer= csv.DictWriter(file, fieldnames=["name", "number"])
        writer.writerow({"name":name, "number": number})




#Ejemplo de uso de parametros en la apertura de archivos
def checkArgv():
    if len(sys.argv) != 2:
        print("Tiene que ser solo 1")
        exit (1)
    #exit  o sys.exit cierra el cierra el programa y reporta un codigo como lo hacia main para errores,
    #  si no se le da valor toma 0 (Exito como en C), tambien se le puede dar un str que saldria como mensaje mas codigo 1  
    print(f"hello, {sys.argv[1]}")
    exit (0)

#Ejemplo de lerctura de csv
def countKey():
    with open("favorites.csv","r") as file:
        reader = csv.DictReader(file)
        count= {}                
        for row in reader:
            favorite = row["language"]
            if favorite in count:
                count[favorite] += 1
            else:
                count[favorite] = 1
#Sorted organiza elementos iterables, alfabeticamente o numericamente principalmente
#si se le añade otro parametro key, puedes elegir el criterio 
# (count, key=counts.get) Aqui cogeria los valores de la key y los organizaria de menos a mas
    for favorite in sorted(count):
        print(f"{favorite}: {count[favorite]}")