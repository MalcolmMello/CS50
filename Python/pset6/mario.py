from cs50 import get_string


def main():
    height = int(get_string("Height: "))

    draw(height)

def draw(h):
    if h == 0:
        return

    draw(h-1)

    for i in range(h):
        print("#", end="")
    print()


main()