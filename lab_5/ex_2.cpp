#include <cstdio>
#include <iostream>
#include <vector>


// Вспомогательная функция для удаления из строки всех символов, кроме чисел
std::string remove_not_digits(std::string& str) {
    std::string res;
    for (auto& ch: str) {
        if(std::isdigit(ch)) {
            res.push_back(ch);
        }
    }
    return res;
}


//Input file:
//123\n
//word1-1\n
//word1-2\n\t
//555\n
//word2-1\n
//word2-2\n\t
//
//Output file:
//word1-1\n
//word1-2\n\t
//123\n
//word2-1\n
//word2-2\n\t
//555\n
int main() {
    FILE* in;
    std::string name;
    std::cout << "Enter file name: ";
    std::cin >> name;
    std::cout << std::endl;
    in = fopen(name.c_str(), "r");
    if (in) {
        // Строка файла
        std::string str;
        // Страница файла (между \t)
        std::string page;
        // Первая строка страницы с номером
        std::string number_str;
        // Флаг, считывается ли сейчас первая строка страницы
        bool is_first_string = true;
        for(char ch; !feof(in); ch = getc(in)) {
            if(ch == '\n') {
                // Найден конец страницы
                if (is_first_string) {
                    // Строка с номеров в страницу не заносится
                    number_str = std::move(str);
                    is_first_string = false;
                } else {
                    page += str + '\n';
                }
                str.clear();
            } else if(ch == '\t') {
                // Найден конец страницы
                is_first_string = true;
                // Перенос номера страницы в конец
                page += remove_not_digits(number_str) + '\n';
                // Вывод в stdout
                std::cout << page;
                // Очищение буфера страницы
                page.clear();
            } else {
                // Заполнение очередной строки
                str += ch;
            }
        }
    } else {
        std::cout << "File not found" << std::endl;
        return -1;
    }


}
