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
    isMove = true;
    isFullScreen = false;
    isTargetView = true;
    ofSetFullscreen(isFullScreen);
    ofSetFrameRate(30);
    cout<<"START LOADING PERFUME MEMBERS"<<endl;

    ofxObjLoader::load("model1.obj", aachan, true);
    ofxObjLoader::load("model2.obj", nocchi, true);
    ofxObjLoader::load("model3.obj", kashiyuka, true);


    cout << " num vertices " << aachan.getNumVertices() << endl;
    cout << " num texcords " << aachan.getNumTexCoords() << endl;
    cout << " num normals " << aachan.getNumNormals() << endl;
    cout << " num indices " << aachan.getNumIndices() << endl;

    //test
    mseX = 0;
    mseY = 0;

    mouseP.set(0.0f, 0.0f);
    mouseD.set(0.0f, 0.0f);
    mouseR.set(0.0f, 0.0f);

    //camera position
    //myCam.setDistance(1000);

    point.set(0.0f, 0.0f, -100.0f);

    origin.set(0, 1, 0);
    upVector.set(0.0f, 1.0f, 0.0f);
    target.set(1.0f, 0.0f, 0.0f);
    camVec.set(-100.0f, 0.0f, 500.0f);
    lensoffset.set(0.0f, 0.0f);
    myCam.setupPerspective(false, 45, 0, 10000, lensoffset);
    //myCam.lookAt(target, upVector);
    //myCam.setTarget(origin);


    //lighting
    /*
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
     */

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
    /*
    camVec.x = sin(2*PI);
    camVec.y = cos(2*PI);
    camVec.z = 100;
     */

     t = ofGetElapsedTimef();

    if(isMove) camVec.set(5000*sin(2*PI/10*t), 500, 5000*cos(2*PI/10*t));
    camPos.set(point.x+camVec.x, point.y+camVec.y, point.z+camVec.z);
    myCam.setPosition(camPos);
    //target.set(1.0f, 0.0f, 0.0f);
    //target = target + 0.01f*mouseD.x*getScreenX(target) + 0.01f*mouseD.y*getScreenY(target);
    origin.set(point.x + camVec.x + target.x, point.y + camVec.y + target.y, point.z + camVec.z + target.z);
    //origin.set(-sin(2*PI/10*t) * sin(2*PI*t/10), cos(2*PI*t/10), -cos(2*PI/10*t) * sin(2*PI*t/10));
    if(isTargetView) myCam.lookAt(point, upVector);
    else myCam.lookAt(origin, upVector);

}

//--------------------------------------------------------------
void testApp::draw(){

    myCam.begin();

    ofSetColor(0, 0, 250);
    scrX = getScreenX(target);
    scrY = getScreenY(target);
    float l = 100.0f;
    for(int i = 0; i < 100; i++){
        ofLine(camPos.x + l*(sin(i*PI*2.0f/100.0f)*scrY.x + cos(i*PI*2.0f/100.0f)*scrX.x+target.x),
               camPos.y + l*(sin(i*PI*2.0f/100.0f)*scrY.y + cos(i*PI*2.0f/100.0f)*scrX.y+target.y),
               camPos.z + l*(sin(i*PI*2.0f/100.0f)*scrY.z + cos(i*PI*2.0f/100.0f)*scrX.z+target.z),
               camPos.x + l*(target.x),
               camPos.y + l*(target.y),
               camPos.z + l*(target.z)
               );
    }
    ofSetColor(255, 255, 200);
    float r = 5000.0f;
    for(int i = 0; i < 100; i++){
            ofLine(0.0f, -500.0f, 0.0f, r*sin(i*2.0f*PI/100.0f), -200.0f, r*cos(i*2.0f*PI/100.0f));
    }
    ofPushMatrix();
    ofTranslate(point);

    //繧ｪ繝悶ず繧ｧ繧ｯ繝郁・菴薙・蝗櫁ｻ｢
    //ofRotateY(ofGetElapsedTimef() * 10);

    //Aachan
    if (isAachan) {
        //ofTranslate(ofGetWidth()/3, 0);

        ofSetColor(200+ofRandom(55), 200, 200);
        aachan.drawWireframe();
        ofSetColor(200+ofRandom(55), 200, 200);
        aachan.drawFaces();
        //aachan.drawWireframe();
        //aachan.drawVertices();
    }

    //NOCCHi
    if (isNOCCHi) {
        //ofTranslate(ofGetWidth()/2, -ofGetHeight()/2);


        //ofSetColor(30, 30, 30);
        ofSetColor(200, 200, 200+ofRandom(55));
        nocchi.drawWireframe();
        ofSetColor(200, 200, 200+ofRandom(55));
        nocchi.drawFaces();
        //nocchi.drawVertices();
        ofSetColor(0, 0, 0);
        nocchi.drawWireframe();

    }

    //Kashiyuka
    if (isKashiyuka) {

        //ofSetColor(70, 70, 70);
        ofSetColor(200, 200+ofRandom(55), 200);
        kashiyuka.drawWireframe();
        ofSetColor(200, 200+ofRandom(55), 200);
        kashiyuka.drawFaces();
        //kashiyuka.drawWireframe();
        //kashiyuka.drawVertices();
    }


    ofPopMatrix();

    myCam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    //Full screen or not
    if(key == 'f'){
        if(isFullScreen) isFullScreen = false;
        else isFullScreen = true;
        ofSetFullscreen(isFullScreen);
    }else if(key == 'm'){
        isMove = false;
    }else if(key == 'n'){
        isMove = true;
    }else if(key == 't'){
        if(isTargetView) isTargetView = false;
        else isTargetView = true;
    }
    else if (key == 'a') {
        isAachan = !isAachan;
    }
    else if (key == 'n') {
        isNOCCHi = !isNOCCHi;
    }
    else if (key == 'k') {
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
    mouseD.set((float)x - mouseP.x, (float)y - mouseP.y);
    target = targetTemp - 0.01f*mouseD.x*getScreenX(targetTemp) + 0.01f*mouseD.y*getScreenY(targetTemp);

    cout<<"X:"<<target.x<<endl;
    cout<<"Y:"<<target.y<<endl;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mseX = x;
    mseY = y;

    mouseP.set((float)x, (float)y);
    targetTemp.set(target);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouseD.set((float)x - mouseP.x, (float)y - mouseP.y);
    target = targetTemp - 0.01f*mouseD.x*getScreenX(targetTemp) + 0.01f*mouseD.y*getScreenY(targetTemp);
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


ofVec3f testApp::normalize(ofVec3f P){
    float l = sqrt(sq(P.x)+sq(P.y)+sq(P.z));
    ofVec3f normalized;
    normalized.set(P.x/l, P.y/l, P.z/l);
    return normalized;
}

float testApp::sq(float x){
    return abs(x*x);
}

ofVec3f testApp::getScreenX(ofVec3f P){
    ofVec3f screenX;
    screenX.set(-P.z, 0.0f, P.x);
    return normalize(screenX);
}

ofVec3f testApp::getScreenY(ofVec3f P){
    ofVec3f screenY;
    screenY.set(-P.x*P.y, sq(P.x)+sq(P.z), -P.y*P.z);
    return normalize(screenY);
}
