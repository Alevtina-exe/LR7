#include <iostream>
extern int N1, N2;
bool o1, o2;
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
int* input_num(int& N, bool& otr) {
    while(true) {
        int* num = new int[500]{0};
        int i = 0;
        otr = false;
        char a = getchar();
        if(a == '-') {
            otr = true;
            a = getchar();
            }
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
        if(i) {
            N = i;
            return num;
        }
        else {
            if(i) std::cout << "Неверный формат ввода." << std::endl;
            delete[] num;
        }
    }
}
void num_cout(int* num, int& N, bool otr) {
    int i = N - 1;
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