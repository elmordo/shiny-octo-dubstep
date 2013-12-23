/*
 * Sun.cpp
 *
 *  Created on: 18.9.2013
 *      Author: petr
 */

#include "Sun.hpp"

namespace Gremlin {
namespace Materials {

Sun::Sun() {
	// TODO Auto-generated constructor stub
	d.vector(true);
}

Sun::Sun(const Color& ambient, const Color& diffuse, const Color& specular) : LightBase(ambient, diffuse, specular) {
	d.vector(true);
}

Sun::Sun(const Color& ambient, const Color& diffuse, const Color& specular,
		GLfloat k, GLfloat l, GLfloat q) : LightBase(ambient, diffuse, specular, k, l, q) {
	d.vector(true);
}

Sun::Sun(const Sun& o) : LightBase(o) {
	d = o.d;
}

Sun::~Sun() {
	// TODO Auto-generated destructor stub
}

const Point3D<GLfloat>& Sun::direction() const {
	return d;
}

void Sun::direction(const Point3D<GLfloat>& d) {
	this->d = d;
	this->d.vector(true);
}

void Sun::direction(GLfloat x, GLfloat y, GLfloat z) {
	d.x(x);
	d.y(y);
	d.z(z);
}

void Sun::render(const MaterialMap& mats) const {
	// nastaveni obecnych dat
	setParameters();

	// pretypovani na float
	GLfloat dir[4];
	const GLfloat *raw = d.rawData();

	for (int i = 0; i < 4; i++) {
		dir[i] = float(raw[i]);
	}

	glLightfv(index(), GL_POSITION, dir);
}

} /* namespace Materials */
} /* namespace Gremlin */
