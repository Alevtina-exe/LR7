#include "func.h"
#include <iostream>
int* N = new int[2];
void Task_4_Solution() {
    std::cout << "Введите число.\n";
    long long num = int_input();
    std::cout << "Данное число:\n";
    func(num, 11); // O(log(num))
    func(num, 31); // O(log(num))
    func(num, 113); // O(log(num))
}