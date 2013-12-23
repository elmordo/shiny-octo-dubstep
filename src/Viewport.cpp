/*
 * Viewport.cpp
 *
 *  Created on: 30.10.2013
 *      Author: petr
 */

#include "Viewport.hpp"

namespace Gremlin {
namespace Utils {

const GLsizei Viewport::STANDARD_HEIGHT = 360;
const GLsizei Viewport::STANDARD_WIDTH = 480;
const GLint Viewport::STANDARD_X = 0;
const GLint Viewport::STANDARD_Y = 0;

Viewport::Viewport() {
	// TODO Auto-generated constructor stub
	h = STANDARD_HEIGHT;
	w = STANDARD_WIDTH;
	cx = STANDARD_X;
	cy = STANDARD_Y;
}

Viewport::Viewport(GLsizei width, GLsizei height, GLint x, GLint y) {
	w = width;
	h = height;
	cx = x;
	cy = y;
}

Viewport::Viewport(const Viewport& o) {
	w = o.w;
	h = o.h;
	cx = o.cx;
	cy = o.cy;
}

Viewport::~Viewport() {
	// TODO Auto-generated destructor stub
}

Camera Viewport::camera() const {
	Camera retVal;

	retVal.aspect(h / w);

	return retVal;
}

GLsizei Viewport::height() const {
	return h;
}

void Viewport::height(GLsizei h) {
	this->h = h;
}

void Viewport::setup() const {
	glViewport(cx, cy, w, h);
}

GLsizei Viewport::width() const {
	return w;
}

void Viewport::width(GLsizei w) {
	this->w = w;
}

GLint Viewport::x() const {
	return cx;
}

void Viewport::x(GLint x) {
	cx = x;
}

GLint Viewport::y() const {
	return cy;
}

void Viewport::y(GLint y) {
	cy = y;
}

} /* namespace Utils */
} /* namespace Gremlin */
