#include <cassert>
#include "my_string_utils.h"


size_t my_strlen1(const char* str) {
    assert(str);
    auto ptr{str};
    for (; *ptr; ptr++);
    return ptr - str;
}


size_t my_strlen2(const char* str) {
    assert(str);
    size_t len{};
    for (; *str; str++, len++);
    return len;
}


size_t my_strlen3(const char* str) {
    assert(str);
    size_t len{};
    while(*str++) {
        len++;
    }
    return len;
}


void my_strcpy(const char* str1, char* str2) {
    assert(str1 && str2);
    for (; *str1; *str2++ = *str1++);
}


int my_strcmp(const char* str1, const char* str2) {
    assert(str1 && str2);
    for (; *str1 == *str2 && *str1 && *str2; str2++, str1++);
    if (*str1 < *str2) {
        return -1;
    } else if (*str1 > *str2) {
        return +1;
    } else {
        return 0;
    }
}


void my_strcat(char* to, const char* from) {
    assert(to && from);
    my_strcpy(from, to + my_strlen1(to));
}