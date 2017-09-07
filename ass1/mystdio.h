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


// remember to free the return value of this function,
// if it is not null.
char * read_line() {

    int c = mygetchar();

    // Our memory allocation cannot be empty,
    // so we will allocate 1024 bytes per line, then
    // when we fill this buffer we will add
    // another 1024 bytes..
    char * text = malloc(sizeof(char)*1024);

    // If it is just an empty line
    // ignore it.
    while(c == '\n') {
        c = mygetchar();
    }

    // Check if we have enough memory.
    if(text == NULL) {
        perror("out of memory\n");
        // return a null pointer, to indicate
        // we have run out of memory.
        return NULL;
    }

    unsigned int text_index = 0;


    while(c != '\n' && c != EOF) {

        // 1024 bytes have been written since the last time
        // this statement has been true.
        if(text_index%1023 ==0) {
            // Add another KB of memory to the pointer text.
            text = realloc(text, sizeof(char) * (text_index+1024));
            // we have run out of memory.
            if(text == NULL) {
                perror("out of memory\n");
                return NULL;
            }

        }

        // set the next character to what we got
        text[text_index] = (char)c;
        text_index++;

        // update what c represents.
        c = mygetchar();

    }

    // NULL terminator is added to the string.
    text[text_index] = '\0';

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
