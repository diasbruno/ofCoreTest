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
	
	ofVec3( T _x, T _y, T _z )
	: x(_x), y(_y), z(_z) 
	{}
	
	ofVec3( const of::ofVec3<T>& v )
	: x(v.x), y(v.y), z(v.z) 
	{}
	
	template<typename S>
	ofVec3( const ofVec2<S>& v ) 
	: x((T)v.x), y((T)v.y), z(0) 
	{}
		
	// Equality -----------------------------------------------
		
	bool operator == ( const ofVec3<T>& v ) const;
	bool operator != ( const ofVec3<T>& v ) const;
	bool match( const ofVec3<T>& vec, T tolerance ) const;

	// Operators ----------------------------------------------
    
	template<typename S>
    ofVec3<T>  operator +  ( const ofVec3<S>& pnt ) const;
	template<typename S>
    ofVec3<T>& operator += ( const ofVec3<S>& pnt );
	template<typename S>
    ofVec3<T>  operator -  ( const ofVec3<S>& vec ) const;
	template<typename S>
	ofVec3<T>& operator -= ( const ofVec3<S>& vec );
	template<typename S>
    ofVec3<T>  operator *  ( const ofVec3<S>& vec ) const;
	template<typename S>
    ofVec3<T>& operator *= ( const ofVec3<S>& vec );
	template<typename S>
    ofVec3<T>  operator /  ( const ofVec3<S>& vec ) const;
	template<typename S>
    ofVec3<T>& operator /= ( const ofVec3<S>& vec );
	template<typename S>
    ofVec3<T>  operator -  () const;
	
	template<typename S>
    ofVec3<T>  operator +  ( const S f ) const;
	template<typename S>
    ofVec3<T>& operator += ( const S f );
	template<typename S>
 	ofVec3<T>  operator -  ( const S f ) const;
	template<typename S>
    ofVec3<T>& operator -= ( const S f );
	template<typename S>
	ofVec3<T>  operator *  ( const S f ) const;
	template<typename S>
    ofVec3<T>& operator *= ( const S f );
	template<typename S>
    ofVec3<T>  operator /  ( const S f ) const;
	template<typename S>
    ofVec3<T>& operator /= ( const S f );
	
	// Setters ------------------------------------------------
	
	void set( T _scalar );
	void set( T _x, T _y, T _z );
	void set( const ofVec3<T>& v );

    // Methods ------------------------------------------------

    bool isAligned( const ofVec3<T>& vec, float tolerance ) const;
    bool align( const ofVec3<T>& vec, float tolerance ) const;
    bool isAlignedRad( const ofVec3<T>& vec, float tolerance ) const;
    bool alignRad( const ofVec3<T>& vec, float tolerance ) const;

    // ios stream ---------------------------------------------
    
	template <typename S>
    friend ostream& operator<<( ostream& os, const ofVec3<S>& v );
    template <typename S>
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
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator+( const ofVec3<S>& pnt ) const {
	return ofVec3<T>( x+(S)pnt.x, y+(S)pnt.y, z+(S)pnt.z );
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator+=( const ofVec3<S>& pnt ) {
	x += (S)pnt.x;
	y += (S)pnt.y;
	z += (S)pnt.z;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator-( const ofVec3<S>& vec ) const {
	return ofVec3<T>( x-vec.x, y-vec.y, z-vec.z );
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator-=( const ofVec3<S>& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator*( const ofVec3<S>& vec ) const {
	return ofVec3<T>( x*vec.x, y*vec.y, z*vec.z );
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator*=( const ofVec3<S>& vec ) {
	x*=vec.x;
	y*=vec.y;
	z*=vec.z;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator/( const ofVec3<S>& vec ) const {
	return ofVec3<T>( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z );
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator/=( const ofVec3<S>& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator-() const {
	return ofVec3<T>( -x, -y, -z );
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator+( const S f ) const {
	return ofVec3<T>( x+f, y+f, z+f);
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator+=( const S f ) {
	x += f;
	y += f;
	z += f;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator-( const S f ) const {
	return ofVec3<T>( x-f, y-f, z-f);
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator-=( const S f ) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator*( const S f ) const {
	return ofVec3<T>( x*f, y*f, z*f );
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator*=( const S f ) {
	x*=f;
	y*=f;
	z*=f;
	return *this;
}

template<typename T>
template<typename S>
inline 
ofVec3<T> ofVec3<T>::operator/( const S f ) const {
	if(f == 0) return ofVec3<T>( x, y, z);
	
	return ofVec3<T>( x/f, y/f, z/f );
}

template<typename T>
template<typename S>
inline 
ofVec3<T>& ofVec3<T>::operator/=( const S f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	z/=f;
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
void ofVec3<T>::set( T _x, T _y, T _z ) {
	x = _x;
	y = _y;
	z = _z;
}

/*! */
template<typename T>
void ofVec3<T>::set( const ofVec3<T>& v ) {
	x = v.x;
	y = v.y;
	z = v.z;
}

	
// Methods -------------------------------------------------------



// 

template<typename T, typename S>
inline 
ostream& operator<<( ostream& os, const ofVec3<S>& v ) {
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

template<typename T, typename S>
inline 
istream& operator>>( istream& is, ofVec3<S>& v ) {
	is >> (T)v.x;
	is.ignore(2);
	is >> (T)v.y;
	is.ignore(2);
	is >> (T)v.z;
	return is;
}

}
