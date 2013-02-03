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
		
    template <typename S>
	ofVec2( const ofVec2<S>& v ) 
    : x((T)v.x), y((T)v.y)
    {}
    
	
	// Equality -----------------------------------------------
		
	bool operator == ( const ofVec2<T>& v ) const;
	bool operator != ( const ofVec2<T>& v ) const;
	bool match( const ofVec2<T>& vec, T tolerance ) const;
	
	// Operators ----------------------------------------------
	
    ofVec2<T>  operator +  ( const ofVec2<T>& v ) const;
    ofVec2<T>& operator += ( const ofVec2<T>& v );
    ofVec2<T>  operator -  ( const ofVec2<T>& v ) const;
    ofVec2<T>& operator -= ( const ofVec2<T>& v );
    ofVec2<T>  operator *  ( const ofVec2<T>& v ) const;
    ofVec2<T>& operator *= ( const ofVec2<T>& v );
    ofVec2<T>  operator /  ( const ofVec2<T>& v ) const;
    ofVec2<T>& operator /= ( const ofVec2<T>& v );
	
    ofVec2<T>  operator +  ( const T s ) const;
    ofVec2<T>& operator += ( const T s );
    ofVec2<T>  operator -  ( const T s ) const;
    ofVec2<T>& operator -= ( const T s );
    ofVec2<T>  operator -  () const;
    ofVec2<T>  operator *  ( const T s ) const;
    ofVec2<T>& operator *= ( const T s );
    ofVec2<T>  operator /  ( const T s ) const;
    ofVec2<T>& operator /= ( const T s );

    // Scaling ---------------------------------------------------
    
    ofVec2<T>  getScaled( const T length ) const;
    ofVec2<T>& scale( const T length );
	
    // Rotation --------------------------------------------------
    
    ofVec2<T>  getRotated( T angle ) const;
    ofVec2<T>  getRotatedRad( T angle ) const;
    ofVec2<T>& rotate( T angle );
    ofVec2<T>& rotateRad( T angle );
	
    // Rotation - point around pivot -------------------------------

    ofVec2<T>  getRotated( T angle, const ofVec2<T>& pivot ) const;
    ofVec2<T>& rotate( T angle, const ofVec2<T>& pivot );
    ofVec2<T>  getRotatedRad( T angle, const ofVec2<T>& pivot ) const;
    ofVec2<T>& rotateRad( T angle, const ofVec2<T>& pivot ); 

    // Setters -----------------------------------------------------
	
	void set( T _scalar );
	void set( T _x, T _y );
	void set( const ofVec2<T>& v );
    
    // ios stream --------------------------------------------------
		
	// This is crazy, but it removes the compiler warnings.
	// bla bla bla...Non-template....
	template <typename S>
    friend ostream& operator << ( ostream& os, const ofVec2<S>& v );
	template <typename S>
    friend istream& operator >> ( istream& is, ofVec2<S>& v );

    //
    // Deprecated --------------------------------------------------
	// Version: 006
	//
	
    /*! Use getScaled() instead. */
    ofVec2<T> rescaled( const T length ) const;
	
	/*! Use scale() instead. */
    ofVec2<T>& rescale( const T length );

    /*! Use getRotated() instead. */
    ofVec2<T> rotated( T angle ) const;

    /*! Use getRotated() instead. */
    ofVec2<T> rotated( T angle, const ofVec2<T>& pivot ) const;    
};

//
// -------------------------------------------------------------
//

// This file is really big.
// Maybe, this can help.
#include "ofVec2Operators.h"
#include "ofVec2Geom.h"
	
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
