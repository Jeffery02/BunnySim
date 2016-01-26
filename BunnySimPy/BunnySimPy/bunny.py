import random

class bunny(object):
    """makes a bunny"""
    age = 0
    def __init__(self):
        if random.getrandbits(1):                   # New bunny is male
            sex = 'm'
            name = getName("maleNames.txt")         # Obtain male name
        else:                                       # New bunny is female
            sex = 'f'
            name = getName("femaleNames.txt")       # Obtain female name

        color = ["white", "brown", "black", "spotted"]

        if random.randint(1,100) <= 2:              # Check for radioactive mutant vapire bunny mutation
            rmvb = True
            sex = 'x'
            print("Radioactive mutant vampire bunny", end = " ")
        else:
            rmvb = False
            print("Bunny", end = " ")

        # Store randomized specifics into new bunny object
        self.sex = sex
        self.color = color[random.getrandbits(2)]
        self.name = name
        self.radioactive_mutant_vampire_bunny = rmvb

        print(name, "has been born")       # Display that the new bunny has been born


# Obtains random name from file list
def getName(fileOfNames):
    nameList = open(fileOfNames, "r")               # Open file
    for i in range(0, random.randint(1,500)):       # Cycle through a random number of times
        name = nameList.readline()                  # Obtain name
    nameList.close()                                # Close file
    return name.split()[0]                          # Return name without all the white space and extra information


# Print population information
def printPop(bunnyPop):
    for i in range(0, len(bunnyPop)):
        if bunnyPop[i].radioactive_mutant_vampire_bunny:
            print("Radioactive mutant vampire bunny", bunnyPop[i].name, end = " ")
            print("is", bunnyPop[i].age, "year", end = "")
        else:
            print("Bunny", bunnyPop[i].name, end = " ")
            print("is", bunnyPop[i].age, "year", end = "")
        if bunnyPop[i].age != 1:
            print("s", end = "")
        print(" old,", end = " ")
        if bunnyPop[i].sex == 'm':
            print("male,", end = " ")
        elif bunnyPop[i].sex == 'f':
            print("female,", end = " ")
        else:
            print("genderless,", end = " ")
        print("with", bunnyPop[i].color, "fur")

# Things that happen when the year ends
def endYear(bunnyPop):

    for rabbit in bunnyPop:     # Age bunnies
        rabbit.age += 1

    for rabbit in bunnyPop:     # Check for reproduction conditions
        if rabbit.sex is 'm' and rabbit.age > 1:        # Check to see if there is a male bunny 2 years old or older
            male = True
            break                                       # We only need to check for 1 adult male
        else:
            male = False                                # No adult males exist
    
    if male:                        # Only perform if there is an adult male bunny
        for rabbit in bunnyPop:
            if rabbit.sex is 'f' and rabbit.age > 1:    # Check to see if there is a female bunny 2 years old or older
                babyBunny = bunny()                     # MAKE BABIES!!!
                babyBunny.color = rabbit.color          # Shares mother's color
                bunnyPop.append(babyBunny)              # Add baby bunny to the population

    mutateBunnies(bunnyPop)                         # Spread the RMVB infection

    bunnyDeath(bunnyPop)                            # Kill extra bunnies


def mutateBunnies(bunnyPop):
    mutants = 0
    for rabbit in bunnyPop:
        if rabbit.radioactive_mutant_vampire_bunny:
            mutants += 1

    mutated = 0
    if (mutants*2) < len(bunnyPop):
        while (mutated < mutants):
            i = random.randint(0, len(bunnyPop) - 1)
            if not bunnyPop[i].radioactive_mutant_vampire_bunny:
                bunnyPop[i].radioactive_mutant_vampire_bunny = True
                bunnyPop[i].sex = 'x'
                mutated += 1
    else:
        for i in range(0, len(bunnyPop)):
            bunnyPop.remove(bunnyPop[0])
        print("The radioactive mutant vampire bunnies have won")
        print(len(bunnyPop), "bunnies were left")
        input("Press enter to continue")


# Remove bunnies that died of old age
def bunnyDeath(bunnyPop):
    for rabbit in bunnyPop:
        if rabbit.radioactive_mutant_vampire_bunny and (rabbit.age > 50):           # If mutated bunny, then lives to be 50
            print("Radioactive mutant vampire bunny", rabbit.name, "has died")
            bunnyPop.remove(rabbit)                                                 # Mutated bunny dies of old age
        elif rabbit.age > 10:                                                       # Regular bunnies live to be 10
            print("Bunny", rabbit.name, "has died")
            bunnyPop.remove(rabbit)                                                 # Regular bunny dies of old age

    population = len(bunnyPop)
    deadBunnies = 0
    if population > 1000:                                                           # Make sure bunny population does not exceed 1000
        print("A food shortage has occurred")
        while len(bunnyPop) > population/2:                                         # Half of the bunny population starves
            deadBunnies += 1
            bunnyPop.remove(bunnyPop[random.randint(0,len(bunnyPop) - 1)])
        print(deadBunnies, "bunnies have starved to death")                         # Print the number of bunnies that starved to death

        input("Press enter to continue")
        

