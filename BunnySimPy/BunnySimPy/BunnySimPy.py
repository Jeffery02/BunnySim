import bunny
#import random

years = 0
population = 0
rabbits = []

for i in range(0,5):
    rabbits.append(bunny.bunny())

bunny.printPop(rabbits)

print("Initial bunny population")
input("Press enter to begin the simulation")

while len(rabbits) > 0:
    bunny.endYear(rabbits)
    if len(rabbits) > population:
        population = len(rabbits)
    bunny.printPop(rabbits)
    years += 1
    print("Year", years, "has ended")

print("The largest population was", population, "bunnies")