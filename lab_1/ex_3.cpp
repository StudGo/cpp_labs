#include <iostream>
using namespace std;


// Обмен значений переменных через указатель
void obmen2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


// Обмен значений переменных, переданных по ссылке
void obmen3(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


// При вызове функции проиходит копирование, изменений не будет
void obmen1(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}


int main() {
    int a = 5, b = 10;
    cout << "Before obmen a = " << a << " b = " << b << endl;
    obmen1(a, b);
    cout << "After obmen1 a = " << a << " b = " << b << endl;
    obmen2(&a, &b);
    cout << "After obmen2 a = " << a << " b = " << b << endl;
    obmen3(a, b);
    cout << "After obmen3 a = " << a << " b = " << b << endl;
    return 0;
}
