#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(54, 54, 54);
    
    soundStream.printDeviceList();
    
    //soundStream.setDeviceID(0);
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    ofSoundStreamSetup(2, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(225);
    ofDrawBitmapString("Guitar Distortion", 32, 32);
    
    ofNoFill();
    
    // draw left
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(32, 170, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("left channel for testing", 4, 18);
    
    ofSetLineWidth(1);
    ofDrawRectangle(0, 0, 760, 200);
    
    ofSetColor(92, 107, 251);//blue
    ofSetLineWidth(3);
    
    ofBeginShape();
    for (unsigned int i = 0; i < left.size(); i++){
        ofVertex(i*3, 100 -left[i]*160.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    

    for (int i = 0; i < bufferSize; i++){
        left[i]   = input[i];
        right[i]  = input[i];
    }

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
// I know that I need to make the "output = left and right" here, but I just don't understand how to do that, all of the examples are using a synthisized wave, how do you use the imput that is already there?
    
//    for (int i = 0; i < bufferSize; i++){
//        left[i]   = output[i];
//        right[i]  = output[i];
//    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
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


