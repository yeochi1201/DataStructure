#include <iostream>

using namespace std;

class Stack {
private:
	int* array;
	int maxBound;
	int pos;

	void ExtendArray() {
		int* temp = new int[maxBound * 2];
		copy(array, array + maxBound, temp);
		delete[] array;
		array = temp;
		temp = NULL;
		maxBound *= 2;
	}

public:
	Stack(int n = 10) {
		array = new int[n];
		maxBound = n;
		pos = 0;
	}

	bool Empty() {
		if (pos == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Push(int t) {
		if (pos == maxBound) {
			ExtendArray();
		}
		array[pos] = t;
		pos++;
	}

	int Pop() {
		if (Empty()) {
			return NULL;
		}
		pos--;
		int result = array[pos];
		array[pos] = NULL;
		return result;
	}

	int Count() {
		return pos;
	}

	void Clear() {
		for (int i = 0; i < pos; i++) {
			array[i] = NULL;
		}
	}
};

