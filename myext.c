#include <stdio.h>
#include "ext.h"


void print()
{
    printf("print in myext");
}

function_entry functions[1] = {{"print", print}};

ext_entry myext_entry = {
    "myext",
    1,
    functions
};

ext_entry* get_ext_entry()
{
    return &myext_entry;
}
