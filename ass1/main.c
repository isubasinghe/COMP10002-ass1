#include "queries.h"
#include "mystrings.h"


int main(int argc, char * argv[]) {
    if(argc == 1) {
        return 0;
    }
    process_queries(argc, argv);
    process_lines(argc, argv);
}