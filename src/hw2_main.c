#include "hw2.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> 
#include <getopt.h>

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    const char *input_file = NULL;
    const char *output_file = NULL;
    int option;
    while ((option = getopt(argc, argv, "i:o:c:p:r:")) != -1) {
        switch (option) {
            case 'i':
                input_file = optarg;
                break;
            case 'o':
                output_file = optarg;
                break;
            case 'c':

                break;
            case 'p':

                break;
            case 'r':

                break;
            case '?':
            default:
                return UNRECOGNIZED_ARGUMENT;
        }
    }
    if (input_file == NULL || output_file == NULL) 
    {
        return MISSING_ARGUMENT;
    }
    return 0;
}
