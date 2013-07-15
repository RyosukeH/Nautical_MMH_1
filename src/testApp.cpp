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

    cout<<"START LOADING PERFUME MEMBERS"<<endl;

    ofxObjLoader::load("model1.obj", aachan, true);
    ofxObjLoader::load("model2.obj", nocchi, true);
    ofxObjLoader::load("model3.obj", kashiyuka, true);


    cout << " num vertices " << aachan.getNumVertices() << endl;
    cout << " num texcords " << aachan.getNumTexCoords() << endl;
    cout << " num normals " << aachan.getNumNormals() << endl;
    cout << " num indices " << aachan.getNumIndices() << endl;


    //camera position
    myCam.setDistance(1000);

    //lighting
    mySun.enable();
    mySun.setSpotlight();
    mySun.setPosition(-300, 10, 1000);
    ambtCol = ofFloatColor(0.1, 0.1, 0.3);
    dffsCol = ofFloatColor(0.8, 0.8, 0.8);
    spclCol = ofFloatColor(0.9, 0.9, 0.9);
    mySun.setAmbientColor(ambtCol);
    mySun.setDiffuseColor(dffsCol);
    mySun.setSpecularColor(spclCol);

    //mySun.setAmbientColor(

    //flag initialize
    isAachan = true;
    isNOCCHi = true;
    isKashiyuka = true;

    //nocchi.enableIndices();
    //nocchi.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    glEnable(GL_DEPTH_TEST);

    cout<<"SET UP FINISHED."<<endl;


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

        ofSetColor(200+ofRandom(55), 200, 200);

        aachan.drawWireframe();
        //aachan.drawVertices();
    }

    //NOCCHi
    if (isNOCCHi) {
        //ofTranslate(ofGetWidth()/2, -ofGetHeight()/2);


        ofSetColor(30, 30, 30);
        nocchi.drawWireframe();
        ofSetColor(200, 200, 200+ofRandom(55));
        nocchi.drawFaces();
        //nocchi.drawVertices();

    }

    //Kashiyuka
    if (isKashiyuka) {
        ofSetColor(200, 200+ofRandom(55), 200);

        //kashiyuka.drawWireframe();
        kashiyuka.drawVertices();
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
