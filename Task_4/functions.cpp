#include <iostream>
#include <cmath>
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
long long int_input() {
    long long a;
    while (true) {
        while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n'); // O(n), где n - количество символов до перевода строки
            std::cout << "Неверный формат ввода.\n";
        }
        return a;
    }
}
void func(int a, int b) {
    a = llabs(a);
    int c = (b + 1) >> 1;
    while (a > b) { // O(log(a))
        a = (a >> 1) + ((a & 1) ? c : 0);
    }
    std::cout << "-";
    if (a != b && a) {
        std::cout << "не ";
    }
    std::cout << "делится на " << b << " без остатка;\n";
}

