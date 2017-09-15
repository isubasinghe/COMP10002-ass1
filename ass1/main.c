//

#include <stdio.h>

#include "queries.h"


int main(int argc, char * argv[]) {
    // No queries were given, since q = arg -1
    if(argc == 1) {
        printf("S1: No query specified, must provide at least one word\n");
        return 0;
    }

    // indicate if we have detected an error.
    int errors = 0;
    int i;
    for (i = 1; i < argc; i++) {
        if (!is_valid_query(argv[i])) {
            printf("S1: %s: invalid character(s) in query\n", argv[i]);
            // we have found an error;
            errors = 1;
            break;
        }
    }


    // error was detected so we don't process the input, and exit the program.
    if(errors) {
        return -1;
    }

    printf("S1: query =");

    //print the queries out
    for(i=1; i < argc; i++) {
        printf(" %s", argv[i]);
    }
    printf("\n");





    process_lines(argc, argv);

    return 0;
}