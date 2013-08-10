#pragma once

#include "ofMain.h"
#include "ofxObjLoader.h"

class testApp : public ofBaseApp{
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		float sq(float value);
		ofVec3f normalize(ofVec3f P);
		ofVec3f getScreenX(ofVec3f P);
		ofVec3f getScreenY(ofVec3f P);

    //ofCamera cam;
    ofMesh aachan;
    ofMesh nocchi;
    ofMesh kashiyuka;

    ofCamera myCam;
    ofVec2f lensoffset;
    ofLight mySun;
    ofFloatColor ambtCol, dffsCol, spclCol;

    bool isAachan, isNOCCHi, isKashiyuka;
    bool isFullScreen;
    bool isTargetView;
    bool isMove;

    //MEMBER FOR REPRESENTING TIME
    float t;

    //
    ofPoint point;
    ofVec3f camVec, origin, upVector, target, targetTemp;
    ofVec3f scrX, scrY;
    ofVec3f camPos;

    //camera position
    int mseX, mseY;
    ofVec2f mouseP, mouseD, mouseR;
};
