#include <iostream>
extern int* N;
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
            if((a > 47 && a < 58) || (a == '-' && !i)) {
                num[i] = a - 48;
                i++;
            }
            else {
                i = 0;
                while(getchar() != '\n'); //O(n), где n - количество символов до следующего перевода строки
            }
            a = getchar();
        }
        if(i > (num[0] == -3)) {
            return i;
        }
        else {
            if(i) std::cout << "Неверный формат ввода." << std::endl;
        }
    }
}
void num_cout(int* num, int n) {
    int i = N[n] - 1;
    bool otr = num[i];
    std::cout << num[i];
    for(i--; i >=0; i--) { //O(i)
        if(otr) {
            std::cout << !num[i];
        }
        else{
            std::cout << num[i];
        }
    }
    std::cout << std::endl;
} 