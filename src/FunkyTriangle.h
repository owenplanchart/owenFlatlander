#pragma once

#include "ofMain.h"
#include "ofxDelaunay.h"

class FunkyTriangle : public ofBaseApp{
  public:
    void setup();
    void update(ofColor TriCol);
    void draw(ofPoint _a, ofPoint _b, ofPoint _c);

    ofPoint a;
    ofPoint b;
    ofPoint c;
    
//    ofColor triCol;
};
