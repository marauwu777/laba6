#pragma once
#include <iostream>
using namespace std;
class CVector
{

protected:
	int size;
	double* data;
private:
	void init();
public:
	virtual void vprint();
	// �������
	void clear();
	// ����������� �������������
	CVector(int size = 0, const double* NewData = nullptr);
	// ����� �����������
	CVector(const CVector& vec);
	// ����������
	virtual ~CVector();
	// ����������� ������
	void copyobj(const CVector& vec);
	// ����������� ������ � ������
	int copy(const int New_size, const double* New_data);
	// �����
	void print();
	// �����������
	void add(CVector& vec);
	//���������
	void subtract(CVector& vec);
	//������
	double length();
	// ��������� ������������
	friend double scalar_product(CVector& vec1, CVector& vec2);
	// �����
	friend CVector sum(CVector& vec1, CVector& vec2);
	// ��������
	friend CVector diff(CVector& vec1, CVector& vec2);
	// �������� ������������
	CVector& operator=(CVector& vec);
	// l-value
	double& operator[](int index);
	// r-value
	double operator[](int index) const;
	// �������� ���������� ������������
	friend double operator*(CVector& vec1, CVector& vec2);
	// �������� �����
	friend CVector operator+(CVector& vec1, CVector& vec2);
	// �������� ��������
	friend CVector operator-(CVector& vec1, CVector& vec2);
	// �������� �����������
	CVector& operator+=(CVector& vec);
	// �������� ���������
	CVector& operator-=(CVector& vec);
	// ������� ������
	double operator()();
	// ����������� �����������
	CVector(CVector&& vec);
	// �������� �����������
	CVector& operator=(CVector&& vec);
};
class CVector2 : public CVector {
public:
	CVector2(int size = 0, const double* NewData = nullptr) : CVector(size, NewData) {};
	CVector2(const CVector2& vec) : CVector(vec) {};
	~CVector2();
	void print();
};

class CVector3 : public CVector {
public:
	CVector3(int size = 0, const double* NewData = nullptr) : CVector(size, NewData) {};
	CVector3(const CVector3& vec) : CVector(vec) {};
	~CVector3();
	virtual void vprint();
};
