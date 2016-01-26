import bunny
import random

years = 0
rabbits = []

for i in range(0,5):
    rabbits.append(bunny.bunny())

bunny.printPop(rabbits)

print("Initial bunny population")
input("Press enter to begin the simulation")

while len(rabbits) > 0:
    bunny.endYear(rabbits)
    bunny.printPop(rabbits)
    years += 1
    print("Year", years, "has ended with", len(rabbits), "still alive")

print("All bunnies have died")