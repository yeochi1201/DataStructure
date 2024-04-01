#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
	T* array;
	int maxBound;
	int writePos;
	int readPos;
	int count;

	void ExtendArray() {
		T* temp = new T[maxBound * 2];
		copy(array, array + maxBound, temp);
		delete[] array;
		array = temp;
		temp = NULL;
		maxBound *= 2;
	}

public:
	Queue(int n = 10) {
		array = new T[n];
		maxBound = n;
		writePos = 0;
		readPos = 0;
		count = 0;
	}

	bool Empty() {
		if (count == 0) return true;
		else return false;
	}

	void Push(T t) {
		if (count == maxBound) {
			ExtendArray();
		}
		array[writePos] = t;
		writePos = writePos + 1 % maxBound;
		count++;
	}

	T Pop() {
		if (Empty()) {
			return NULL;
		}
		T result = array[readPos];
		array[readPos] = NULL;
		readPos = readPos + 1 % maxBound;
		count--;
	}

	int Count() {
		return count;
	}

	void Clear() {
		for (int i = 0; i < count; i++) {
			array[readPos + i % maxBound] = NULL;
		}
	}

	T Front() {
		return array[readPos];
	}

	T Back() {
		return array[writePos - 1];
	}
};

int main() {
	return 0;
}