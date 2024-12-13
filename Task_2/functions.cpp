#include "func.h"
#include <iostream>
extern int* N;
int div(int* num, int n) {
    bool otr = num[0] < 0 ? true : false;
    int mod = num[otr] % 2; 
    for(int i = N[n] - 1; i >= otr; i--) { //O(N[n])
        if(num[i] == 1 && i != otr) {
            num[i]--; i--;
            num[i] += 10;
        }
        if(i != otr) {
            num[i - 1] += (num[i] % 2) * 10;
        }
        num[i] /= 2;
    }
    N[n] = !num[N[n] - 1] ? N[n] - 1 : N[n];
    return mod;
}
void num_reverse(int* num, int n) {
    bool otr = num[0] < 0;
    for(int i = otr; i < N[n] / 2 + otr; i++) { //O(N[n])
        std::swap(num[i], num[N[n] - i - !otr]);
    }
} 
int* num_convert(int* num, int n) {
    int i = 0;
    num_reverse(num, n); //O(N[n])
    int* bnum = new int[10000]{0};
    bool otr = num[0] < 0;
    while(N[n] > otr) { //O(N[n])
        bnum[i] = otr? !div(num, n) : div(num, n);
        i++;
    }
    i++;
    N[n] = n && i < N[0] ? N[0] : i;
    for(i -= 1; i < N[n]; i++) { //O(N[n])
        bnum[i] = otr;
    }
    return bnum;
}
void summ(int* n1, int* n2) {
    if(!n1[N[0] - 1] && !n2[N[0] - 1]) {
        for(int i = 0; i < N[0]; i++) { //O(N[0])
            n1[i] += n2[i];
            if (n1[i] > 1) {
                n1[i + 1]++;
                n1[i] -= 2 ;
            }
        }
        if(n1[N[0] - 1]) {
            n1[N[0]] = 0;
            N[0]++;
        }
    }
    else {
        for(int i = 0; i < N[0]; i++) { //O(N[0])
            n1[i] += n2[i];
            if (n1[i] > 1) {
                n1[i + 1] ++;
                n1[i] -= 2 ;
            }
        }
        if (n1[N[0]] % 2) {
            n1[0]++;
            for(int i = 0; n1[i] > 1; i++) { //O(N[0])
                n1[i] = 0;
                n1[i + 1]++;
            }
            if(n1[N[0]]) {
                N[0]++;
            }
        }
    }
}