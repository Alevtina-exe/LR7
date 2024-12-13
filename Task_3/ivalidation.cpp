#include <iostream>
extern int n;
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
int int_input() {
    int a;
    while (true) {
        while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n'); // O(n), где n - количество символов до перевода строки
            std::cout << "Неверный формат ввода. Введите целое число от 1 до 62.\n";
        }
        if (a > 0 && a <= 62) return a;
        std::cout << "Неверный формат ввода. Введите целое число от 1 до 62.\n";
    }
}
int input_num(int* num, bool& otr) {
    while(true) {
        int i = 0;
        otr = false;
        char a = getchar();
        if(a == '-') {
            otr = true;
            a = getchar();
        } 
        while(a != '\n') { // O(n), где n - количество символов до перевода строки
            if(isdigit(a)) {
                num[i] = a - 48;
            }
            else if(isalpha(a)) {
                if(isupper(a)) {
                    num[i] = a - 55;
                }
                else {
                    num[i] = a - 61; 
                } 
            }
            else {
                num[i] = 0;
            }
            if(num[i] >= n) {
                i = 0;
                while(getchar() != '\n'); // O(n), где n - количество символов до перевода строки
                break;
            }
            i++;
            a = getchar();
        }
        if(!i) {
            std::cout << "Неверный формат ввода." << std::endl;
        }
        else {
            return i;
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