#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //2 output ch, 1 input ch
    ofSoundStreamSetup(2, 1, 44100, 512, 3);
    micSamples.assign(512, 0.0f);
    
    //setup GUI
    mGui.setup("settings");
    mFreqSlider.setup("frequency", 200.0f, 60.0f, 2500.0f);
    mVolumeSlider.setup("volume(amplitude)", 0.0f,0.0f,0.5f);
    
    
    mGui.add(&mFreqSlider);
    mGui.add(&mVolumeSlider);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofScopedLock lockIt(audioMutex);
    
    //draw polyline
    waveform.clear();
    for(size_t i = 0; i < mInBuffer.getNumFrames(); i++) {
        float sample = mInBuffer.getSample(i, 0);
        float x = ofMap(i, 0, mInBuffer.getNumFrames(), 0, ofGetWidth());
        float y = ofMap(sample, -1, 1, 0, ofGetHeight());
        waveform.addVertex(x, y);
    }
    
    rms = mInBuffer.getRMSAmplitude();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    //text
    
    ofSetColor(225);
    ofDrawBitmapString("Press 2, 3, 4 for effects, 1 for override", 31, 60);
    ofDrawBitmapString("Current Effect: " + ofToString(currWaveForm), 31, 90);
    ofDrawBitmapString("Current Phase: " + ofToString(mPhase), 31, 120);
    
    //sliders
    mGui.draw();
    
    //Draw waveform
    
    ofSetColor(255);
    ofSetLineWidth(3 + (rms * 20));
    waveform.draw();
    
}

void ofApp::audioIn(ofSoundBuffer &inBuff){
    ofScopedLock lockIt(audioMutex);
    //copy our inbuffer over to our mInBuffer
    mInBuffer = inBuff;
    
}

void ofApp::audioOut(ofSoundBuffer &outBuff){
    ofScopedLock lockIt(audioMutex);
    
    
    
    //Where the magic happens
    if(currWaveForm > 1){
        for(int i=0; i < mInBuffer.size(); i+=2){
            
            
            float sample = distortion(mPhase, currWaveForm);
            sample *= mInBuffer[i];
            sample *= (float)mVolumeSlider;
            
            //output
            outBuff[i]= sample;
            outBuff[i+1]= sample;
            
            //Phase Offset important!
            float phaseOffset = ((float)mFreqSlider / 44100);
            mPhase += phaseOffset;
            
            
            }
        }
    
    else{
        //override
        mInBuffer.copyTo(outBuff);
//        for(int i=0; i < outBuff.size(); i+=2){
//            outBuff[i] = mInBuffer[i];
//            outBuff[i+1]= mInBuffer[i+1];
//        }
    }
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            currWaveForm = 1;
            break;
        case '2':
            currWaveForm = 2;
            
            break;
        case '3':
            currWaveForm = 3;
            
            break;
            
        case '4':
            currWaveForm = 4;
            
            break;
            
        case '5':
            currWaveForm = 5;
            
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
float ofApp::distortion(float phase, int waveType){
    switch (waveType) {
        case 1://overived
            
            break;
        case 2://square
            return sin(phase*TWO_PI)>0?1:-1;
            break;
        case 3://sawtooth
            return fmod(phase,TWO_PI);
            break;
        case 4://triangle
            return abs(sin(phase*TWO_PI));
            break;
        case 5://sine
            return sin(phase*TWO_PI);
            break;
        default:
            break;
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

