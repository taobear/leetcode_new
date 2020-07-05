#include "dijkstra_minpath.h"
#include "dfs_minpath.h"

#include "test_data.h"

#include <iostream>
using namespace std;

void test_minpath(const vector<vector<int>> &A)
{
    dfs_solution sln;

    cout << sln.maximumMinimumPath(A) << endl;
}

int main(int argc, char **argv)
{
    test_minpath(test1);
    test_minpath(test2);
    test_minpath(test3);
    test_minpath(test4);
    test_minpath(test5);

    return 0;
}