/*
 * Sun.hpp
 *
 *  Created on: 18.9.2013
 *      Author: petr
 */

#ifndef SUN_HPP_
#define SUN_HPP_

#include "LightBase.hpp"
#include <Point3D.hpp>

using namespace Gremlin::Math;

namespace Gremlin {
namespace Materials {

class Sun: public Gremlin::Materials::LightBase {

	Point3D<GLfloat> d;

public:
	/**
	 * vytvori bile svetlo
	 */
	Sun();

	/**
	 * nastavi barvu svetla
	 */
	Sun(const Color &ambient, const Color &diffuse, const Color &specular);

	/**
	 * nastavi barvu a koeficienty utlumu
	 */
	Sun(const Color &ambient, const Color &diffuse, const Color &specular, GLfloat k, GLfloat l, GLfloat q);

	/**
	 * kopytor
	 */
	Sun(const Sun &o);

	/**
	 * destruktor
	 */
	virtual ~Sun();

	/**
	 * vraci smer vektoru
	 */
	const Point3D<GLfloat> &direction() const;

	/**
	 * nastavi smer svitu
	 */
	void direction(const Point3D<GLfloat> &d);
	void direction(GLfloat x, GLfloat y, GLfloat z);

	/**
	 * nastavi parametry svetla
	 */
	virtual void render(const MaterialMap &mats) const;
};

} /* namespace Materials */
} /* namespace Gremlin */
#endif /* SUN_HPP_ */
