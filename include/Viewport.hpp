/*
 * Viewport.hpp
 *
 *  Created on: 30.10.2013
 *      Author: petr
 */

#ifndef VIEWPORT_HPP_
#define VIEWPORT_HPP_

#include<GL/gl.h>
#include "Camera.hpp"

namespace Gremlin {
namespace Utils {

class Viewport {

	/**
	 * vyska
	 */
	GLsizei h;

	/**
	 * sirka
	 */
	GLsizei w;

	/**
	 * souradnice x
	 */
	GLint cx;

	/**
	 * souradnice y
	 */
	GLint cy;

public:

	static const GLsizei STANDARD_HEIGHT;
	static const GLsizei STANDARD_WIDTH;
	static const GLint STANDARD_X;
	static const GLint STANDARD_Y;

	/**
	 * nastavi zakladni data
	 */
	Viewport();

	/**
	 * nastavi visku, sirku a pozici vykreslovaciho prostoru
	 */
	Viewport(GLsizei width, GLsizei height, GLint x, GLint y);

	/**
	 * kopytor
	 */
	Viewport(const Viewport &o);

	/**
	 * desturktor
	 */
	virtual ~Viewport();

	/**
	 * vytvori kameru pro tento pohled a vraci jeji instanci
	 */
	Camera camera() const;

	/**
	 * vraci / nastavi vysku
	 */
	GLsizei height() const;
	void height(GLsizei h);

	/**
	 * nastavi viewport do OpenGL
	 */
	void setup() const;

	/**
	 * vraci / nastavi sirku
	 */
	GLsizei width() const;
	void width(GLsizei w);

	/**
	 * vraci / nastavi souradnici x
	 */
	GLint x() const;
	void x(GLint x);

	/**
	 * vraci / nastavi souradnici y
	 */
	GLint y() const;
	void y(GLint y);
};

} /* namespace Utils */
} /* namespace Gremlin */
#endif /* VIEWPORT_HPP_ */
