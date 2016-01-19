#pragma once

#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

#define RMVB radioactive_mutant_vampire_bunny
#define POP_LIMIT 1000
#define MAX_POP POP_LIMIT*2
#define RMVB_PERCENT 2

extern std::ofstream outp;

class bunny
{
public:
	char sex, color[8], name[16];
	int age;
	bool radioactive_mutant_vampire_bunny;

	bunny();
	~bunny();
};

void bunnySimInit(bunny **);
int countBunnies(bunny **);
bool findMaleBunny(bunny **);
void mutate(bunny **);
int countMutants(bunny **);
bunny * reproduce(bunny *);
int noBunny(bunny **);
void bunnyDeath(bunny **);
void ageBunnies(bunny **);
void famine(bunny **);
void record(bunny **);
