#ifndef __DFS_MINPATH_H_
#define __DFS_MINPATH_H_

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class dfs_solution {
public:
    int maximumMinimumPath(const vector<vector<int>> &A);

private:
    bool hasPathBiggerThanK(const vector<vector<int>> &A, vector<vector<bool>> &visited, int rows, int cols, int x, int y, int k);
};

bool dfs_solution::hasPathBiggerThanK(const vector<vector<int>> &A, vector<vector<bool>> &visited, int rows, int cols, int x, int y, int K)
{
    if (x == rows - 1 && y == cols - 1) {
        return true;
    }

    visited[x][y] = true;

    int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; ++i) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];

        if (next_x < 0 || next_x >= rows) {
            continue;
        }

        if (next_y < 0 || next_y >= cols) {
            continue;
        }

        if (visited[next_x][next_y] == true) {
            continue;
        }

        if (A[next_x][next_y] < K) {
            continue;
        }

        if (hasPathBiggerThanK(A, visited, rows, cols, next_x, next_y, K)) {
            return true;
        }
    }

    return false;
} 

int dfs_solution::maximumMinimumPath(const vector<vector<int>> &A)
{
    int rows = A.size();
    if (rows <= 0) {
        return INT_MAX;
    }

    int cols = A[0].size();
    if (cols <= 0) {
        return INT_MAX;
    }

    int hi = min(A[0][0], A[rows - 1][cols - 1]);
    int lo = 0;
    int mid = 0;
    int result = 0;
    while (lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        if (hasPathBiggerThanK(A, visited, rows, cols, 0, 0, mid)) {
            lo = mid + 1;
            result = mid;
        } else {
            hi = mid - 1;
        }
    }

    return result;
}

#endif