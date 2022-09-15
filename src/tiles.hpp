//
//  tiles.hpp
//  interactive_faces
//
//  Created by Adam Cole on 9/15/22.
//

#ifndef tiles_hpp
#define tiles_hpp

#include <stdio.h>
#include "tile.hpp"

class Tiles {
public:
    Tiles();
    Tiles(int verticalTileCount, int horizontalTileCount, string imagesFolder, int imageCount);
    void rebuildTiles();
    void updateTileCount(int verticalTileCount, int horizontalTileCount);
    void draw();
    
//    
private:
    int horizontalTileCount;
    int verticalTileCount;
    int imageCount;
    string imagesFolder;

    vector<Tile> tiles;

};

#endif /* tiles_hpp */
