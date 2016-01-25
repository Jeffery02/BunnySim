import bunny
import random

rabbit = []

for i in range(0,5):
    rabbit.append(bunny.bunny())

for obj in rabbit:
    print(obj.age, obj.sex, obj.color, obj.name, obj.radioactive_mutant_vampire_bunny)

print("\nBunny 1/", len(rabbit), end = ": "),
print("age =", rabbit[1].age, "\tsex =", rabbit[1].sex, "\tcolor =", rabbit[1].color, "\tname =", rabbit[1].name, "\trmvb:", rabbit[1].radioactive_mutant_vampire_bunny)
del rabbit[1]
print("Bunny 1/", len(rabbit), end = ": "),
print("age =", rabbit[1].age, "\tsex =", rabbit[1].sex, "\tcolor =", rabbit[1].color, "\tname =", rabbit[1].name, "\trmvb:", rabbit[1].radioactive_mutant_vampire_bunny)