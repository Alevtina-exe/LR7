#include<iostream>
#include "func.h"

int main() {
    int i;
    for (i = 0; i <= 78; i++) {
        std::cout << "*";
    }
    std::cout << "\nДанная программа проверяет, делится ли введенное пользователем число на 11, 31 и 113 без остатка." <<
        std::endl << "Выполнила Огиенко Дарья, группа 453502, вариант 15." << std::endl;
    for (i = 0; i <= 78; i++) {
        std::cout << "*";
    }
    std::cout << "\nВведите 1, чтобы выйти из программы, или 2, чтобы начать выполнение программы:\n";
    int exit_status = exit_status_input();
    
    while (true) {
        if (exit_status == 1) {
                return 0;
            }
        else if (exit_status == 2) {
            Task_4_Solution(); //O(log(a))
            exit_status = 3;
        }
        else {
            std::cout << "Введите 1, чтобы завершить выполнение программы, или 2, чтобы повторно выполнить программу:\n";
            exit_status = exit_status_input();
        }
    }
}