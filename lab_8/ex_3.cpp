// Программа-шифратор файлов


#include <stdio.h>
#include <iostream>
#include <fstream>

// Функция для циклического доступа к символам ключа
char next_key_symbol(const std::string& key) {
    static size_t i = 0;
    if (i >= key.size()) {
        i = 0;
    }
    return key[i++];
}


int main(int argc, char *argv[]) {
#ifdef KEY_FROM_ARGS
    std::string key{argv[1]};
    if (argc != 2) {
        std::cout << "Invalid param count error";
        return 1;
    }
    std::cout << "Key = " << key << std::endl;
    if(key.empty()) {
        std::cout << "Empty key error";
        return 2;
    }
#else
    std::string key;
    std::cout << "Enter key: ";
    std::cin >> key;
    std::cout << std::endl;
#endif
    std::string input_file, output_file;
    std::cout << "Enter input file name: ";
    std::cin >> input_file;
    std::cout << std::endl << "Enter output file name: ";
    std::cin >> output_file;
    std::cout << std::endl;
    std::ifstream in(input_file, std::ios::in);
    std::ofstream out(output_file, std::ios::out);


    if (in.is_open() && out.is_open()) {
        for(char ch; !in.eof(); in.get(ch)) {
            if (ch < 0x20) {
                continue;
            }
            // Получить символ для шифрования
            char key_ch = next_key_symbol(key);
            // Зашифровать символ
            char new_ch = ch ^ key_ch;
            // Вывод отладочной информации
            std::cout << "ch=" << ch << " new=" << new_ch << " key=" << key_ch << std::endl;
            // Записать зашифрованный символ
            out << new_ch;
        }
    } else {
        std::cout << "File not found" << std::endl;
    }
}