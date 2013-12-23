/*
 * Camera.cpp
 *
 *  Created on: 22.10.2013
 *      Author: petr
 */

#include "Camera.hpp"

namespace Gremlin {
namespace Utils {

const GLfloat Camera::STANDARD_ASPECT = 1.77f;
const GLfloat Camera::STANDARD_THETA = 45.0f;
const GLfloat Camera::STANDARD_NEAR = 0.1f;
const GLfloat Camera::STANDARD_FAR = 100.0f;

Camera::Camera() {
	a = STANDARD_ASPECT;
	t = STANDARD_THETA;
	n = STANDARD_NEAR;
	f = STANDARD_FAR;
}

Camera::Camera(const Camera& o) {
	m = o.m;
	a = o.a;
	t = o.t;
	n = o.n;
	f = o.f;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

Vector3D<GLfloat> Camera::lookingAt() const {
	Vector3D<GLfloat> retVal;

	// nastaveni souradnic osy Z do navratoveho vektoru
	retVal[0] = m.cellValue(2, 0);
	retVal[1] = m.cellValue(2, 1);
	retVal[2] = m.cellValue(2, 2);

	return retVal;
}

const Transform3Df &Camera::matrix() const {
	return m;
}

Transform3Df &Camera::matrix() {
	return m;
}

void Camera::rotateX(GLfloat a) {
	m.rotateX(a);
}

void Camera::rotateY(GLfloat a) {
	m.rotateY(a);
}

void Camera::rotateZ(GLfloat a) {
	m.rotateZ(a);
}

Point3Df Camera::translation() const {
	return Point3Df(m.cellValue(0, 3), m.cellValue(1, 3), m.cellValue(2, 3));
}

void Camera::translate(GLfloat dx, GLfloat dy, GLfloat dz) {
	m.translate(dx, dy, dz);
}

void Camera::translateX(GLfloat d) {
	m.translate(d, 0, 0);
}

void Camera::translateY(GLfloat d) {
	m.translate(0, d, 0);
}

GLdouble Camera::aspect() const {
	return a;
}

void Camera::aspect(GLdouble a) {
	this->a = a;
}

GLdouble Camera::far() const {
	return f;
}

void Camera::far(GLdouble f) {
	this->f = f;
}

GLdouble Camera::near() const {
	return n;
}

void Camera::near(GLdouble n) {
	this->n = n;
}

void Camera::setup() {
	gluPerspective(t, a, n, f);
}

GLdouble Camera::theta() const {
	return t;
}

void Camera::theta(GLdouble t) {
	this->t = t;
}

void Camera::translateZ(GLfloat d) {
	m.translate(0, 0, d);
}

} /* namespace Utils */
} /* namespace Gremlin */
