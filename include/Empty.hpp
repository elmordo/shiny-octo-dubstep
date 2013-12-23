/*
 * Empty.hpp
 *
 *  Created on: 7.8.2013
 *      Author: petr
 */

#ifndef EMPTY_HPP_
#define EMPTY_HPP_

#include "Object.hpp"

namespace Gremlin {
namespace Graphics {

/**
 * prazdne objekty slouzi jako pomocne objekty sceny
 * napriklad pro vytvareni rodicovskych vazeb a podobne
 */
class Empty: public Gremlin::Graphics::Object {
public:

	/**
	 * vytvori prazdny objekt
	 */
	Empty();

	/**
	 * copytor
	 */
	Empty(const Empty &o);

	/**
	 * destruktor
	 */
	virtual ~Empty();

	/**
	 * pouze necha vykreslit potomky
	 */
	void render(const Transform3Df& matrix) const;
};

} /* namespace Graphics */
} /* namespace Gremlin */
#endif /* EMPTY_HPP_ */
