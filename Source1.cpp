#include "CVector.h"

int main() {
	int size1;
	while (true) {
		cout << "Enter vec1 size - ";
		cin >> size1;
		if (size1 == 0) {
			break;
		}
		cout << "Fill vec1" << endl;
		double* arr1 = new double[size1];
		for (int i = 0; i < size1; i++) {
			cout << "Vec1 element [" << i << "] - ";
			cin >> arr1[i];
			cout << endl;
		}
		CVector vec1(size1, arr1);
		CVector vec3(size1, arr1);
		CVector vec2;
		cout << "a = b (copy)" << endl;
		vec2 = vec1;
		vec2.print();
		cout << "a = b + c (move)" << endl;
		vec2 = vec1 + vec3;
		vec2.print();
		delete[] arr1;
		CVector vec4(move(vec1));
		vec4.print();
	}
	return 0;
}
