//
//  tile.cpp
//  interactive_faces
//
//  Created by Adam Cole on 9/15/22.
//

#include "tile.hpp"

ofVec2f UP_VECTOR(0, -1);

Tile::Tile(int _width, int _height, int _x, int _y, string _imageFolder, int _imageFolderCount) {
    width = _width;
    height = _height;
    x = _x;
    y = _y;
    imageFolder = _imageFolder;
    imageFolderCount = _imageFolderCount;
    
    tileCenterX = x + width / 2;
    tileCenterY = y + height / 2;
    tileCenter = ofVec2f(tileCenterX, tileCenterY);
    
    for (int i = 0; i < imageFolderCount; i++) {
        string imageFilename = "";
        if (i < 10) {
            imageFilename = "00" + ofToString(i) + ".png";
        } else {
            imageFilename = "0" + ofToString(i) + ".png";
        }
        
        ofImage img;
        img.load(imageFolder + imageFilename);
        images.push_back(img);
    }
    
    ofImage img;
    img.load(imageFolder + "center.png");
    images.push_back(img);
    
    lastPhotoNum = -1;
}

void Tile::draw(ofVec2f mousePos) {
//    string img_path = imageFolder + "000.png";
//    std::cout << "Image path: " << img_path << std::endl;
//    int imageNum = floor(ofRandom(0, imageFolderCount));
    int imageNum = getImageNumFromMousePos(mousePos);
    ofImage img = images[imageNum];

//    string imageFilename = "";
//    if (imageNum < 10) {
//        imageFilename = "00" + ofToString(imageNum) + ".png";
//    } else {
//        imageFilename = "0" + ofToString(imageNum) + ".png";
//    }
//
    
//    img.load(imageFolder + imageFilename);
    if (imageNum != lastPhotoNum) {
        img.draw(x, y, width, height);
    }
}

int Tile::getImageNumFromMousePos(ofVec2f mousePos) {
    ofVec2f direction = mousePos - tileCenter;
    
    float angleIncrement = 360 / imageFolderCount;
    float angle = direction.angle(UP_VECTOR);
    
    float distance = direction.lengthSquared();
    if (distance < pow(width / 2, 2)) {
        return imageFolderCount; // center is last i
    }
    
    if (angle < 0) {
        angle = abs(angle);
    } else {
        angle = 360 - angle;
    }
    
    int imageNum = floor(angle / angleIncrement);
    return imageNum;
}