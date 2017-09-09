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
#include "mystrings.h"

int is_valid_query(char *);

void process_lines(int, char *[]);



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
        if(text[0] == '\n') {
            linec++;
            free(text);
            continue;
        }
        size_t bytes = strlen(text);
        printf("---\n");
        printf("%s\n", text);
        words_loc_t words_loc = get_words(text);
        printf("S2: line = %d, bytes = %zu, words = %d\n", linec, bytes, words_loc.size);
        printf("S3: line = %d, score = %0.03f\n", linec, score(argc, argv, text, words_loc));
        linec++;

        free(text);
        free(words_loc.word_loc);

    }
}






#endif //ASS1_QUERIES_H
