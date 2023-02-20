from cs50 import get_float

def main():
    amountInCents = get_amount() * 100

    change = 0

    coins = 0

    while change < amountInCents:
        if(change + 25 <= amountInCents):
            change += 25
            coins += 1

        elif(change + 10 <= amountInCents):
            change += 10
            coins += 1

        elif(change + 5 <= amountInCents):
            change += 5
            coins += 1

        elif(change + 1 <= amountInCents):
            change += 1
            coins += 1

    print(coins)

def get_amount():
    while True:
        required_change = get_float("Change owned: ")

        if(required_change < 0):
            print("Type a positive number!\n");
        else:
            break
    return required_change

main()
