#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup() {
    
    //Gui Setup
    mGui.setup("Oscillator Settings");
    mGui.setup("a for AM, f for FM");
    mFreqSlider.setup("Frequency", 200.0f, 60.0f, 2500.0f);
    mLfoFreqSlider.setup("LFO Freq", 1.5, 1.0f, 20.0f);
    mLfoAmpSlider.setup("LFO Amplitude", 1.0f, 1.0f, 2.5f);
    
    mGui.add(&mFreqSlider);
    mGui.add(&mLfoFreqSlider);
    mGui.add(&mLfoAmpSlider);
    
    //2 output ch, 1 input ch
    ofSoundStreamSetup(2, 1, 44100, 512, 3);
    micSamples.assign(512, 0.0f);
}

//--------------------------------------------------------------
void ofApp::update() {
    ofScopedLock lockIt(audioMutex);
    
    //draw polyline
    waveform.clear();
    for (size_t i = 0; i < mModulationBuffer.getNumFrames(); i++) {
        float sample = mModulationBuffer.getSample(i, 0);
        float x = ofMap(i, 0, mModulationBuffer.getNumFrames(), 0, ofGetWidth());
        float y = ofMap(sample, -1, 1, 0, ofGetHeight());
        waveform.addVertex(x, y);
    }
    
    //if (count > 1078.0f) {
    //count = 0.0f;
    //waveform_sample.clear();
    //}
    //else
    //    count=mPhase;
    rms = mModulationBuffer.getRMSAmplitude();
}

//--------------------------------------------------------------
void ofApp::draw() {
      ofBackground(0);
    //text
    
    ofSetColor(225);
    ofDrawBitmapString("Press 2, 3, 4 for effects, 1 for override", 31, 60);
    ofDrawBitmapString("Current Effect: " + ofToString(currWaveForm), 31, 90);
    ofDrawBitmapString("Current Phase: " + ofToString(mPhase/44100), 31, 120);
    
    //Draw waveform
    
    
    
    
    //ofTranslate(0, 100);
    ofSetColor(91, 102, 255);
    waveform_sample.draw();
   
    
    
  
    ofSetColor(142, 4, 255);
    ofSetLineWidth(1 + (rms * 30.));
    waveform.draw();
    
   
    
    mGui.draw();
}

void ofApp::audioIn(ofSoundBuffer &inBuff) {
    ofScopedLock lockIt(audioMutex);
    //copy our inbuffer over to our modulation buffer
    
    mModulationBuffer = inBuff;
    
}

void ofApp::audioOut(ofSoundBuffer &outBuff) {
    ofScopedLock lockIt(audioMutex);
    
    if (currWaveForm == 1) {
        mModulationBuffer.addTo(outBuff);
    }
    
    else {
        for (int i = 0; i < mModulationBuffer.size(); i += 1) {
            if (mCurrentMod == ModulationType::FM) {
                mPhase += ofDegToRad(sin(mModPhase)*0.01f);
            }
            sample = generateSample(mPhase, currWaveForm);
            sample = modulateSample(sample, (float)mLfoFreqSlider, mModPhase, mCurrentMod);
            waveform_sample.addVertex(mPhase, (768/2) + (float)mLfoAmpSlider*20.0f*sample);
            sample *= mModulationBuffer[i];
            
            
            float phaseOffset = ((float)mFreqSlider / 44100.0f);
            float modOffset = (float)mLfoFreqSlider / 44100.0f;
            mPhase += phaseOffset;
            mModPhase += modOffset;
            
            outBuff[2*i] = sample;
            outBuff[2*i + 1] = sample;
            
            
            //prevents mPhase from getting too large and clears waveform image
            if (mPhase > 1078) {
                waveform_sample.clear();
                mPhase = 0;
            }
            
        }
    }
}

float ofApp::modulateSample(float sample, float modFreq, float modOffset, const ModulationType modType) {
    if (modType == ModulationType::AM) {
        return sample * sin(modOffset*TWO_PI);
    }
    return sample;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
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
        case 'f':
            mCurrentMod = ModulationType::FM;
            break;
        case 'a':
            mCurrentMod = ModulationType::AM;
            break;
        default:
            break;
    }
}

//switched distortion to generateSample
//--------------------------------------------------------------
float ofApp::generateSample(float phase, int waveType) {
    switch (waveType) {
        case 2://tri
            return abs(sin(phase*TWO_PI));
            ofLogNotice("tri");
            break;
        case 3://square
            return sin(phase*TWO_PI)>0 ? 1 : -1;
            ofLogNotice("square");
        case 4://sine
            return fmod(phase, TWO_PI);
            break;
        case 5://sine
            return sin(phase*TWO_PI);
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}

