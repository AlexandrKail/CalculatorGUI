#pragma once
#include<windows.h>
#include<algorithm>
#include<cmath>
#include"resource.h"

//Константы
const unsigned long long PRECESSION = 1000000000;

//Структура для хранения вещественного числа в целочисленном предстовлении
struct FloatNumb
{
	long long whole;
	long long decPart;
	bool neg;
	FloatNumb(int _intPart = 0, int _decPart = -1, bool _neg = false) : whole(_intPart), decPart(_decPart), neg(_neg)
	{}
	void clean();
};


class Calculator
{
	long double result;
	long double lVal;
	long double rVal;
	int lCount;
	int rCount;
	int idx;

//Метод извлечения данных из массива(lValue и rValue)
	void dataExtraction(char* input);
//Метод извлечения квадратного корня из числа
	void extSQRT(char* input);
//Запись результата подвырожения в массив
	void writeRes(char* input);
//Вычесляет колличество символов числа, до арифмитического знака или после
	int numbCount(char* input, int i, bool direction);
//Переводит символы в вещественное число
	double charToDouble(char* input, int i, int numb);
//Переводит веществинные числа в char
	void DoubleToChar(char* buf);
//Разделяет вещественное число на целую и дробную часть
	void devideDouble(FloatNumb& obj, long double val);
//Метод перевода int в char
	void intToChar(char* buf, FloatNumb& obj);
//Вспомогательный метод который переворачивает массив(Первый символ становится последним)
	void inversArr(char* buf, bool negative, const int SZ);
//Вставляет в массив вместо подвырожения его результат
	void copy(char* input, char* buftmp);
	bool checkNull(char* buf, int i);

public:
//Основной публичный метод
	int doColculations(char* input);
 };

//Прототипы
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

