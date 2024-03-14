#include <stddef.h>
#include <cassert>
#include <iostream>


template<class T>
class stack final {
public:
    stack(size_t size);

    ~stack();

    void push(T t);

    T pop();

    size_t size() const;

private:
    size_t sz;
    size_t max_size;
    T *item;
};

template<typename T>
stack<T>::stack(size_t sz)
        : sz(0), max_size(sz), item(new T[sz]) {
}

template<typename T>
stack<T>::~stack() {
    delete[] item;
}

template<typename T>
void stack<T>::push(T t) {
    assert(sz + 1 <= max_size);
    item[sz++] = t;
}

template<typename T>
T stack<T>::pop() {
    assert(sz > 0);
    return item[--sz];
}

template<typename T>
size_t stack<T>::size() const {
    return sz;
}


// Нахождение индекса минимального индекса
template<typename T>
T get_min_index(T t[], size_t sz) {
    size_t imax{0};
    for (size_t i = 0; i < sz; i++) {
        if (t[i] < t[imax]) {
            imax = i;
        }
    }
    return imax;
}


// Удаление элемента с заданным индексом из массива
template<typename T>
void remove(T t[], size_t sz, size_t index) {
    assert(index < sz);
    for (size_t i = index; i < sz - 1; i++) {
        t[i] = t[i + 1];
    }
    t[sz - 1] = 0;
}


int main() {
    // Поочередно перемещается минимальный элемент из массива в стек.
    using value_type = int;
    stack<value_type> s(15);
    value_type train[]{-5, 12, 5, 1, 1, 5, 3};
    size_t train_size = sizeof(train) / sizeof(value_type);
    for (size_t i = 0; i < train_size; i++) {
        auto max_index = get_min_index(train, train_size - i);
        s.push(train[max_index]);
        remove(train, train_size - i, max_index);
    }
    while (s.size()) {
        std::cout << s.pop() << " ";
    }
    return 0;
}
