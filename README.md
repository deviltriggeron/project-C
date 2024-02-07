# project-C

Decimal - Реализация библиотеки с новым типом данных decimal

Math - Реализация стандартной библиотеки math.h

Matrix - Реализация работы с матрицами

SimpleBash - Реализация утилит cat и grep

SmartCalc - Реализация расширенного калькулятора

String - Реализация стандартной библиотеки string.h

## Decimal

- Создан тип данных decimal и decimal_overflow   
Сложение - int add(decimal value_1, decimal value_2, decimal *result)      
Вычитание - int sub(decimal value_1, decimal value_2, decimal *result)   
Умножение - int mul(decimal value_1, decimal value_2, decimal *result)    
Деление - int div(decimal value_1, decimal value_2, decimal *result)  
Меньше - int s21_is_less(s21_decimal, s21_decimal)  
Меньше или равно - int s21_is_less_or_equal(s21_decimal, s21_decimal)  
Больше - int s21_is_greater(s21_decimal, s21_decimal)  
Больше или равно - int s21_is_greater_or_equal(s21_decimal, s21_decimal)  
Равно - int s21_is_equal(s21_decimal, s21_decimal)  
Не равно - int s21_is_not_equal(s21_decimal, s21_decimal)  
Из int в decimal - int s21_from_int_to_decimal(int src, s21_decimal *dst)  
Из float в decimal - int s21_from_float_to_decimal(float src, s21_decimal *dst)   
Из decimal в int - int s21_from_decimal_to_int(s21_decimal src, int *dst)   
Из decimal в float - int s21_from_decimal_to_float(s21_decimal src, float *dst)   
Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности - 
int s21_floor(s21_decimal value, s21_decimal *result)  
Округляет Decimal до ближайшего целого числа - 
int s21_round(s21_decimal value, s21_decimal *result)  
Возвращает целые цифры указанного Decimal числа; любые дробные цифры отбрасываются, включая конечные нули - 
int s21_truncate(s21_decimal value, s21_decimal *result)  
Возвращает результат умножения указанного Decimal на -1 - 
int s21_negate(s21_decimal value, s21_decimal *result)

## Math

- Стандартная реализация существующей библиотеки math.h  
int abs(int x)
вычисляет абсолютное значение целого числа.    
long double acos(double x)
вычисляет арккосинус.   
long double asin(double x)
вычисляет арксинус.   
long double atan(double x)
вычисляет арктангенс.    
long double ceil(double x)
возвращает ближайшее целое число, не меньшее заданного значения. 
long double cos(double x)
вычисляет косинус.   
long double exp(double x)
возвращает значение e, возведенное в заданную степень.  
long double fabs(double x)
вычисляет абсолютное значение числа с плавающей точкой.   
long double floor(double x)
возвращает ближайшее целое число, не превышающее заданное значение.    
long double fmod(double x, double y)
остаток операции деления с плавающей точкой.   
long double log(double x)
вычисляет натуральный логарифм.  
long double pow(double base, double exp)
возводит число в заданную степень.  
long double sin(double x)
вычисляет синус.   
long double sqrt(double x)
вычисляет квадратный корень.   
long double tan(double x)
вычисляет тангенс.

## Matrix

- Реализация работы с матрицой    
Создание матриц (create_matrix)  
int s21_create_matrix(int rows, int columns, matrix_t *result);   
Очистка матриц (remove_matrix)   
void s21_remove_matrix(matrix_t *A);
Сравнение матриц (eq_matrix)  
int s21_eq_matrix(matrix_t *A, matrix_t *B);   
Сложение (sum_matrix)    
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
Вычитание матриц (sub_matrix)
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
Умножение матрицы на число (mult_number)   
int s21_mult_number(matrix_t *A, double number, matrix_t *result);    
Умножение двух матриц (mult_matrix)   
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    
Транспонирование матрицы (transpose)     
int s21_transpose(matrix_t *A, matrix_t *result);   
Минор матрицы и матрица алгебраических дополнений (calc_complements)    
int s21_calc_complements(matrix_t *A, matrix_t *result);
Определитель матрицы (determinant)   
int s21_determinant(matrix_t *A, double *result);    
Обратная матрица (inverse_matrix)  
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

## SimpleBash

- Реализация утилит cat и grep

## SmartCalc

- реализован расширенный калькулятор с использованием структурного подхода. Он включает базовые арифметические операции, а также возможность вычисления сложных арифметических выражений с приоритетами. Кроме того, калькулятор поддерживает математические функции, такие как синус, косинус, логарифм и другие. (подробная документация описана в Doxygen)

## String

- void *memchr(const void *str, int c, size_t n)
Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.   
int memcmp(const void *str1, const void *str2, size_t n)
Сравнивает первые n байтов str1 и str2.    
void *memcpy(void *dest, const void *src, size_t n)
Копирует n символов из src в dest.     
void *memset(void *str, int c, size_t n)
Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.  
char *strncat(char *dest, const char *src, size_t n)
Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.     
char *strchr(const char *str, int c)
Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.     
int strncmp(const char *str1, const char *str2, size_t n)
Сравнивает не более первых n байтов str1 и str2.     
char *strncpy(char *dest, const char *src, size_t n)
Копирует до n символов из строки, на которую указывает src, в dest.     
size_t strcspn(const char *str1, const char *str2)
Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.     
char *strerror(int errnum)
Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.    
size_t strlen(const char *str)
Вычисляет длину строки str, не включая завершающий нулевой символ.  
char *strpbrk(const char *str1, const char *str2)
Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.   
char *strrchr(const char *str, int c)
Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.   
char *strstr(const char *haystack, const char *needle)
Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.   
char *strtok(char *str, const char *delim)
Разбивает строку str на ряд токенов, разделенных delim.