//
// Created by isitha on 6/09/17.
//

#ifndef ASS1_MYSTRINGS_H
#define ASS1_MYSTRINGS_H


// I had to define this as
// as int ascii_atrophe = ''',
// is invalid
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


int has_prefix(char *, char *, int, int);

double score(int, char *[], char *);

words_loc_t get_words(char *);


int has_prefix(char * prefix, char * text, int low, int high) {
    if(strlen(prefix) > high - low + 1) {
        return 0;
    }
}

double score(int argc, char *argv[], char * text) {

}

// remember to free the pointer word_loc_t.words.
words_loc_t get_words(char * text) {

    words_loc_t words_loc;
    words_loc.words = NULL;
    words_loc.size = 0;

    if(text == NULL) {
        return words_loc;
    }

    // Allocate 1024 instances of a pointer.
    words_loc.words = malloc(sizeof(char *) * 1024);

    int prevchar = ' ';
    int starting_index = 0;

    // for a bit of efficiency, the length of the string text is calculated once, instead of every iteration.
    size_t tlen = strlen(text);

    // make sure that the character we are starting off at isn't a word terminator.
    for(int i=0; prevchar == ' ' || prevchar == ASCII_ATROPHE || prevchar == '.' || prevchar == '-' && i < tlen;i++) {
        prevchar = text[i];
        starting_index = i;
    }


    // indicate the start of a word
    int wstart = starting_index;
    // indicate the end of a word
    int wend = wstart;


    for(int i = starting_index + 1; i < tlen +1; i++) {
        prevchar = text[i-1];


        // check if what the project defines as the terminator for a word is reached.
        int terminator_met = text[i] == ' ' || text[i] == ASCII_ATROPHE || text[i] == '-' || text[i] == '.' || text[i] == '\0';
        // furthermore check to make sure that the previous characters weren't a word terminator,
        // this indicates the end of a word.
        int prevchar_not_terminator = prevchar != ' ' && prevchar != ASCII_ATROPHE && prevchar != '-' && prevchar != '.';

        if(terminator_met && prevchar_not_terminator) {

            //since we have reached what we have defined to be an indicator for
            // the end of the word, the character before it must have been the end of the word
            wend = i -1;

            if(words_loc.size%1023 == 0) {
                words_loc.words = realloc(words_loc.words, sizeof(char *) * (1024 + words_loc.size));
                if(words_loc.words == NULL) {
                    perror("in function get_words: out of memory");
                    words_loc.size = 0;
                    return words_loc;
                }
            }

            words_loc.words[words_loc.size].start = wstart;
            words_loc.words[words_loc.size].end = wend;

            words_loc.size++;

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
    return words_loc;
}

#endif //ASS1_MYSTRINGS_H
