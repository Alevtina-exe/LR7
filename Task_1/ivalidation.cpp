#include <iostream>
int exit_status_input() {
    int a;
    while (true) {
        while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n'); //O(n), где n - количество символов до следующего перевода строки
            std::cout << "Неверный формат ввода.\n";
        }
        if (a == 2 || a == 1) return a;
        else std::cout << "Неверный формат ввода.\n";
    }
}
int input_num(int* num) {
    while(true) {
        int i = 0;
        char a = getchar();
        while(a != '\n') { //O(n), где n - количество символов до следующего перевода строки
            if(a == '0' || a == '1') {
                num[i] = a - 48;
                i++;
            }
            else {
                i = 0;
                while(getchar() != '\n'); //O(n), где n - количество символов до следующего перевода строки
                std::cout << "Неверный формат ввода." << std::endl;
            }
            a = getchar();
        }
        if(i < 2) {
            std::cout << "Неверный формат ввода." << std::endl;
        }
        else {
            return i;
        }
    }
}