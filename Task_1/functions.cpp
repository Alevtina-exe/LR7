#include <iostream>
int summ(int* n1, int* n2, int N1, int N2) {
    int i;
    for(i = 0; i < N1 || i < N2; i++) { //O(max(N1, N2))
        n1[i] += n2[i];
        n1[i + 1] += n1[i] / 10;
        n1[i] %= 10;
    }
    return i + bool(n1[i]);
}
int mult(int* num, int N) {
    int i;
    for(i = 0; i < N; i++) { //O(N)
        num[i] *= 2;
    }
    for(i = 0; i < N; i++) { //O(N)
        num[i + 1] += num[i] / 10;
        num[i] %= 10;
    }
    return N + bool(num[i]);
}
void num_transform(int* num, int N) {
    int* bpow = new int[10000]{0}, n1 = 1;
    int* NUM = new int[10000]{0}, n2 = 0;
    bpow[0] = 1;
    if(num[0]) {
        for(int i = 1; i < N; i++) { //O(N) 
            num[i] = !num[i];
        }
    }
    N--;
    for(long long i = 1; N > 0; N--) { //O(N)
        if(num[N]) {
            n2 = summ(NUM, bpow, n2, n1); //O(max(n2, n1))
        }
        n1 = mult(bpow, n1);
    }
    n2--;
    if(num[0]) {
        std::cout << "-";
    }
    if(n2 == -1) std::cout << 0;
    while(n2 >= 0) { //O(n2)
        std::cout << NUM[n2];
        n2--;
    }
    std::cout << std::endl;
    delete[] bpow;
    delete[] NUM;
    NUM = nullptr; bpow = nullptr;
}