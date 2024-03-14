#include <stddef.h>
#include <string.h>
#include <iostream>


// Шаблон функции поиска максимума из двух
template<typename T>
T get_max(T t1, T t2) {
    return t1 > t2 ? t1 : t2;
}


// Шаблон функции поиска максимума в массиве
template<typename T>
T get_max(T t[], size_t sz) {
    size_t imax{};
    for(size_t i = 0; i < sz; i++) {
        if (t[i] > t[imax]) {
            imax = i;
        }
    }
    return t[imax];
}


// Специализация шаблона функции
template<>
char* get_max(char* c1, char* c2) {
    return strcmp(c1, c2) > 0 ? c1 : c2;
}


int main() {
    std::cout << "max from 1 and 5 = " << get_max(1, 5) << std::endl;
    std::cout << "max from \"123\" and \"555\" = " << get_max("123", "555") << std::endl;
    int arr[]{1, 2, 3, 4, 5};
    std::cout << "max in [1,2,3,4,5] = " << get_max(arr, sizeof(arr) / sizeof(int));
    return 0;
}
