#include "ways.h"

#include <stdio.h>

void test1()
{
    char pizza1[] = "A..";
    char pizza2[] = "AAA";
    char pizza3[] = "...";
    
    char *pizza[] = {pizza1, pizza2, pizza3};
    int k = 3;
    int pizzaSize = sizeof(pizza) / sizeof(*pizza);

    printf("test1(): %d\n", ways(pizza, pizzaSize, k));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}