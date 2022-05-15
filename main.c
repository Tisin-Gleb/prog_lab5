#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "strings.c"

char* winput(char buffer[])
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        buffer[i] = ch;
        i++;
        if (i > MAXPATH - 1) exit(1);
    }
    buffer[i] = '\0';
    return buffer;
}

int main()
{
    FILE* input;
    //FILE* output;
    char buffer[MAXPATH];
    char delim = '+';
    if ( (input = fopen("input.txt", "w") ) == NULL) return 0;
    //if ( (output = fopen("output.txt", "r")) == NULL) return 0;
    printf("delim: +\n");
    printf("dir: ");

    //winput(buffer);
    
    // fprintf(input, "%s", buffer);
    // if (!isabsolute(buffer)) exit(2);
    // printf("aboba\n");
    
    printf("paths: ");
    char *ptr[MAXPATH];
    char str1[MAXPATH] = "~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc";
    int a = stok(str1, delim, ptr);
    printf("%d", a);

    for (int i = 0; a > 0; i++, a--)
    {
        fprintf(input, "%s\n", ptr[i]);
    }
    fclose(input);
    

    //fprintf(input, "%s", buffer);
    
}