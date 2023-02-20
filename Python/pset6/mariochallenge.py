from cs50 import get_string

height = int(get_string("Height: "))

for i in range(height):
    current = i + 1

    print(" " * (height - current), end="")
    print("#" * (current), end="")

    print(" ", end="")

    print("#" * (current), end="")
    print(" " * (height - current), end="")

    print()