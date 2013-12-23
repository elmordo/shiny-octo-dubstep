/*
 * GraphicData.cpp
 *
 *  Created on: 20.8.2013
 *      Author: petr
 */

#include "GraphicData.hpp"

namespace Gremlin {
namespace Graphics {

GraphicData::GraphicData() : Materialed() {
	// TODO Auto-generated constructor stub

}

Gremlin::Graphics::GraphicData::GraphicData(const GraphicData& o) : Materialed(o) {
}

GraphicData::~GraphicData() {
	// TODO Auto-generated destructor stub
}

Math::Box<GLfloat>& GraphicData::boundary() {
	return b;
}

const Math::Box<GLfloat>& GraphicData::boundary() const {
	return b;
}

} /* namespace Graphics */
} /* namespace Gremlin */
