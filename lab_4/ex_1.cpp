#include <iostream>
#include <cassert>


// Вариант реализации подсчета размера строки через разность указатель на начало и конец строки
size_t my_strlen1(const char* str) {
    auto ptr{str};
    for (; *ptr; ptr++);
    return ptr - str;
}


// Вариант реализации подсчета размера строки через количество символов от начала до конца строки
size_t my_strlen2(const char* str) {
    size_t len{};
    for (; *str; str++, len++);
    return len;
}


// Вариант реализации подсчета размера строки через количество символов от начала до конца строки
size_t my_strlen3(const char* str) {
    size_t len{};
    while(*str++) {
        len++;
    }
    return len;
}


// Копирование str1 в str2
// Размер str2 должен быть больше или равен размеру str1
void my_strcpy(const char* str1, char* str2) {
    for (; *str1; *str2++ = *str1++);
}


// Сравнение строк
// Ищется первый не равный символ, после чего выполняется сравнение.
// Если такого символа нет, возвращается 0
int my_strcmp(const char* str1, const char* str2) {
    for (; *str1 == *str2 && *str1 && *str2; str2++, str1++);
    if (*str1 < *str2) {
        return -1;
    } else if (*str1 > *str2) {
        return +1;
    } else {
        return 0;
    }
}


// Копирование строки в конец другой
void my_strcat(char* to, const char* from) {
    my_strcpy(from, to + my_strlen1(to));
}


int main() {
    // Размер буферов для размещения строк
    const size_t buf_size = 100;
#define STATIC_STR
#if defined(STATIC_STR)
    // Размещение строке в статической памяти
    char str1[buf_size] { "qwerty" };
    char str2[buf_size] { "1234567890" };
#elif defined(MALLOC_STR)
    // Размещение строке в динамической памяти
    // malloc выделяет n-ое количество байт, возвращает указатель
    auto* str2 = static_cast<char*>(malloc(buf_size));
    auto* str1 = static_cast<char*>(malloc(buf_size));
    memset(str1, 0, buf_size);
    memset(str2, 0, buf_size);
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");
#elif defined(CALLOC_STR)
    // Размещение строке в динамической памяти
    // calloc выделяет память n-ое количество элементов m-ого размера и зануляет их
    auto* str1 = static_cast<char*>(calloc(buf_size, sizeof(char)));
    auto* str2 = static_cast<char*>(calloc(buf_size, sizeof(char)));
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");
#endif

    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    std::cout << "len1 str1 = " << my_strlen1(str1) << std::endl;
    std::cout << "len2 str1 = " << my_strlen2(str1) << std::endl;
    std::cout << "len3 str1 = " << my_strlen3(str1) << std::endl;
    std::cout << "len1 str2 = " << my_strlen1(str2) << std::endl;
    std::cout << "len2 str2 = " << my_strlen2(str2) << std::endl;
    std::cout << "len3 str2 = " << my_strlen3(str2) << std::endl;

    my_strcpy(str2, str1);
    std::cout << "str1 after copy = " << str1 << std::endl;
    std::cout << "compare = " << my_strcmp(str1, str2) << std::endl;
    my_strcat(str1, str2);
    std::cout << "str cut = " << str1 << std::endl;

    // Работа с массивом строк
    char* str_array[] = {"123", "456", "abc"};
    char* str3 = static_cast<char*>(calloc(buf_size, sizeof(char)));
    my_strcat(str3, str_array[0]);
    my_strcat(str3, str_array[1]);
    my_strcat(str3, str_array[2]);
    std::cout << "cat array of string = " << str3;

#if defined(MALLOC_STR) || defined(CALLOC_STR)
    // Освобождение памяти по указателю
    free(str1);
    free(str2);
#endif
    return 0;
}