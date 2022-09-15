#include <iostream>
#include "ofApp.h"

string faceImagesFolder = "face_01/";

ofImage testImage;

int horizontalTileCount = 5;
int verticalTileCount = 5;
int imageFolderCount = 12;

vector<Tile> tiles;

//--------------------------------------------------------------
void ofApp::setup(){
    testImage.load("face_01/000.png"); // first load image, assuming it's in bin/data folder
    
    int tileWidth = ofGetWidth() / (float) horizontalTileCount;
    int tileHeight = ofGetHeight() / (float) verticalTileCount;
    
    for (int i = 0; i < horizontalTileCount; i++) {
        for (int j = 0; j < verticalTileCount; j++) {
            int tileX = i * tileWidth;
            int tileY = j * tileHeight;
            Tile tile(tileWidth, tileHeight, tileX, tileY, faceImagesFolder, imageFolderCount);
//            tiles.push(tile);
            tiles.push_back(tile);
        }
    }
    
    std::cout << "Total tiles: " << tiles.size() << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
    for (Tile tile : tiles) {
        tile.draw(mousePos);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
