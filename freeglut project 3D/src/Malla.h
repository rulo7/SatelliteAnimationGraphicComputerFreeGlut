/* 
 * File:   Malla.h
 * Author: furia
 *
 * Created on 3 de diciembre de 2013, 18:07
 */

#ifndef MALLA_H
#define	MALLA_H
#include "PV3D.h"
#include "Cara.h"
class Malla {
public:
    Malla();
    Malla(int nVertices, int nNormales, int nCaras);
    void dibuja();
    void vectoresNormalNewell();
protected:
    int _numVertices;
    PV3D** _vertices;
    int _numNormales; // =numCaras
    PV3D** _normal;
    int _numCaras;
    Cara** _cara;
private:
    PV3D* newell(Cara* c);
};

#endif	/* MALLA_H */

