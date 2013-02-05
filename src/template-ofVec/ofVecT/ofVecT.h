#pragma once

#include <cmath>
#include <iostream>

#include "ofConstants.h"

namespace of {
	
template<typename T>
class ofVecT {
public:
	T x;
	// T* x[ DIM ] ?
	
	static const int DIM = 1;
	
	ofVecT()
	: x(0) {}
	
	ofVecT( T _x )
	: x(_x) {}
	
	// Accessors ------------------------------------
	
	T* getPtr() {
		return (T*)&x;
	}
	const T* getPtr() const {
		return (const T*)&x;
	}
	
	T& operator[]( int n ){
		return getPtr()[n];
	}
	
	T operator[]( int n ) const {
		return getPtr()[n];
	}
	
};
	
}
