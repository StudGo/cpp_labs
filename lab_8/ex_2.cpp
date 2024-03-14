#include <iostream>
#include "my_string.h"

class Money
{
    long dollars;
    int cent;
public:
    Money() {}
    Money(long d, int c);
    int operator>(const Money& m) const;
    friend std::ostream& operator<<(std::ostream&, Money&);
};

Money::Money(long d, int c)
    : dollars(d)
    , cent(c)
{
}

int Money::operator>(const Money &m) const {
    return (dollars>m.dollars) || ((dollars==m.dollars) && (cent>m.cent));
}

std::ostream &operator<<(std::ostream& os, Money& m) {
    os << "$" << m.dollars << "." << m.cent;
    return os;
}

template<typename T>
T get_max(T& t1, T& t2) {
    return t1 > t2 ? t1 : t2;
}

template<typename T>
T get_max(T t[], size_t sz) {
    size_t imax{};
    for(size_t i = 0; i < sz; i++) {
        if (t[i] > t[imax]) {
            imax = i;
        }
    }
    return t[imax];
}

int main() {
    Money mas[] {
            Money(19, 10),
            Money(99, 99),
            Money(99, 95),
            Money(19, 95),
    };
    for(auto& m: mas) {
        std::cout << m << std::endl;
    }
    auto max = get_max(mas, sizeof(mas) / sizeof(Money));
    std::cout << "max money = " << max << std::endl;
    my_string strings[] {
        "123",
        "456",
        "abc"
    };
    auto max_str = get_max(strings, sizeof(strings) / sizeof(strings));
    std::cout << "max string = " << max_str << std::endl;
    return 0;
}
