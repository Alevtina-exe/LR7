#include "func.h"
#include <iostream>
int* N = new int[2];

void Task_2_Solution() {
    std::cout << "Введите первое число.\n";  
    int* num = new int[10000];  
    getchar();  
    N[0] = input_num(num); // O(N[0])
    int* bnum1 = num_convert(num, 0); // O(N[0]^2)
    delete[] num;  
    num = nullptr;  
    std::cout << "Введите второе число.\n";  
    num = new int[10000];  
    N[1] = input_num(num); // O(N[1])
    int* bnum2 = num_convert(num, 1); // O(N[1]^2)
    delete[] num;  
    num = nullptr;  
    if(N[0] < N[1]) {  
        bool otr = bnum1[N[0] - 1];  
        for(; N[0] < N[1]; N[0]++) { // O(N[1] - N[0])
            bnum1[N[0]] = otr;  
        }
    }
    std::cout << "Заданные числa в обратной форме:\n";  
    num_cout(bnum1, 0); // O(N[0])
    num_cout(bnum2, 1); // O(N[1])
    std::cout << "Сумма заданных чисел:\n";  
    summ(bnum1, bnum2); // O(N[0] + N[1])
    num_cout(bnum1, 0); // O(N[0])
    delete[] bnum1;  
    delete[] bnum2;  
    bnum1 = nullptr;  
    bnum2 = nullptr;  
}
