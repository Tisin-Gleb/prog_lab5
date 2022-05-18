#include <stdio.h>
#include <stdlib.h>
#include "relative_to_absolute.h"
#include "relative_to_absolute.c"

int main()
{
    char buffer[MAXPATH];
    char home_dir[MAXPATH];
    input(home_dir, buffer);
    check(home_dir, buffer);
    proccess(home_dir);
    output_path();
}