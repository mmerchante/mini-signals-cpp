/*
 * EventHandler.h
 *
 *  Created on: 13/07/2011
 *      Author: Mariano
 */

#pragma once

#include "MFunctor.h"
#include "Functor.h"
#include <list>
using std::list;

// Base signal declaration
template<class Signature> class Signal;

// Signal 0
template<class R>
class Signal<R()> {
private:
	typedef R(*Signature)();
	typedef class list<_Functor<Signature> >::iterator SlotIterator;

	list<_Functor<Signature> > slots;

public:

	Signal connect(Signature f) {
		this->slots.push_back(_Functor<Signature> (f));
		return *this;
	}

	template<class T>
	Signal connect(T * t, R(T::*fPointer)()) {
		_Functor<Signature> f(t, fPointer);
		this->slots.push_back(f);
		return *this;
	}

	int size() {
		return slots.size();
	}

	R operator()() {
		SlotIterator s;
		for (s = slots.begin(); s != slots.end(); s++) {
			class list<_Functor<Signature> >::iterator next = s;
			next++;
			if (next != slots.end())
				(*s)();
		}
		return slots.back()();
	}

};

// Signal 1
template<class R, class A1>
class Signal<R(A1)> {
private:
	typedef R(*Signature)(A1);
	typedef class list<_Functor<Signature> >::iterator SlotIterator;

	list<_Functor<Signature> > slots;

public:

	Signal connect(Signature f) {
		this->slots.push_back(_Functor<Signature> (f));
		return *this;
	}

	template<class T>
	Signal connect(T * t, R(T::*fPointer)(A1)) {
		_Functor<Signature> f(t, fPointer);
		this->slots.push_back(f);
		return *this;
	}

	int size() {
		return slots.size();
	}

	R operator()(const A1& a) {
		SlotIterator s;
		for (s = slots.begin(); s != slots.end(); s++) {
			class list<_Functor<Signature> >::iterator next = s;
			next++;
			if (next != slots.end())
				(*s)(a);
		}
		return slots.back()(a);
	}

};

// Signal 2
template<class R, class A1, class A2>
class Signal<R(A1, A2)> {
private:
	typedef R(*Signature)(A1, A2);
	typedef class list<_Functor<Signature> >::iterator SlotIterator;

	list<_Functor<Signature> > slots;

public:

	Signal connect(Signature f) {
		this->slots.push_back(_Functor<Signature> (f));
		return *this;
	}

	template<class T>
	Signal connect(T * t, R(T::*fPointer)(A1, A2)) {
		_Functor<Signature> f(t, fPointer);
		this->slots.push_back(f);
		return *this;
	}
	int size() {
		return slots.size();
	}

	R operator()(const A1& a, const A2&b) {
		SlotIterator s;
		for (s = slots.begin(); s != slots.end(); s++) {
			class list<_Functor<Signature> >::iterator next = s;
			next++;
			if (next != slots.end())
				(*s)(a, b);
		}
		return slots.back()(a, b);
	}

};

// Signal 3
template<class R, class A1, class A2, class A3>
class Signal<R(A1, A2, A3)> {
private:
	typedef R(*Signature)(A1, A2, A3);
	typedef class list<_Functor<Signature> >::iterator SlotIterator;

	list<_Functor<Signature> > slots;

public:

	Signal connect(Signature f) {
		this->slots.push_back(_Functor<Signature> (f));
		return *this;
	}

	template<class T>
	Signal connect(T * t, R(T::*fPointer)(A1, A2, A3)) {
		_Functor<Signature> f(t, fPointer);
		this->slots.push_back(f);
		return *this;
	}

	int size() {
		return slots.size();
	}

	R operator()(const A1& a, const A2& b, const A3& c) {
		SlotIterator s;
		for (s = slots.begin(); s != slots.end(); s++) {
			class list<_Functor<Signature> >::iterator next = s;
			next++;
			if (next != slots.end())
				(*s)(a, b, c);
		}
		return slots.back()(a, b, c);
	}

};
