/*
 * LightBase.cpp
 *
 *  Created on: 18.9.2013
 *      Author: petr
 */

#include "LightBase.hpp"

namespace Gremlin {
namespace Materials {

const GLfloat LightBase::DEFAULT_CONSTANT = 1.0f;
const GLfloat LightBase::DEFAULT_LINEAR = 0.0f;
const GLfloat LightBase::DEFAULT_QUADRATIC = 0.0f;

LightBase::LightBase() {
	k = DEFAULT_CONSTANT;
	l = DEFAULT_LINEAR;
	q = DEFAULT_QUADRATIC;

	i = 0;
}

LightBase::LightBase(const Color& ambient, const Color& diffuse,
		const Color& specular) {

	ac = ambient;
	dc = diffuse;
	sc = specular;

	// hodnoty utlumu se nastavi na vychozi hodnoty
	k = DEFAULT_CONSTANT;
	l = DEFAULT_LINEAR;
	q = DEFAULT_QUADRATIC;

	i = 0;
}

LightBase::LightBase(const Color& ambient, const Color& diffuse,
		const Color& specular, GLfloat k, GLfloat l, GLfloat q) {

	ac = ambient;
	dc = diffuse;
	sc = specular;

	this->k = k;
	this->l = l;
	this->q = q;

	i = 0;
}

LightBase::LightBase(const LightBase& o) {
	ac = o.ac;
	dc = o.dc;
	sc = o.sc;

	k = o.k;
	l = o.l;
	q = o.q;

	i = o.i;
}

LightBase::~LightBase() {
	// TODO Auto-generated destructor stub
}

void LightBase::ambient(const Color& c) {
	ac = c;
}

const Color& LightBase::ambient() const {
	return ac;
}

void LightBase::constant(GLfloat v) {
	k = v;
}

GLfloat LightBase::constant() const {
	return k;
}

void LightBase::diffuse(const Color& c) {
	dc = c;
}

const Color& LightBase::diffuse() const {
	return dc;
}

void LightBase::linear(GLfloat v) {
	l = v;
}

GLfloat LightBase::linear() const {
	return l;
}

void LightBase::quadratic(GLfloat v) {
	q = v;
}

GLfloat LightBase::quadratic() const {
	return q;
}

void LightBase::specular(const Color& c) {
	sc = c;
}

void LightBase::index(GLenum i) {
	this->i = i;
}

GLenum LightBase::index() const {
	return i;
}

void LightBase::setParameters() const {
	// kontrola aktivace svetla. Pokud je index == 0, pak svetlo neni aktivni
	if (i == 0)
		return;

	// nastaveni parametru utlumu
	glLightf(i, GL_CONSTANT_ATTENUATION, k);
	glLightf(i, GL_LINEAR_ATTENUATION, l);
	glLightf(i, GL_QUADRATIC_ATTENUATION, q);

	// nastaveni parametru svetel
	glLightfv(i, GL_AMBIENT, ac.color());
	glLightfv(i, GL_DIFFUSE, dc.color());
	glLightfv(i, GL_SPECULAR, sc.color());
}

const Color& LightBase::specular() const {
	return sc;
}

} /* namespace Materials */
} /* namespace Gremlin */
