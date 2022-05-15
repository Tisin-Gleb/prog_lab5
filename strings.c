#include "strings.h"
#include <stdio.h>
#define MAXPATH 260
// sspn(char *buf)
// {
//     char inc_sym[] = {'\0', '/'};
//     int length = strlen(buf);
//     int i = 0;
//     printf("%d\n", length);
//     while(length--)
//     {   
        
//     }
    
//     //char array_inc_sym = {'*', '?', ' ', '$', '&', '(', ')', '/', '.'};
// }

int isabsolute(char *buf)
{
    if (buf[0] == '/')
        return 1;
    else
        return 0;
}

int slen(char *buf)
{
    int i = 0;
    while (buf[i] != '\0')
    {
        i++;
    }
    return i;
}

char *scpy(char *destination, char *source)
{
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return start;
}

 //-1 s1>s2 | 1 s1<s2 | 0 s1=s2
int scmp(char *str1, char *str2)
{
    int len1 = slen(str1);
    int len2 = slen(str2);
    int len_max = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < len_max; i++)
    {
        if (str1[i] > str2[i]) return 1;
        else if (str1[i] < str2[i]) return -1;
        else if (str1[i] == str2[i]) continue;
    }
    return 0;
}

int stok(char *in_string, char delim)
{
    int length = slen(in_string);
    char buf[length + 1];
    FILE *tokens;
    if ((tokens = fopen("tokens.txt", "w+")) == NULL)
        return 0;
    for (int i = 0; i < length; i++)
    {
        if (in_string[i] == delim)
        {
            scpy(buf, in_string);
            buf[i] = '\0';
            fprintf(tokens, "%s", buf);
        }
    }
    fclose(tokens);
    return 1;
}