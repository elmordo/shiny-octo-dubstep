/*
 * Empty.cpp
 *
 *  Created on: 7.8.2013
 *      Author: petr
 */

#include "Empty.hpp"

namespace Gremlin {
namespace Graphics {

Empty::Empty() {
	// TODO Auto-generated constructor stub

}

Gremlin::Graphics::Empty::Empty(const Empty& o) : Object(o) {

}

Empty::~Empty() {
	// TODO Auto-generated destructor stub
}

void Gremlin::Graphics::Empty::render(const Transform3Df& matrix) const {
	// nic se nevykresluje
}

} /* namespace Graphics */
} /* namespace Gremlin */
