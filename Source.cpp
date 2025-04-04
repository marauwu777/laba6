#include <iostream>
#include <vector>
#include "CVector.h"
#include <cmath>
using namespace std;
void CVector::init()
{
	size = 0;
	data = nullptr;
}

// �������
void CVector::clear() {
	delete[] data;
	init();
}
// ����������� ������
void CVector::copyobj(const CVector& vec) {
	if (this == &vec) {
		return;
	}
	copy(vec.size, vec.data);
}
// ����������� ������ � ������
int CVector::copy(const int New_size, const double* New_data) {
	if (data != New_data) {
		clear();
		data = new double[New_size];
		if (data) {
			size = New_size;
			for (int i = 0; i < size; i++) {
				data[i] = New_data[i];
			}
		}
	}
	return New_size;
}
// ����������� �������������
CVector::CVector(const int NewSize, const double* NewData) {
	init();
	copy(NewSize, NewData);

}
// ����� �����������
CVector::CVector(const CVector& vec) {
	cout << " copy constructor" << endl;
	init();
	copyobj(vec);
}
// ����������
CVector::~CVector() {
	clear();
}
// �����
void CVector::print() {
	cout << "Num: " << size << " Data: ";
	if (data) {
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
	}
	else {
		cout << "NULL";
	}
	cout << endl;
}
// ��������� ������������
double scalar_product(CVector& vec1, CVector& vec2) {
	double result = 0;
	int s = min(vec1.size, vec2.size);
	for (int i = 0; i < s; i++) {
		result += vec1.data[i] * vec2.data[i];
	}
	return result;

}

// ������
double CVector::length() {
	return(sqrt(scalar_product(*this, *this)));
}
// �����
CVector sum(CVector& vec1, CVector& vec2) {
	int smin = min(vec1.size, vec2.size);
	int smax = max(vec1.size, vec2.size);
	double* resultData = new double[smax];

	for (int i = 0; i < smin; i++) {
		resultData[i] = vec1.data[i] + vec2.data[i];
	}
	for (int i = smin; i < vec1.size; i++) {
		resultData[i] = vec1.data[i];
	}
	for (int i = smin; i < vec2.size; i++) {
		resultData[i] = vec2.data[i];
	}
	CVector result;
	result.size = smax;
	result.data = resultData;
	return result;
}
// ��������
CVector diff(CVector& vec1, CVector& vec2) {
	int smin = min(vec1.size, vec2.size);
	int smax = max(vec1.size, vec2.size);
	double* resultData = new double[smax];

	for (int i = 0; i < smin; i++) {
		resultData[i] = (vec1.data[i] - vec2.data[i]);
	}
	for (int i = smin; i < vec1.size; i++) {
		resultData[i] = vec1.data[i];
	}
	for (int i = smin; i < vec2.size; i++) {
		resultData[i] = -vec2.data[i];
	}
	CVector result;
	result.size = smax;
	result.data = resultData;
	return result;
}

// �����������
void CVector::add(CVector& vec) {
	this->copyobj(sum(*this, vec));
}
// ���������
void CVector::subtract(CVector& vec) {
	this->copyobj(diff(*this, vec));
}
// �������� ������������
CVector& CVector::operator=(CVector& vec) {
	cout << "=copy" << endl;
	if (this != &vec) {
		copyobj(vec);
	}
	return *this;
}
// l-value
double& CVector::operator[](int index) {
	return data[index];
}
// r-value
double CVector::operator[](int index) const {
	return data[index];
}
// �������� ���������� ������������
double operator*(CVector& vec1, CVector& vec2) {
	return scalar_product(vec1, vec2);
}
// �������� �����
CVector operator+(CVector& vec1, CVector& vec2) {
	return sum(vec1, vec2);
}
// �������� ��������
CVector operator-(CVector& vec1, CVector& vec2) {
	return diff(vec1, vec2);
}
// �������� �����������
CVector& CVector::operator+=(CVector& vec) {
	this->add(vec);
	return *this;
}
// �������� ���������
CVector& CVector::operator-=(CVector& vec) {
	this->subtract(vec);
	return *this;
}
// ������� ������
double CVector::operator()() {
	return this->length();
}
// ������� ����� vprint
void CVector::vprint() {
	print();
}
// ������� ����� out() ��� CVector2
void CVector2::print() {
	cout << "NUM: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " << data[i] << endl;
	}
	cout << endl;;
}
// ����������� ����� vout() ��� CVector3
void CVector3::vprint() {
	cout << "NUM: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " << data[i] << endl;
	}
	cout << endl;;
}
CVector2::~CVector2() {
	clear();
}
CVector3::~CVector3() {
	clear();
}
// ���� ������������ �����������
CVector::CVector(CVector&& vec) : size(vec.size), data(vec.data) {
	cout << "Move constructor" << endl;
	vec.init();
}
// �������� �����������
CVector& CVector::operator=(CVector&& vec) {
	cout << "=Move" << endl;
	if (this != &vec) {
		clear();
		size = vec.size;
		data = vec.data;
		vec.init();
	}
	return *this;
}
