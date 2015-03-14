//
//  analizador.h
//  exampleOpenNI HandTracking
//
//  Created by Voodoo Noise on 13/03/15.
//
//

#ifndef __exampleOpenNI_HandTracking__analizador__
#define __exampleOpenNI_HandTracking__analizador__

#include <stdio.h>
#include <lowPass.h>
#include <string>

#endif /* defined(__exampleOpenNI_HandTracking__analizador__) */

class Analizador {

public:
    
    //variables
    float actPos;
    float oldPos;
    float oldV;
    float actV;
    std::string oldPend;
    std::string actPend;
    std::string hit;
    LowPass *lp;
    
    //constructor
    Analizador();
    
    
    //metodos
    
    //calcula la velocidad
    float calcVel();
    
    //calcula sentido de la velocidad
    std::string calcPend();
    
    //analiza si hay un cambio en el sentido de la velocidad y dependiendo de este devuelve un string para disparar un evento
    //TODO En realidad se esta analizando el signo de la aceleración y esto puede ser lo que genere fallas
    std::string maximo();
    
    
    //implementa los metodos anteriores y actualiza los valores pasados.
    std::string  calcularTodo(float posAct);



};