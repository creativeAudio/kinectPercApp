#ifndef _OF_APP
#define _OF_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "analizador.h"
#include <string>

#define MAX_DEVICES 2

class GestureEvent : public ofEventArgs {
    
    string message;
    GestureEvent(){};
    static ofEvent <GestureEvent> gestureDetected;
};

class ofApp : public ofBaseApp{

public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    //Clase usada para detectar si hubo un golpe explicaci—n de los metodos estan en analizador.h
    Analizador anIzq = *new Analizador();
    Analizador anDer = *new Analizador();
    
    //Strings para guardar el resultado del analizador, este devuelve "hit" en caso de que haya sucedido un golpe y " " en caso de que no.
    std::string hitDer;
    std::string hitIzq; 

private:
    void gestureDetected(GestureEvent& event);
    void handEvent(ofxOpenNIHandEvent & event);
    
	ofxOpenNI openNIDevice;
    ofTrueTypeFont verdana;
    
};

#endif
