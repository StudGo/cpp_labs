#include <iostream>
#include <iomanip>

int main() {
    // Установка точности вывода чисел с плавающей точкой
    std::cout << std::fixed << std::setprecision(2) << 3.14159 << std::endl;

    std::cout << "message 1" << std::endl;

    std::cout.clear();
    std::cout.setstate(std::ios_base::failbit);
    // Сообщение не выводится, так как установлен failbit
    std::cout << "message 2" << std::endl;
    std::cout.clear();
    std::cout << "message 3" << std::endl;
    return 0;
}