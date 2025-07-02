import sqlite3

db = sqlite3.connect("clientes.db")
db.row_factory = sqlite3.Row
cursor = db.cursor()

querie = input("¿Que ciudad? ")
cursor.execute("SELECT COUNT(*) AS n FROM clientes WHERE ciudad = ?",(querie,))

row = cursor.fetchone()

print(row[0])

db.close()