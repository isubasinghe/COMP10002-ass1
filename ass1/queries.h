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




int is_valid_query(char * query) {
    for(unsigned int i=0; i < strlen(query); i++) {

        if(!isalphal(query[i]) && !isdigit(query[i])) {
            return 0;
        }
    }
    return 1;
}

queries_t process_queries(int argc, char * argv[]) {
    queries_t queries;

    queries.queries = malloc(sizeof(char *) * (argc-1));
    queries.size = 0;
    queries.errorc = 0;

    if(argc >= 1) {
        printf("S1: query =");
        for(int i=1; i < argc; i++) {
            printf(" %s", argv[i]);
        }

        printf("\n");

        for(int i=1; i < argc; i++) {
            if(!is_valid_query(argv[i])) {
                printf("S1: %s: invalid character(s) in query\n", argv[i]);
                queries.errorc++;
            }else {

                queries.queries[i-1] = argv[i];
                queries.size++;
            }
        }
    }

    return queries;

}




void process_lines(int argc, char * argv[]) {
    char * text = NULL;
    unsigned int line = 1;

    while((text = read_line())!= NULL) {

        int words = words_count(text);

        size_t bytes = strlen(text);

        printf("%s\n", text);
        printf("S2: line = %d, bytes = %zu, words = %d\n", line, bytes, words);
        line++;
        free(text);

    }
}






#endif //ASS1_QUERIES_H
