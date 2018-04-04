#pragma once

#include "ofMain.h"
#include "ofxGui.h"

enum class ModulationType { AM, FM };

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioIn(ofSoundBuffer &inBuff);
    void audioOut(ofSoundBuffer &outBuff);
    
    //samples
    float generateSample(float phase, int waveType);
    float modulateSample(float sample, float modFreq, float modOffset, const ModulationType modType);
    
    float sample;
    float output_sample;
    
    //gui shit
    ofxFloatSlider mFreqSlider;
    ofxFloatSlider mLfoAmpSlider;
    ofxFloatSlider mLfoFreqSlider;
    ofxPanel mGui;
    
    //Mic
    std::vector<float> micSamples;
    
    //Sound Shit
    ofSoundBuffer mModulationBuffer;
    float mModPhase = 0.0f;
    
    mutex audioMutex;
    float mPhase;
    float rms;
    
    //Visuals
    ofPolyline waveform;
    ofPolyline waveform_sample;
    int currWaveForm = 1;
    float count=0.0f;
    
    //Not sure
    ModulationType mCurrentMod = ModulationType::AM;
};

