#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //setup GUI
    mGui.setup("settings");
    mHeightSlider.setup("height", 2.0f, 1, 10);
    mWidthSlider.setup("Width", 50.0f, 10, 100);
    mPadSlider.setup("negative space", 0.0f, 0, 100);
    
    mGui.add(&mHeightSlider);
    mGui.add(&mWidthSlider);
    mGui.add(&mPadSlider);

    
    //api call to pull in JSON
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
    
    
    //add json data to vector
    for(int i = 0; i < json["personalData"].size(); i++){
        
        //pull in age as string and convert to int
        std::string age   = json["personalData"][i]["ager"].asString();
        int nAge = std::stoi(age);
        
        // add that int to the age vector "vAge"
        vAge.push_back(nAge);
        
        //do the same for weight
        std::string weight   = json["personalData"][i]["weight"].asString();
        float nWeight = std::stof(weight);
        
        //convert to a number between 10 & 255, by clamping
        //"threshold" will control how light and dark the lines are.
        
        float clampednWeight = ofClamp(nWeight/threshold, 10, 230);
    
        //add the clammeped nuber to the Vector for Weight
        vWeight.push_back(clampednWeight);
        
//        ofLogNotice("Weight int ") << ofToString(nWeight);
        
    };
    
    //call variable for accessing vectors
    int k = 0;
    
    // draw squares
    for (int i = 0; i < ofGetWindowWidth(); i+=mWidthSlider){
        
        for(int j = 0; j <ofGetWindowHeight(); j+=50){
    
            k++;
            
            ofFill();
            //minus 20 just to double make sure it doesn't go over 255.
            ofSetColor(vWeight[k]-20);
            ofDrawRectangle(i, j, 50-mPadSlider, vAge[k]*mHeightSlider);
        }
    }
    
    //add Gui control
   mGui.draw();
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
