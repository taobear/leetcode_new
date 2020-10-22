#include "coinChange.h"

void test1()
{
    int coins[] = { 1, 2, 5 };
    int coinsSize = sizeof(coins) / sizeof(*coins);
    int amount = 11;

    printf("test1(): %d\n", coinChange(coins, coinsSize, amount));
}

void test2()
{
    int coins[] = { 2 };
    int coinsSize = sizeof(coins) / sizeof(*coins);
    int amount = 3;

    printf("test2(): %d\n", coinChange(coins, coinsSize, amount));
}

void test3()
{
    int coins[] = { 1 };
    int coinsSize = sizeof(coins) / sizeof(*coins);
    int amount = 0;

    printf("test3(): %d\n", coinChange(coins, coinsSize, amount));
}

void test4()
{
    int coins[] = { 1 };
    int coinsSize = sizeof(coins) / sizeof(*coins);
    int amount = 1;

    printf("test4(): %d\n", coinChange(coins, coinsSize, amount));
}

void test5()
{
    int coins[] = { 1 };
    int coinsSize = sizeof(coins) / sizeof(*coins);
    int amount = 2;

    printf("test5(): %d\n", coinChange(coins, coinsSize, amount));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    test5();

    return 0;
}