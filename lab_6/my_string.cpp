#include "my_string.h"
#include "my_string_utils.h"
#include <cstring>


my_string::my_string(const char* str) {
    buf_size = content_size = my_strlen1(str);
    // Выделение буфера в динамической памяти
    buf = new char[buf_size];
    // Зануление буфера
    std::memset(buf, 0, buf_size);
    // Копирование с-строки из аргумента
    my_strcpy(str, buf);
}

my_string::my_string(const my_string& str)
    : buf(new char[str.size()])
    , buf_size(str.size())
    , content_size(str.size())
{
    std::memset(buf, 0, buf_size);
    my_strcpy(str.buf, buf);
}

my_string::my_string(my_string&& str) noexcept
    : buf(str.buf)
    , buf_size(str.buf_size)
    , content_size(str.content_size)
{
    std::memset(buf, 0, buf_size);
    str.buf = nullptr;
    str.buf_size = 0;
    str.content_size = 0;
}

my_string::my_string(size_t size)
    : buf(new char[size])
    , buf_size(size)
    , content_size(size)
{
    std::memset(buf, 0, size);
}

my_string::~my_string() {
    delete[] buf;
}

my_string& my_string::operator=(const my_string& str) {
    // Увеличение буфера при необходимости
    if (buf_size < str.content_size) {
        delete[] buf;
        buf = new char[str.content_size];
        std::memset(buf, 0, buf_size);
        buf_size = content_size = str.content_size;
    }
    my_strcpy(str.buf, buf);
    return *this;
}

my_string& my_string::operator=(my_string&& str) {
    delete[] buf;
    buf = str.buf;
    buf_size = str.buf_size;
    content_size = str.content_size;
    str.buf = nullptr;
    str.buf_size = 0;
    str.content_size = 0;
    return *this;
}

my_string& my_string::operator+(const my_string& str) {
    size_t both_content = content_size + str.content_size;
    if (buf_size < both_content) {
        auto prev_buf = buf;
        buf = new char[both_content];
        std::memset(buf, 0, both_content);
        std::memcpy(buf, prev_buf, buf_size);
        content_size = buf_size = both_content;
        delete[] prev_buf;
    }
    my_strcat(buf, str.buf);
    return *this;
}

int my_string::operator==(const my_string& str) {
    return my_strcmp(buf, str.buf);
}

size_t my_string::size() const {
    return content_size;
}

std::ostream& operator<<(std::ostream& os, const my_string& str) {
    return os << std::string(str.buf, str.content_size - 1 ? str.content_size : 0);
}

std::istream& operator>>(std::istream& in, my_string& str) {
    std::string val;
    in >> val;
    str = my_string(val.c_str());
    return in;
}

int my_string::operator>(const my_string& str) {
    return my_strcmp(buf, str.buf) == 1;
}
