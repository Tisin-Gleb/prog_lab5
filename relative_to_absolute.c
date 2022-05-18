#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "strings.c"
#include "relative_to_absolute.h"

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

int input(char home_dir[], char buffer[])
{
    FILE* input;
    char delim = '+';
    char *ptr[MAXPATH];
    int path_counter;
    if ( (input = fopen("input.txt", "w+") ) == NULL) return 0;

    printf("delim: +\ndir: ");
    winput(home_dir);
    //char str2[MAXPATH] = "~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc";
    path_counter = stok(buffer, delim, ptr);
    printf("paths: ");
    winput(buffer);
    for (int i = 0; i < path_counter; i++)
    {
        fscanf(input, "%s", ptr[i]);
    }
    
    fclose(input);
    return 1;
}
int check(char home_dir[], char buf[])
{
    char test_buf[MAXPATH];
    char *test_ptr[MAXPATH];
    int count_tokens = 0;

    if (slen(home_dir) > MAXPATH){
        printf("check dir - len failed/n");
        exit(1);
    }

    scpy(test_buf, home_dir);
    count_tokens = stok(test_buf, '/', test_ptr);
    for (int i = 1; i < count_tokens; i++)
    {
        if ( !(slen(*(test_ptr + i))) )
        {
            puts("incorrect home_dir");
            exit(2);
        }
    }
    if (!is_abs_path(home_dir)) exit(3);

    if (slen(buf) > MAXPATH){
        printf("check path - len failed/n");
        exit(3);
    }

    scpy(test_buf, buf);

    if ( ((count_tokens = stok(test_buf, '/', test_ptr) ) == 0)){
        puts("not a linux path");
        exit(1);
    }
    printf("%d",count_tokens);
    for (int i = 1; i < count_tokens; i++)
    {
        if ( !(slen(*(test_ptr + i))) )
        {
            puts("incorrect path");
            exit(2);
        }
    } 
    return 1;
}

int proccess(char home_dir[])
{
    FILE *output;
    FILE *input;

    char buf[MAXPATH];
    char *ptr;

    if ( (output = fopen("output.txt", "w") ) == NULL) return 0; 
    if ( (input = fopen("input.txt", "r") ) == NULL) return 0;
    
    int first_iter = 0;
    while (fscanf(input, "%s", buf) == 1)
    {
        if (first_iter)
        {
            fprintf(output, "+");
        }
        if ( (buf[0] == '~')  && (buf[1] != '/') )
        {
            ptr = &buf[1];
            fprintf(output, "%s/%s", home_dir, ptr);
        }else{
            ptr = &buf[0];
            fprintf(output, "%s", buf);
        }
        first_iter++;
    }

    fclose(output);
    fclose(input);
    return 1;
}

int output_path()
{
    FILE *output;
    char buf[MAXPATH];
    printf("paths: ");
    if ( (output = fopen("output.txt", "r") ) == NULL) return 0;
    while(!feof(output))
    {
        fscanf(output, "%s", buf);
    }
    printf("%s\n", buf);
    
    return 1;
}
