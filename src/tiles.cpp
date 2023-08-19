//
//  tiles.cpp
//  interactive_faces
//
//  Created by Adam Cole on 9/15/22.
//

#include <algorithm>
#include <random>
#include "tiles.hpp"



Tiles::Tiles() {}

Tiles::Tiles(int _verticalTileCount, int _horizontalTileCount, vector<string> _imageFolders, int _imageCount, vector<string> _imageFileNames) {
    verticalTileCount = _verticalTileCount;
    horizontalTileCount = _horizontalTileCount;
    imageFolders = _imageFolders;
    imageCount = _imageCount;
    imageFileNames = _imageFileNames;
    
    rebuildTiles();
    
}

void Tiles::rebuildTiles() {
    tiles = vector<Tile>();
    
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(imageFolders), std::end(imageFolders), rng);

    int tileWidth = ofGetWidth() / (float) horizontalTileCount;
    int tileHeight = ofGetHeight() / (float) verticalTileCount;
    
    cout << "First image folder: " << imageFolders[0] << endl;
    
    for (int i = 0; i < horizontalTileCount; i++) {
        for (int j = 0; j < verticalTileCount; j++) {
            int tileX = i * tileWidth;
            int tileY = j * tileHeight;
            
            int imageFolderIndex = ((horizontalTileCount * i) + j) % imageFolders.size();
            
            Tile tile(tileWidth, tileHeight, tileX, tileY, imageFolders[imageFolderIndex], imageCount, imageFileNames);
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

void Tiles::toggleVideoPlay() {
    cout << "Tiles::toggleVideoPlay" << endl;
    for (Tile tile : tiles) {
        if (tile.videoPlayer.isPlaying()) {
            tile.shouldShowVideo = 0;
            tile.videoPlayer.stop();
        } else {
            tile.shouldShowVideo = 1;
            tile.videoPlayer.play();
        }

    }
}
