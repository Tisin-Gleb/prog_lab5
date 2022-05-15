#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "strings.c"
#include <string.h>

int main()
{
    // FILE* input;
    // FILE* output;
    // char buffer[MAXPATH];
    // char delim;
    // // if ( (input = fopen("input.txt", "w+") ) == NULL) return 0;
    // // if ( (output = fopen("output.txt", "r")) == NULL) return 0;
    // // printf("delim: +\n");
    // // printf("dir: ");

    // // char ch;
    // // int i = 0;
    // // while ((ch = getchar()) != '\n')
    // // {
    // //     buffer[i] = ch;
    // //     i++;
    // //     if (i > MAXPATH - 1) exit(1);
    // // }
    // // buffer[i] = '\0';
    // // fprintf(input, "%s", buffer);
    // // if (!isabsolute(buffer)) exit(2);
    char str1[] = "bubuntudsa";
    char str2[] = "bubuntzzzz";
    scpy(str1, str2);

    printf("%s", str1);
    
    //printf("aboba\n");


}