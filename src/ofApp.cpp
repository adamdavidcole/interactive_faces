#include <iostream>
#include "ofApp.h"
#include <algorithm>
#include <random>


// TODO: preload all relevant images
vector<string> imageFolders{ "face_03/", "face_04/", "face_05/", "face_06/", "face_07/", "face_08/", "face_09/", "face_10/", "face_11/", "face_12/", "face_13/", "face_14/", "face_15/", "face_16/", "face_17/", "face_18/",  "face_20/", "face_21/", "face_22/", "face_23/", "face_24/", "face_25/", "face_26/", "face_27/", "face_28/", "face_29/", "face_30/", "face_31/", "face_32/", "face_33/", "face_34/", "face_35/"  };

int horizontalTileCount = 6;
int verticalTileCount = 6;
int imageCount = 12;

//vector<string> imageFileNames{"025.jpg", "156.jpg", "146.jpg", "129.jpg", "120.jpg", "117.jpg", "100.jpg", "096.jpg", "081.jpg", "066.jpg", "055.jpg", "046.jpg", "001.jpg"};
vector<string> imageFileNames{"025.png", "156.png", "146.png", "129.png", "120.png", "117.png", "100.png", "096.png", "081.png", "066.png", "055.png", "046.png", "001.png"};

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(30);
    
    tiles = Tiles(verticalTileCount, horizontalTileCount, imageFolders, imageCount, imageFileNames);
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
    if (numKey >= 1 && numKey <= 9) {
        cout << "UPDATE TILE COUNT" << endl;
        tiles.updateTileCount(numKey, numKey);
    }
//
    if (numKey == 70) {
        cout << "TOGGLE VIDEO PLAY" << endl;
        tiles.toggleVideoPlay();
    }
    
    
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
