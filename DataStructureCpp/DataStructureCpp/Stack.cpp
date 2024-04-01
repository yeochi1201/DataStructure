#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
	T* array;
	int maxBound;
	int pos;

	void ExtendArray() {
		T* temp = new T[maxBound * 2];
		copy(array, array + maxBound, temp);
		delete[] array;
		array = temp;
		temp = NULL;
		maxBound *= 2;
	}

public:
	Stack(int n = 10) {
		array = new T[n];
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

	void Push(T t) {
		if (pos == maxBound) {
			ExtendArray();
		}
		array[pos] = t;
		pos++;
	}

	T Pop() {
		if (Empty()) {
			return NULL;
		}
		pos--;
		T result = array[pos];
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

