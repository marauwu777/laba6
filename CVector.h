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
	// очистка
	void clear();
	// Конструктор инициализации
	CVector(int size = 0, const double* NewData = nullptr);
	// Копия конструктор
	CVector(const CVector& vec);
	// Деструктор
	virtual ~CVector();
	// Копирование объект
	void copyobj(const CVector& vec);
	// Копирование размер и данные
	int copy(const int New_size, const double* New_data);
	// Вывод
	void print();
	// прибавление
	void add(CVector& vec);
	//вычитание
	void subtract(CVector& vec);
	//модуль
	double length();
	// скалярное произведение
	friend double scalar_product(CVector& vec1, CVector& vec2);
	// сумма
	friend CVector sum(CVector& vec1, CVector& vec2);
	// разность
	friend CVector diff(CVector& vec1, CVector& vec2);
	// оператор присваивания
	CVector& operator=(CVector& vec);
	// l-value
	double& operator[](int index);
	// r-value
	double operator[](int index) const;
	// оператор скалярного произведения
	friend double operator*(CVector& vec1, CVector& vec2);
	// опреатор суммы
	friend CVector operator+(CVector& vec1, CVector& vec2);
	// оператор разности
	friend CVector operator-(CVector& vec1, CVector& vec2);
	// оператор прибавления
	CVector& operator+=(CVector& vec);
	// оператор вычитания
	CVector& operator-=(CVector& vec);
	// функтор модуль
	double operator()();
	// конструктор перемещения
	CVector(CVector&& vec);
	// оператор перемещения
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
