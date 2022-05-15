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

int input(char home_dir[])
{
    FILE* input;
    char buffer[MAXPATH];
    char delim = '+';
    if ( (input = fopen("input.txt", "w+") ) == NULL) return 0;

    printf("delim: +\ndir: ");
    winput(home_dir);
    

    char str2[MAXPATH] = "~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc";
    
    printf("paths: ");
    //winput(buffer);

    char *ptr[MAXPATH];
    int path_counter = 0;
    
    path_counter = stok(str2, delim, ptr);

    for (int i = 0; path_counter > 0; i++, path_counter--)
    {
        fprintf(input, "%s\n", ptr[i]);
    }
    fclose(input);
    return 1;
}
// int check(char buf[])
// {
//     char *ptr = buf;
//     char *paths[MAXPATH];
//     char delim = '+';
//     int length = slen(buf);

//     int path_count = 0;
//     while (schr(buf, delim)!= NULL) //клч путей
//     {
//         path_count++;
//     }

//     stok(buf, delim, paths);
//     // for (int i = 0; i < path_count; i++)
//     // {

//     //     stok(*paths[i]  )
//     // }
//         //проверка на запрещенку
    
    
// }

int proccess(char home_dir[])
{
    FILE *output;
    FILE *input;
    char buf[MAXPATH];
    char *ptr;

    if ( (output = fopen("output.txt", "w") ) == NULL) return 0; 
    if ( (input = fopen("input.txt", "r") ) == NULL) return 0;
    
    //relative_path
    while(feof(input))
    {
        fscanf(input, "%s", buf);
        if ( (buf[0] == '~')  && (buf[1] != '/') )
        {
            ptr = &buf[1];
            fprintf(output, "%s%s\n", home_dir, ptr);
        }
    }
    // fclose(output);
    fclose(input);
    return 1;
}

int output()
{

}

int main()
{
    char home_dir[MAXPATH];
    input(home_dir);
    proccess(home_dir);
}