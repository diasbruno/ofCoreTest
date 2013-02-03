#pragma once

#include "ofVecT.h"
#include "ofVec3.h"

namespace of {

template<typename T>
class ofVec4 
	: public ofVecT<T> {
public:
	T x, y, z, w;
	
	static const int DIM = 4;
	
	ofVec4()
	: x(0), y(0), z(0), w(0) 
	{}
	
	ofVec4( T _x, T _y, T _z, T _w ) 
	: x(_x), y(_y), z(_z), w(_w) 
	{}
	
	ofVec4( const ofVec4<T>& v ) 
	: x(v.x), y(v.y), z(v.z), w(v.w)
    {}

    template<typename S>
	ofVec4( const ofVec3<S>& v ) 
	: x((T)v.x), y((T)v.y), z((T)v.z), w(0)
	{}
	
	// Equality -----------------------------------------------
	
	bool operator == ( const ofVec4<T>& v ) const;
	bool operator != ( const ofVec4<T>& v ) const;
	bool match( const ofVec4<T>& v, T tolerance ) const;

	// Operators -----------------------------------------------

    ofVec4<T>  operator +  ( const ofVec4<T>& v ) const;
    ofVec4<T>& operator += ( const ofVec4<T>& v );
    ofVec4<T>  operator -  ( const T s ) const;
    ofVec4<T>& operator -= ( const T s );
    ofVec4<T>  operator -  ( const ofVec4<T>& v ) const;
    ofVec4<T>& operator -= ( const ofVec4<T>& v );
    ofVec4<T>  operator +  ( const T s ) const;
    ofVec4<T>& operator += ( const T s );
    ofVec4<T>  operator -  () const;
	
    ofVec4<T>  operator *  ( const ofVec4<T>& v ) const;
    ofVec4<T>& operator *= ( const ofVec4<T>& v );
    ofVec4<T>  operator *  ( const T s ) const;
    ofVec4<T>& operator *= ( const T s );
    ofVec4<T>  operator /  ( const ofVec4<T>& v ) const;
    ofVec4<T>& operator /= ( const ofVec4<T>& v );
    ofVec4<T>  operator /  ( const T s ) const;
    ofVec4<T>& operator /= ( const T s );	

	// Setters ------------------------------------------------
	
	void set( T _scalar );
	void set( T _x, T _y, T _z, T _w );
	void set( const ofVec4<T>& v );
};

//
// ---------------------------------------------------------------------------
//


// Equality -------------------------------------------------------------------

template <typename T>
inline
bool ofVec4<T>::operator == ( const ofVec4<T> & v ) const {
	return x == v.x 
		&& y == v.y;
}

template <typename T>
inline
bool ofVec4<T>::operator != ( const ofVec4<T> & v ) const {
	return x != v.x 
		|| y != v.y;
}

//TODO: need test.
template <typename T>
inline
bool ofVec4<T>::match( const ofVec4<T>& v, T tolerance ) const {
	return fabs(x - v.x) < tolerance 
		&& fabs(y - v.y) < tolerance;
}


// Operators -----------------------------------------------------------------
	
template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator+( const ofVec4<T>& v ) const {
	return ofVec4<T>( x+v.x, y+v.y, z+v.z, w+v.w);
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator+=( const ofVec4<T>& v ) {
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator-( const T s ) const {
	return ofVec4<T>( x-s, y-s, z-s, w-s );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator-=( const T s ) {
	x -= s;
	y -= s;
	z -= s;
	w -= s;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator-( const ofVec4<T>& v ) const {
	return ofVec4<T>( x-v.x, y-v.y, z-v.z, w-v.w );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator-=( const ofVec4<T>& v ) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator+( const T s ) const {
	return ofVec4<T>( x+s, y+s, z+s, w+s );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator+=( const T s ) {
	x += s;
	y += s;
	z += s;
	w += s;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator-() const {
	return ofVec4<T>( -x, -y, -z, -w );
}


template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator*( const ofVec4<T>& v ) const {
	return ofVec4<T>( x*v.x, y*v.y, z*v.z, w*v.w );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator*=( const ofVec4<T>& v ) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator*( const T s ) const {
	return ofVec4<T>( x*s, y*s, z*s, w*s );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator*=( const T s ) {
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator/( const ofVec4<T>& v ) const {
	return ofVec4<T>( 
                v.x!=0 ? x/v.x : x , 
                v.y!=0 ? y/v.y : y, 
                v.z!=0 ? z/v.z : z, 
                v.w!=0 ? w/v.w : w  
           );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator/=( const ofVec4<T>& vec ) {
	vec.x != 0 ? x/=vec.x : x;
	vec.y != 0 ? y/=vec.y : y;
	vec.z != 0 ? z/=vec.z : z;
	vec.w != 0 ? w/=vec.w : w;
	return *this;
}

template <typename T>
inline 
ofVec4<T> ofVec4<T>::operator/( const T s ) const {
	if(s == 0) return ofVec4<T>(x, y, z, w);
	
	return ofVec4<T>( x/s, y/s, z/s, w/s );
}

template <typename T>
inline 
ofVec4<T>& ofVec4<T>::operator/=( const T s ) {
	if(s == 0)return *this;
	
	x /= s;
	y /= s;
	z /= s;
	w /= s;
	return *this;
}


// Setters -------------------------------------------------------------

/*! */
template<typename T>
void ofVec4<T>::set( T _scalar ) {
	x = _scalar;
	y = _scalar;
	z = _scalar;
	w = _scalar;
}

/*! */
template<typename T>
void ofVec4<T>::set( T _x, T _y, T _z, T _w ) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

/*! */
template<typename T>
void ofVec4<T>::set( const ofVec4<T>& v ) {
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

}
