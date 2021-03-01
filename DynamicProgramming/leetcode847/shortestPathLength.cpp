
#include "shortestPathLength.h"

typedef struct {
    int state;
    int last;
} Node;

int shortestPathLength(int** graph, int graphSize, int* graphColSize)
{
    if (graphSize <= 0 || graphColSize[0] <= 0) {
        return 0;
    }

    int maxState = 1 << graphSize;

    int minDist[maxState][graphSize];
    for (int i = 0; i < maxState; i++) {
        for (int j = 0; j < graphSize; j++) {
            minDist[i][j] = graphSize * graphSize;
        }
    }

    int head = 0, tail = 0;
    Node queue[maxState * graphSize];
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphColSize[i]; j++) {
            int state = (1 << i) | (1 << graph[i][j]);
            minDist[state][i] = 0;

            queue[tail].state = state;
            queue[tail].last = i;
            tail++;
        }
    }

    while (head != tail) {
        Node node = queue[head++];
        for (int i = 0; i < graphColSize[node.last]; i++) {
            int newLast = graph[node.last][i];
            int newState = node.state | (1 << newLast);
            if (minDist[newState][newLast] <= minDist[node.state][node.last] + 1) {
                continue;
            }

            queue[tail].state = newState;
            queue[tail].last = newLast;
            tail++;

            minDist[newState][newLast] = minDist[node.state][node.last] + 1;

            if (newState == (1 << graphSize) - 1) {
                return minDist[newState][newLast];
            }
        }
    }

    return -1;
}