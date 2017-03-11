#include <string>
#include <iostream>

using namespace std;

int min(int num1, int num2,int &minEle) {
	if (num1 < num2) {
		minEle = 1;
		return num1;
	}
	else {
		minEle = 2;
		return num2;
	}
}

class AssemblyLine {
	int* line1;
	int* line2;
	int* cost1to2;
	int* cost2to1;
	int start1, start2;
	int exit1, exit2;
	int numOfStation;

	int **pathRecord;
	int lastPath;
private:
	int getLine1AtStation(int i, int sumLine1, int sumLine2) {
		int minLine;
		int value = min(sumLine1 + line1[i], sumLine2 + line1[i] + cost2to1[i-1], minLine);
		pathRecord[0][i] = minLine;
		return value;
	}

	int getLine2AtStation(int i, int sumLine1, int sumLine2) {
		int minLine;
		int value = min(sumLine1 + line2[i] + cost1to2[i-1], sumLine2 + line2[i], minLine);
		pathRecord[1][i] = minLine;
		return value;
	}
public:
	AssemblyLine(int* line1,int* line2,int numOfStation,int* cost1to2,int* cost2to1,int start1,int start2,int exit1,int exit2) {
		this->line1 = line1;
		this->line2 = line2;
		this->cost1to2 = cost1to2;
		this->cost2to1 = cost2to1;
		this->start1 = start1;
		this->start2 = start2;
		this->exit1 = exit1;
		this->exit2 = exit2;
		this->numOfStation = numOfStation;

		pathRecord = new int*[2];
		pathRecord[0] = new int[numOfStation]; // It doesn't use index 0
		pathRecord[1] = new int[numOfStation];
	}

	int getOptimalValue(){
		int sumLine1_b = line1[0] + start1;
		int sumLine2_b = line2[0] + start2;
		int sumLine1_a;
		int sumLine2_a;
		int optimalValue;

		for (int i = 1; i < numOfStation; i++) {
			sumLine1_a = getLine1AtStation(i, sumLine1_b, sumLine2_b);
			sumLine2_a = getLine2AtStation(i, sumLine1_b, sumLine2_b);
			//cout << "i : " << i << "[" << "sumLine1 : " << sumLine1_a << "]" << endl;
			//cout << "i : " << i << "[" << "sumLine2 : " << sumLine2_a << "]" << endl;
			sumLine1_b = sumLine1_a;
			sumLine2_b = sumLine2_a;
		}

		if (sumLine1_a + exit1 < sumLine2_a + exit2) {
			optimalValue = sumLine1_a + exit1;
			lastPath = 1;
		}
		else {
			optimalValue = sumLine2_a + exit2;
			lastPath = 2;
		}
		return optimalValue;
	}

	void showOptimalPath() {
		string optimalPath = "";
		optimalPath.append(to_string(lastPath));
		for (int i = numOfStation - 1; i >= 1; i--) {
			optimalPath.append(to_string(pathRecord[lastPath - 1][i]));
			lastPath = pathRecord[lastPath - 1][i];
		}
		
		for (string::reverse_iterator itr = optimalPath.rbegin(); itr != optimalPath.rend(); itr++) {
			cout << (*itr);
		}
		cout << endl;
	}
};