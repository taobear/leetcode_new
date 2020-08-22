#include "restoreIpAddresses.h"

#include "../func_2d_objs.h"

void test1()
{
    char s[] = "25525511135";

    int returnSize = 0;
    char **ipAddr = restoreIpAddresses(s, &returnSize);

    print_2d_str(ipAddr, returnSize);
    free_2d_str(ipAddr, returnSize);
}

void test2()
{
    char s[] = "0000";

    int returnSize = 0;
    char **ipAddr = restoreIpAddresses(s, &returnSize);

    print_2d_str(ipAddr, returnSize);
    free_2d_str(ipAddr, returnSize);
}

void test3()
{
    char s[] = "1111";

    int returnSize = 0;
    char **ipAddr = restoreIpAddresses(s, &returnSize);

    print_2d_str(ipAddr, returnSize);
    free_2d_str(ipAddr, returnSize);
}

void test4()
{
    char s[] = "010010";

    int returnSize = 0;
    char **ipAddr = restoreIpAddresses(s, &returnSize);

    print_2d_str(ipAddr, returnSize);
    free_2d_str(ipAddr, returnSize);
}

void test5()
{
    char s[] = "101023";

    int returnSize = 0;
    char **ipAddr = restoreIpAddresses(s, &returnSize);

    print_2d_str(ipAddr, returnSize);
    free_2d_str(ipAddr, returnSize);
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