#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(125);
    ofSetFrameRate(60);
    ofSetLineWidth(3);
    numOfPoints = 9;
    
    for (int i=0; i<numOfPoints; i++){
        triangulation.addPoint(glm::vec2(ofRandomWidth(), ofRandomHeight())); // add random points in the triangulation object of ofxDelaunay
////        FunkyTriangle ft;
//        fts.push_back(ft);
    }
    triangulation.triangulate(); // calculate the triangulation!
    
    wireFrame = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
//for (int i=0; i<fts.size(); i++)
//    fts[i].update();
}

//--------------------------------------------------------------
void ofApp::draw(){


    ofFill();

    // what's important for us is to loop over the triangles and extract them. In this case
    // There's a helper function getTriangle(int i) which when you loop over all triangles
    // extracts the 3 points making each one and stores them in a vector called pts.
    // In this example pts is used to draw a triangle.
    // You should use the data of the points to create a FunkyTriangle
    // object using your custom FunkyTriangle class. Create a
    // setup() function in the class to pass it the initial parameters. You'll also need a draw()
    // and later on an update(). Start by making 1 FunkyTriangle Object that has some behavior (it
    // goes from black to white and then back to white. Then create a vector of FunkyTriangles.
    // For the more daring, create a FunkyTriangleSystem so that you hide the vector and these loops
    // that might get a bit too complex after a while. See the code provided in class. It's very
    // similar to that, only you don't draw balls, you draw triangles.

    for (int g=0; g<triangulation.getNumTriangles(); g++){ // loop over the triangles
        vector <glm::vec2> pts = getTriangle(g); // extract the vector with 3 points

        float factor = ofMap(g, 0, triangulation.getNumTriangles(), 0, 255);

//        ofColor triangleColour = ofColor::fromHsb(155, 155, 200);
        ofColor triangleColour;
        triangleColour.r = factor;
        triangleColour.g = 0;
        fts[g].update(triangleColour);
        fts[g].draw(pts[0], pts[1], pts[2]);// use this point to draw a triangle
    
    }
    //draw the wireframe for debugging purposes
    if (wireFrame){
        ofNoFill();
        ofSetColor(0);
        triangulation.triangleMesh.drawWireframe();
    }
    

}

//--------------------------------------------------------------
// custom function that takes an index and returns the coordinates of the triangle we refer to
vector <glm::vec2> ofApp::getTriangle(int i){
    int pA = triangulation.triangleMesh.getIndex(i*3);
    int pB = triangulation.triangleMesh.getIndex(i*3+1);
    int pC = triangulation.triangleMesh.getIndex(i*3+2);

    glm::vec2 pointA = triangulation.triangleMesh.getVertex(pA);
    glm::vec2 pointB = triangulation.triangleMesh.getVertex(pB);
    glm::vec2 pointC = triangulation.triangleMesh.getVertex(pC);

    vector <glm::vec2> points;
    points.push_back(pointA);
    points.push_back(pointB);
    points.push_back(pointC);
    return points;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 't') {
        triangulation.addPoint(glm::vec2(ofRandomWidth(), ofRandomHeight()));
        triangulation.triangulate(); // calculate the triangulation!
    }
    
    if(key == 'c') {
        int lastPoint = triangulation.getNumPoints();
        cout << lastPoint << endl;
        triangulation.removePointAtIndex(lastPoint-1);
        // this allows you to get the
    }
    if(key == 'r') {
        triangulation.reset();
        // this allows you to get the
    }
    if(key == 'w'){
        wireFrame =! wireFrame;
    }
    if(key == 'q'){
        triangulation.addPoint(glm::vec2(0,0));
        triangulation.addPoint(glm::vec2(ofGetWidth(), 0));
        triangulation.addPoint(glm::vec2(0, ofGetHeight()));
        triangulation.addPoint(glm::vec2(ofGetWidth(), ofGetHeight()));
        triangulation.triangulate();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i=0; i<9; i++){
        triangulation.addPoint(glm::vec2(ofRandomWidth(), ofRandomHeight())); // add random
    }
    triangulation.triangulate(); // calculate the triangulation!
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
