#include "func.h"
#include <iostream>
void Task_5_Solution() {
    char** barrel = new char*[240];
    bool checked[240]{false};
    int alive[5]{1, 1, 1, 1, 1}, found = 0;
    std::cout << "Введите номер бочки, которую хотели бы отравить:\n";
    int n = int_input();
    std::cout << "Поиск нужной бочки начался...\n";
    for(int i = 0; i < 78; i++) std::cout << '-';
    std::cout << "\nПеревод номеров бочек в троичную систему...\n";
    for (int i = 0; i < 240; i++) {
        barrel[i] = ternary_convert(i + 1); //O(log(i))
    }
    std::cout << "Перевод номеров бочек в троичную систему завершён.\n";
    int s = 81;

    std::cout << "\nДень 1:\n";
    std::cout << "Определяем, как распределены бочки между рабами:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Раб " << i + 1 << " проверил бочки: ";
        for (int j = 0; j < 240; j++) {
            if (barrel[j][i] == '0') {
                std::cout << j + 1 << " ";
                if (j + 1 == n) {
                    alive[i] = 0;
                }
            }
        }
        std::cout << std::endl;
        if (alive[i]){
            alive[i] = 2;
        }
    }

    std::cout << "По итогу первого дня:\n";
    for (int i = 0; i < 5; i++) {
        if(!alive[i]) {
            std::cout << "Раб " << i + 1 << " умер.\n";
        }
    }

    std::cout << "\nДень 2:\n";
    std::cout << "Определяем, как распределены бочки между рабами:\n";

    for (int i = 0; i < 5; i++, s /= 3) {
        if (!alive[i]) continue; 
        std::cout << "Раб " << i + 1 << " проверил бочки: ";
        for (int j = 0; j < 240; j++) {
            if (verify(barrel[j], i, alive)) {
                std::cout << j + 1<< " ";
                if (j + 1 == n) {
                    alive[i] = 1;
                }
            }
        }
        std::cout << '\n';
        found += alive[i] * s;
    }
    std::cout << "\nПо итогу второго дня:\n";
    for (int i = 0; i < 5; i++) {
        if(alive[i] == 1) {
            std::cout << "Раб " << i + 1 << " умер.\n";
        }
    }

    std::cout << "\nПолученный опытным путём номер бочки: " << found << '.';
    std::cout << "\nОтравлена была бочка №" << n << ".\n";
    for(int i = 0; i < 240; i++) {
        delete[] barrel[i];
    }
    delete[] barrel;
    barrel = nullptr;
}
