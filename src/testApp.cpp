/*
 // Perfume 3D scan data
 // http://wt2.perfume-global.com/polygon.html
 // Terms of use
 // http://wt2.perfume-global.com/scan_terms_jp.html
 // 
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    
    ofxObjLoader::load("model1.obj", aachan, true);
    ofxObjLoader::load("model2.obj", nocchi, true);
    ofxObjLoader::load("model3.obj", kashiyuka, true);
    
    /*
    cout << " num vertices " << aachan.getNumVertices() << endl;
    cout << " num texcords " << aachan.getNumTexCoords() << endl;
    cout << " num normals " << aachan.getNumNormals() << endl;
    cout << " num indices " << aachan.getNumIndices() << endl;
    */
    
    //camera position
    myCam.setDistance(1000);
    
    //flag initialize
    isAachan = false;
    isNOCCHi = false;
    isKashiyuka = false;


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    myCam.begin();
    
    //Aachan
    if (isAachan) {
        //ofTranslate(ofGetWidth()/3, 0);
        
        ofSetColor(ofRandom(255), 50, 200);
        
        aachan.drawWireframe();
        //aachan.drawVertices();
    }
    
    //NOCCHi
    if (isNOCCHi) {
        //ofTranslate(ofGetWidth()/2, -ofGetHeight()/2);
        
        ofSetColor(50, 200, ofRandom(255));
        
        nocchi.drawWireframe();
        //nocchi.drawVertices();
    }
    
    //Kashiyuka
    if (isKashiyuka) {
        ofSetColor(200, ofRandom(255), 50);
        
        kashiyuka.drawWireframe();
        //kashiyuka.drawVertices();
    }
    
    
    myCam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    //Full screen or not
    if(key == 'f'){
        ofSetFullscreen(true);
    }
    if (key == 's') {
        ofSetFullscreen(false);
    }
    
    if (key == 'a') {
        isAachan = !isAachan;
    }
    if (key == 'n') {
        isNOCCHi = !isNOCCHi;
    }
    if (key == 'k') {
        isKashiyuka = !isKashiyuka;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}