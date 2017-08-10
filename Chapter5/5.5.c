#include <stdio.h>
#include <stdlib.h>

int isperfect(int n) {
    int halfed = (n >> 1);
    
    int sum = 0;

    for(int i=1; i <= halfed; i++) {
        if(sum > n) {
            break;
        }

        if(n%i==0) {
            sum += i;
        }
    }

    return (n==sum);
}

int find_pval(int n) {
    
}

int next_perfect(int n) {
    int p_val;

}

int main() {
    printf("%d\n", next_perfect(8128));
}
  