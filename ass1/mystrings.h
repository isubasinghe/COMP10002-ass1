//
// Created by isitha on 6/09/17.
//

#ifndef ASS1_MYSTRINGS_H
#define ASS1_MYSTRINGS_H

#define ASCII_ATROPHE 39

#include <stdio.h>
#include <string.h>


typedef struct {
    int start;
    int end;
} word_loc_t;

typedef struct {
    word_loc_t * words;
    int size;
} words_loc_t;


words_loc_t get_words(char * text) {
    //words_t words;

    if(text == NULL) {
        //words.words = NULL;
        //words.size = -1;
    }


    //words.words = malloc(sizeof(char *) * 1024);

    int prevchar = ' ';
    int starting_index = 0;

    // for a bit of efficiency, the length of the string text is calculated once, instead of every iteration.
    size_t tlen = strlen(text);


    for(int i=0; prevchar == ' ' || prevchar == ASCII_ATROPHE || prevchar == '.' || prevchar == '-' && i < tlen;i++) {
        prevchar = text[i];
        starting_index = i;
    }


    // indicate the start of a word
    int wstart = starting_index;
    // indicate the end of a word
    int wend = starting_index;
    int wcount = 0;


    printf("tlen = %zu\n", tlen);

    for(int i = starting_index + 1; i < tlen +1; i++) {
        prevchar = text[i-1];

        // Lets say that if a '.' is detected, everything to the left
        // is a word.

        // check if what the project defines as the terminator for a word is reached.
        int terminator_met = text[i] == ' ' || text[i] == 39 || text[i] == '-' || text[i] == '.' || text[i] == '\0';
        // furthermore check to make sure that the previous characters weren't a word terminator.
        int prevchar_not_terminator = prevchar != ' ' && prevchar != ASCII_ATROPHE && prevchar != '-' && prevchar != '.';

        if(terminator_met && prevchar_not_terminator) {
            // increment the counter for the number of words.
            wcount++;
            //since we have reached what we have defined to be an indicator for
            // the end of the word, the character before it must have been the end of the word
            wend = i -1;

            //Debuging stuff
            for(int j=wstart; j <= wend; j++) {
                printf("%c", text[j]);
            }
            printf("\n");

            // If the character we are at right now isn't the last,
            // we assume the next character is the start of a new word.
            if(i < tlen -1) {
                wstart = i + 1;
                wend = i + 1;
            }
        // check if the character text[i] is not what we defined to be a word terminator and
        // check if the previous character was a word terminator.
        // this indicates a new word has started.
        }else if(!terminator_met && !prevchar_not_terminator) {
            // index starting point for the new word.
            wstart = i;
        }



    }
    printf("wcount = %d\n", wcount);

    //return words;
}

#endif //ASS1_MYSTRINGS_H
