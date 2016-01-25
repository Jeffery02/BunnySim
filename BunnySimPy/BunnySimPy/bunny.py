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

        self.sex = sex
        self.color = color(random.getrandbits(2))
        self.name = "testBunny"
        self.radioactive_mutant_vampire_bunny = random.getrandbits(1)

