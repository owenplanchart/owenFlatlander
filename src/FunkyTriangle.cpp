#include "FunkyTriangle.h"

//--------------------------------------------------------------
void FunkyTriangle::setup(){

}

//--------------------------------------------------------------
void FunkyTriangle::update(ofColor _triCol){
//    ofPushStyle();
    ofColor triCol = _triCol;
    float c = abs(sin(ofDegToRad(ofGetFrameNum())))+0.3;
    triCol*=c;
    ofSetColor(triCol);
}

//--------------------------------------------------------------
void FunkyTriangle::draw(ofPoint a, ofPoint b, ofPoint c){
    ofFill();
    ofDrawTriangle(a, b, c);
    
}




