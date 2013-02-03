#pragma once

#include <cmath>
#include <iostream>

#include "ofVecT.h"
#include "ofVec2.h"

namespace of {

template<typename T>
class ofVec3 
	: public ofVecT<T> {
public:
	T x, y, z;
	
	static const int DIM = 3;
	
	ofVec3()
	: x(0), y(0), z(0) 
	{}
	
	ofVec3( T cx, T cy, T cz )
	: x(cx), y(cy), z(cz) 
	{}
	
	ofVec3( const ofVec3<T>& v )
	: x(v.x), y(v.y), z(v.z) 
	{}
	
	ofVec3( const ofVec2<T>& v ) 
	: x(v.x), y(v.y), z(0) 
	{}
		
	// Equality -----------------------------------------------
		
	bool operator == ( const ofVec3<T>& v ) const;
	bool operator != ( const ofVec3<T>& v ) const;
	bool match( const ofVec3<T>& vec, T tolerance ) const;

	// Operators ----------------------------------------------
    
    ofVec3<T>  operator +  ( const ofVec3<T>& v ) const;
    ofVec3<T>& operator += ( const ofVec3<T>& v );
    ofVec3<T>  operator -  ( const ofVec3<T>& v ) const;
	ofVec3<T>& operator -= ( const ofVec3<T>& v );
    ofVec3<T>  operator *  ( const ofVec3<T>& v ) const;
    ofVec3<T>& operator *= ( const ofVec3<T>& v );
    ofVec3<T>  operator /  ( const ofVec3<T>& v ) const;
    ofVec3<T>& operator /= ( const ofVec3<T>& v );
    ofVec3<T>  operator -  () const;
	
    ofVec3<T>  operator +  ( const T s ) const;
    ofVec3<T>& operator += ( const T s );
 	ofVec3<T>  operator -  ( const T s ) const;
    ofVec3<T>& operator -= ( const T s );
	ofVec3<T>  operator *  ( const T s ) const;
    ofVec3<T>& operator *= ( const T s );
    ofVec3<T>  operator /  ( const T s ) const;
    ofVec3<T>& operator /= ( const T s );
	
	// Setters ------------------------------------------------
	
	void set( T _scalar );
	void set( T _x, T _y, T _z );
	void set( const ofVec3<T>& v );

    // Methods ------------------------------------------------

    bool isAligned( const ofVec3<T>& v, float tolerance ) const;
    bool align( const ofVec3<T>& v, float tolerance ) const;
    bool isAlignedRad( const ofVec3<T>& v, float tolerance ) const;
    bool alignRad( const ofVec3<T>& v, float tolerance ) const;

    // ios stream ---------------------------------------------
    
	template<typename S>
    friend ostream& operator<<( ostream& os, const ofVec3<S>& v );
	template<typename S>
	friend istream& operator>>( istream& is, ofVec3<S>& v );
};

//
// ----------------------------------------------------------------
//

// Equality -------------------------------------------------------

template<typename T>
inline
bool ofVec3<T>::operator==( const ofVec3<T>& v ) const {
	return x == v.x 
		&& y == v.y
		&& z == v.z;
}

template<typename T>
inline
bool ofVec3<T>::operator!=( const ofVec3<T>& v ) const {
	return x != v.x 
        || y != v.y
        || z != v.z;
}

template<typename T>
inline
bool ofVec3<T>::match( const ofVec3<T>& v, T tolerance ) const {
	 return fabs(x - v.x) < tolerance 
		 && fabs(y - v.y) < tolerance 
		 && fabs(z - v.z) < tolerance;
}


// Operators -------------------------------------------------------

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator+( const ofVec3<T>& v ) const {
	return ofVec3<T>( x + v.x, y + v.y, z + v.z );
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator+=( const ofVec3<T>& v ) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator-( const ofVec3<T>& v ) const {
	return ofVec3<T>( x - v.x, y - v.y, z - v.z );
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator-=( const ofVec3<T>& v ) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator*( const ofVec3<T>& v ) const {
	return ofVec3<T>( x * v.x, y * v.y, z * v.z );
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator*=( const ofVec3<T>& v ) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator/( const ofVec3<T>& v ) const {
	return ofVec3<T>( v.x!=0 ? x/v.x : x , v.y!=0 ? y/v.y : y, v.z!=0 ? z/v.z : z );
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator/=( const ofVec3<T>& v ) {
	v.x != 0 ? x /= v.x : x;
	v.y != 0 ? y /= v.y : y;
	v.z != 0 ? z /= v.z : z;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator-() const {
	return ofVec3<T>( -x, -y, -z );
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator+( const T s ) const {
	return ofVec3<T>( x + s, y + s, z + s);
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator+=( const T s ) {
	x += s;
	y += s;
	z += s;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator-( const T s ) const {
	return ofVec3<T>( x-s, y-s, z-s);
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator-=( const T s ) {
	x -= s;
	y -= s;
	z -= s;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator*( const T s ) const {
	return ofVec3<T>( x*s, y*s, z*s );
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator*=( const T s ) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

template<typename T>
inline 
ofVec3<T> ofVec3<T>::operator/( const T s ) const {
	if( s == 0 ) return ofVec3<T>( x, y, z);
	
	return ofVec3<T>( x / s, y / s, z / s );
}

template<typename T>
inline 
ofVec3<T>& ofVec3<T>::operator/=( const T s ) {
	if(s == 0) return *this;
	
	x /= s;
	y /= s;
	z /= s;
	return *this;
}


// Setters --------------------------------------------------------

/*! */
template<typename T>
void ofVec3<T>::set( T _scalar ) {
	x = _scalar;
	y = _scalar;
	z = _scalar;
}

/*! */
template<typename T>
void ofVec3<T>::set( T cx, T cy, T cz ) {
	x = cx;
	y = cy;
	z = cz;
}

/*! */
template<typename T>
void ofVec3<T>::set( const ofVec3<T>& v ) {
	x = v.x;
	y = v.y;
	z = v.z;
}

	
// Methods -------------------------------------------------------

template<typename S>
inline 
ostream& operator<<( ostream& os, const ofVec3<S>& v ) {
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

template<typename S>
inline 
istream& operator>>( istream& is, ofVec3<S>& v ) {
	is >> v.x;
	is.ignore(2);
	is >> v.y;
	is.ignore(2);
	is >> v.z;
	return is;
}

}
