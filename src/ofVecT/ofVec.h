#pragma once

#include "ofVecT.h"
#include "ofVec2.h"
#include "ofVec3.h"
#include "ofVec4.h"

namespace of { // using namespace to avoid conflicts.

/*!
 
 Definition:
 
 ofVec2 should mean 'untyped vector 2d'.  ofVec2<T> - the missing type.
 ofVec2f should mean 'vector 2d with float type'.
 
 */

// Pre-defined types.
typedef ofVec2<int>    ofVec2i;
typedef ofVec2<float>  ofVec2f;
typedef ofVec2<double> ofVec2d;

typedef ofVec3<int>    ofVec3i;
typedef ofVec3<float>  ofVec3f;
typedef ofVec3<double> ofVec3d;

typedef ofVec4<int>    ofVec4i;
typedef ofVec4<float>  ofVec4f;
typedef ofVec4<double> ofVec4d;

// Non-Member operators

// Vec2<T>

template<typename T>
inline ofVec2<T> operator+( T f, const ofVec2<T>& vec ) {
    return ofVec2<T>( f+vec.x, f+vec.y);
}

template<typename T>
inline ofVec2<T> operator-( T f, const ofVec2<T>& vec ) {
    return ofVec2<T>( f-vec.x, f-vec.y);
}

template<typename T>
inline ofVec2<T> operator*( T f, const ofVec2<T>& vec ) {
    return ofVec2<T>( f*vec.x, f*vec.y);
}

template<typename T>
inline ofVec2<T> operator/( T f, const ofVec2<T>& vec ) {
    return ofVec2<T>( f/vec.x, f/vec.y);
}

// Vec3<T>

template<typename T>
inline ofVec3<T> operator+( T s, const ofVec3<T>& v ) {
    return ofVec3<T>( s+v.x, s+v.y, s+v.z, s+v.w );
}

template<typename T>
inline ofVec3<T> operator-( T s, const ofVec3<T>& v ) {
    return ofVec3<T>( s-v.x, s-v.y, s-v.z, s-v.w );
}

template<typename T>
inline ofVec3<T> operator*( T s, const ofVec3<T>& v ) {
    return ofVec3<T>( s*v.x, s*v.y, s*v.z, s*v.w );
}

template<typename T>
inline ofVec3<T> operator/( T s, const ofVec3<T>& v ) {
    return ofVec3<T>( s/v.x, s/v.y, s/v.z, s/v.w);
}

// Vec4<T>

template<typename T>
inline ofVec4<T> operator+( T f, const ofVec4<T>& vec ) {
    return ofVec4<T>( f+vec.x, f+vec.y, f+vec.z, f+vec.w );
}

template<typename T>
inline ofVec4<T> operator-( T f, const ofVec4<T>& vec ) {
    return ofVec4<T>( f-vec.x, f-vec.y, f-vec.z, f-vec.w );
}

template<typename T>
inline ofVec4<T> operator*( T f, const ofVec4<T>& vec ) {
    return ofVec4<T>( f*vec.x, f*vec.y, f*vec.z, f*vec.w );
}

template<typename T>
inline ofVec4<T> operator/( T f, const ofVec4<T>& vec ) {
    return ofVec4<T>( f/vec.x, f/vec.y, f/vec.z, f/vec.w);
}

}
