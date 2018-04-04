#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    colorTo = ofColor::aquamarine;
    colorFrom = ofColor::indianRed;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float clamped = ofClamp(ofGetElapsedTimef()*0.001f,0,1.0f);
    
    ofColor lerped = colorFrom.lerp(colorTo, clamped);
    
    if(bExport){
        ofBeginSaveScreenAsPDF("my-pdf-" + ofToString(ofGetElapsedTimef()) + ".pdf", true);
        bExport = false;
    }
    ofBackground(lerped);
    if(bStopExport){
        ofEndSaveScreenAsPDF();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        if(!bExport){
            bStopExport = true;
            bExport = false;
        } else {
            bExport = true;
            bStopExport = false;
        }
        
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
