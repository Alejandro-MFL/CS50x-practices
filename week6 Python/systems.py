import sys
import csv

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