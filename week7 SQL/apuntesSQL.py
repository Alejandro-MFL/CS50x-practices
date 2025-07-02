#Como toda la clase la estoy realizando trabajando con el Terminal, voy agregar un par de recordatorios como recordatorios

#Para importar elementos de un csv, es necesario primero ".mode csv", si se hace manualmente creando las tablas, 
    #la primera linea sera usada como elemento de la tabla
"""
    .mode csv
    .import clientes.csv clientes
    """

#Para ver tablas:
    #PRAGMA table_info(clientes);
    #Devuelve:
        #Columna	    Significado
        #cid	        Índice de la columna (0, 1, 2...)
        #name	        Nombre de la columna
        #type	        Tipo de dato (TEXT, INTEGER, etc.)
        #notnull	    ¿Puede ser nulo? (1 = NO, 0 = sí)
        #dflt_value	    Valor por defecto (si tiene alguno)
        #pk	            ¿Es clave primaria? (1 = sí, 0 = no)

#Para eliminar una tabla:
    # DROP TABLE IF EXISTS clientes;
    #Columna	Significado
    #cid	Índice de la columna (0, 1, 2...)
    #name	Nombre de la columna
    #type	Tipo de dato (TEXT, INTEGER, etc.)
    #notnull	¿Puede ser nulo? (1 = NO, 0 = sí)
    #dflt_value	Valor por defecto (si tiene alguno)
    #pk	¿Es clave primaria? (1 = sí, 0 = no)

#Para mediciones de tiempos
    #.timer ON

#Ejemplo de crear tablas
    #Se pueden vincular tablas con PRYMARY y FOREIGN(PRIMARY KEY se puede usar ade una)
        #Con JOIN pueden unirse para que salgan juntas:
            #SELECT * FROM clientes JOIN consumidores ON clientes.id = consumidores.show_id;
            #los muestra una al lado de la otra
""" 
    Crear tablas
    CREATE TABLE clientes (
        id INTEGER,
        nombre TEXT,
        tiempo NUMERIC,
        correo TEXT,
        PRIMARY KEY (ID)
    ); 
    
    CREATE TABLE consumidor (
        show_id INTEGER NOT NULL,
        money REAL NOT NULL,
        FOREIGN KEY(show_id) REFERENCES shows(id)

    )
    """
#Ejemplo de insercion de datos:
"""
    -- Insertar datos de ejemplo
    INSERT INTO clientes(nombre, correo) VALUES
    ('Ana García', 'ana@example.com'),
    ('Luis Pérez', 'luis@example.com');
    """
    #Las columnas no rellenas tendran el valor de NULL

#Ejemplo de modificacion de datos con UPDATE:
    #UPDATE clientes SET correo = 'nuevo@email.com' WHERE nombre = 'Ana García';

#Ejemplo de eleminar datos
    #DELETE FROM clientes WHERE ciudad IS NOT NULL;

#Ejemplo de SELECT con multiples modificaciones:
    #SELECT * FROM clientes WHERE ciudad = 'Madrid' AND id < 70;
    #SELECT * FROM clientes WHERE (ciudad = 'Madrid' or ciudad = 'Barcelona') AND correo LIKE '%gmail.com';
    #SELECT ciudad, COUNT(*) AS n FROM clientes GROUP BY ciudad ORDER BY n DESC LIMIT 4;
        #DESC descendiente ASC ascendente

#Crear una copia de seguridad
    #.backup 'clientes_backup.db'
