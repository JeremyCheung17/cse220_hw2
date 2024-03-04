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
    int crow = -1;
    int ccol = -1;
    int cwidth = -1;
    int cheight = -1; 
    /*
    int prow = NULL;
    int pcol = NULL; 
    const char *message = NULL;
    const char *font_path = NULL;
    int font_size = NULL;
    int rrow = NULL;
    int rcol = NULL; */
    int i = 0; 
    int o = 0;
    int c = 0;
    int p = 0;
    int r = 0; 
    int x = 0; 
    int y = 0; 
    int option;
    while ((option = getopt(argc, argv, ":i:o:c:p:r:")) != -1) {
        switch (option) {
            case 'i':
                input_file = optarg;
                if(input_file[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                i++;
                break;
            case 'o':
                output_file = optarg;
                if(output_file[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                o++;
                break;
            case 'c':
                a = optarg; 
                char *token = strtok(optarg, ",");
                char * pEnd;
                crow = strtol (token,&pEnd,10);
                token = strtok (NULL, " ,.-");
                ccol = strtol (token,&pEnd,10);
                token = strtok (NULL, " ,.-");
                cwidth = strtol (token,&pEnd,10);
                token = strtok (NULL, " ,.-");
                cheight = strtol (token,&pEnd,10);
                token = strtok (NULL, " ,.-");
                if(token != NULL)
                {
                    y = 1; 
                }
                if(a[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                c++; 
                break;
            case 'p':
                b = optarg; 
                //char *token = strtok(optarg, ",");
                if(b[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                p++;
                break;
            case 'r':
                z = optarg; 
                //char *token = strtok(optarg, ",");
                if(z[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                r++; 
                break;
            case ':':
                return MISSING_ARGUMENT; 
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
    if(y == 1 || crow == -1 || ccol == -1 || cwidth == -1 || cheight == -1)
    {
        return C_ARGUMENT_INVALID; 
    }
    return 0;
}
