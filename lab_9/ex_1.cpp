#include <cstddef>
#include <iostream>


// Шаблон функции обмена
template<typename T>
void swap(T t[], size_t i1, size_t i2) {
    T tmp{t[i1]};
    t[i1] = t[i2];
    t[i2] = tmp;
}


// Шаблон функции сортировки
template<typename T>
void sort(T array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = size - 1; i < j; j--) {
            if (array[i] > array[j]) {
                swap(array, i, j - 1);
            }
        }
    }
}


// Тестовый класс
template<typename T>
struct my_class
{
    T a;
    T b;
    bool operator>(const my_class<T>& other) {return (a > other.a) && (b > other.b);}
};


int main() {
    my_class<int> arr[]{{1,2}, {64,5}, {-2, 1}, {5, -2}, {1, 0}, {-5, 3}};
    size_t size = sizeof(arr) / sizeof(my_class<int>);
    sort(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i].a << " " << arr[i].b  << std::endl;
    }
    return 0;
}
