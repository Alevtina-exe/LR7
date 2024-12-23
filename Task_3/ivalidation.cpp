#include <iostream>
#define max 350000000000000000
extern long long n;
extern bool otr1, otr2;
int exit_status_input() {
    int a;
    while (true) {
        while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n'); // O(n), где n - количество символов до перевода строки
            std::cout << "Неверный формат ввода.\n";
        }
        if (a == 2 || a == 1) return a;
        else std::cout << "Неверный формат ввода.\n";
    }
}
long long int_input(bool min) {
    long long a;
    while (true) {
        while (!(std::cin >> a) || (std::cin.peek() != '\n' && min)) {
            std::cin.clear();
            while (std::cin.get() != '\n'); // O(n), где n - количество символов до перевода строки
            std::cout << "Неверный формат ввода.\n";
            if (!min) return n;
        }
        if (a >= min * 2 || (a < max && ! min)) return a;
        std::cout << "Неверный формат ввода.\n";
    }
}
long long* input_num(bool& otr, int& N) {
    while(true) {
        long long* num = new long long[5000]{0};
        int i = 0;
        otr = false;
        char a = getchar();
        if(a == '-') {
            otr = true;
            a = getchar();
        } 
        while(a != '\n') { // O(n), где n - количество символов до перевода строки
            if(n <= 36) {
                if(isdigit(a)) {
                    num[i] = a - 48;
                }
                else if(isalpha(a)) {
                    a = toupper(a);
                    num[i] = a - 55;
                }
                else num[i] = n + 1;
            }
            else {
                if(isalpha(a)) {
                    num[i] = int_input(0) * 26 + toupper(a) - 65;
                }
                else {
                    num[i] = n + 1;                  
                }
            }
            if(num[i] >= n) {
                i = 0;
                while(getchar() != '\n'); // O(n), где n - количество символов до перевода строки
                break;
            }
            else {
                i++;
                a = getchar();
            }
        }
        if(!i) {
            std::cout << "Неверный формат ввода." << std::endl;
            delete[] num;
            num = nullptr;
        }
        else {
            N = i;
            return num;
        }
    }
}
bool sign_input() {
    while(true) {
        char a = getchar();
        if(a != '\n') { // O(n), где n - количество символов до перевода строки
            if(getchar() == '\n') {
                if(a == '+') return false;
                else if(a == '-') return true;
            }
            else {
                while(getchar() != '\n'); // O(n), где n - количество символов до перевода строки
            }
            std::cout << "Неверный формат ввода." << std::endl;
        }
    }
}