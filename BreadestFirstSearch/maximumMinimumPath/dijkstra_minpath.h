#ifndef __DIJKSTRA_MINPATH_H_
#define __DIJKSTRA_MINPATH_H_

#include <vector>
#include <queue>
#include <climits>

using namespace  std;

struct qnode {
    int x;
    int y;
};

class Solution {
public:
    int maximumMinimumPath(const vector<vector<int>> &A);

private:
    void relax(const vector<vector<int>> &A, int rows, int cols, int x, int y);

    queue<qnode> pq;
    vector<vector<int>> minPath;
};

int Solution::maximumMinimumPath(const vector<vector<int>> &A)
{
    int rows = A.size();
    if (rows <= 0) {
        return INT_MAX;
    }

    int cols = A[0].size();
    if (cols <= 0) {
        return INT_MAX;
    }

    minPath.resize(rows, vector<int>(cols, INT_MAX));

    pq.push(qnode{0,0});
    minPath[0][0] = A[0][0];
    while (!pq.empty()) {
        qnode qn = pq.front();
        pq.pop();

        relax(A, rows, cols, qn.x, qn.y);
    }

    return minPath[rows - 1][cols - 1];
}

void Solution::relax(const vector<vector<int>> &A, int rows, int cols, int x, int y)
{
    for (int delta_x = -1; delta_x <= 1; ++delta_x) {
        for (int delta_y = -1; delta_y <= 1; ++delta_y) {
            if (delta_x == delta_y || delta_x + delta_y == 0) {
                continue;
            }

            if (x + delta_x < 0 || x + delta_x >= rows) {
                continue;
            }

            if (y + delta_y < 0 || y + delta_y >= cols) {
                continue;
            }

            int currMinPath = min(minPath[x][y], A[x + delta_x][y + delta_y]);
            if (minPath[x + delta_x][y + delta_y] == INT_MAX || 
                minPath[x + delta_x][y + delta_y] < currMinPath) {
                minPath[x + delta_x][y + delta_y] = currMinPath;
                pq.push(qnode {x + delta_x, y + delta_y});
            }
        }
    }
}
#endif


