/*
 * GraphicData.hpp
 *
 *  Created on: 20.8.2013
 *      Author: petr
 */

#ifndef GRAPHICDATA_HPP_
#define GRAPHICDATA_HPP_

#include<cstddef>
#include<MaterialBase.hpp>
#include"Materialed.hpp"
#include"Box.hpp"

using namespace std;
using namespace Gremlin::Materials;

namespace Gremlin {
namespace Graphics {

/**
 * obecna trida pro uchovani ruznych grafickych dat
 */
class GraphicData : public Materialed {

	/**
	 * ohranicujici box
	 */
	Math::Box<GLfloat> b;

protected:

	/**
	 * vraci ohranicujici box
	 */
	Math::Box<GLfloat> &boundary();

public:

	/**
	 * standardni bezparametricky konstruktor
	 */
	GraphicData();

	/**
	 * kopytor
	 */
	GraphicData(const GraphicData &o);

	/**
	 * destruktor
	 */
	virtual ~GraphicData();

	/**
	 * vraci konstantni referenci na box
	 */
	const Math::Box<GLfloat>& boundary() const;

	/**
	 * vraci pocet materialu pouzitych v objektu
	 */
	virtual size_t materialCount() const = 0;

	/**
	 * vykresli data
	 */
	virtual void render(const MaterialMap &mats) const = 0;

};

} /* namespace Graphics */
} /* namespace Gremlin */
#endif /* GRAPHICDATA_HPP_ */
