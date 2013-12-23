/*
 * Object.hpp
 *
 *  Created on: 2.8.2013
 *      Author: petr
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <Transform3D.hpp>
#include <Point3D.hpp>
#include <vector>
#include "GraphicData.hpp"
#include "Materialed.hpp"
#include <Box.hpp>

using namespace Gremlin::Math;

namespace Gremlin {
namespace Graphics {

/**
 * trida Object slouzi k uchvoani obecnych vlastnosti vsech objektu, ktere se objevuji ve scene
 * obsahuje transformacni matici, ktera definuje pozici stredu objektu a jeho natoceni
 * dale obsahuje informace o rodicovskych vazbach
 */
class Object : public Materialed {
public:
	/**
	 * seznam podrizenych objektu
	 */
	typedef vector<Object*> ObjectList;

private:

	/**
	 * ohranicujici box
	 */
	Box<GLfloat> b;

	/**
	 * seznam podrizenych objektu
	 */
	ObjectList childList;

	/**
	 * transformacni matice tohoto prvku
	 */
	Transform3Df matrix;

	/**
	 * transformacni matice slozena ze vsech matic v linii
	 * obsahuje take matici tohoto prvku
	 */
	Transform3Df fullMatrix;

	/**
	 * ukazatel graficka data k vykresleni
	 */
	const GraphicData *gData;

	/**
	 * rodicovsky objekt
	 */
	Object *p;

	/**
	 * provede udpate matic vyvolany predkem
	 */
	void pushMatrixRec(const Transform3Df &m);

	/**
	 * odebere potomka
	 */
	void umountChild(Object *c);

public:

	typedef std::vector<Point3Df> PointList;

	/**
	 * zakladni konstruktor - vytvori prazdny objekt
	 */
	Object();

	/**
	 * copytor
	 */
	Object(const Object &o);

	/**
	 * destruktor
	 */
	virtual ~Object();

	/**
	 * prida podrizeny objekt
	 */
	void addChild(Object* child);

	/**
	 * vrací referenci na ohranicujici box
	 */
	const Box<GLfloat> &boundary() const;

	/**
	 * nastavi nova graficka data
	 */
	void graphicData(const GraphicData *data);

	/**
	 * vraci graficka data
	 */
	const GraphicData *graphicData() const;

	/**
	 * vraci seznam podrizenych objektu
	 */
	const ObjectList &children() const;

	/**
	 * vraci (konstantni) referenci na rodicovky objekt
	 */
	Object *parent();
	const Object *parent() const;

	/**
	 * provede rekurzivni update matic
	 */
	void pushMatrix();

	/**
	 * odebere potomka ze seznamu
	 */
	void removeChild(Object *child);

	/**
	 * vykresli objekt
	 */
	virtual void render() const;

	/**
	 * vykresli potomky
	 */
	void renderChildren(bool recursive) const;

	/**
	 * vraci transformacni matici
	 */
	const Transform3Df &transMatrix() const;
	Transform3Df &transMatrix();

	/**
	 * operator prirazeni
	 */
	Object &operator =(const Object &o);
};

} /* namespace Graphics */
} /* namespace Gremlin */
#endif /* OBJECT_HPP_ */
