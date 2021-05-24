from cs50 import get_int

while True:
    height = get_int("Height : ")
    if height > 0 and height <= 8:
        break


column_number = height - 1
for i in range(height):
    for j in range(0, column_number - i):
        print(" ", end='')
    for k in range(i + 1):
        print("#", end='')
    print("  ", end='')
    for l in range(i+1):
        print("#", end='')
    print()
