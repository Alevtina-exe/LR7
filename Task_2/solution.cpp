#include "func.h"
#include <iostream>
int N1, N2;
extern bool o1, o2;

void Task_2_Solution() {
    std::cout << "Введите первое число.\n";  
    int* num;  
    getchar();  
    num = input_num(N1, o1); // O(N1)
    int* bnum1 = num_convert(num, N1, o1); // O(N1^2)
    delete[] num;  
    std::cout << "Введите второе число.\n";   
    num = input_num(N2, o2); // O(N2)
    int* bnum2 = num_convert(num, N2, o2); // O(N2^2)
    delete[] num;  
    num = nullptr;  
    if(N1 < N2) {  
        bool otr = bnum1[N1 - N2];  
        for(; N1 < N2; N1++) { // O(N2 - N1)
            bnum1[N1] = otr;  
        }
    }
    std::cout << "Заданные числa в обратной форме:\n";  
    num_cout(bnum1, N1, 0); // O(N1)
    num_cout(bnum2, N2, 0); // O(N2)
    std::cout << "Сумма заданных чисел:\n";  
    summ(bnum1, bnum2); // O(N1)
    num_cout(bnum1, N1, o1); // O(N1)
    delete[] bnum1;  
    delete[] bnum2;  
    bnum1 = nullptr;  
    bnum2 = nullptr;  
}
