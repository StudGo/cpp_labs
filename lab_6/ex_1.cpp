#include <iostream>
#include "my_string.h"


int main() {
    my_string s1("qwert"), s3, s4(s1), s5;
    std::cin >> s3;
    s3 = "aswdfg";
    s5 =
            s1 + s3 + s4;
    std::cout << "Length s5 = " << s5.size() << std::endl;
    std::cin >> s5;
    if (s1 == s5) {
        std::cout << "Strings s1 and s5 are equel";
    } else if (s1 == s4) {
        std::cout << "Strings s1 and s4 are equel";
    }
    return 0;
}