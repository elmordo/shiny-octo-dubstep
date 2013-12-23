/*
 * Materialed.cpp
 *
 *  Created on: 30.8.2013
 *      Author: petr
 */

#include "Materialed.hpp"

namespace Gremlin {
namespace Graphics {

Materialed::Materialed() {
	// TODO Auto-generated constructor stub

}

Materialed::Materialed(const Materialed& o) {
	mats = o.mats;
}

Materialed::~Materialed() {
	// TODO Auto-generated destructor stub
}

size_t Materialed::addMaterial(const MaterialBase* material) {
	// index pridaneho materialu
	size_t retVal = mats.size();

	// pridani materialu a vraceni indexu
	mats.push_back(material);
	return retVal;
}

void Materialed::dropMaterial(size_t index) {
	// ziskani iteratoru
	MaterialList::iterator it = iterateToIndex(index);

	// kontrola, jestli byl iterator nalezen
	if (it == mats.end()) return;

	// pred odstanenim se zavola callback a pak probehne odstaneni
	materialDopped(index, *it);
	mats.erase(it);
}

const MaterialBase* Materialed::getMaterial(size_t index) const {
	MaterialList::const_iterator it = iterateToIndex(index);

	if (it == mats.end()) return 0x0;

	return *it;
}

MaterialList::iterator Materialed::iterateToIndex(size_t index) {
	// inicializace hodnoty
	MaterialList::iterator retVal = mats.begin();

	for (size_t i = 0; i < index && retVal != mats.end(); i++, retVal++);

	return retVal;
}

MaterialList::const_iterator Materialed::iterateToIndex(size_t index) const {
	// inicializace hodnoty
	MaterialList::const_iterator retVal = mats.begin();

	for (size_t i = 0; i < index && retVal != mats.end(); i++, retVal++);

	return retVal;
}

const MaterialList& Materialed::materials() const {
	return mats;
}

void Materialed::materialDopped(size_t index, const MaterialBase* material) const {
}

} /* namespace Graphics */
} /* namespace Gremlin */
