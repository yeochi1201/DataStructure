#include <iostream>

using namespace std;

class Queue {
private:
	int* array;
	int maxBound;
	int writePos;
	int readPos;
	int count;

	void ExtendArray() {
		int* temp = new int[maxBound * 2];
		copy(array, array + maxBound, temp);
		delete[] array;
		array = temp;
		temp = NULL;
		maxBound *= 2;
	}

	void Reposit() {
		int i = 0;
		while (true) {
			if (i+readPos == maxBound || array[i+readPos] == NULL)
				break;
			array[i] = array[i + readPos];
		}
		writePos = writePos - readPos;
		readPos = 0;

		if (writePos == maxBound) {
			ExtendArray();
		}
	}
public:
	Queue(int n = 10) {
		array = new int[n];
		maxBound = n;
		writePos = 0;
		readPos = 0;
		count = 0;
	}
	
	bool Empty() {
		if (count == 0) return true;
		else return false;
	}

	void Push(int t) {
		if (writePos == maxBound) {
			Reposit();
		}
		array[writePos] = t;
		writePos++;
		count++;
	}

	int Pop() {
		if (Empty()) {
			return NULL;
		}
		int result = array[readPos];
		array[readPos] = NULL;
		readPos++;
		count--;
	}

	int Count() {
		return count;
	}

	void Clear() {
		for (int i = 0; i < count; i++) {
			array[readPos + i] = NULL;
		}
	}

	int Front() {
		return array[readPos];
	}

	int Back() {
		return array[writePos - 1];
	}
};
