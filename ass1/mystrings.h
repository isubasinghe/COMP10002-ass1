//
// Created by isitha on 6/09/17.
//

#ifndef ASS1_MYSTRINGS_H
#define ASS1_MYSTRINGS_H


// I had to define this as
// as int ascii_atrophe = ''',
// is invalid
#define ASCII_ATROPHE 39
#define ASCII_LOWER_TO_HIGHER_DIFF 32

#include <stdio.h>
#include <string.h>
#include <math.h>




typedef struct {
    int start;
    int end;
} word_loc_t;

typedef struct {
    word_loc_t * word_loc;
    int size;
} words_loc_t;


int has_prefix(char *, char *, int, int);

double score(int, char *[], char *, words_loc_t);

int is_terminator(int c);

words_loc_t get_words(char *);


int has_prefix(char * prefix, char * text, int low, int high) {
    if(strlen(prefix) > high - low + 1) {
        return 0;
    }

    int i;
    for(i=0; i < strlen(prefix); i++) {
        int c = text[i + low];
        if(c >= 'A' && c <= 'Z') {
            c = c + ASCII_LOWER_TO_HIGHER_DIFF;
        }

        if (prefix[i] != c) {
            return 0;
        }
    }
    return 1;
}

double score(int argc, char *argv[], char * text, words_loc_t words_loc) {
    double sum = 0;
    words_loc = get_words(text);
    for(int i=0; i < argc; i++) {
        int query_occurrences = 0;
        for(int j = 0; j < words_loc.size; j++) {
            if(has_prefix(argv[i], text, words_loc.word_loc[j].start, words_loc.word_loc[j].end)) {
                query_occurrences++;
            }
        }
        //printf("query occurs = %d times\n", query_occurrences);
        sum += log(1.0 + query_occurrences)/log(2.0);

    }

    if(words_loc.word_loc != NULL) {
        free(words_loc.word_loc);

    }
    return sum/(log(8.5 + words_loc.size)/log(2.0));

}

int is_terminator(int c) {
    char terminators[] = {' ', ASCII_ATROPHE, '.', '-', '*', ',', '(', ')', ';', '\0'};
    if (strchr(terminators, c) != NULL)
    {
        return 1;
    }
    return 0;
}

// remember to free the pointer word_loc_t.words.
words_loc_t get_words(char * text) {

    words_loc_t words_loc;
    words_loc.word_loc = NULL;
    words_loc.size = 0;

    if(text == NULL) {
        return words_loc;
    }

    // Allocate 1024 instances of a single word_loc_t pseudo object.
    words_loc.word_loc = malloc(sizeof(word_loc_t) * 1024);

    int prevchar = ' ';
    int starting_index = 0;

    // for a bit of efficiency, the length of the string text is calculated once, instead of every iteration.
    size_t tlen = strlen(text);

    // make sure that the character we are starting off at isn't a word terminator.
    for(int i=0; (prevchar == ' ' || prevchar == ASCII_ATROPHE || prevchar == '.' || prevchar == '-') && i < tlen;i++) {
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

            // Allocate 1024 more instances of word_loc_t
            if(words_loc.size%1023 == 0) {
                words_loc.word_loc = realloc(words_loc.word_loc, sizeof(word_loc_t) * (1024 + words_loc.size));
                if(words_loc.word_loc == NULL) {
                    perror("in function get_words: out of memory");
                    words_loc.size = 0;
                    return words_loc;
                }
            }

            words_loc.word_loc[words_loc.size].start = wstart;
            words_loc.word_loc[words_loc.size].end = wend;

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
