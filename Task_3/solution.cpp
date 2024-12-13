#include "func.h"
#include <iostream>
int N1, N2, n;
bool sign, otr1, otr2;
void Task_3_Solution() {
    int* n1 = new int[10000]{0}, *n2 = new int[10000]{0};
    std::cout << "Введите основание системы счисления:\n";
    n = int_input();
    std::cout << "Введите первое число в заданной системе счисления соблюдая регистр:\n";
    getchar();
    N1 = input_num(n1, otr1); //O(N1)
    std::cout << "Введите второе число в заданной системе счисления соблюдая регистр:\n";
    N2 = input_num(n2, otr2); //O(N2)
    std::cout << "Введите '+', если хотите найти сумму, или '-', если хотите найти разность:\n";
    sign = sign_input();
    if(sign) {
        std::cout << "Разность данных чисел:\n";
    }
    else {
        std::cout << "Сумма данных чисел:\n";
    }
    comp(n1, n2); // O(max(N1, N2))
    operation(n1, n2); // O(N1 + N2)
    delete[] n1;
    delete[] n2;
    n1 = nullptr;
    n2 = nullptr;
}
