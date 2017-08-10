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



int max_4_ints(int a, int b, int c, int d) {
    return max_ints(4, a, b, c, d);
}

int main() {

}