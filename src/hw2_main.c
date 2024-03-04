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
    const char *a = NULL;
    const char *b = NULL;
    const char *z = NULL;
    int i = 0; 
    int o = 0;
    int c = 0;
    int p = 0;
    int r = 0; 
    int x = 0; 
    int option;
    while ((option = getopt(argc, argv, "i:o:c:p:r:")) != -1) {
        switch (option) {
            case 'i':
                input_file = optarg;
                if(input_file[0] == "-")
                {
                    return MISSING_ARGUMENT; 
                }
                i++;
                break;
            case 'o':
                output_file = optarg;
                if(output_file[0] == "-")
                {
                    return MISSING_ARGUMENT; 
                }
                o++;
                printf("%s", optarg);
                break;
            case 'c':
                a = optarg; 
                if(a[0] == "-")
                {
                    return MISSING_ARGUMENT; 
                }
                c++; 
                break;
            case 'p':
                b = optarg; 
                if(b[0] == "-")
                {
                    return MISSING_ARGUMENT; 
                }
                p++;
                break;
            case 'r':
                z = optarg; 
                if(z[0] == "-")
                {
                    return MISSING_ARGUMENT; 
                }
                r++; 
                break;
            case '?':
            default:
                x = 1;
        }
    }
    printf("%s", output_file);
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
