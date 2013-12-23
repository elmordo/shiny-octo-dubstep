/*
 * LightBase.hpp
 *
 *  Created on: 18.9.2013
 *      Author: petr
 */

#ifndef LIGHTBASE_HPP_
#define LIGHTBASE_HPP_

#include "GraphicData.hpp"
#include <Color.hpp>

using namespace Gremlin::Materials;

namespace Gremlin {
namespace Materials {

class LightBase: public Gremlin::Graphics::GraphicData {

	/**
	 * ambientni barva
	 */
	Color ac;

	/**
	 * difusni barva
	 */
	Color dc;

	/**
	 * index svetla (GL_LIGHTx)
	 */
	GLfloat i;

	/**
	 * koeficient konstantiho ubytku
	 */
	GLfloat k;

	/**
	 * koeficient linearniho ubytku
	 */
	GLfloat l;

	/**
	 * koeficient kvadratickeho ubytku
	 */
	GLfloat q;

	/**
	 * spekularni barva
	 */
	Color sc;

protected:

	/**
	 * nastavi standardni parametry do openGl
	 */
	void setParameters() const;

public:

	/**
	 * vychozi nastaveni koeficientu utlumu
	 */
	static const GLfloat DEFAULT_CONSTANT;
	static const GLfloat DEFAULT_LINEAR;
	static const GLfloat DEFAULT_QUADRATIC;

	/**
	 * vytvori bile svetlo
	 */
	LightBase();

	/**
	 * nastavi barvu svetla
	 */
	LightBase(const Color &ambient, const Color &diffuse, const Color &specular);

	/**
	 * nastavi barvu a koeficienty utlumu
	 */
	LightBase(const Color &ambient, const Color &diffuse, const Color &specular, GLfloat k, GLfloat l, GLfloat q);

	/**
	 * kopytor
	 */
	LightBase(const LightBase &o);

	/**
	 * destruktor
	 */
	virtual ~LightBase();

	/**
	 * prace s ambientni slozkou
	 */
	void ambient(const Color &c);
	const Color &ambient() const;

	/**
	 * vraci/nastavi konstantni utlum
	 */
	void constant(GLfloat v);
	GLfloat constant() const;

	/**
	 * prace s difusni slozkou
	 */
	void diffuse(const Color &c);
	const Color &diffuse() const;

	/**
	 * nastavi/varti index svetla
	 */
	void index(GLenum i);
	GLenum index() const;

	/**
	 * vraci/nastavi linearni utlum
	 */
	void linear(GLfloat v);
	GLfloat linear() const;

	/**
	 * vraci/nastavi kvadratickou slozku
	 */
	void quadratic(GLfloat v);
	GLfloat quadratic() const;

	/**
	 * prace s reflexni slozkou
	 */
	void specular(const Color &c);
	const Color &specular() const;
};

} /* namespace Materials */
} /* namespace Gremlin */
#endif /* LIGHTBASE_HPP_ */
