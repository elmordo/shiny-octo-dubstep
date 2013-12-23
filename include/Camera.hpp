/*
 * Camera.hpp
 *
 *  Created on: 22.10.2013
 *      Author: petr
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include<GL/glu.h>
#include<Vector3D.hpp>
#include<Transform3D.hpp>

using namespace Gremlin::Math;

namespace Gremlin {
namespace Utils {

class Camera {

	/**
	 * transformacni matice
	 */
	Transform3Df m;

	/**
	 * pomer stran obrazu
	 */
	GLdouble a;

	/**
	 * uhel zaberu kamery na ose YZ
	 */
	GLdouble t;

	/**
	 * vzdalenost k blizsi plose
	 */
	GLdouble n;

	/**
	 * vzdalenost ke vzdalenejsi plose
	 */
	GLdouble f;

public:

	static const GLfloat STANDARD_ASPECT;
	static const GLfloat STANDARD_THETA;
	static const GLfloat STANDARD_NEAR;
	static const GLfloat STANDARD_FAR;

	/**
	 * standardni konstruktor
	 */
	Camera();

	/**
	 * copytor
	 */
	Camera(const Camera &o);

	/**
	 * destruktor
	 */
	virtual ~Camera();

	/**
	 * vraci / nastavi pomer stran
	 */
	GLdouble aspect() const;
	void aspect(GLdouble a);

	/**
	 * vraci / nastavi vzdalenou rovinu
	 */
	GLdouble far() const;
	void far(GLdouble f);

	/**
	 * vraci / nastavi mistni rovinu
	 */
	GLdouble near() const;
	void near(GLdouble n);

	/**
	 * vraci vektor, kam smeruje kamera
	 */
	Vector3D<GLfloat> lookingAt() const;

	/**
	 * vraci transformacni matici kamery
	 */
	const Transform3Df &matrix() const;
	Transform3Df &matrix();

	/**
	 * provede rotaci dle osy
	 */
	void rotateX(GLfloat a);
	void rotateY(GLfloat a);
	void rotateZ(GLfloat a);

	/**
	 * nastavi parametry kamery do jadra opengl
	 */
	void setup();

	/**
	 * vraci / nastavi uhel kamery
	 */
	GLdouble theta() const;
	void theta(GLdouble t);

	/**
	 * vraci aktualni bod, kde se kamera nachazi
	 */
	Point3Df translation() const;

	/**
	 * provede posunuti pomoci slozek vektoru
	 * posun je proveden ve smeru pohledu
	 */
	void translate(GLfloat dx, GLfloat dy, GLfloat dz);

	/**
	 * provede posunuti pouze v jednom smeru
	 * posun je proveden ve smeru pohledu
	 */
	void translateX(GLfloat d);
	void translateY(GLfloat d);
	void translateZ(GLfloat d);
};

} /* namespace Utils */
} /* namespace Gremlin */
#endif /* CAMERA_HPP_ */
