/*
 * Object.cpp
 *
 *  Created on: 2.8.2013
 *      Author: petr
 */

#include "Object.hpp"

namespace Gremlin {
namespace Graphics {

Object::Object() :
		Materialed() {
	gData = 0x0;
	p = 0x0;
}

Object::~Object() {
	// pokud je objekt parentovan, odebere se z predka
	if (p != 0x0) {
		// odebrani z predka
		p->removeChild(this);
	}

	// odebrani potomku
	while (childList.size())
		removeChild(childList.back());
}

Object::Object(const Object& o) :
		Materialed(o) {
	matrix = o.matrix;
	gData = o.gData;
	p = 0x0;
}

const Transform3Df& Object::transMatrix() const {
	return matrix;
}

Transform3Df& Gremlin::Graphics::Object::transMatrix() {
	return matrix;
}

void Object::render() const {
	// pokud nejsou nastavena zadna data, pak se nic nedela
	if (gData == 0x0)
		return;

	// prepocet matice
	const GLfloat *vals = fullMatrix.rawData();

	// uschovani puvodnich dat
	glPushMatrix();

	// zapis nove matice do bufferu
	glLoadMatrixf(vals);

	// vykresleni grafickych dat
	gData->render(MaterialMap());

	// obnoveni puvodnich dat matice
	glPopMatrix();
}

void Object::renderChildren(bool recursive = false) const {
	// iterace nad potomky a jejich vykresleni
	// vytvoreni fnalni matice
	Transform3Df final(this->matrix * matrix);

	for (ObjectList::const_iterator pos = childList.begin();
			pos < childList.end(); pos++) {
		// vykresleni objektu na pozici
		(*pos)->render();

		if (recursive) {
			(*pos)->renderChildren(recursive);
		}
	}
}

void Object::addChild(Object* child) {

	childList.push_back((Object*) child);

	child->p = this;
	child->pushMatrix();

}

const Object::ObjectList& Object::children() const {
	return childList;
}

void Object::removeChild(Object* child) {
	// iterate on all elements
	umountChild(child);

	child->pushMatrix();
}

Object& Object::operator =(const Object& o) {
	matrix = o.matrix;

	return *this;
}

void Object::graphicData(const GraphicData* data) {
	// nastaveni novych grafickych dat
	gData = data;

	// nastaveni noveho obaloveho prvku
	b = data->boundary();
	b.matrix(&fullMatrix);
	b.transform();
}

const GraphicData* Object::graphicData() const {
	return gData;
}

Object *Object::parent() {
	return p;
}

const Object *Object::parent() const {
	return p;
}

void Gremlin::Graphics::Object::umountChild(Object* c) {
	// vyhodnoceni, jestli ma potomek tohoto rodice
	if (c->p != this)
		return;

	// odnastaveni rodice
	c->p = 0x0;

	// odebrani ze seznamu
	for (ObjectList::iterator pos = childList.begin(); pos < childList.end();
			pos++) {
		// porovnani ukazatelu
		if ((*pos) == c) {
			// ukazatel vyhovuje - vymazani pozice
			childList.erase(pos);
			return;
		}
	}
}

void Object::pushMatrix() {
	// kontrola, jestli je prvek korenovy
	if (p == 0x0) {
		pushMatrixRec(Transform3Df());
	} else {
		pushMatrixRec(p->matrix);
	}
}

void Object::pushMatrixRec(const Transform3Df &m) {
	fullMatrix = matrix * m;
	b.transform();

	// rekurzivni update dat
	for (ObjectList::iterator pos = childList.begin(); pos != childList.end();
			pos++) {
		(*pos)->pushMatrixRec(fullMatrix);
	}
}

const Box<GLfloat> &Object::boundary() const {
	return b;
}

} /* namespace Graphics */
} /* namespace Gremlin */
