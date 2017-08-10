#include <stdio.h>
#include <stdlib.h>

int int_pow(unsigned int a, unsigned int b) {
    if(a==2) {
        return (1 << b);
    }else {
        int retval = 1;
        for(int i =0; i< b; i++) {
            retval *= a;
        }
        return retval;
    }
    

}

int main() {
    printf("%d\n", int_pow(3, 4));
}