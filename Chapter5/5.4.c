#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    if(n==1) {
        return 1;
    }else {
        return n * fact(n-1);
    }
}

int n_choose_k(int n, int k) {
    return fact(n)/(fact(n-k)*fact(k));
}

int main() {
}
  