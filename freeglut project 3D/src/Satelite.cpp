/* 
 * File:   Satelite.cpp
 * Author: usuario_local
 * 
 * Created on 19 de diciembre de 2013, 15:20
 */
/*
int _numVertices;
    PV3D** _vertices;
    int _numNormales; // =numCaras
    PV3D** _normal;
    int _numCaras;
    Cara** _cara;*/
#include "Satelite.h"
#include "Malla.h"

Satelite::Satelite() {
}

Satelite::Satelite(int nCaras, GLdouble altura, GLdouble radio) {
    _numCaras = nCaras;
    _numNormales = nCaras;
    _numVertices = 2 * nCaras;

    _cara = new Cara*[_numCaras];
    _normal = new PV3D*[_numNormales];
    _vertices = new PV3D*[_numVertices];



    _vertices[0] = new PV3D(-1, 0, 1);
    _vertices[1] = new PV3D(-1, 0, -1);
    _vertices[2] = new PV3D(1, 0, -1);
    _vertices[3] = new PV3D(1, 0, 1);


    _vertices[4] = new PV3D(-1, 5, 1);
    _vertices[5] = new PV3D(-1, 5, -1);
    _vertices[6] = new PV3D(1, 5, -1);
    _vertices[7] = new PV3D(1, 5, 1);

    for (int i = 0; i < _numCaras; i++) {
        _cara[i] = new Cara(4);
        _cara[i]->addVerticeNormal(new VerticeNormal(i, i), 0);
        _cara[i]->addVerticeNormal(new VerticeNormal((i + 1) % _numVertices, i), 1);
        _cara[i]->addVerticeNormal(new VerticeNormal((i + 1 + _numCaras) % _numVertices, i), 2);
        _cara[i]->addVerticeNormal(new VerticeNormal((i + _numCaras) % _numVertices, i), 3);

    }



    vectoresNormalNewell();
}