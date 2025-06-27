def main():
    list1()
 
def OnlyList():
    
    num = int(input("length: "))
    scores = addList(num)
    print(scores)
    num2 = float(input("number to check "))
    checkList(scores,num2)

    checkList


# añadir a lista
def addList(n):
    newlis = []
    for i in range(n):
        num = float(input("number" + str(i) + " "))
        newlis.append(num)
    return newlis

#Chequear elementos en una list
def checkList(list,num):    
    for n in list:
        if n == num:
            print("Found.")
            break
    else:
        print("No found.")
#Aqui tenemos dos busquedas en dictionaries, con dos formas de nombrarlos como de busqueda 
#Uno hace una lista de diccionarios y el otro usa directamente un diccionario, list2 es mas rapida pero mas simple
def list1():
    people = [
        {"name":"a","number":"1"},
        {"name":"b","number":"2"}
    ]
    newName = input("Name: ")
    for n in people:
        if n["name"] == newName:
            print(f"Found. {n["number"]}")
            break
    else:
        print("No found.")

def list2():
    people = {
        "a":"1",
        "b":"2"
    }
    newName = input("Name: ")
    if newName in people:
        print(f"Found. {people[newName]}")        
    else:
        print("No found.")

main()