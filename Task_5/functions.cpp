#include <iostream>
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
        if (a > 0 && a <= 240) return a;
        std::cout << "Неверный формат ввода. Введите целое число от 1 до 62.\n";
    }
}

// если 0 то не пил из бочки
// 1 пил в первый день
// 2 пил во второй день

char* ternary_convert(int a) { 
    char* s = new char[6]; 
    s[5] = '\0'; 
    int i = 4; 
    while (a != 0) {  // O(log3(a))
        s[i--] = '0' + (a % 3);
        a /= 3;
    }
    while (i >= 0) {
        s[i--] = '0';
    }
    return s;
}

bool verify(char* b, int n, int* alive) {
    if (b[n] == '1') {
        for (int j = 0; j < 5; j++) {
            if (!alive[j] && b[j] != '0')
                return false;
        }
        return true; 
    }
    return false; 
}
