#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mGui.setup();
   
    //add Freq Slider to Gui
    mFreqSlider.setup("osc freq", 250.0f, 60.0f, 40000.0f);
    mGui.add(&mFreqSlider);
    
    
      //add Amp Slider to Gui
    mAmpSlider.setup("osc amplitude", 0.2f, 0.0f,0.89);
    mGui.add(&mAmpSlider);
    
    //add Attack to Gui
    mAttack.setup("envelope A");
    mGui.add(&mAttack);
    
    //add Attack to Gui
    mAttack.setup("envelope A");
    mGui.add(&mAttack);
    
    
    
    ofSoundStreamSetup(2, 0,mSampleRate, 512, 3);
    
    mAttack.addListener(this, &ofApp::onButtonPressed);
}

//--------------------------------------------------------------
void ofApp::update(){

    if(bAttack && mAmpSlider < 0.8f){
    mAmpSlider =  ofLerp(mAmpSlider,0.89f, 0.2f);
    }
    else if(!bAttack && mAmpSlider > 0.01f){
        
        mAmpSlider = ofLerp(mAmpSlider,0, 0.02f);
    }
    else{
        bAttack = false;
    }
}

void ofApp::onButtonPressed(){
    ofLogNotice() << "Button Pressed" << endl;
    bAttack = true;
    mAmpSlider = 0.0f;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    mGui.draw();
}

void ofApp::audioOut(ofSoundBuffer &output){

    for(int i=0; i <output.size(); i+=2){
        //angle = frequency / sample rate
        float offset = (float)mFreqSlider / (float)mSampleRate;
        
        output[i] = sin(mPhase) * (float)mAmpSlider;//left channel
        output[i+1] = sin(mPhase) * (float)mAmpSlider;//right channel
        mPhase += offset;
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
