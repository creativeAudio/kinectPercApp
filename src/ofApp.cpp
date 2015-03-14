#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();
    //openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    
    // setup the hand generator
    openNIDevice.addHandsGenerator();
    
    // add all focus gestures (ie., wave, click, raise arm)
    openNIDevice.addAllHandFocusGestures();
    
    //openNIDevice.addHandFocusGesture("raise arm");
    
    openNIDevice.setMaxNumHands(2);
    
    
    openNIDevice.start();
    
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    openNIDevice.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    // draw debug (ie., image, depth, skeleton)
    openNIDevice.drawDebug();
    ofPopMatrix();
    
    ofPushMatrix();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    // iterate through users
    for (int i = 0; i < openNIDevice.getNumTrackedHands(); i++){
        
        // get a reference to this user
        ofxOpenNIHand & hand = openNIDevice.getTrackedHand(i);
        
        // get hand position
        ofPoint & handPosition = hand.getPosition();
        
        // draw a rect at the position
        ofSetColor(255,0,0);
        ofRect(handPosition.x, handPosition.y, 2, 2);
        
        if (i % 2 == 0){
            
            //Este string es el que se puede usar despues para disparar eventos en pure data
            
            hitIzq = anIzq.calcularTodo(handPosition.y);
            
        } else {
            
            //Este string es el que se puede usar despues para disparar eventos en pure data
            
            hitDer = anDer.calcularTodo(handPosition.y);
            
        }
        
        // set depthThresholds based on handPosition
        //ofxOpenNIDepthThreshold & depthThreshold = openNIDevice.getDepthThreshold(i); // we just use hand index for the depth threshold index
        
        // draw ROI over the depth image
        ofSetColor(255,255,255);
        
        ofPushMatrix();
        ofTranslate(320 * i, 480);
        ofScale(0.5, 0.5);
        ofPopMatrix();
        
        
    }
    
    ofDisableBlendMode();
    ofPopMatrix();
    
    // draw some info regarding frame counts etc
	ofSetColor(0, 255, 0);
	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate()) + " Device FPS: " + ofToString(openNIDevice.getFrameRate());
    
	verdana.drawString(msg, 20, 480 - 20);
}

//--------------------------------------------------------------
void ofApp::handEvent(ofxOpenNIHandEvent & event){
   
    ofLogNotice() << getHandStatusAsString(event.handStatus) << "for hand" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void ofApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}