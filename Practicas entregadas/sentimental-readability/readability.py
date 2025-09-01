from cs50 import get_string


# It asks the reader, evaluates and measures it with respect to the Luhn coefficient, and finally prints the result.
def main():
    reading = get_string("Text: ")
    index = ReadAndCalculate(reading)
    printTheAnswer(index)


# It measures the letters, words, and sentences of the argument, then calculates the Luhn coefficient and returns it.
def ReadAndCalculate(reading):

    letters, words, sentences = (0, 0, 0)
    for i in range(len(reading)):
        # It measures the letters.
        if reading[i].isalpha():
            letters += 1
        # It measures the words according to the spaces, plus one that will be measured from the last word.
        elif reading[i].isspace():
            words += 1
        # It measures the sentences by their endings.
        elif reading[i] in (".", "?", "!"):
            sentences += 1
    words += 1
    l = (letters * 100.0) / words
    s = (sentences * 100.0) / words

    index = round(0.0588 * l - 0.296 * s - 15.8)
    return index


# It prints the result.
def printTheAnswer(index):
    if index < 1:
        print("Before Grade 1")
    elif index < 16:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


main()
