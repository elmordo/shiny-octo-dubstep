/*
 * Renderer.cpp
 *
 *  Created on: 1.11.2013
 *      Author: petr
 */

#include "Renderer.hpp"

namespace Gremlin {
namespace Graphics {

Renderer::Renderer() {
	// TODO Auto-generated constructor stub

}

Renderer::Renderer(const Renderer& o) {
	il = o.il;

	resort();
}

Renderer::~Renderer() {
	// TODO Auto-generated destructor stub
}

void Renderer::addItem(const Object* obj) {

}

const Renderer::RenderItems& Renderer::items() const {
	return il;
}

void Renderer::removeItem(const Object* obj) {
}

void Renderer::resort() {
	// vycisteni seznamu
	sil.clear();
	ail.clear();

	// prochazeni seznamu objektu a rozrazovani
	for (RenderItems::iterator pos = il.begin(); pos != il.end(); pos++) {

	}
}

} /* namespace Utils */
} /* namespace Gremlin */
