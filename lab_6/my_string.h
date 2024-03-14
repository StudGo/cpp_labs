#ifndef MY_STRING_H
#define MY_STRING_H


#include <stddef.h>
#include <string>


class my_string final {
public:
    // Тип символа строки
    using value_type = char;
    // Конструктор из с-строки
    my_string(const char* str);
    // Конструктор из размера внутреннего буфера
    explicit my_string(size_t size = 0);
    // Конструктор копирования
    my_string(const my_string& str);
    // Конструктор перемещения
    my_string(my_string&& str) noexcept;
    // Деструктор. Не виртуальный, так как клас помечен final.
    ~my_string();
    // Оператор присваивания копированием
    my_string& operator=(const my_string&);
    // Оператор присваивания перемещением
    my_string& operator=(my_string&&);
    // Оператор сложения
    my_string& operator+(const my_string&);
    // Оператор сравнения
    int operator==(const my_string&);
    int operator>(const my_string&);
    // Размер строки
    size_t size() const;

    // Операторы вывода в поток помечены как friend для доступа к буферу
    friend std::ostream& operator<<(std::ostream& os, const my_string& str);
    friend std::istream& operator>>(std::istream& os, my_string& str);

private:
    char* buf;
    size_t buf_size;
    size_t content_size;
};


std::ostream& operator<<(std::ostream& os, const my_string& str);
std::istream& operator>>(std::istream& os, my_string& str);


#endif //MY_STRING_H
