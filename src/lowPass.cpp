//
//  lowPass.cpp
//  exampleOpenNI HandTracking
//
//  Created by Voodoo Noise on 13/03/15.
//
//

#include "lowPass.h"


LowPass :: LowPass(int size) {
    
    len = size;
    buffer.reserve(len);
    for(int i = 0; i < len; i++) {
        
        buffer.push_back(0);
    }
    
}

float LowPass:: filt(float v) {

    buffer.push_back(v);
    buffer.erase (buffer.begin());
    
    float sum = 0;
    
    
    for(int i=0; i<buffer.size(); i++) {
        
        float fv = (float)buffer[i];
        sum += fv;
    }
    
    output = sum / buffer.size();
    return output;

}


  

