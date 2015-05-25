

#include "PV3D.h"

/* Constructores */
PV3D::PV3D() {
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

PV3D::PV3D(GLfloat x, GLfloat y, GLfloat z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

/* Métodos de la clase */
GLfloat PV3D::modulo() {
    return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

void PV3D::normaliza() {
    GLfloat mod = modulo();
    if (mod != 0) {
        _x = _x / mod;
        _y = _y / mod;
        _z = _z / mod;
    }

}

PV3D* PV3D::clona() {
    return new PV3D(_x, _y, _z);
}

GLfloat PV3D::productoEscalar(PV3D* p) {
    return (_x + p->_x, _y + p->_y, _z + p->_z);
}

PV3D* PV3D::productoVectorial(PV3D* p) {
    GLfloat x = _y * p->_z - _z * p->_y;
    GLfloat y = _z * p->_x - _x * p->_z;
    GLfloat z = _x * p->_y - _y * p->_x;
    return new PV3D(x, y, z);
}

/* Sobrecarga */
PV3D& PV3D::operator +(const PV3D &p) {
    return *(new PV3D(_x + p._x, _y + p._y, _z + p._z));
}

PV3D& PV3D::operator -(const PV3D &p) {
    return *(new PV3D(_x - p._x, _y - p._y, _z - p._z));
}

bool PV3D::operator ==(const PV3D &p) {
    return (this->_x == p._x) && (this->_y == p._y) && (this->_z == p._z);
}

bool PV3D::operator !=(const PV3D &p) {
    return !(this == &p);
}

std::ostream& operator <<(std::ostream &o, const PV3D &p) {
    o << "(" << p._x << "," << p._y << "," << p._z << ")";
    return o;
}

/* Getters */
GLfloat PV3D::getX() {
    return this->_x;
}

GLfloat PV3D::getY() {
    return this->_y;
}

GLfloat PV3D::getZ() {
    return this->_z;
}