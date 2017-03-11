#include <iostream>
#include "rodcutting.h"

int main() {
	int p[] = { 0,1,5,8,9,10,17,17,20,24,30 };
	RodCutting cut = RodCutting(p, sizeof(p) / sizeof(int));
	//std::cout << cut.getMaxValue_d(4) << std::endl;
	//std::cout << cut.memorizedCutRod(4) << std::endl;
	cut.printRodSolution(4);
}