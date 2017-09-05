//
// Created by isitha on 2/09/17.
//

#ifndef ASS1_MYSTDIO_H
#define ASS1_MYSTDIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

int mygetchar() {

    int c = getchar();

    while(c=='\r') {
        c = getchar();
    }
    return c;
}



char * read_line() {
    int c = mygetchar();

    char * text = malloc(sizeof(char)*1024);
    assert(text != NULL);

    unsigned int text_index = 0;

    while(c != '\n' && c != EOF) {

        assert(text_index != UINT_MAX);

        if(text_index%1023 ==0) {
            text = realloc(text, sizeof(char) * (text_index+1024));
            assert(text != NULL);

        }

        text[text_index] = (char)c;
        text_index++;

        c = mygetchar();

    }

    text[text_index] = 0;

    // If text_index hasn't been incremented, the above loop
    // has not been entered into, which means that c was either
    // a '\n' or EOF character, both of which signifies an empty
    // line.

    if(text_index == 0) {

        // text holds no data, returning this is
        // pointless, as no data can be gained.
        free(text);
        return NULL;
    }


    return text;
}



#endif //ASS1_MYSTDIO_H
