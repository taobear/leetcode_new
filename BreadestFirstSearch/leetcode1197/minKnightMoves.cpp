#include "minKnightMoves.h"

#define MOVE_OPTIONS 8
#define GRID_EXTENCE 3
#define GRID_MINUS_EXT 2
#define GRID_MAX_ROW (300 + GRID_EXTENCE + GRID_MINUS_EXT)
#define GRID_MAX_COL (300 + GRID_EXTENCE + GRID_MINUS_EXT)
#define MAX_QUEUE_SIZE (GRID_MAX_ROW * GRID_MAX_COL)

typedef struct {
    int x;
    int y;
} Position;

int moves[MOVE_OPTIONS][2] = {{-1, 2}, {-1, -2}, {1, -2}, {1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int g_distance[GRID_MAX_ROW][GRID_MAX_COL];
Position g_queue[MAX_QUEUE_SIZE];

int minKnightMoves(int x, int y)
{
    int head = 0, tail = 0;
    
    int positiveX = x > 0 ? x : -x;
    int positiveY = y > 0 ? y : -y;

    for (int i = 0; i < positiveX + GRID_EXTENCE + GRID_MINUS_EXT; ++i) {
        for (int j = 0; j < positiveY + GRID_EXTENCE + GRID_MINUS_EXT; ++j) {
            g_distance[i][j] = -1;
        }
    }

    g_queue[tail].x = 0;
    g_queue[tail].y = 0;
    tail++;

    g_distance[GRID_MINUS_EXT][GRID_MINUS_EXT] = 0;

    while (tail != head) {
        Position front = g_queue[head ++];
        for (int i = 0; i < MOVE_OPTIONS; ++i) {
            int newX = moves[i][0] + front.x;
            int newY = moves[i][1] + front.y;

            if (newX < -GRID_MINUS_EXT || newX >= GRID_MAX_ROW) {
                continue;
            }

            if (newY < -GRID_MINUS_EXT || newY >= GRID_MAX_COL) {
                continue;
            }

            if (g_distance[newX + GRID_MINUS_EXT][newY + GRID_MINUS_EXT] != -1)
            {
                continue;
            }

            g_distance[newX + GRID_MINUS_EXT][newY + GRID_MINUS_EXT] = g_distance[front.x + GRID_MINUS_EXT][front.y + GRID_MINUS_EXT] + 1;

            if (newX == positiveX && newY == positiveY) {
                return g_distance[newX + GRID_MINUS_EXT][newY + GRID_MINUS_EXT];
            }

            g_queue[tail].x = newX;
            g_queue[tail].y = newY;
            tail++;
        }
    }

    return g_distance[positiveX + GRID_MINUS_EXT][positiveY + GRID_MINUS_EXT];
}