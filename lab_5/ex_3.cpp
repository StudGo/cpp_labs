// Программа-шифратор файлов


#include <stdio.h>
#include <iostream>


// Функция для циклического доступа к символам ключа
char next_key_symbol(const std::string& key) {
    static size_t i = 0;
    if (i >= key.size()) {
        i = 0;
    }
    return key[i++];
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Invalid param count error";
        return 1;
    }
std::string key{argv[1]};
#ifdef KEY_FROM_ARGS
    std::cout << "Key = " << key << std::endl;
    if(key.empty()) {
        std::cout << "Empty key error";
        return 2;
    }
#else
    std::cout << "Enter key: ";
    std::cin >> key;
    std::cout << std::endl;
#endif
    FILE* in, *out;
    std::string input_file, output_file;
    std::cout << "Enter input file name: ";
    std::cin >> input_file;
    std::cout << std::endl << "Enter output file name: ";
    std::cin >> output_file;
    std::cout << std::endl;
    if ((in = fopen(input_file.c_str(), "r")) && (out = fopen(output_file.c_str(), "w"))) {
        for(char ch; !feof(in); ch = getc(in)) {
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
            fwrite(&new_ch, sizeof(char), 1, out);
        }
    } else {
        std::cout << "File not found" << std::endl;
    }
}