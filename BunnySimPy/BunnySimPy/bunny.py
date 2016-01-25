import random

class bunny(object):
    """makes a bunny"""
    age = 0
    def __init__(self):
        if random.getrandbits(1):
            sex = 'm'
        else:
            sex = 'f'

        color = ["white  ", "brown  ", "black  ", "spotted"]

        if random.randint(1,100) <= 2:
            rmvb = True
        else:
            rmvb = False

        self.sex = sex
        self.color = color[random.getrandbits(2)]
        self.name = "testBunny"
        self.radioactive_mutant_vampire_bunny = rmvb


# Print population information
def printPop(bunnyPop):
    for i in range(0, len(bunnyPop)):
        print("Bunny ", i+1, "/", len(bunnyPop), sep = "", end = ": ")
        print( "age =", bunnyPop[i].age, "\tsex =", bunnyPop[i].sex, "\tcolor =", bunnyPop[i].color, "\tname =", bunnyPop[i].name, "\trmvb:", bunnyPop[i].radioactive_mutant_vampire_bunny)
