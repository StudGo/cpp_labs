#include <iostream>
#include <cstdint>
using namespace std;

//функция возведения в степень
int power(int x, int n) {
    int p = 1;
    //цикл для возведения в степень
    for (int i = 0; i <= n; i++) {
        p *= x;
    }
    return p;
}

int main() {
    cout << "Enter number: ";
    int b;
    cin >> b;

    for (int i = 0; i < 10; i++) {
        //вывод всех полученных значений по порядку до указаной
        cout << power(b, i) << endl;
    }
    return 0;
}