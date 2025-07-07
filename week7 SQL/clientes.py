import sqlite3

db = sqlite3.connect("clientes.db")
#Esta parte evita que los datos sean tuplas para que sean diccionarios
db.row_factory = sqlite3.Row
cursor = db.cursor()

def askCiudad():
    querie = input("¿Que ciudad? ")

    cuantos(querie)
    quienes(querie)
    
def cuantos(ciudad):
    #Se añade la informacion como tupla, de ahí la coma al final
#IMPORTANTE, siempre se ha de inserta asi datos de una querie para evitar inyecciones queda descartado
    #f-strings, + o .format(), tambien se podrian validar manualmente.
    cursor.execute("SELECT Count(*) AS n FROM clientes WHERE ciudad = ?",(ciudad,))
    #Se usa fetchone por ser uno con Count*, si no usariamos fetchmany(x) para x filas
    linea = cursor.fetchone()
    print(linea[0])

def quienes(ciudad):
    cursor.execute("SELECT * FROM clientes WHERE ciudad = ?",(ciudad,))
    
    rows = cursor.fetchall()
    for row in rows:
        print(dict(row))

askCiudad()        

db.close()