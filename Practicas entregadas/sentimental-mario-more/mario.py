# Query the height of the pyramid until a valid value is obtained, then print the requested pyramid.
def main():
    numOfRows = 0

    while numOfRows == 0:
        numOfRows = askForRows()

    if buildRows(numOfRows, numOfRows) == 1:
        return 1

    return 0

# Since it is recursive, it checks that the values are greater than 0. If correct,
# it builds the spaces without bricks first, then the bricks, the center space, and the remaining bricks.


def buildRows(rows, totalRows):
    if rows <= 0:
        return 1

    buildRows(rows - 1, totalRows)
    spaces = totalRows - rows

    for i in range(spaces):
        print(" ", end="")

    buildBricks(rows)
    print("  ", end="")
    buildBricks(rows)
    print("")


def buildBricks(bricks):
    for i in range(bricks):
        print("#", end="")

# Ask the height, check that it is not a value that cannot be converted to an integer,
# and then check if it is in the range of 1 to 8


def askForRows():
    try:
        numOfRows = int(input("Height: "))
        if numOfRows > 0 and numOfRows < 9:
            return numOfRows
        else:
            print("Sorry, I need a number between 1 and 8\n")
            return 0

    except ValueError:
        print("Sorry, I need a number between 1 and 8\n")
        return 0


main()
