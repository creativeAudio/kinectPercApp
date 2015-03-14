//
//  lowPass.h
//  exampleOpenNI HandTracking
//
//  Created by Voodoo Noise on 13/03/15.
//
//

#ifndef __exampleOpenNI_HandTracking__lowPass__
#define __exampleOpenNI_HandTracking__lowPass__

#include <stdio.h>
#include <vector>
#include "ofMain.h"


class LowPass {
    
public:
    
    //variables
    std::vector <int > buffer; 
    int len;
    float output;
    
    //Methods
    float filt (float v);
    
    //Constructor
    LowPass(int size);
    
    
    

};

#endif /* defined(__exampleOpenNI_HandTracking__lowPass__) */
