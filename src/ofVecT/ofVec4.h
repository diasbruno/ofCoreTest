#pragma once

#include "ofVecT.h"

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

	
	// Equality -----------------------------------------------
	
    template <typename S>
	bool operator==( const ofVec4<S>& v ) const;
    template <typename S>
	bool operator!=( const ofVec4<S>& v ) const;
    template <typename S>
	bool match( const ofVec4<S>& vec, T tolerance ) const;

	// Operators -----------------------------------------------

    template<typename S>
    ofVec4<T>  operator +  ( const ofVec4<S>& vec ) const;
    template<typename S>
    ofVec4<T>& operator += ( const ofVec4<S>& vec );
    template<typename S>
    ofVec4<T>  operator -  ( const S f ) const;
    template<typename S>
    ofVec4<T>& operator -= ( const S f );
    template<typename S>
    ofVec4<T>  operator -  ( const ofVec4<S>& vec ) const;
    template<typename S>
    ofVec4<T>& operator -= ( const ofVec4<S>& vec );
    template<typename S>
    ofVec4<T>  operator +  ( const S f ) const;
    template<typename S>
    ofVec4<T>& operator += ( const S f );
    template<typename S>
    ofVec4<T>  operator -  () const;
	
    template<typename S>
    ofVec4<T>  operator *  ( const ofVec4<S>& vec ) const;
    template<typename S>
    ofVec4<T>& operator *= ( const ofVec4<S>& vec );
    template<typename S>
    ofVec4<T>  operator *  ( const S f ) const;
    template<typename S>
    ofVec4<T>& operator *= ( const S f );
    template<typename S>
    ofVec4<T>  operator /  ( const ofVec4<S>& vec ) const;
    template<typename S>
    ofVec4<T>& operator /= ( const ofVec4<S>& vec );
    template<typename S>
    ofVec4<T>  operator /  ( const S f ) const;
    template<typename S>
    ofVec4<T>& operator /= ( const S f );	

	// Setters ------------------------------------------------
	
	void set( T _scalar );
	void set( T _x, T _y, T _z, T _w );
	void set( const ofVec4<T>& vec );
};

//
// ---------------------------------------------------------------------------
//


// Equality -------------------------------------------------------------------

template <typename T>
template <typename S>
inline
bool ofVec4<T>::operator == ( const ofVec4<S> & v ) const {
	return x == (T)v.x 
		&& y == (T)v.y;
}

template <typename T>
template <typename S>
inline
bool ofVec4<T>::operator != ( const ofVec4<S> & v ) const {
	return x != (T)v.x 
		|| y != (T)v.y;
}

//TODO: need test.
template <typename T>
template <typename S>
inline
bool ofVec4<T>::match( const ofVec4<S>& v, T tolerance ) const {
	return fabs(x - v.x) < tolerance 
		&& fabs(y - v.y) < tolerance;
}


// Operators -----------------------------------------------------------------
	
template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator+( const ofVec4<S>& v ) const {
	return ofVec4<T>( x+v.x, y+v.y, z+v.z, w+v.w);
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator+=( const ofVec4<S>& v ) {
	x += (T)v.x;
	y += (T)v.y;
	z += (T)v.z;
	w += (T)v.w;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator-( const S s ) const {
	return ofVec4<T>( x-(T)s, y-(T)s, z-(T)s, w-(T)s );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator-=( const S s ) {
	x -= (T)s;
	y -= (T)s;
	z -= (T)s;
	w -= (T)s;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator-( const ofVec4<S>& v ) const {
	return ofVec4<T>( x-(T)v.x, y-(T)v.y, z-(T)v.z, w-(T)v.w );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator-=( const ofVec4<S>& v ) {
	x -= (T)v.x;
	y -= (T)v.y;
	z -= (T)v.z;
	w -= (T)v.w;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator+( const S s ) const {
	return ofVec4<T>( x+(T)s, y+(T)s, z+(T)s, w+(T)s );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator+=( const S s ) {
	x += (T)s;
	y += (T)s;
	z += (T)s;
	w += (T)s;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator-() const {
	return ofVec4<T>( -x, -y, -z, -w );
}


template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator*( const ofVec4<S>& v ) const {
	return ofVec4<T>( x*(T)v.x, y*(T)v.y, z*(T)v.z, w*(T)v.w );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator*=( const ofVec4<S>& v ) {
	x *= (T)v.x;
	y *= (T)v.y;
	z *= (T)v.z;
	w *= (T)v.w;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator*( const S s ) const {
	return ofVec4<T>( x*(T)s, y*(T)s, z*(T)s, w*(T)s );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator*=( const S s ) {
	x *= (T)s;
	y *= (T)s;
	z *= (T)s;
	w *= (T)s;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator/( const ofVec4<S>& v ) const {
	return ofVec4<T>( v.x!=0 ? x/(T)v.x : x , v.y!=0 ? y/(T)v.y : y, v.z!=0 ? z/(T)v.z : z, v.w!=0 ? w/(T)v.w : w  );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator/=( const ofVec4<S>& vec ) {
	vec.x != 0 ? x/=(T)vec.x : x;
	vec.y != 0 ? y/=(T)vec.y : y;
	vec.z != 0 ? z/=(T)vec.z : z;
	vec.w != 0 ? w/=(T)vec.w : w;
	return *this;
}

template <typename T>
template <typename S>
inline 
ofVec4<T> ofVec4<T>::operator/( const S s ) const {
	if(s == 0) return ofVec4<T>(x, y, z, w);
	
	return ofVec4<T>( x/(T)s, y/(T)s, z/(T)s, w/(T)s );
}

template <typename T>
template <typename S>
inline 
ofVec4<T>& ofVec4<T>::operator/=( const S s ) {
	if(s == 0)return *this;
	
	x /= (T)s;
	y /= (T)s;
	z /= (T)s;
	w /= (T)s;
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
