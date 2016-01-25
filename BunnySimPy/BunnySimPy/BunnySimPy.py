import bunny
import random

rabbit = []

for i in range(0,5):
    rabbit.append(bunny.bunny())

for obj in rabbit:
    print(obj.age, obj.sex, obj.color, obj.name, obj.radioactive_mutant_vampire_bunny)

print("\npopulation =", len(rabbit))
bunny.printPop(rabbit)
deadBunny = random.randint(0,len(rabbit)-1)
print("\nBunny", deadBunny + 1, "has died")
del rabbit[deadBunny]
print("\npopulation =", len(rabbit))
bunny.printPop(rabbit)