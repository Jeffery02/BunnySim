// BunnySim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bunny.h"

using namespace std;

int main()
{
	outp.open("Bunny History.txt");

	// Array to store bunny object population
	bunny * bunnyPop[MAX_POP];
	int years = 0, mutants;

	bunnySimInit(bunnyPop);

	int i, most = 0;
	while (countBunnies(bunnyPop)) {	// Continue until population is dead

		// Bunnies practice multiplication
		bool daddy = findMaleBunny(bunnyPop);
		for (i = 0; i < MAX_POP; i++) {
			if (daddy && (bunnyPop[i]) && (bunnyPop[i]->sex == 'f')) {
				bunnyPop[noBunny(bunnyPop)] = reproduce(bunnyPop[i]);
			}
		}
		ageBunnies(bunnyPop);

		// Spread mutation except during year 0
		if (years)
			mutate(bunnyPop);

		// Record largest population
		if (most < countBunnies(bunnyPop))
			most = countBunnies(bunnyPop);

		// Check for food shortage
		famine(bunnyPop);

		// Display current population total
		cout << "There are " << countBunnies(bunnyPop) << " bunnies currently alive" << endl;
		outp << "There are " << countBunnies(bunnyPop) << " bunnies currently alive" << endl;

		// Display details of current population
		record(bunnyPop);

		// If every bunny is a mutant, then it's the apocalypse and simulation ends
		mutants = countMutants(bunnyPop);
		if (mutants && (mutants >= countBunnies(bunnyPop))) {
			cout << "The Radioactive Mutant Vampire Bunnies have won!!!" << endl;
			outp << "The Radioactive Mutant Vampire Bunnies have won!!!" << endl;
			system("pause");
			for (i = 0; i < MAX_POP; i++)
				bunnyDeath(&bunnyPop[i]);
		}

		years++;	// Another year has now passed
	}

	cout << "It took " << years << " years and the largest bunny population was " << most << " bunnies" << endl;
	outp << "It took " << years << " years and the largest bunny population was " << most << " bunnies" << endl;

	outp.close();
	system("pause");

	return 0;
}
