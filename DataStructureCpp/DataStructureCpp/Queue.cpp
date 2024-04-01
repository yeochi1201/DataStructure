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
		if (writePos == maxBound) {
			Reposit();
		}
		array[writePos] = t;
		writePos++;
		count++;
	}

	T Pop() {
		if (Empty()) {
			return NULL;
		}
		T result = array[readPos];
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