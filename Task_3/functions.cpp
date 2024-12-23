#include <iostream>
#include <algorithm>
extern bool otr1, otr2, sign;
extern int N1, N2;
extern long long n;
bool AbB;
void display(long long* num, int& N, bool otr);
void comp(long long* n1, long long* n2) {
    AbB = true;
    if(N1 < N2) {
        AbB = false;
    }
    else if(N1 == N2) {
        for(long long i = 0; i < N1; i++) { //O(N1)
            if(n1[i] > n2[i]) {
                return;
            }
            else if(n1[i] < n2[i]) {
                AbB = false;
                return;
            }
        }
    }
}
void summ(long long* n1, int& N1, long long* n2, int& N2, bool otr) {
    for(long long i = 0; i < std::max(N1, N2); i++) { //O(max(N1, N2))
        n1[i] += n2[i];
        n1[i + 1] += n1[i] / n;
        n1[i] %= n;
    }
    while(n1[N1]) {
        N1++;
    }
    display(n1, N1, otr);
}
void razn(long long* n1, int& N1, long long* n2, int& N2, bool otr) {
    for(long long i = 0; i < N2; i++) { //O(N2)
        if(n1[i] < n2[i]) {
            n1[i + 1]--;
            n1[i] += n;
        }
        n1[i] -= n2[i];
    }
    while(N1 && !n1[N1 - 1]) { //O(N1)
        N1--;
    }
    display(n1, N1, otr); //O(N1)
}
void operation(long long* n1, long long* n2) {
    std::reverse(n1, n1 + N1); //O(N1)
    std::reverse(n2, n2 + N2); //O(N2)
    if(sign) {
        if ((!otr1 && otr2) || (!otr2 && otr1)) {
            summ(n1, N1, n2, N2, otr1); //O(max(N1, N2))
        }
        else if ((!otr2 && !otr1 && AbB) || (otr2 && otr1 && !AbB)) {
            if(!AbB) {
                otr1 = false;
            }
            razn(n1, N1, n2, N2, otr2); //O(N2)
        }
        else if ((!otr2 && !otr1 && !AbB) || (otr2 && otr1 && AbB)) {
            if(!AbB) {
                otr2 = true;
            }
            razn(n2, N2, n1, N1, otr2); //O(N1)
        }

    }
    else {
        if ((!otr2 && !otr1) || (otr2 && otr1)){
            summ(n1, N1, n2, N2, otr1); //O(max(N1, N2))
        }
        else if ((otr2 && AbB) || (otr1 && AbB)) {
            razn(n1, N1, n2, N2, otr1); //O(N2)
        }
        else if ((otr1 && !AbB) || (otr2 && !AbB)) {
            razn(n2, N2, n1, N1, otr2); //O(N1)
        }
    }
}
void display(long long* num, int& N, bool otr) {
    if(!N) {
        std::cout << "0\n"; 
        return;
    }
    if(otr) {
        std::cout << '-';
    }
    long long i;
    if (n <= 36) {
        char* symb = new char[n];
        long long i;
        for(i = 0; i < n && i < 10; i++) { //O(min(n, 10))
            symb[i] = char(48 + i);
        }
        for(; i < n; i++) { //O(n - 10)
            symb[i] = char(55 + i);
        }
        for(i = N - 1; i >= 0; i--) { //O(N)
            std::cout << symb[num[i]];
        }
        delete[] symb;
        symb = nullptr;
    }
    else {
        for(i = N - 1; i >= 0; i--) { //O(N)
            std::cout << char(65 + num[i] % 26) << num[i] / 26;
        }
    }
    std::cout << std::endl;
}
