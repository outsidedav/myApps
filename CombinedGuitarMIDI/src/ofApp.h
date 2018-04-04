#pragma once

#include "ofMain.h"
#include "ofxATK.hpp"
#include "ofxMidi.h"
#include "ofXGui.h"

enum class ModulationType { AM, FM };

class ofApp : public ofBaseApp, public ofxMidiListener{
    
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
    
    //Shuai
    ofxMidiIn midiIn;
    WTSine* modulator;
    Reverb* reverb;
    
    ofxFloatSlider absorptionFreq;
    ofxFloatSlider absorption;
    ofxFloatSlider dryWet;
    ofxFloatSlider preDelay;
    
    WTTriangle triangle;
    WTSawtooth sawtooth;
    WTSquare square;
    CTEnvelope envelope;
    int mostRecentNote;
    
    
    SoundFile* soundFile;
    SoundPlayer* player;
    Recorder* recorder;
    SoundFile* soundFile2;
    SoundPlayer* player2;
    
    float playbackSpeed;
    
    int wave;
    bool isPlaying;
    
    
    
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


