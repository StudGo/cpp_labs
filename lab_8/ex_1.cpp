// Операторы вывода в поток для строки


#include <ostream>
#include <istream>
#include "my_string.h"


std::ostream& operator<<(std::ostream& os, const my_string& str) {
    return os << std::string(str.buf, str.content_size - 1 ? str.content_size : 0);
}

std::istream& operator>>(std::istream& in, my_string& str) {
    std::string val;
    in >> val;
    str = my_string(val.c_str());
    return in;
}
