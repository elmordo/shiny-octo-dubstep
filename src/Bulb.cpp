/*
 * Bulb.cpp
 *
 *  Created on: 18.9.2013
 *      Author: petr
 */

#include "Bulb.hpp"

namespace Gremlin {
namespace Materials {

Bulb::Bulb() {
	// TODO Auto-generated constructor stub

}

Bulb::Bulb(const Color& ambient, const Color& diffuse, const Color& specular) : LightBase(ambient, diffuse, specular) {
}

Bulb::Bulb(const Color& ambient, const Color& diffuse, const Color& specular,
		GLfloat k, GLfloat l, GLfloat q) : LightBase(ambient, diffuse, specular, k, l, q) {
}

Bulb::Bulb(const Bulb& o) : LightBase(o) {
}

Bulb::~Bulb() {
	// TODO Auto-generated destructor stub
}

void Bulb::render(const MaterialMap& mats) const {
	// nastaveni obecnych hodnot
	setParameters();
}

} /* namespace Materials */
} /* namespace Gremlin */
