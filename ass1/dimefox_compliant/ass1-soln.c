#define ASCII_ATROPHE 39
#define ASCII_LOWER_TO_HIGHER_DIFF 32

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


typedef  struct {
    char * text;
    int line;
    double score;
} score_data_t;

typedef struct {
    int start;
    int end;
} word_loc_t;

typedef struct {
    word_loc_t * word_loc;
    int size;
} words_loc_t;


int isalphal(int);

int mygetchar();

char * read_line();

int has_prefix(char *, char *, int, int);

double score(int, char *[], char *, words_loc_t);

int is_terminator(int c);

words_loc_t get_words(char *);

int is_valid_query(char *);

void process_lines(int, char *[]);

int insert_top5(score_data_t * top5, score_data_t sdata);








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

    printf("------------------------------------------------\n");
    for(int i=0 ; i < 5; i++) {
        if(top5[i].text != NULL) {
            printf("S4: %s score = %0.2f at line %d\n", top5[i].text, top5[i].score, top5[i].line);
            free(top5[i].text);
        }
    }

    free(top5);
}

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
    char terminators[] = {' ', ASCII_ATROPHE, '.', '-', '*', ',', '(', ')', ';',
                          '"',':', '!', '?', '[', ']', '/', '\\', '@', '\0'};
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

    // for a bit of efficiency, the length of the string text is
    // calculated once, instead of every iteration.
    size_t tlen = strlen(text);

    // make sure that the character we are starting
    // off at isn't a word terminator.
    for(int i=0; (!is_terminator(prevchar)) && i < tlen;i++) {
        prevchar = text[i];
        starting_index = i;
    }


    // indicate the start of a word
    int wstart = starting_index;
    // indicate the end of a word
    int wend = wstart;


    for(int i = starting_index + 1; i < tlen +1; i++) {
        prevchar = text[i-1];


        // check if what the project defines as the
        // terminator for a word is reached.
        int terminator_met = is_terminator(text[i]) || text[i] == '\0';
        // furthermore check to make sure that the previous
        // characters weren't a word terminator,
        // this indicates the end of a word.
        int prevchar_not_terminator = !is_terminator(prevchar);

        if(terminator_met && prevchar_not_terminator) {

            //since we have reached what we have defined to be an indicator for
            // the end of the word, the character before
            // it must have been the end of the word
            wend = i -1;

            // Allocate 1024 more instances of word_loc_t
            if(words_loc.size%1023 == 0) {
                words_loc.word_loc = realloc(words_loc.word_loc,
                                             sizeof(word_loc_t) *
                                                     (1024 + words_loc.size));
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
        // check if the character text[i] is not what we
            // defined to be a word terminator and
        // check if the previous character was a word terminator.
        // this indicates a new word has started.
        }else if(!terminator_met && !prevchar_not_terminator) {
            // index starting point for the new word.
            wstart = i;
        }



    }
    return words_loc;
}

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
    
    if (c == '\n') {
        text[0] = '\n';
        return text;
    }
    
    // Check if we have enough memory.
    if(text == NULL) {
        perror("in function read_line: out of memory\n");
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

// Checks if a character is a lowercase
// alphabetic character.
int isalphal(int c) {
    if(c >= 'a' && c<= 'z') {
        return 1;
    }
    return 0;
}

int main(int argc, char * argv[]) {
    // No queries were given, since q = arg -1
    if(argc == 1) {
        printf("S1: No query specified, must provide at least one word\n");
        return 0;
    }

    // indicate if we have detected an error.
    int errors = 0;

    for(int i=1; i < argc; i++) {
        if(!is_valid_query(argv[i])) {
            printf("S1: %s: invalid character(s) in query\n", argv[i]);
            // we have found an error;
            errors =1;
        }
    }


    // error was detected so we don't process the input, and exit the program.
    if(errors) {
        return -1;
    }

    printf("S1: query =");

    //print the queries out
    for(int i=1; i < argc; i++) {

        printf(" %s", argv[i]);
    }
    printf("\n");

    process_lines(argc, argv);
}