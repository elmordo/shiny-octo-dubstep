/*
 * Bulb.hpp
 *
 *  Created on: 18.9.2013
 *      Author: petr
 */

#ifndef BULB_HPP_
#define BULB_HPP_

#include "LightBase.hpp"

namespace Gremlin {
namespace Materials {

class Bulb: public Gremlin::Materials::LightBase {
public:

	/**
	 * vytvori bile svetlo
	 */
	Bulb();

	/**
	 * nastavi barvu svetla
	 */
	Bulb(const Color &ambient, const Color &diffuse, const Color &specular);

	/**
	 * nastavi barvu a koeficienty utlumu
	 */
	Bulb(const Color &ambient, const Color &diffuse, const Color &specular, GLfloat k, GLfloat l, GLfloat q);

	/**
	 * kopytor
	 */
	Bulb(const Bulb &o);

	/**
	 * destruktor
	 */
	virtual ~Bulb();

	/**
	 * nastavi parametry svetla
	 */
	virtual void render(const MaterialMap &mats) const;
};

} /* namespace Materials */
} /* namespace Gremlin */
#endif /* BULB_HPP_ */
