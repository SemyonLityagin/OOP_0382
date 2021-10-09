#ifndef GAME_FLOORBUILDERTREE_H
#define GAME_FLOORBUILDERTREE_H
/*
#define NORMAL_TEXTURE_PATH "../Game_Obj/Tiles/tile_0019.png"
#define ENTRY_TEXTURE_PATH "../Game_Obj/Tiles/tile_0048.png"
#define EXIT_TEXTURE_PATH "../Game_Obj/Tiles/tile_0083.png"
#define WALL_TEXTURE_PATH "../Game_Obj/Tiles/tile_0013.png"
*/
#define NORMAL_TEXTURE_PATH "../Game_Obj/Normal.jpg"
#define ENTRY_TEXTURE_PATH "../Game_Obj/Entry.jpg"
#define EXIT_TEXTURE_PATH "../Game_Obj/Exit.jpg"
#define WALL_TEXTURE_PATH "../Game_Obj/Wall.jpg"

#include "FloorBuilder.h"
#include <cstdlib>

class FloorBuilderTree : public FloorBuilder{
private:
    Floor* floor;

public:
    FloorBuilderTree();
    ~FloorBuilderTree();

    void GeneratNormalCells() override;
    void GeneratWallCells() override;
    void GeneratWallDungeonCells(int x1, int y1, int x2, int y2, int** mass);
    void GeneratEntryCell() override;
    void GeneratExitCell() override;

    void Reset();
    Floor* getFloor();
};


#endif //GAME_FLOORBUILDERTREE_H
