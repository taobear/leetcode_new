#include "minPushBox.h"

#include <stdlib.h>

#define MAX_GRID_ROW 20
#define MAX_GRID_COL 20

typedef enum {
    PLAYER_AT_LEFT = 0,
    PLAYER_AT_RIGHT,
    PLAYER_AT_UP,
    PLAYER_AT_BOTTOM,
    PLAYER_AT_BUTT
} PlayerAtPos;

typedef unsigned int PlayerAtPosInt;

typedef struct {
    int gridX;
    int gridY;
} Position, Box, Player;

typedef struct {
    Box box;
    PlayerAtPosInt atPos;
} BoxPlayer;

bool existGrid(char** grid, int gridSize, int* gridColSize, const Position* pos)
{
    if (pos == NULL) {
        return false;
    }

    if (pos->gridX < 0 || pos->gridX >= gridSize) {
        return false;
    }

    if (pos->gridY < 0 || pos->gridY >= gridColSize[pos->gridX]) {
        return false;
    }

    return true;
}

Player convertPlayer(const Box* box, const PlayerAtPosInt atPos)
{
    const int playerPos[PLAYER_AT_BUTT][2] = {{ 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }};

    Player rslt;
    rslt.gridX = box->gridX + playerPos[atPos][0];
    rslt.gridY = box->gridY + playerPos[atPos][1];
    return rslt;
}

bool canReachTarget(char** grid, int gridSize, int* gridColSize, const Box* box, const Player* src, const Player* dst)
{
    int visitedMem[MAX_GRID_ROW][MAX_GRID_COL] = {0};
    Player playerQue[MAX_GRID_ROW * MAX_GRID_COL];
    int playerQueBeg = 0;
    int playerQueEnd = 0;

    playerQue[playerQueEnd++] = *src;
    visitedMem[src->gridX][src->gridY] = 1;
    while (playerQueBeg != playerQueEnd) {
        Player front = playerQue[playerQueBeg++];
        if (grid[front.gridX][front.gridY] == '#') {
            continue;
        }

        if (front.gridX == box->gridX && front.gridY == box->gridY) {
            continue;
        }

        if (front.gridX == dst->gridX && front.gridY == dst->gridY) {
            break;
        }

        for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
            Player after = convertPlayer(&front, at);
            if (!existGrid(grid, gridSize, gridColSize, &after)) {
                continue;
            }

            if (visitedMem[after.gridX][after.gridY] != 0) {
                continue;
            }

            visitedMem[after.gridX][after.gridY] = 1;
        }
    }

    return visitedMem[dst->gridX][dst->gridY];
}

void pushOneStepBox(const BoxPlayer *before, BoxPlayer *after)
{
    if (before == NULL || after == NULL) {
        return;
    }

    const int move[PLAYER_AT_BUTT][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    after->box.gridX = before->box.gridX + move[before->atPos][0];
    after->box.gridY = before->box.gridY + move[before->atPos][1];
    after->atPos = before->atPos;
}

void initGameMap(char** grid, int gridSize, int* gridColSize, Box *box, Player *start, Position *target)
{
    if (box == NULL || start == NULL || target == NULL) {
        return;
    }

    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            if (grid[row][col] == 'S') {
                start->gridX = row;
                start->gridY = col;
            } else if (grid[row][col] == 'T') {
                target->gridX = row;
                target->gridY = col;
            } else if (grid[row][col] == 'B') {
                box->gridX = row;
                box->gridY = col;
            }
        }
    }
}

BoxPlayer g_boxPlayerQue[MAX_GRID_ROW * MAX_GRID_COL * PLAYER_AT_BUTT];
int g_boxPlayerQueBeg = 0;
int g_boxPlayerQueEnd = 0;

int g_boxPlayerTimes[MAX_GRID_ROW][MAX_GRID_COL][PLAYER_AT_BUTT];

void initBoxPlayer(char** grid, int gridSize, int* gridColSize)
{
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
                g_boxPlayerTimes[row][col][at] = -1;
            }
        }
    }
}

int minPushBox(char** grid, int gridSize, int* gridColSize)
{
    Box box;
    Player start;
    Position target;

    initGameMap(grid, gridSize, gridColSize, &box, &start, &target);
    initBoxPlayer(grid, gridSize, gridColSize);

    g_boxPlayerQueBeg = 0;
    g_boxPlayerQueEnd = 0;
    for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
        Player player = convertPlayer(&box, at);
        if (!existGrid(grid, gridSize, gridColSize, &player)) {
            continue;
        }

        BoxPlayer boxPlayer = {box.gridX, box.gridY, at};
        g_boxPlayerQue[g_boxPlayerQueEnd++] = boxPlayer;
        g_boxPlayerTimes[box.gridX][box.gridY][at] = 0;
    }

    while (g_boxPlayerQueBeg != g_boxPlayerQueEnd) {
        BoxPlayer front = g_boxPlayerQue[g_boxPlayerQueBeg++];
        BoxPlayer after;

        pushOneStepBox(&front, &after);
        if (!existGrid(grid, gridSize, gridColSize, &after.box)) {
            continue;
        }

        if (after.box.gridX == target.gridX && after.box.gridY == target.gridY) {
            break;
        }

        for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
            if (at == after.atPos) {
                continue;
            }

            Player player = convertPlayer(&after.box, at);
            if (!existGrid(grid, gridSize, gridColSize, &player)) {
                continue;
            }

            if (g_boxPlayerTimes[after.box.gridX][after.box.gridY][at] != -1) {
                continue;
            }

            BoxPlayer boxPlayer = { after.box.gridX, after.box.gridY, at };
            g_boxPlayerQue[g_boxPlayerQueEnd++] = boxPlayer;
            g_boxPlayerTimes[after.box.gridX][after.box.gridY][at] = g_boxPlayerTimes[front.box.gridX][front.box.gridY][at] + 1;
        }
    }

    for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
        if (g_boxPlayerTimes[target.gridX][target.gridY][at] != -1) {
            return g_boxPlayerTimes[target.gridX][target.gridY][at];
        }
    }
    return -1;
}