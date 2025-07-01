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


#Ejemplo de crear tablas
    """ 
    Crear tablas
    CREATE TABLE clientes (
        id INTEGER PRIMARY KEY,
        nombre TEXT,
        correo TEXT
    ); 
    """
#Ejemplo de insercion de datos:
    """
    -- Insertar datos de ejemplo
    INSERT INTO clientes(nombre, correo) VALUES
    ('Ana García', 'ana@example.com'),
    ('Luis Pérez', 'luis@example.com');
    """

#Ejemplo de SELECT con multiples modificaciones:
    #SELECT * FROM clientes WHERE ciudad = 'Madrid' AND id < 70;
    #SELECT * FROM clientes WHERE (ciudad = 'Madrid' or ciudad = 'Barcelona') AND correo LIKE '%gmail.com';
