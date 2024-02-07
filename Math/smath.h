#ifndef SMATH_H
#define SMATH_H
#define _GNU_SOURSE_

#define PI 3.14159265358979323846L
#define EPS 1e-9
#define NAN 0.0 / 0.0
#define INF_PLUS +1.0 / 0.0
#define INF_MINUS -1.0 / 0.0
#define E 2.71828

#include <float.h>
#include <limits.h>
#include <stdio.h>

int abs(int x);
long double acos(double x);
long double asin(double x);
long double atan(double x);
long double ceil(double x);
long double cos(double x);
long double exp(double x);
long double fabs(double x);
long double floor(double x);
long double fmod(double x, double y);
long double log(double x);
long double pow(double base, double exp2);
long double sin(double x);
long double sqrt(double x);
long double tan(double x);

#endif

// LIMITS.H CONST:
// CHAR_BIT	Количество бит в символе типа char.	 8
// SCHAR_MIN	Минимальное значение объекта типа signed char.	-128
// SCHAR_MAX	Максимальное значение объекта типа signed char.	127
// UCHAR_MAX	Максимальное значение объекта типа unsigned char.	255
// CHAR_MIN	Минимальное значение объекта типа char.	-128
// CHAR_MAX	Максимальное значение объекта типа char.	127
// MB_LEN_MAX	Максимальное количество байтов многобайтового символа, любого
// языка.	16 SHRT_MIN	Минимальное значение объекта типа short int.
// -32768 SHRT_MAX	Максимальное значение объекта типа short int.	32767
// USHRT_MAX	Максимальное значение объекта типа unsigned short int.	65535
// INT_MIN	Минимальное значение объекта типа int.	-32767
// INT_MAX	Максимальное значение объекта типа int.	2147483647
// UINT_MAX	Максимальное значение объекта типа unsigned int.
// 4294967295 LONG_MIN	Минимальное значение объекта типа long int.
// -9223372036854775808 LONG_MAX	Максимальное значение объекта типа long
// int.	9223372036854775807 ULONG_MAX	Максимальное значение объекта типа
// unsigned long int.	18446744073709551615

// FLOAT.H CONST:
// FLT_RADIX	2	Основание для всех типов данных с плавающей точкой (long
// double, double, float  и ). FLT_MANT_DIG (float) DBL_MANT_DIG (double)
// LDBL_MANT_DIG (long double)	24 53 64	Количество цифр мантиссы,
// соответственно для указанных типов данных. FLT_DIG (float) DBL_DIG (double)
// LDBL_DIG (long double)	6 15 18	Количество десятичных цифр, которые
// могут быть округлены в число с плавающей точкой и обратно, без потери данных.
// FLT_MIN_EXP (float) DBL_MIN_EXP (double) LDBL_MIN_EXP (long double)	 -125
// -1021 -16381	Минимальное отрицательное целое значение для степени, которое
// генерирует нормализованное число с плавающей точкой (запятой). FLT_MIN_10_EXP
// (float) DBL_MIN_10_EXP (double) LDBL_MIN_10_EXP (long double)	-37 -307
// -4931	Минимальное отрицательное целое значение степени основания 10
// выражение, которое будет генерировать нормализованное число с плавающей
// точкой (запятой). FLT_MAX_EXP (float) DBL_MAX_EXP (double) LDBL_MAX_EXP (long
// double)	128 1024 16384	Максимальное целое значение для степени в
// нормализованной форме представления числа с плавающей точкой (запятой).
// FLT_MAX_10_EXP (float) DBL_MAX_10_EXP (double) LDBL_MAX_10_EXP (long double)
// 383084932	Максимальное целое значение для степени с основанием 10 в
// нормализованной форме представления числа с плавающей точкой (запятой).
// FLT_MAX (float) DBL_MAX (double) LDBL_MAX (long
// double)	3.40282e+38 1.79769e+308 1.18973e+4932	Максимальные значения
// чисел с плавающей точкой (запятой). FLT_EPSILON (float) DBL_EPSILON (double)
// LDBL_EPSILON (long double)	1.19209e-07 2.22045e-16 1.0842e-19	Разница
// между 1 и минимальным значением, большим единицы, которое может быть
// представлено указанными типами данных. FLT_MIN (float) DBL_MIN (double)
// LDBL_MIN (long double)	1.17549e-38 2.22507e-308 3.3621e-4932
// Минимальные значения чисел с плавающей точкой (запятой)