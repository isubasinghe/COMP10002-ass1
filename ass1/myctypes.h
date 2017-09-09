//
// Created by isitha on 5/09/17.
//

#ifndef ASS1_MYCTYPES_H
#define ASS1_MYCTYPES_H

#include <string.h>
#include <ctype.h>

int isalphal(int);

// Checks if a character is a lowercase
// alphabetic character.
int isalphal(int c) {
    if(c >= 'a' && c<= 'z') {
        return 1;
    }
    return 0;
}



#endif //ASS1_MYCTYPES_H
