#pragma once

/*!
 
 Definition:
 
 ofVec2 should mean 'untyped vector 2d'.  ofVec2<T> - the missing type.
 ofVec2f should mean 'vector 2d with float type'.
 
 */
#include "_ofVec2.h"
#include "_ofVec3.h"
#include "_ofVec4.h"
#include "_ofVecMath.h"

// Pre-defined types.

typedef _ofVec2<int>    _ofVec2i;
typedef _ofVec2<float>  _ofVec2f;
typedef _ofVec2<double> _ofVec2d;

typedef _ofVec3<int>    _ofVec3i;
typedef _ofVec3<float>  _ofVec3f;
typedef _ofVec3<double> _ofVec3d;

typedef _ofVec4<int>    _ofVec4i;
typedef _ofVec4<float>  _ofVec4f;
typedef _ofVec4<double> _ofVec4d;