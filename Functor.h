/*
 * Functor.h
 *
 *  Created on: 15/07/2011
 *      Author: Mariano
 */

#include "MFunctor.h"
#pragma once

// Base class definition to specialize templates
template<typename Signature>
class _Functor {
};

// Static functor 0, and wrapper of member functors
template<class R>
class _Functor<R(*)()> {

private:

	typedef R(*Signature)();
	MFunctor0<R> * mFunctor;
	Signature staticFunction;
	bool member;

public:

	// This constructor wraps member functor
	template<class T>
	_Functor(T * object, R(T::*fPointer)()) {
		this->mFunctor = new _MFunctor<R(T::*)()> (object, fPointer);
		this->member = true;
	}

	_Functor(Signature f) {
		this->staticFunction = f;
		this->member = false;
	}

	// Call function or functor, depending on wrapped data
	R operator()() {
		if (member)
			return mFunctor->operator()();
		else
			return staticFunction();
	}
};

// Static functor 1, and wrapper of member functors
template<class R, class A1>
class _Functor<R(*)(A1)> {

private:

	typedef R(*Signature)(A1);
	MFunctor1<R, A1> * mFunctor;
	Signature staticFunction;
	bool member;

public:

	// This constructor wraps member functor
	template<class T>
	_Functor(T * object, R(T::*fPointer)(A1)) {
		this->mFunctor = new _MFunctor<R(T::*)(A1)> (object, fPointer);
		this->member = true;
	}

	_Functor(Signature f) {
		this->staticFunction = f;
		this->member = false;
	}

	// Call function or functor, depending on wrapped data
	R operator()(const A1& a) {
		if (member)
			return mFunctor->operator()(a);
		else
			return staticFunction(a);
	}
};

// Static functor 2, and wrapper of member functors
template<class R, class A1, class A2>
class _Functor<R(*)(A1, A2)> {

private:

	typedef R(*Signature)(A1, A2);
	MFunctor2<R, A1, A2> * mFunctor;
	Signature staticFunction;
	bool member;

public:

	// This constructor wraps member functor
	template<class T>
	_Functor(T * object, R(T::*fPointer)(A1, A2)) {
		this->mFunctor = new _MFunctor<R(T::*)(A1, A2)> (object, fPointer);
		this->member = true;
	}

	_Functor(Signature f) {
		this->staticFunction = f;
		this->member = false;
	}

	// Call function or functor, depending on wrapped data
	R operator()(const A1& a, const A2& b) {
		if (member)
			return mFunctor->operator()(a, b);
		else
			return staticFunction(a, b);
	}
};

// Static functor 3, and wrapper of member functors
template<class R, class A1, class A2, class A3>
class _Functor<R(*)(A1, A2, A3)> {

private:

	typedef R(*Signature)(A1, A2, A3);
	MFunctor3<R, A1, A2, A3> * mFunctor;
	Signature staticFunction;
	bool member;

public:

	// This constructor wraps member functor
	template<class T>
	_Functor(T * object, R(T::*fPointer)(A1, A2, A3)) {
		this->mFunctor = new _MFunctor<R(T::*)(A1, A2, A3)> (object, fPointer);
		this->member = true;
	}

	_Functor(Signature f) {
		this->staticFunction = f;
		this->member = false;
	}

	// Call function or functor, depending on wrapped data
	R operator()(const A1& a, const A2& b, const A3& c) {
		if (member)
			return mFunctor->operator()(a, b, c);
		else
			return staticFunction(a, b, c);
	}
};

