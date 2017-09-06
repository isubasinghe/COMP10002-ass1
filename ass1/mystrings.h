//
// Created by isitha on 6/09/17.
//

#ifndef ASS1_MYSTRINGS_H
#define ASS1_MYSTRINGS_H
#include <stdio.h>
#include <string.h>

int getalnum(char * text) {
    size_t len = strlen(text);

    for(int i=0; i < len; i++) {
        if(text[i] == EOF) {
            return -1;
        }else if(text[i] != ' ') {
            return i;
        }
    }
    return -1;
}

int words_count(char * text) {

    int count = 0;

    size_t len = strlen(text);

    if(len == 0) {return 0;}

    int prevchar = getalnum(text);

    if(prevchar == -1) {return 0;}

    if(text[len-1] == ' ') {
        count--;
    }

    for(int i=prevchar; i < len + 1; i++) {
        if(text[i] == '\0') {
            count++;
            return count;
        }else if((text[i] == ' ' && prevchar != ' ') ) {
            count++;
        }
        prevchar = text[i];

    }
    return count;

}

#endif //ASS1_MYSTRINGS_H
