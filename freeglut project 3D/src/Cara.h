/* 
 * File:   Cara.h
 * Author: furia
 *
 * Created on 3 de diciembre de 2013, 18:05
 */

#ifndef CARA_H
#define	CARA_H
#include "VerticeNormal.h"

class Cara {
public:
    Cara();
    Cara(int numVertices);
    int getNumeroVertices();
    int getIndiceNormalK(int normal);
    int getIndiceVerticeK(int vertice);
    void addVerticeNormal(VerticeNormal *vn, int indx);
private:
    int _numVertices;
    VerticeNormal** _arrayVN;
};

#endif	/* CARA_H */

