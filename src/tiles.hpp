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
    Tiles(int verticalTileCount, int horizontalTileCount, vector<string> imageFolders, int imageCount, vector<string> imageFileNames);
    void rebuildTiles();
    void updateTileCount(int verticalTileCount, int horizontalTileCount);
    void draw();
    
//    
private:
    int horizontalTileCount;
    int verticalTileCount;
    int imageCount;
    vector<string> imageFolders;
    vector<string> imageFileNames;

    vector<Tile> tiles;

};

#endif /* tiles_hpp */
