def main():
    
    num = int(input("length: "))
    scores = addList(num)
    print(scores)
    num2 = float(input("number to check "))
    checkList(scores,num2)

    checkList



def addList(n):
    newlis = []
    for i in range(n):
        num = float(input("number" + str(i) + " "))
        newlis.append(num)
    return newlis

def checkList(list,num):    
    for n in list:
        if n == num:
            print("Found.")
            break
    else:
        print("No found.")
    


main()