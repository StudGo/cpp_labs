#include <cstdlib>
#include <array>
#include <iostream>
#include <functional>

// Кол-во элементов в массиве
const size_t array_size = 20;
// Тип элементов массива
using value_type = int;
// Тип массива
using array_type = std::array<value_type, array_size>;
// Тип функции для сравнения элементов. Инкапсулирует условия обмена элементов.
using comparer_type = std::function<bool(value_type, value_type)>;


// Вывод массива в stdout
void print_array(const array_type &array) {
    for (const auto &v: array) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}


// Создать массив случайный чисел
array_type make_random_array() {
    array_type arr;
    for (auto &val: arr) {
        val = rand() / 10;
    }
    return arr;
}


// Шаблон функции обменя элементов
template <typename T>
void swap(T& a, T& b) {
    auto tmp = a;
    a = b;
    b = tmp;
}


// Сортировка элементов методом минимакса
void min_max_sort(array_type &array, comparer_type &comparer) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        size_t imin{i};
        for (size_t j = i + 1; j < array.size(); j++) {
            if (comparer(array[j], array[imin])) {
                imin = j;
            }
        }
        swap(array[i], array[imin]);
    }
}


// Сортировка элементов методом пузырька
void buble_sort(array_type &array, const comparer_type &comparer) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        for (size_t j = 0; j < array.size() - i - 1; j++) {
            if (comparer(array[j], array[j + 1])) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}


// Вспомогательная функция для быстрой сортировки
size_t partition(array_type &array, const comparer_type &comparer, size_t low, size_t high, value_type pivot) {
    size_t i = low;
    size_t j = low;
    while (i <= high) {
        if (comparer(array[i], pivot)) {
            i++;
        } else {
            swap(array[i], array[j]);
            i++;
            j++;
        }
    }
    return j - 1;
}


// Функция быстрой сортировки
void quick_sort(array_type &array, const comparer_type &comparer, size_t low = 0, size_t high = array_size - 1) {
    if (low < high) {
        value_type pivot = array[high];
        size_t pos = partition(array, comparer, low, high, pivot);

        quick_sort(array, comparer, low, pos - 1 ? pos > 0 : 0);
        quick_sort(array, comparer, pos + 1, high);
    }
}


int main() {
    // Функция сравнения для сортировки по убыванию
    comparer_type min_comparer = [](auto a, auto b) { return a < b; };
    // Функция сравнения для сортировки по возрастанию
    comparer_type max_comparer = [](auto a, auto b) { return a > b; };

    array_type array{make_random_array()};
    std::cout << "Origin array: " << std::endl;
    print_array(array);

    std::cout << "Min-max sort: " << std::endl;
    array_type array_1(array);
    min_max_sort(array_1, min_comparer);
    std::cout << "Max: " << std::endl;
    print_array(array_1);
    min_max_sort(array_1, max_comparer);
    std::cout << "Min: " << std::endl;
    print_array(array_1);

    std::cout << "Buble sort: " << std::endl;
    array_type array_2(array);
    buble_sort(array_2, min_comparer);
    std::cout << "Max: " << std::endl;
    print_array(array_2);
    buble_sort(array_2, max_comparer);
    std::cout << "Min: " << std::endl;
    print_array(array_2);

    std::cout << "Quick sort: " << std::endl;
    array_type array_3(array);
    quick_sort(array_3, min_comparer);
    std::cout << "Max: " << std::endl;
    print_array(array_3);
    quick_sort(array_3, max_comparer);
    std::cout << "Min: " << std::endl;
    print_array(array_3);

    const size_t n1 {0};
    const size_t n2 {5};
    std::cout << "Sort from " << n1 << " to " << n2 << ":" << std::endl;
    array_type array_4(array);
    quick_sort(array_4, max_comparer, n1, n2);
    std::cout << "Max:" << std::endl;
    print_array(array_4);
    array_type array_5(array);
    quick_sort(array_5, min_comparer, n1, n2);
    std::cout << "Min:" << std::endl;
    print_array(array_5);

    array_type array_6(array);
    auto is_even = [](value_type &num) { return num % 2 == 0; };
    comparer_type even_max_comparer = [&is_even](auto a, auto b) { return is_even(a) && (a > b); };
    comparer_type not_even_min_comparer = [&is_even](auto a, auto b) { return !is_even(a) && (a < b); };
    buble_sort(array_6, even_max_comparer);
    buble_sort(array_6, not_even_min_comparer);
    std::cout << "Sort max even and min not odd:" << std::endl;
    print_array(array_6);

    return 0;
}
