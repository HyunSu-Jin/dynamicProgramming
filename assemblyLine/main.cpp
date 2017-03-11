#include <iostream>
#include "assemblyLine.h"

int main() {
	int line1[] = { 7,9,3,4,8,4 };
	int line2[] = { 8,5,6,4,5,7 };
	int numOfStation = sizeof(line1) / sizeof(int);
	int cost1to2[] = { 2,1,1,3,4 };
	int cost2to1[] = { 2,1,2,2,1 };
	int start1 = 2;
	int start2 = 4;
	int exit1 = 3;
	int exit2 = 2;

	AssemblyLine assem = AssemblyLine(line1, line2, numOfStation, cost1to2, cost2to1, start1, start2, exit1, exit2);
	cout << "optimal value : " << assem.getOptimalValue() << endl;
	cout << "optimal path : ";
	assem.showOptimalPath();


}