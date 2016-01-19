#include "stdafx.h"
#include "bunny.h"

time_t seedShift = 0;

std::ofstream outp;

// Initialize the bunny class
bunny::bunny()
{
	// Make sure the seed is different for every iteration
	srand(time(NULL) + (15485863 * seedShift++));

	// Generate random jumble of random length for naming
	int i, j = 4 + ((rand() % 56) / 7);
	strcpy_s(name, "            ");
	for (i = 0; i < j; i++)
		name[i] = 'a' + (rand() % 26);
	name[0] -= 0x20;	// Capitalize the first letter
	name[12] = 0;

	// New born
	age = 0;

	// Male or Female?
	if (rand() % 2)
		sex = 'm';
	else
		sex = 'f';

	// Which color?
	switch (rand() % 4) {
	case 0:
		strcpy_s(color, "white  ");
		break;
	case 1:
		strcpy_s(color, "brown  ");
		break;
	case 2:
		strcpy_s(color, "black  ");
		break;
	case 3:
		strcpy_s(color, "spotted");
		break;
	}

	// Is it a radioactive mutant vampire bunny?
	if ((rand() % 100) < RMVB_PERCENT) {
		radioactive_mutant_vampire_bunny = true;
		sex = 'x';
		std::cout << "Radioactive Mutant Vampire ";
		outp << "Radioactive Mutant Vampire ";
	}
	else
		radioactive_mutant_vampire_bunny = false;

	std::cout << "Bunny " << name << " was born" << std::endl;
	outp << "Bunny " << name << " was born" << std::endl;
}

// Display death information upon bunny deletion
bunny::~bunny()
{
	if (RMVB) {
		std::cout << "Radioactive Mutant Vampire ";
		outp << "Radioactive Mutant Vampire ";
	}
	std::cout << "Bunny " << name << " has died" << std::endl;
	outp << "Bunny " << name << " has died" << std::endl;
}

// Initialize bunny population array for simulation
void bunnySimInit(bunny ** bunnyPop)
{
	int i;

	// Initialize bunny population to 0;
	for (i = 0; i < MAX_POP; i++)
		bunnyPop[i] = NULL;

	// Initialize simulation with 5 bunnies.
	for (i = 0; i < 5; i++) {
		bunnyPop[i] = new bunny;
		//		cout << bunnyPop[i]->name << ": " << bunnyPop[i]->color << " " << bunnyPop[i]->sex << " RMVB = " << bunnyPop[i]->RMVB << endl;
		//		system("pause");
	}
}

// Count bunny population
int countBunnies(bunny ** bunnyPop)
{
	int i, count = 0;
	for (i = 0; i < MAX_POP; i++) {
		if (bunnyPop[i])
			count++;
	}
	return count;
}

// Check if there is at least one adult male bunny
bool findMaleBunny(bunny ** bunnyPop) {
	for (int i = 0; i < MAX_POP; i++) {
		if ((bunnyPop[i]) && (bunnyPop[i]->sex == 'm') && (bunnyPop[i]->age >= 2))
			return true;
	}
	return false;
}

// Spread the radioactive mutant vampire bunny plague
void mutate(bunny ** bunnyPop)
{
	int normal, mutant, found, i, j, k;

	//	int total = countBunnies(bunnyPop);

	// Count infected and non-infected bunnies
	mutant = countMutants(bunnyPop);
	normal = countBunnies(bunnyPop) - mutant;

	//	std::cout << mutant << " + " << normal << " = " << total << std::endl;

	// Mutate one normal bunny for each radioactive mutant vampire bunny
	for (i = 0; i < mutant; i++) {
		found = 0;
		if ((normal - i) == 0)
			return;
		j = 1 + (rand() % (normal - i));
		k = 0;
		while (found < j) {
			if (bunnyPop[k] && (!bunnyPop[k]->RMVB))
				found++;
			k++;
		}
		bunnyPop[k - 1]->sex = 'x';
		bunnyPop[k - 1]->RMVB = true;
	}
}

// Count number of infect bunnies
int countMutants(bunny ** bunnyPop)
{
	int count = 0;
	for (int i = 0; i < MAX_POP; i++) {
		if ((bunnyPop[i]) && (bunnyPop[i]->RMVB))
			count++;
	}
	return count;
}

// Create baby bunny from adult mother
bunny * reproduce(bunny * mommy)
{
	if ((mommy->age < 2) | mommy->RMVB)
		return NULL;
	bunny * baby = new bunny;
	strcpy_s(baby->color, mommy->color);
	return baby;
}

// Find the index value of the first empty slot
int noBunny(bunny ** bunnyPop)
{
	for (int i = 0; i < MAX_POP; i++) {
		if (!bunnyPop[i])
			return i;
	}
	return NULL;
}

// Kill the bunny and initialize pointer back to NULL
void bunnyDeath(bunny ** bunnyInd)
{
	if (*bunnyInd == 0)
		return;
	delete *bunnyInd;
	*bunnyInd = 0;
}

// Age each bunny and kill bunnies that are too old
void ageBunnies(bunny ** bunnyPop)
{
	for (int i = 0; i < MAX_POP; i++) {
		if (bunnyPop[i]) {
			bunnyPop[i]->age++;
			if ((bunnyPop[i]->RMVB) && (bunnyPop[i]->age >= 50))
				bunnyDeath(&bunnyPop[i]);
			else if ((!bunnyPop[i]->RMVB) && bunnyPop[i]->age > 10)
				bunnyDeath(&bunnyPop[i]);
		}
	}
}

// Food shortage! Half of the bunny population dies
void famine(bunny ** bunnyPop)
{
	int i, starved = 0, population = countBunnies(bunnyPop);
	if (population < 1000)
		return;
	std::cout << "A food shortage has occured" << std::endl;
	outp << "A food shortage has occured" << std::endl;
	for (i = 0; i < MAX_POP; i++) {
		if (bunnyPop[i] && (rand() % 2)) {
			bunnyDeath(&bunnyPop[i]);
			starved++;
			if (starved >= (population / 2)) {
				std::cout << starved << " bunnies have starved to death" << std::endl;
				outp << starved << " bunnies have starved to death" << std::endl;
				system("pause");
				return;
			}
			i = 0;
		}
	}
}

// Record population information of the current turn
void record(bunny ** bunnyPop)
{
	for (int i = 0; i < MAX_POP; i++) {
		if (bunnyPop[i]) {
			std::cout << "Name: " << bunnyPop[i]->name << "\t| Sex: " << bunnyPop[i]->sex << "\t| Color: " << bunnyPop[i]->color << "\t| Age: " << bunnyPop[i]->age << "\t| RMVB: " << bunnyPop[i]->radioactive_mutant_vampire_bunny << std::endl;
			outp << "Name: " << bunnyPop[i]->name << "\t| Sex: " << bunnyPop[i]->sex << "\t| Color: " << bunnyPop[i]->color << "\t| Age: " << bunnyPop[i]->age << "\t| RMVB: " << bunnyPop[i]->radioactive_mutant_vampire_bunny << std::endl;
		}
	}
}