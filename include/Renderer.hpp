/*
 * Renderer.hpp
 *
 *  Created on: 1.11.2013
 *      Author: petr
 */

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "Object.hpp"

#include <list>

namespace Gremlin {
namespace Graphics {

using namespace std;

struct RenderItem {

	/**
	 * objekt k vykresleni
	 */
	const Object *obj;

	/**
	 * prepinac k vykreslovani
	 */
	bool renderable;
};

class Renderer {
public:

	/**
	 * seznam objektu k vykresleni
	 */
	typedef list<RenderItem> RenderItems;

private:

	typedef vector<RenderItem*> SortedItems;

	/**
	 * seznam všech objektů k vykreslení
	 */
	RenderItems il;

	/**
	 * seznam objektu, ktere nejsou pruhledne
	 */
	SortedItems sil;

	/**
	 * seznam objektu, ktere jsou pruhledne
	 */
	SortedItems ail;

public:

	/**
	 * vytvori prazdnou instanci
	 */
	Renderer();

	/**
	 * kopytor
	 */
	Renderer(const Renderer &o);

	/**
	 * destruktor
	 */
	virtual ~Renderer();

	/**
	 * prida objekt do seznamu
	 */
	void addItem(const Object *obj);

	/**
	 * vraci seznam registrovanych objektu
	 */
	const RenderItems &items() const;

	/**
	 * odebere objekt ze seznamu
	 */
	void removeItem(const Object *obj);

	/**
	 * znovu rozdeli objekty na pruhledne a nepruhledne
	 */
	void resort();
};

} /* namespace Utils */
} /* namespace Gremlin */
#endif /* RENDERER_HPP_ */
