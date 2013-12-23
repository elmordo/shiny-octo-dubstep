/*
 * Materialed.hpp
 *
 *  Created on: 30.8.2013
 *      Author: petr
 */

#ifndef MATERIALED_HPP_
#define MATERIALED_HPP_

#include<MaterialBase.hpp>
#include<cstddef>

using namespace std;
using namespace Gremlin::Materials;

namespace Gremlin {
namespace Graphics {

class Materialed {

	MaterialList mats;

	/**
	 * naiteruje na prislusny index mats a vraci iterator
	 * pokud iterator neexistuje, vraci end()
	 */
	MaterialList::iterator iterateToIndex(size_t index);
	MaterialList::const_iterator iterateToIndex(size_t index) const;

protected:

	/**
	 * metoda slozici k pozdejsimu prepsani
	 * metoda je volana po smazani materialu
	 */
	virtual void materialDopped(size_t index, const MaterialBase *material) const;

public:

	/**
	 * bezparametricky konstruktor
	 */
	Materialed();

	/**
	 * kopytor
	 */
	Materialed(const Materialed &o);

	/**
	 * destruktor
	 */
	virtual ~Materialed();

	/**
	 * prida material do seznamu
	 */
	size_t addMaterial(const MaterialBase *material);

	/**
	 * odebere material
	 */
	void dropMaterial(size_t index);

	/**
	 * vraci material dle indexu
	 * pokud index neexistuje, vraci 0x0
	 */
	const MaterialBase *getMaterial(size_t index) const;

	/**
	 * vraci seznam materialu
	 */
	virtual const MaterialList &materials() const;


};

} /* namespace Graphics */
} /* namespace Gremlin */
#endif /* MATERIALED_HPP_ */
