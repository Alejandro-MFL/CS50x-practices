def main():
    # Ask for the number, check that they are numerical values and measure the length
    try:
        card = int(input("Number: "))
    except ValueError:
        print("INVALID")
        return 1
    length = len(str(card))

    # Create a reverse list of the card code
    # In Python it could be reduced to:
    # listCard = [int(d) for d in str(card)][::-1]
    # where it loops through each character in the string made of Card and adds it to the list,
    # [::-1] reverses it and is equivalent to [start:stop:step] where step would be -1
    listCard = [0] * length
    createList(card, length, listCard)

    # Checks the reference and prints it.
    # The if statement can be reduced in Python to:
    # luhn = checkLuhn(listCard, length) if ref < 9 else False
    ref = checkCompany(listCard, length)
    if ref < 9:
        luhn = checkLuhn(listCard, length)
    else:
        luhn = False
    printResult(luhn, ref)
    return 0


def printResult(lunh, company):
    if lunh:
        if company == 1:
            print("AMEX")
        elif company == 2:
            print("MASTERCARD")
        elif company == 3:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def checkLuhn(array, length):
    sumDouble = 0
    sumNormal = 0
    for i in range(length):
        if i == 0 or i % 2 == 0:
            sumNormal += array[i]
        else:
            x2 = array[i] * 2
            if x2 < 10:
                sumDouble += x2
            else:
                sumDouble += (x2 // 10) + (x2 % 10)

    if (sumDouble + sumNormal) % 10 == 0:
        return True
    else:
        return False


# Check the characteristics of each company's cards. 9 is taken as it has more values to add more cards in the future.


def checkCompany(array, length):
    if length == 15:
        if array[-1] == 3 and array[-2] in (4, 7):
            return 1
        else:
            return 9
    elif length == 16:
        if array[-1] == 5 and (array[-2] in range(1, 6)):
            return 2
        elif array[-1] == 4:
            return 3
        else:
            return 9
    elif length == 13:
        if array[-1] == 4:
            return 3
        else:
            return 9
    else:
        return 9


# This method was done because in C you can't look at the length directly, now it is replaced by len()
# I keep it for educational purposes but the """ are not temporary measures and are not equivalent to /**/,
# to leave it as a comment on each line you should add #
"""
def checkLength(card):
    digits = 0
    while card > 0:
        card //= 10
        digits += 1
    return digits
"""


def createList(card, length, listInt):
    for i in range(length):
        n = card % 10
        card //= 10
        listInt[i] = n


main()
