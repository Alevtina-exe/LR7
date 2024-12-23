#include "func.h"
#include <iostream>
extern int N1, N2;
extern bool o1, o2;
int div(int* num, int& N) {
    int mod = num[0] % 2; 
    for(int i = N - 1; i >= 0; i--) { //O(N)
        if(num[i] == 1 && i) {
            num[i]--; i--;
            num[i] += 10;
        }
        if(i) {
            num[i - 1] += (num[i] % 2) * 10;
        }
        num[i] /= 2;
    }
    N = !num[N - 1] ? N - 1 : N;
    return mod;
}
void num_reverse(int* num, int N) {
    for(int i = 0; i < N / 2; i++) { //O(N)
        std::swap(num[i], num[N - i - 1]);
    }
} 
int* num_convert(int* num, int& N, bool otr) {
    int i = 0;
    num_reverse(num, N); //O(N)
    int* bnum = new int[10000]{0};
    while(N > 0) { //O(N)
        bnum[i] = otr ? !div(num, N) : div(num, N);
        i++;
    }
    i++;
    N = N == N2 && i < N1 ? N1 : i;
    for(i -= 1; i < N; i++) { //O(N)
        bnum[i] = otr;
    }
    return bnum;
}
void summ(int* n1, int* n2) {
    if(!o1 && !o2) {
        for(int i = 0; i < N1; i++) { //O(N1)
            n1[i] += n2[i];
            if (n1[i] > 1) {
                n1[i + 1]++;
                n1[i] -= 2 ;
            }
        }
        if(n1[N1 - 1] || n1[N1]) {
            n1[N1] = o1;
            N1++;
        }
        if(o1) {
            n1[0]++;
            for(int i = 0; n1[i] > 1; i++) { //O(N1)
                n1[i] = 0;
                n1[i + 1]++;
            } 
        }
    }
    else {
        for(int i = 0; i < N1; i++) { //O(N1)
            n1[i] += n2[i];
            if (n1[i] > 1) {
                n1[i + 1] ++;
                n1[i] -= 2 ;
            } 
        }
        if(n1[N1] % 2) {
            n1[0]++;
            for(int i = 0; n1[i] > 1; i++) { //O(N1)
                n1[i] = 0;
                n1[i + 1]++;
            }
            if(o1 && o2) {
                N1++;
            }
        }

    }
    if(n1[N1 - 1]) {
        o1 = true;
    }
    else {
        o1 = false;
    }
}