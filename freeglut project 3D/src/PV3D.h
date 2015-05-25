/**
 * Clase PV3D. Representa un vector o un punto en un espacio de tres dimensiones.
 * Autores: Álvar Soler y Raúl Cobos.
 */

#ifndef PV3D_H
#define	PV3D_H

#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

class PV3D {
public:
    PV3D();
    PV3D(GLfloat x, GLfloat y, GLfloat z);

    /* Métodos de la clase */
    GLfloat modulo();
    void normaliza();
    PV3D* clona();
    GLfloat productoEscalar(PV3D* p);
    PV3D* productoVectorial(PV3D* p);


    /* Sobrecarga */
    PV3D& operator +(const PV3D &p);
    PV3D& operator -(const PV3D &p);
    bool operator ==(const PV3D &p);
    bool operator !=(const PV3D &p);
    friend std::ostream& operator <<(std::ostream &o, const PV3D &p);
    
    /* Getters */
    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();

private:

    GLfloat _x, _y, _z;
    int _pv;
};

#endif	/* PV3D_H */

