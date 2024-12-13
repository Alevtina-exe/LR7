#include<iostream>
#include "func.h"

int main() {
    int i;
    for (i = 0; i <= 78; i++) {
        std::cout << "*";
    }
    std::cout << "\nПатриций решил устроить праздник и приготовил для него 240 бочек вина. Но к нему пробрался недоброжелатель " <<
        "и подсыпал яд в одну из бочек. \nПро яд известно, что человек, который его выпил, умирает в течение 24 часов. До " <<
        "праздника осталось 48 часов. \nУ патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд." <<
        "\nПользователь вводит номер бочки, которую хотел бы отравить, а программа определяет этот номер." <<
        std::endl << "Выполнила Огиенко Дарья, группа 453502." << std::endl;
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
            Task_5_Solution();
            exit_status = 0;
        }
        else {
            std::cout << "Введите 1, чтобы завершить выполнение программы, или 2, чтобы повторно выполнить программу:\n";
            exit_status = exit_status_input();
        }
    }
}