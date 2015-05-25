/* 
 * File:   Malla.cpp
 * Author: furia
 * 
 * Created on 3 de diciembre de 2013, 18:07
 */

#include "Malla.h"

Malla::Malla() {
}

Malla::Malla(int nVertices, int nNormales, int nCaras) {
    _numVertices = nVertices;
    _vertices = new PV3D*[_numVertices];
    _numNormales = nNormales;
    _normal = new PV3D*[_numNormales];
    _numCaras = nCaras;
    _cara = new Cara*[_numCaras];
}

void Malla::dibuja() {
    for (int i = 0; i < _numCaras; i++) {
        glLineWidth(1.0);
        glBegin(GL_POLYGON); // o glBegin(GL_LINE_LOOP);
        for (int j = 0; j < _cara[i]->getNumeroVertices(); j++) {
            int iN = _cara[i]->getIndiceNormalK(j);
            int iV = _cara[i]->getIndiceVerticeK(j);
            glNormal3f(_normal[iN]->getX(), _normal[iN]->getY(), _normal[iN]->getZ());
            glVertex3f(_vertices[iV]->getX(), _vertices[iV]->getY(), _vertices[iV]->getZ());
        }
        glEnd();
    }
}
void Malla::vectoresNormalNewell() {
    for(int i = 0; i < _numCaras; i++)
        _normal[i] = newell(_cara[i]);

}

PV3D* Malla::newell(Cara* c) {
    int x = 0;
    int y = 0;
    int z = 0;
    PV3D* va;
    PV3D* vs;
    //std::cout << c->getNumeroVertices() << std::endll;
    for (int i = 0; i < c->getNumeroVertices(); i++) {
        va = _vertices[c->getIndiceVerticeK(i)];
        vs = _vertices[c->getIndiceVerticeK((i + 1) % c->getNumeroVertices())];
        x += (va->getY() - vs->getY()) * (va->getZ() + vs->getZ());
        y += (va->getZ() - vs->getZ()) * (va->getX() + vs->getX());
        z += (va->getX() - vs->getX()) * (va->getY() + vs->getY());
    }
    
    PV3D* n = new PV3D(x, y, z);
    n->normaliza();
    
    return n;
}