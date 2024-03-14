// Копии из 4 лабы


#ifndef MY_STRING_UTILS_H
#define MY_STRING_UTILS_H


#include <cassert>


// Вариант реализации подсчета размера строки через разность указатель на начало и конец строки
size_t my_strlen1(const char* str);
// Вариант реализации подсчета размера строки через количество символов от начала до конца строки
size_t my_strlen2(const char* str);
// Вариант реализации подсчета размера строки через количество символов от начала до конца строки
size_t my_strlen3(const char* str);
// Копирование str1 в str2
// Размер str2 должен быть больше или равен размеру str1
void my_strcpy(const char* str1, char* str2);
// Сравнение строк
// Ищется первый не равный символ, после чего выполняется сравнение.
// Если такого символа нет, возвращается 0
int my_strcmp(const char* str1, const char* str2);
// Копирование строки в конец другой
void my_strcat(char* to, const char* from);


#endif //MY_STRING_UTILS_H
