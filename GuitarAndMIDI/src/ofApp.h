#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
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
    float distortion(float phase, int waveType);
    std::vector<float> micSamples;
    ofSoundBuffer mInBuffer;
    mutex audioMutex;
    float mPhase;
    float rms;
    ofPolyline waveform;
    int currWaveForm = 1;
    
    
    ofxFloatSlider mFreqSlider;
    ofxFloatSlider mVolumeSlider;
    ofxPanel mGui;
    
};

