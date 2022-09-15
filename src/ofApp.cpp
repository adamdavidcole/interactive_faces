#include <iostream>
#include "ofApp.h"

// TODO: preload all relevant images
string imagesFolder = "face_02/";

int horizontalTileCount = 6;
int verticalTileCount = 6;
int imageCount = 12;

//--------------------------------------------------------------
void ofApp::setup(){
    tiles = Tiles(verticalTileCount, horizontalTileCount, imagesFolder, imageCount);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    tiles.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    std::cout << "Key pressed: " << key << std::endl;
    int numKey = key - 48;
    if (numKey < 1 || numKey > 9) return;
    
    tiles.updateTileCount(numKey, numKey);
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
    // TODO: throttle
    tiles.rebuildTiles();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
