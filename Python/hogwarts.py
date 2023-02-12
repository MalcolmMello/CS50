import csv

houses = {
    "Gryffindor": 0,
    "Hufflepuff": 0,
    "Ravenclaw": 0,
    "Slytherin": 0,
}

with open("Sorting Hat (Responses) - Form Response 1.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in header:
        house = row[1]
        houses[house] += 1

for house in houses:
    print(f"{house}: {houses[house]}")