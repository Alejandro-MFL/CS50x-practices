def main():
    
    num = int(input("length: "))
    scores = addList(num)
    print(scores)

def addList(n):
    newlis = []
    for i in range(n):
        num = float(input("number" + str(i) + " "))
        newlis.append(num)
    return newlis




main()