int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

class RodCutting {
private:
	int* p;
	int* r;
	int* s;
	int size;
private:
	void bottomUpCutRod() {
		r[0] = 0;
		for (int i = 1; i < size; i++) {
			int q = -9999;
			for (int j = 1; j <= i; j++) {
				if (p[j] + r[i - j] > q) {
					q = p[j] + r[i - j];
					s[i] = j;
				}
			}
			r[i] = q;
		}
	}
	int memorizedCutRodAux(int length) {
		if (r[length] >= 0) {
			return r[length];
		}
		int q;
		if (length == 0) {
			q = 0;
		}
		else {
			q = -9999;
			for (int i = 1; i <= length; i++) {
				//q = max(q, p[i] + memorizedCutRodAux(length - i));
				if (p[i] + memorizedCutRodAux(length - i) > q) {
					q = p[i] + memorizedCutRodAux(length - i);
					s[length] = i;
				}
			}
		}
		r[length] = q;
		return q;
	}
public:
	RodCutting(int* valuePerLength,int length) {
		p = valuePerLength;
		r = new int[length];
		s = new int[length];
		size = length;
	}

	/*divide-and-conquer method*/
	int memorizedCutRod(int length) {
		r = new int[length];
		for (int i = 0; i < length; i++) {
			r[i] = -9999;
		}
		return memorizedCutRodAux(length);
	}
	
	/*dynamic programming(bottom to up) method*/
	int getMaxValue_d(int length){
		bottomUpCutRod();
		return r[length];
	}

	void printRodSolution(int length) {
		int optimalValue = getMaxValue_d(length);
		std::cout << "optimal value : " << optimalValue << std::endl;
		while (length > 0) {
			std::cout << s[length] << std::endl;
			length = length - s[length];
		}
	}
	
};
