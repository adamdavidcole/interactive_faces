//
//  tiles.cpp
//  interactive_faces
//
//  Created by Adam Cole on 9/15/22.
//

#include "tiles.hpp"

Tiles::Tiles() {}

Tiles::Tiles(int _verticalTileCount, int _horizontalTileCount, string _imagesFolder, int _imageCount) {
    verticalTileCount = _verticalTileCount;
    horizontalTileCount = _horizontalTileCount;
    imagesFolder = _imagesFolder;
    imageCount = _imageCount;
    
    rebuildTiles();
    
}

void Tiles::rebuildTiles() {
    tiles = vector<Tile>();

    int tileWidth = ofGetWidth() / (float) horizontalTileCount;
    int tileHeight = ofGetHeight() / (float) verticalTileCount;
    
    for (int i = 0; i < horizontalTileCount; i++) {
        for (int j = 0; j < verticalTileCount; j++) {
            int tileX = i * tileWidth;
            int tileY = j * tileHeight;
            Tile tile(tileWidth, tileHeight, tileX, tileY, imagesFolder, imageCount);
//            tiles.push(tile);
            tiles.push_back(tile);
        }
    }
    
    std::cout << "Total tiles: " << tiles.size() << std::endl;
}

void Tiles::updateTileCount(int _verticalTileCount, int _horizontalTileCount) {
    verticalTileCount = _verticalTileCount;
    horizontalTileCount = _horizontalTileCount;
    rebuildTiles();
}

void Tiles::draw() {
    ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
    for (Tile tile : tiles) {
        tile.draw(mousePos);
    }
}
