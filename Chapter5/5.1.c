#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max_ints(int num_args, ...) {
    va_list valist;
    va_start(valist, num_args);

    int max_int = 0;


    for(int i=0; i< num_args; i++) {
        int tmp = va_arg(valist, int);
        if(tmp > max_int) {
            max_int = tmp;
        }
    }

    va_end(valist);

    return max_int;
    
}


int max_2_ints(int a, int b) {
    return max_ints(2, a, b);
}



int main() {

}