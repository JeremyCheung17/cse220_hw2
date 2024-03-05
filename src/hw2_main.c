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

typedef struct 
{
    unsigned char r, g, b;
} Pixel;

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    FILE *fp;
    char *input_file = NULL;
    char *output_file = NULL;
    const char *a = NULL;
    const char *b = NULL;
    const char *z = NULL;
    int crow = -1;
    int ccol = -1;
    int cwidth = -1;
    int cheight = -1; 
    int prow = -1;
    int pcol = -1; 
    const char *message = NULL;
    const char *font_path = NULL;
    int font_size = -1;
    int rrow = -1;
    int rcol = -1; 
    int in = 0; 
    int o = 0;
    int c = 0;
    int p = 0;
    int r = 0; 
    int x = 0; 
    int y = 0; 
    int g = 0; 
    int v = 0; 
    int option;
    while ((option = getopt(argc, argv, ":i:o:c:p:r:")) != -1) {
        switch (option) {
            case 'i':
                input_file = optarg;
                if(input_file[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                in++;
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
                if(token != NULL)
                {
                    crow = strtol (token,&pEnd,10);
                }
                token = strtok (NULL, " ,");
                if(token != NULL)
                {
                    ccol = strtol (token,&pEnd,10);
                }
                token = strtok (NULL, " ,");
                if(token != NULL)
                {
                    cwidth = strtol (token,&pEnd,10);
                }
                token = strtok (NULL, " ,");
                if(token != NULL)
                {
                    cheight = strtol (token,&pEnd,10);
                }
                token = strtok (NULL, " ,");
                if(token != NULL || crow == -1 || ccol == -1 || cwidth == -1 || cheight == -1)
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
                char *token2 = strtok(optarg, ",");
                char * pEnd2;
                if(token2 != NULL)
                {
                    prow = strtol (token2,&pEnd2,10);
                }
                token2 = strtok (NULL, " ,");
                if(token2 != NULL)
                {
                    pcol = strtol (token2,&pEnd2,10);
                }
                token2 = strtok (NULL, " ,");
                if(token2 != NULL || prow == -1 || pcol == -1)
                {
                    g = 1; 
                }
                if(b[0] == '-')
                {
                    return MISSING_ARGUMENT; 
                }
                p++;
                break;
            case 'r':
                z = optarg; 
                char *token3 = strtok(optarg, ",");
                char * pEnd3;
                if(token3 != NULL)
                {
                    message = token3;
                }
                token3 = strtok (NULL, " ,");
                if(token3 != NULL)
                {
                    font_path = token3;
                }
                token3 = strtok (NULL, " ,");
                if(token3 != NULL)
                {
                    font_size = strtol (token3,&pEnd3,10);
                }
                token3 = strtok (NULL, " ,");
                if(token3 != NULL)
                {
                    rrow = strtol (token3,&pEnd3,10);
                }
                token3 = strtok (NULL, " ,");
                if(token3 != NULL)
                {
                    rcol = strtol (token3,&pEnd3,10);
                }
                token3 = strtok (NULL, " ,");
                if(token3 != NULL || message == NULL || font_path == NULL || font_size == -1 || rrow == -1 || rcol == -1 || (fp = fopen(font_path, "r")) == NULL)
                {
                    v = 1; 
                }
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
    if(in >= 2 || o >= 2 || c >= 2 || p >= 2 || r >= 2)
    {
        return DUPLICATE_ARGUMENT; 
    }
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
    if(y == 1)
    {
        return C_ARGUMENT_INVALID; 
    }
    if(g == 1)
    {
        return P_ARGUMENT_INVALID; 
    }
    if(v == 1)
    {
        return R_ARGUMENT_INVALID; 
    }

    int ilength = strlen(input_file);
    char itype = input_file[ilength - 1];
    int olength = strlen(output_file);
    char otype = output_file[olength - 1];
    if(itype == 'm')
    {
        if(otype == 'm')
        {
            if(prow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");
                
                if(rrow != -1)
                {

                }
                fclose(f1); 
                fclose(f2); 
            }
            else if(rrow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");

                fclose(f1); 
                fclose(f2); 
            }
            else
            {
                FILE *f1, *f2;
                char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");
                ch = fgetc(f1); 
                while (ch != EOF) 
                { 
                    fputc(ch, f2); 
                    ch = fgetc(f1); 
                }
                fclose(f1); 
                fclose(f2); 
            }
        }
        else if(otype == 'u')
        {
            if(prow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");
                if(rrow != -1)
                {

                }
                fclose(f1); 
                fclose(f2); 
            }
            else if(rrow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");

                fclose(f1); 
                fclose(f2); 
            }
            else
            {
                FILE *f1, *f2;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");
                char format[2];
                int width, height, max_color;
                Pixel image[1000][1000];
                Pixel color_table[255];
                int color_index[1000][1000];
                fscanf(f1, "%2s", format); 
                fscanf(f1, "%d %d", &width, &height); 
                fscanf(f1, "%d", &max_color);
                for (int i = 0; i < height; i++) 
                {
                    for (int j = 0; j < width; j++) 
                    {
                        fscanf(f1, "%hhu %hhu %hhu", &image[i][j].r, &image[i][j].g, &image[i][j].b);
                    }
                }
                int num_colors = 0;
                for (int i = 0; i < height; i++) 
                {
                     for (int j = 0; j < width; j++) 
                     {
                        int found = 0;
                        for (int k = 0; k < num_colors; k++) 
                        {
                            if (image[i][j].r == color_table[k].r && image[i][j].g == color_table[k].g && image[i][j].b == color_table[k].b) 
                            {
                                color_index[i][j] = k;
                                found = 1;
                                break;
                            }
                        }
                        if (!found) 
                        {
                            color_table[num_colors] = image[i][j];
                            color_index[i][j] = num_colors;
                            num_colors++;
                        }
                    }
                }
                fprintf(f2, "SBU\n%d %d\n%d\n", width, height, num_colors);
                for (int i = 0; i < num_colors; i++) 
                {
                    fprintf(f2, "%hhu %hhu %hhu ", color_table[i].r, color_table[i].g, color_table[i].b);
                }
                fprintf(f2, "\n");
                for (int i = 0; i < height; i++) 
                {
                    int count = 1;
                    for (int j = 1; j < width; j++) 
                    {
                        if(j == width - 1 && color_index[i+1][0] == color_index[i][j])
                        {
                            count++; 
                            i++; 
                            j = 0;
                        }
                        if (color_index[i][j] == color_index[i][j-1]) 
                        {
                            count++;
                        } 
                        else 
                        {
                            if (count > 1) 
                            {
                                fprintf(f2, "*%d %d ", count, color_index[i][j-1]);
                            } 
                            else 
                            {
                                fprintf(f2, "%d ", color_index[i][j-1]);
                            }
                            count = 1;
                        }
                    }
                    if (count > 1) 
                    {
                        fprintf(f2, "*%d %d ", count, color_index[i][width-1]);
                    } 
                    else 
                    {
                        fprintf(f2, "%d ", color_index[i][width-1]);
                    }
                }
                fclose(f1); 
                fclose(f2); 
            }
        }
    }
    else if(itype == 'u')
    {
        if(otype == 'u')
        {
            if(prow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");
                if(rrow != -1)
                {

                }
                fclose(f1); 
                fclose(f2); 
            }
            else if(rrow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");

                fclose(f1); 
                fclose(f2); 
            }
            else
            {
                FILE *f1, *f2;
                char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");
                ch = fgetc(f1); 
                while (ch != EOF) 
                { 
                    fputc(ch, f2); 
                    ch = fgetc(f1); 
                }
                fclose(f1); 
                fclose(f2); 
            }
        }
        else if(otype == 'p')
        {
            if(prow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");

                if(rrow != -1)
                {

                }
                fclose(f1); 
                fclose(f2); 
            }
            else if(rrow != -1)
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");

                fclose(f1); 
                fclose(f2); 
            }
            else
            {
                FILE *f1, *f2;
                //char ch;
                f1 = fopen(input_file, "r");
                f2 = fopen(output_file, "w");

                fclose(f1); 
                fclose(f2); 
            }
        }
    }
    return 0;
}
