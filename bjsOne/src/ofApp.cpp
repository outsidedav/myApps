#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    std::string url = "http://www.bjs.gov:8080/bjs/ncvs/v2/personal/2016?format=json";

    // Now parse the JSON
    bool parsingSuccessful = json.open(url);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    
    for (int i = 0; i < ofGetWindowHeight(); i+=50){
        
        std::string age = json["personalData"][i]["ager"].asString();
        int nAge = std::stoi(age);
        
        std::string weight   = json["personalData"][i]["weight"].asString();
        int nWeight = std::stoi(weight);
        
        for(int j =0; j <ofGetWindowWidth(); j+=15){
    
            ofSetColor(nWeight/20);
            ofDrawRectangle(j, i, 10, nAge);
        }
    }
    
//    test rect
    
    
    
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
