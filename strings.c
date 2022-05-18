#include "strings.h"
#include <stdio.h>
#define MAXPATH 260


int schr(char *str, char ch)
{
    int i = 0;
    while (*str != '\0')
    {
        if (*str == ch)
        {
            return i;
        }
        str++;
        i++;
    }
    return -1;
}


int is_abs_path(char *buf)
{
    if (buf[0] == '/') return 1;

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

int stok(char *in_string, char delim, char *ptr[])
{
    char *suf = in_string;
    ptr[0] = in_string;
    int i, j = 1;
    while ( (i = schr(suf, delim)) >= 0)
    {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    
    return j;
}