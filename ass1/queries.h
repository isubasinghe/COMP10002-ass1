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

typedef  struct {
    char * text;
    int line;
    double score;
} score_data_t;

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



int insert_top5(score_data_t * top5, score_data_t sdata) {
    for(int i=0; i < 5; i++) {
        if(top5[i].text == NULL && sdata.score > 0) {
            top5[i].text = sdata.text;
            top5[i].line = sdata.line;
            top5[i].score = sdata.score;
            return 1;
        }
    }

    double lowest_score = top5[0].score;
    int index = 0;

    for(int i=1; i < 5; i++) {
        if(top5[i].score < lowest_score) {
            lowest_score = top5[i].score;
            index = i;
        }
    }

    if(sdata.score > lowest_score) {
        top5[index].text = sdata.text;
        top5[index].line = sdata.line;
        top5[index].score = sdata.score;
        return 1;
    }

    return 0;
}




void process_lines(int argc, char * argv[]) {

    score_data_t * top5 = malloc(sizeof(score_data_t) * 5);

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
        printf("S2: line = %d, bytes = %zu, words = %d\n",
               linec, bytes, words_loc.size);

        double line_score = score(argc, argv, text, words_loc);
        printf("S3: line = %d, score = %0.3f\n",
               linec, line_score);

        linec++;

        score_data_t sdata;

        sdata.text = text;
        sdata.line = linec-1;
        sdata.score = line_score;

        if(!insert_top5(top5, sdata)) {
            free(text);
        }


        free(words_loc.word_loc);

    }

    printf("-------------\n");
    for(int i=0 ; i < 5; i++) {
        if(top5[i].text != NULL) {
            printf("S4: %s %0.2f at line %d\n", top5[i].text, top5[i].score, top5[i].line);
            free(top5[i].text);
        }
    }

    free(top5);
}






#endif //ASS1_QUERIES_H
