#pragma once

#include "ofVecT.h"

namespace of {

template <typename T>
class ofVec2 
	: public ofVecT<T> {
public:
	T x, y;
	
	static const int DIM = 2;
	
	ofVec2()
	: x(0), 
      y(0) 
	{}
	
	ofVec2( T _x, T _y )
	: x(_x), y(_y) 
	{}
	
	ofVec2( const ofVec2<T>& v ) 
    : x(v.x), y(v.y) 
    {}
		
	template<typename S>
	ofVec2( const ofVec2<S>& v ) 
    : x((T)v.x), y((T)v.y)
    {}
    
	
	// Equality -----------------------------------------------
		
	bool operator == ( const ofVec2<T>& v ) const;
	bool operator != ( const ofVec2<T>& v ) const;
	bool match( const ofVec2<T>& vec, T tolerance ) const;
	
	// Operators ----------------------------------------------
	
    template<typename S>
    ofVec2<T>  operator +  ( const ofVec2<S>& v ) const;
    template<typename S>
    ofVec2<T>& operator += ( const ofVec2<S>& v );
    template<typename S>
    ofVec2<T>  operator -  ( const ofVec2<S>& v ) const;
    template<typename S>
    ofVec2<T>& operator -= ( const ofVec2<S>& v );
    template<typename S>
    ofVec2<T>  operator *  ( const ofVec2<S>& v ) const;
    template<typename S>
    ofVec2<T>& operator *= ( const ofVec2<S>& v );
    template<typename S>
    ofVec2<T>  operator /  ( const ofVec2<S>& v ) const;
    template<typename S>
    ofVec2<T>& operator /= ( const ofVec2<S>& v );
	
    template<typename S>
    ofVec2<T>  operator +  ( const S s ) const;
    template<typename S>
    ofVec2<T>& operator += ( const S s );
    template<typename S>
    ofVec2<T>  operator -  ( const S s ) const;
    template<typename S>
    ofVec2<T>& operator -= ( const S s );
    template<typename S>
    ofVec2<T>  operator -  () const;
    template<typename S>
    ofVec2<T>  operator *  ( const S s ) const;
    template<typename S>
    ofVec2<T>& operator *= ( const S s );
    template<typename S>
    ofVec2<T>  operator /  ( const S s ) const;
    template<typename S>
    ofVec2<T>& operator /= ( const S s );

    // Scaling ---------------------------------------------------
    
    template<typename S>
    ofVec2<T>  getScaled( const S length ) const;
    template<typename S>
    ofVec2<T>& scale( const S length );
	
    // Rotation --------------------------------------------------
    
    template<typename S>
    ofVec2<T>  getRotated( S angle ) const;
    template<typename S>
    ofVec2<T>  getRotatedRad( S angle ) const;
    template<typename S>
    ofVec2<T>& rotate( S angle );
    template<typename S>
    ofVec2<T>& rotateRad( S angle );
	
    // Rotation - point around pivot ------------------------------

    template<typename S>
    ofVec2<T>  getRotated( S angle, const ofVec2<S>& pivot ) const;
    template<typename S>
    ofVec2<T>& rotate( S angle, const ofVec2<S>& pivot );
    template<typename S>
    ofVec2<T>  getRotatedRad( S angle, const ofVec2<S>& pivot ) const;
    template<typename S>
    ofVec2<T>& rotateRad( S angle, const ofVec2<S>& pivot ); 

    // Setters ------------------------------------------------
	
	void set( T _scalar );
	void set( T _x, T _y );
	void set( const ofVec2<T>& v );
    
    // ios stream ---------------------------------------------

    template<typename S>
    friend ostream& operator << ( ostream& os, const ofVec2<S>& v );
		
	template<typename S>
    friend istream& operator >> ( istream& is, ofVec2<S>& v );
};

//
// -------------------------------------------------------------
//

// Equality -----------------------------------------------------

/*! Operators */
template<typename T>
inline
bool ofVec2<T>::operator == ( const ofVec2<T> & v ) const {
	return x == v.x 
        && y == v.y;
};

template<typename T>
inline
bool ofVec2<T>::operator != ( const ofVec2<T> & v ) const {
	return x != v.x 
        || y != v.y;
};

template<typename T>
inline
bool ofVec2<T>::match( const ofVec2<T>& v, T tolerance ) const {
	return fabs(x - v.x) < tolerance 
        && fabs(y - v.y) < tolerance;
};
	
	
// Operators -----------------------------------------------------

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator+( const ofVec2<S>& v ) const {
	return ofVec2<T>( x + (T)v.x, y + (T)v.y );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator+=( const ofVec2<S>& v ) {
	x += (T)v.x;
	y += (T)v.y;
	
	return *this;
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator-( const ofVec2<S>& v ) const {
	return ofVec2<T>( x - (T)v.x, y - (T)v.y );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator-=( const ofVec2<S>& v ) {
	x -= (T)v.x;
	y -= (T)v.y;
	
	return *this;
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator*( const ofVec2<S>& v ) const {
	return ofVec2<T>( x * (T)v.x, y * (T)v.y );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator*=( const ofVec2<S>& v ) {
	x *= (T)v.x;
	y *= (T)v.y;
	
	return *this;
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator/( const ofVec2<S>& v ) const {
	return ofVec2<T>( v.x != 0 ? x / (T)v.x : x , v.y != 0 ? y / (T)v.y : y );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator/=( const ofVec2<S>& v ) {
	v.x != 0 ? x /= (T)v.x : x;
	v.y != 0 ? y /= (T)v.y : y;
	
	return *this;
};


template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator+( const S s ) const {
	return ofVec2<T>( x + (T)s, y + (T)s );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator+=( const S s ) {
	x += (T)s;
	y += (T)s;
	
	return *this;
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator-( const S s ) const {
	return ofVec2<T>( x - (T)s, y - (T)s );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator-=( const S s ) {
	x -= (T)s;
	y -= (T)s;
	
	return *this;
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator-() const {
	return ofVec2<T>( -x, -y );
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator*( const S s ) const {
	return ofVec2<T>( x * (T)s, y * (T)s );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator*=( const S s ) {
	x *= (T)s;
	y *= (T)s;
	
	return *this;
};

template<typename T>
template<typename S>
inline 
ofVec2<T> ofVec2<T>::operator/( const S s ) const {
	if( s == 0 ) return ofVec2<T>( x, y );
	
	return ofVec2<T>( x / (T)s, y / (T)s );
};

template<typename T>
template<typename S>
inline 
ofVec2<T>& ofVec2<T>::operator/=( const S s ) {
	if( s == 0 ) return *this;
	
	x /= (T)s;
	y /= (T)s;
	
	return *this;
};
	
	
// Setters --------------------------------------------------------

/*! */
template<typename T>
inline
void ofVec2<T>::set( T _scalar ) {
	x = _scalar;
	y = _scalar;
};

/*! */
template<typename T>
inline
void ofVec2<T>::set( T _x, T _y ) {
	x = _x;
	y = _y;
};

/*! */
template<typename T>
inline
void ofVec2<T>::set( const of::ofVec2<T>& v ) {
	x = v.x;
	y = v.y;
};


// ios stream -----------------------------------------------------

template<typename T, typename S>
inline 
ostream& operator<<(ostream& os, const ofVec2<S>& v) {
	os << v.x << ", " << v.y;
	return os;
};

template<typename T, typename S>
inline 
istream& operator>>(istream& is, ofVec2<S>& v) {
	is >> v.x;
	is.ignore(2);
	is >> v.y;
	return is;
};

}
