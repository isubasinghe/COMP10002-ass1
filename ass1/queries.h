//
// Created by isitha on 5/09/17.
//

#ifndef ASS1_QUERIES_H
#define ASS1_QUERIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mystdio.h"
#include "myctypes.h"
#include "scoring.h"
#include "mystrings.h"


typedef struct {
    char ** queries;
    int size;
    int errorc;
} queries_t;

typedef struct {
    char * line;
    double score;

} line_t;




int is_valid_query(char * query) {
    for(unsigned int i=0; i < strlen(query); i++) {

        if(!isalphal(query[i]) && !isdigit(query[i])) {
            return 0;
        }
    }
    return 1;
}








void process_lines(int argc, char * argv[]) {



    char * text = NULL;

    // line counter
    unsigned int linec = 1;

    while((text = read_line())!= NULL) {

        int words = 0;

        size_t bytes = strlen(text);
        printf("---\n");
        printf("%s\n", text);
        printf("S2: line = %d, bytes = %zu, words = %d\n", linec, bytes, words);
        linec++;
        free(text);

    }
}






#endif //ASS1_QUERIES_H
