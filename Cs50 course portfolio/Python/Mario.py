from cs50 import get_int

h = 0

while (h > 8 or h < 1):  # This part is programmed to get a given input from the user until it receives the correct input
    
    h = get_int("Height: ")

for x in range(1, h + 1):
    print(" " * (h - x), end="")  # this part is programmed to print spaces
    print("#" * (x))  # this part is programed to print hashes
