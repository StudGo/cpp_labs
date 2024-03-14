#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    FILE* in;
    char name[100];
    cout << "Enter file name: ";
    cin >> name;
    cout << std::endl;
    in = fopen(name, "r");
    if (in) {
        size_t cnt{};
        size_t empty{};
        cout << "File content: " << endl;
        for(char ch; !feof(in); ch = getc(in)) {
            putchar(ch);
            cnt++;
            if (ch <= 0x20) {
                empty++;
            }
        }
        cout << std::endl;
        cout << "Emty symbols = " << empty << endl;
        cout << "Not emty symbols = " << cnt - empty << endl;
    } else {
        cout << "File not found" << endl;
    }
}