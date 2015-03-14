//
//  analizador.cpp
//  exampleOpenNI HandTracking
//
//  Created by Voodoo Noise on 13/03/15.
//
//

#include "analizador.h"

Analizador::Analizador ( ) {
    
    actPos = 0;
    oldPos = 0;
    oldV = 0;
    actV = 0;
    oldPend = " ";
    actPend = " ";
    hit = " ";
    lp = new LowPass(2);
    
   
}

float Analizador::calcVel() {

    actV = actPos - oldPos;
    
}

std::string Analizador::calcPend(){

    if (actV - oldV > 0) {
        
        actPend = "positiva";
        
        return actPend;
    }
    
    if (actV - oldV < 0) {
        
        actPend = "negativa";
        
        return actPend;
    }
    
    return actPend;
}


std::string Analizador::maximo(){

    if (actPend=="negativa" && oldPend=="positiva"){
    
    hit="hit";
        
        oldPend=actPend;
        
        return hit;
    }
    
    hit=" ";
    oldPend=actPend;
    
    return hit;
    

}

std::string  Analizador::calcularTodo(float posAct){

    actPos=posAct;
    
    calcVel();
    oldPos=actPos;
    
    calcPend();
    oldV=actV;
    
    
    return maximo();
    
    


}
