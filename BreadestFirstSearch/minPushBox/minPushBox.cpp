#include "minPushBox.h"

#include <stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define MAX_GRID_ROW 20
#define MAX_GRID_COL 20

BOOL box_visited[MAX_GRID_ROW][MAX_GRID_COL];
BOOL player_visited[MAX_GRID_ROW][MAX_GRID_COL];

int pushBoxTimes[MAX_GRID_ROW][MAX_GRID_COL];

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef struct {
    int vtx_x;
    int vtx_y;
} Vertex;

void Queue_init();
Vertex Queue_popFront();
void Queue_push(Vertex vtx);

BOOL getGridInitState(char **grid, int gridSize, int *gridColSize, Vertex *start, Vertex *target, Vertex *box)
{
    if (start == NULL || target == NULL || box == NULL) {
        return FALSE;
    }

    if (gridSize > MAX_GRID_ROW) {
        return FALSE;
    }

    int start_num = 0, target_num = 0, box_num = 0;
    for (int i = 0; i < gridSize; ++i) {
        if (gridColSize[i] > MAX_GRID_COL) {
            return FALSE;
        }

        for (int j = 0; j < gridColSize[i]; ++j) {
            switch (grid[i][j]) {
                case 'S':
                    start->vtx_x = i;
                    start->vtx_y = j;
                    start_num ++;
                    break;
                case 'B':
                    box->vtx_x = i;
                    box->vtx_y = j;
                    box_num ++;
                    break;
                case 'T':
                    target->vtx_x = i;
                    target->vtx_y = j;
                    target_num ++;
                    break;
                default:
                    break;
            }
        }
    }

    return (start_num == 1 && target_num == 1 && box_num == 1) ? TRUE : FALSE;
}

BOOL isVertexAccessible(char **grid, int gridSize, int *gridColSize, Vertex *vertex)
{
    if (grid == NULL || vertex == NULL) {
        return FALSE;
    }

    int vtx_x = vertex->vtx_x;
    int vtx_y = vertex->vtx_y;

    if (vtx_x < 0 || vtx_x >= gridSize) {
        return FALSE;
    }

    if (gridColSize[vtx_y] == NULL) {
        return FALSE;
    }

    if (vtx_y < 0 || vtx_y >= gridColSize[vtx_x]) {
        return FALSE;
    }

    if (grid[vtx_x][vtx_y] == '.' || grid[vtx_x][vtx_y] == 'S' || grid[vtx_x][vtx_y] == 'T') {
        return TRUE;
    }

    return FALSE;
}

BOOL playerHasPathToDest(char **grid, int gridSize, int *gridColSize, Vertex *curr, Vertex *dest)
{
    if (curr == NULL || dest == NULL) {
        return FALSE;
    }

    if (curr->vtx_x == dest->vtx_x && curr->vtx_y == dest->vtx_y) {
        return TRUE;
    }

    for (int i = 0; i < 4; ++i) {
        Vertex next{curr->vtx_x + directions[i][0], curr->vtx_y + directions[i][1]};
        if (isVertexAccessible(grid, gridSize, gridColSize, &next) != TRUE) {
            continue;
        }

        if (player_visited[next.vtx_x][next.vtx_y] == TRUE) {
            continue;
        }
        
        if (playerHasPathToDest(grid, gridSize, gridColSize, &next, dest) == TRUE) {
            return TRUE;
        }

        player_visited[next.vtx_x][next.vtx_y] = TRUE;
    }

    return FALSE;
}

BOOL canPushBox(Vertex *box, Vertex *player)
{
     
}

/**
 * 游戏地图用大小为 n * m 的网格 grid 表示，其中每个元素可以是墙、地板或者是箱子。
 * 现在你将作为玩家参与游戏，按规则将箱子 'B' 移动到目标位置 'T' ：

 * 玩家用字符 'S' 表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。
 * 地板用字符 '.' 表示，意味着可以自由行走。
 * 墙用字符 '#' 表示，意味着障碍物，不能通行。 
 * 箱子仅有一个，用字符 'B' 表示。相应地，网格上有一个目标位置 'T'。
 * 玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。
 * 玩家无法越过箱子。
 * 返回将箱子推到目标位置的最小 推动 次数，如果无法做到，请返回 -1。
 */
int minPushBox(char **grid, int gridSize, int *gridColSize)
{
    Vertex start, target, box;
    if (getGridInitState(grid, gridSize, gridColSize, &start, &target, &box) != TRUE) {
        return -1;
    }

    Queue_init();
    Queue_push(box);
    while (Queue_size()) {
        Vertex front = Queue_popFront();
        for (int i = 0; i < 4; ++i) {
            Vertex next{front.vtx_x + directions[i][0], front.vtx_y + directions[i][1]};
            if (isVertexAccessible(grid, gridSize, gridColSize, &next) != TRUE) {
                continue;
            }

            if (box_visited)
        }
    }

}

#define MAX_QUEUE_SIZE (MAX_GRID_ROW * MAX_GRID_COL)
typedef struct {
    Vertex queue[MAX_QUEUE_SIZE];
    int begin;
    int end;
} VetexQueue;

VetexQueue g_myQueue;

void Queue_init()
{
    g_myQueue.begin = 0;
    g_myQueue.end = 0;
}

int Queue_size()
{
    return (g_myQueue.end + MAX_QUEUE_SIZE - g_myQueue.begin) % MAX_QUEUE_SIZE;
}

Vertex Queue_popFront()
{
    int frontIndex = g_myQueue.begin;
    g_myQueue.begin = (frontIndex + 1) % MAX_QUEUE_SIZE;
    return g_myQueue.queue[frontIndex];
}

void Queue_push(Vertex vtx)
{
    int tailIndex = g_myQueue.end;
    g_myQueue.queue[tailIndex] = vtx;
    g_myQueue.end = (tailIndex + 1) % MAX_QUEUE_SIZE;
}