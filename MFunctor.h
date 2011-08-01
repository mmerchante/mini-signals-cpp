/*
 * MFunctor.h
 *
 *  Created on: 15/07/2011
 *      Author: Mariano
 */

#pragma once

// Base class definition of member functor 0 to hide signature specialization
template<class R>
class MFunctor0 {
public:
	virtual R operator()() = 0;
};

// Base class definition of member functor 1 to hide signature specialization
template<class R, class A1>
class MFunctor1 {
public:
	virtual R operator()(const A1& a) = 0;
};

// Base class definition of member functor 2 to hide signature specialization
template<class R, class A1, class A2>
class MFunctor2 {
public:
	virtual R operator()(const A1& a, const A2& b) = 0;
};

// Base class definition of member functor 3 to hide signature specialization
template<class R, class A1, class A2, class A3>
class MFunctor3 {
public:
	virtual R operator()(const A1& a, const A2& b, const A3& c) = 0;
};

// Base class definition to specialize member functor templates
template<typename Signature>
class _MFunctor {
};

// Member Functor 0
template<class T, class R>
class _MFunctor<R(T::*)()> : public MFunctor0<R> {
private:

	typedef R(T::*Signature)();
	T * t;
	Signature f;

public:

	_MFunctor(T * t, Signature f) :
		MFunctor0<R> (), t(t), f(f) {
	}

	R operator()() {
		return (t->*f)();
	}

};

// Member Functor 1
template<class T, class R, class A1>
class _MFunctor<R(T::*)(A1)> : public MFunctor1<R, A1> {
private:

	typedef R(T::*Signature)(A1);
	T * t;
	Signature f;

public:

	_MFunctor(T * t, Signature f) :
		MFunctor1<R, A1> (), t(t), f(f) {
	}

	R operator()(const A1& a) {
		return (t->*f)(a);
	}

};

// Member Functor 2
template<class T, class R, class A1, class A2>
class _MFunctor<R(T::*)(A1, A2)> : public MFunctor2<R, A1, A2> {
private:

	typedef R(T::*Signature)(A1, A2);
	T * t;
	Signature f;

public:

	_MFunctor(T * t, Signature f) :
		MFunctor2<R, A1, A2> (), t(t), f(f) {
	}

	R operator()(const A1& a, const A2& b) {
		return (t->*f)(a, b);
	}

};

// Member Functor 3
template<class T, class R, class A1, class A2, class A3>
class _MFunctor<R(T::*)(A1, A2, A3)> : public MFunctor3<R, A1, A2, A3> {
private:

	typedef R(T::*Signature)(A1, A2, A3);
	T * t;
	Signature f;

public:

	_MFunctor(T * t, Signature f) :
		MFunctor3<R, A1, A2, A3> (), t(t), f(f) {
	}

	R operator()(const A1& a, const A2& b, const A3& c) {
		return (t->*f)(a, b, c);
	}

};
