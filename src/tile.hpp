//
//  tile.hpp
//  interactive_faces
//
//  Created by Adam Cole on 9/15/22.
//

#ifndef tile_hpp
#define tile_hpp

#include <stdio.h>
#include "ofMain.h"


class Tile {

public:
    Tile(int width, int height, int x, int y, string imageFolder, int imageFolderCount);
    void draw(ofVec2f mousePos);

private:
    int width;
    int height;
    int x;
    int y;
    
    int tileCenterX;
    int tileCenterY;
    ofVec2f tileCenter;
    
    string imageFolder;
    int imageFolderCount;
    
    int lastPhotoNum;
    
    vector<ofImage> images;
    
    int getImageNumFromMousePos(ofVec2f mousePos);
};


#endif /* tile_hpp */
