#include "minPushBox.h"

#include <stdlib.h>

#define QUEUE_ADVANCE(id, size) \
    (id) = ((id) + 1 + (size)) % (size)

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
    const int playerPos[PLAYER_AT_BUTT][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

    Player rslt;
    rslt.gridX = box->gridX + playerPos[atPos][0];
    rslt.gridY = box->gridY + playerPos[atPos][1];
    return rslt;
}

bool canReachTarget(char** grid, int gridSize, int* gridColSize, const Box* box, const Player* src, const Player* dst)
{
    if (grid[dst->gridX][dst->gridY] == '#') {
        return false;
    }

    if (src->gridX == dst->gridX && src->gridY == dst->gridY) {
        return true;
    }

    int visitedMem[MAX_GRID_ROW][MAX_GRID_COL] = { 0 };

    int playerQueBeg = 0;
    int playerQueEnd = 0;
    Player playerQue[MAX_GRID_ROW * MAX_GRID_COL];

    playerQue[playerQueEnd] = *src;
    QUEUE_ADVANCE(playerQueEnd, MAX_GRID_ROW * MAX_GRID_COL);

    visitedMem[src->gridX][src->gridY] = 1;
    while (playerQueBeg != playerQueEnd) {
        Player front = playerQue[playerQueBeg];
        QUEUE_ADVANCE(playerQueBeg, MAX_GRID_ROW * MAX_GRID_COL);

        for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
            Player after = convertPlayer(&front, at);
            if (!existGrid(grid, gridSize, gridColSize, &after)) {
                continue;
            }

            if (visitedMem[after.gridX][after.gridY] != 0) {
                continue;
            }

            if (grid[after.gridX][after.gridY] == '#') {
                continue;
            }

            if (after.gridX == box->gridX && after.gridY == box->gridY) {
                continue;
            }

            if (after.gridX == dst->gridX && after.gridY == dst->gridY) {
                return true;
            }

            visitedMem[after.gridX][after.gridY] = 1;

            playerQue[playerQueEnd] = after;
            QUEUE_ADVANCE(playerQueEnd, MAX_GRID_ROW * MAX_GRID_COL);
        }
    }

    return false;
}

void pushOneStepBox(const Box* before, const PlayerAtPosInt at, Box* after)
{
    if (before == NULL || after == NULL) {
        return;
    }

    const int move[PLAYER_AT_BUTT][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    after->gridX = before->gridX + move[at][0];
    after->gridY = before->gridY + move[at][1];
}

void initGameMap(char** grid, int gridSize, int* gridColSize, Box* box, Player* start, Position* target)
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

    int boxPlayerQueBeg = 0;
    int boxPlayerQueEnd = 0;
    for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
        Player player = convertPlayer(&box, at);
        if (!existGrid(grid, gridSize, gridColSize, &player)) {
            continue;
        }

        if (!canReachTarget(grid, gridSize, gridColSize, &box, &start, &player)) {
            continue;
        }

        BoxPlayer boxPlayer = { box.gridX, box.gridY, at };
        g_boxPlayerQue[boxPlayerQueEnd] = boxPlayer;
        QUEUE_ADVANCE(boxPlayerQueEnd, MAX_GRID_ROW * MAX_GRID_COL * PLAYER_AT_BUTT);

        g_boxPlayerTimes[box.gridX][box.gridY][at] = 0;
    }

    while (boxPlayerQueBeg != boxPlayerQueEnd) {
        BoxPlayer front = g_boxPlayerQue[boxPlayerQueBeg];
        QUEUE_ADVANCE(boxPlayerQueBeg, MAX_GRID_ROW * MAX_GRID_COL * PLAYER_AT_BUTT);

        Box afterBox;
        pushOneStepBox(&front.box, front.atPos, &afterBox);
        if (!existGrid(grid, gridSize, gridColSize, &afterBox)) {
            continue;
        }

        if (grid[afterBox.gridX][afterBox.gridY] == '#') {
            continue;
        }

        if (afterBox.gridX == target.gridX && afterBox.gridY == target.gridY) {
            return g_boxPlayerTimes[front.box.gridX][front.box.gridY][front.atPos] + 1;
        }

        Player beforePlayer = convertPlayer(&afterBox, front.atPos);
        for (PlayerAtPosInt at = PLAYER_AT_LEFT; at != PLAYER_AT_BUTT; at++) {
            Player afterPlayer = convertPlayer(&afterBox, at);
            if (!existGrid(grid, gridSize, gridColSize, &afterPlayer)) {
                continue;
            }

            if (g_boxPlayerTimes[afterBox.gridX][afterBox.gridY][at] != -1) {
                continue;
            }

            if (!canReachTarget(grid, gridSize, gridColSize, &afterBox, &beforePlayer, &afterPlayer)) {
                continue;
            }

            BoxPlayer boxPlayer = { afterBox.gridX, afterBox.gridY, at };
            g_boxPlayerQue[boxPlayerQueEnd] = boxPlayer;
            QUEUE_ADVANCE(boxPlayerQueEnd, MAX_GRID_ROW * MAX_GRID_COL * PLAYER_AT_BUTT);

            g_boxPlayerTimes[afterBox.gridX][afterBox.gridY][at] = g_boxPlayerTimes[front.box.gridX][front.box.gridY][front.atPos] + 1;
        }
    }

    return -1;
}