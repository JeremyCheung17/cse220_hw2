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
    int i = 0; 
    int o = 0;
    int c = 0;
    int p = 0;
    int r = 0; 
    int x = 0; 
    int option;
    while ((option = getopt(argc, argv, "iocpr:")) != -1) {
        switch (option) {
            case 'i':
                input_file = optarg;
                i++;
                break;
            case 'o':
                output_file = optarg;
                o++;
                break;
            case 'c':
                
                c++; 
                break;
            case 'p':

                p++;
                break;
            case 'r':

                r++; 
                break;
            case '?':
            default:
                x = 1;
        }
    }
    if (input_file == NULL || output_file == NULL) 
    {
        return MISSING_ARGUMENT;
    }
    if(x == 1)
    {
        return UNRECOGNIZED_ARGUMENT;
    }
    if(i >= 2 || o >= 2 || c >= 2 || p >= 2 || r >= 2)
    {
        return DUPLICATE_ARGUMENT; 
    }
    FILE *fp;
    if ((fp = fopen(input_file, "r")) == NULL)
    {
        return INPUT_FILE_MISSING; 
    }
    if ((fp = fopen(output_file, "w")) == NULL)
    {
        return OUTPUT_FILE_UNWRITABLE; 
    }
    if(p == 1 && c == 0)
    {
        return C_ARGUMENT_MISSING; 
    }
    return 0;
}
