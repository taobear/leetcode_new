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
} PlayerPosition;

typedef struct {
    int gridX;
    int gridY;
    PlayerPosition playerPos;
} BoxPlayer;

BoxPlayer g_playerBoxQue[MAX_GRID_ROW * MAX_GRID_COL * PLAYER_AT_BUTT];
int g_playerBoxQueSize = 0;

int g_playerBoxTimes[MAX_GRID_ROW][MAX_GRID_COL][PLAYER_AT_BUTT];

bool canReachTarget(char** grid, int gridSize, int* gridColSize, BoxPlayer* source, BoxPlayer* target)
{

}

bool 


int minPushBox(char** grid, int gridSize, int* gridColSize)
{
    memset(g_playerBoxTimes, -1, sizeof(g_playerBoxTimes));

    g_playerBoxQueSize = 0;
    for (PlayerPosition pos = PLAYER_AT_LEFT; pos < PLAYER_AT_BUTT; pos++) {
        
    }

    while (g_playerBoxQueSize) {
        
    }
}