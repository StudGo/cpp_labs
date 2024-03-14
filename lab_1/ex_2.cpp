#include "stdio.h"
#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)

int main() {
    int mas[] {100, 200, 300};
    int *ptr1, *ptr2;
    // Указатель на первый элемент массива arr
    ptr1 = mas;
    // Указатель на третий элемент массива arr
    ptr2 = &mas[2];
    PR(ptr1);
    // Арифметика указателей
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    // Выход за границу массива
    // Указатели ссылаются на область памяти с разницей в 2
    ++ptr2;
    printf("ptr2 - ptr1 = %u\n", ptr2-ptr1);
    return 0;
}
