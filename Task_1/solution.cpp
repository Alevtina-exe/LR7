#include "func.h"
#include <iostream>
void Task_1_Solution() {
    std::cout << "Введите число в форме обратного кода.\n";
    int* num = new int[10000];
    getchar();
    long long N = input_num(num); 
    std::cout << "Заданное число в естественной форме:\n";
    num_transform(num, N); //O(N)
    delete[] num;
    num = nullptr;
}
