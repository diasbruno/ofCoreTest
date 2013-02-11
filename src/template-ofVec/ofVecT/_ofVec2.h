#pragma once

//#include "_ofVecT.h"
#include "_ofVec3.h"
#include "_ofVec4.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

template <typename T> class _ofVec3;
template <typename T> class _ofVec4;

template <typename T>
class _ofVec2 {
//	: public _ofVecT<T> {
public:
    T x, y;
    
    static const int DIM = 2;
	
    _ofVec2();
	
    explicit _ofVec2( T _scalar );
	
    _ofVec2( T _x, T _y );
    
	_ofVec2( const _ofVec3<T>& vec );
	
	_ofVec2( const _ofVec4<T>& vec );
	
    // Getters and Setters. -------------------------------------------------
    
    void set( T _scalar );
    void set( T _x, T _y );
    void set( const _ofVec2<T>& vec );
	
    // Accessors ------------------------------------------------------------
	
    T* getPtr() { 
        return (T*)&x; }

    const T* getPtr() const { 
        return (const T*)&x; }

    T& operator[]( int n ) { 
        return getPtr()[n]; }

    T operator[]( int n ) const { 
        return getPtr()[n]; }
    
    // Similarity/equality --------------------------------------------------
    
    bool operator == ( const _ofVec2<T>& vec ) const;
    bool operator != ( const _ofVec2<T>& vec ) const;
    
    bool match( const _ofVec2<T>& vec, T tolerance=0.0001 ) const;
	
    // Overloading for any type to any type ---------------------------------
    
    _ofVec2<T>  operator +  ( const _ofVec2<T>& vec ) const;
    _ofVec2<T>& operator += ( const _ofVec2<T>& vec );
    _ofVec2<T>  operator -  ( const _ofVec2<T>& vec ) const;
    _ofVec2<T>& operator -= ( const _ofVec2<T>& vec );
    _ofVec2<T>  operator *  ( const _ofVec2<T>& vec ) const;
    _ofVec2<T>& operator *= ( const _ofVec2<T>& vec );
    _ofVec2<T>  operator /  ( const _ofVec2<T>& vec ) const;
    _ofVec2<T>& operator /= ( const _ofVec2<T>& vec );
    
    _ofVec2<T>  operator +  ( const T f ) const;
    _ofVec2<T>& operator += ( const T f );
    _ofVec2<T>  operator -  ( const T f ) const;
    _ofVec2<T>& operator -= ( const T f );
    _ofVec2<T>  operator *  ( const T f ) const;
    _ofVec2<T>& operator *= ( const T f );
    _ofVec2<T>  operator /  ( const T f ) const;
    _ofVec2<T>& operator /= ( const T f );
	
    _ofVec2<T>  operator - () const;
	
    // Alignment ------------------------------------------------------------
    
    /**
     * Checks if vectors look in the same direction.
     * Tolerance is specified in degree.
     */
    bool    isAligned( const _ofVec2<T>& vec, T tolerance = 0.0001 ) const;
    bool isAlignedRad( const _ofVec2<T>& vec, T tolerance = 0.0001 ) const;
    bool        align( const _ofVec2<T>& vec, T tolerance = 0.0001 ) const;
    bool     alignRad( const _ofVec2<T>& vec, T tolerance = 0.0001 ) const;
    
    // Scaling --------------------------------------------------------------
    
    _ofVec2<T>  getScaled( const T length ) const;
    _ofVec2<T>&     scale( const T length );
    
    // Rotation -------------------------------------------------------------
    
    _ofVec2<T>     getRotated( T angle ) const;
    _ofVec2<T>  getRotatedRad( T angle ) const;
    _ofVec2<T>&        rotate( T angle );
    _ofVec2<T>&     rotateRad( T angle );
    
    // Rotation - point around pivot ----------------------------------------
    
    _ofVec2<T>     getRotated( T angle, const _ofVec2<T>& pivot ) const;
    _ofVec2<T>&        rotate( T angle, const _ofVec2<T>& pivot );
    _ofVec2<T>  getRotatedRad( T angle, const _ofVec2<T>& pivot ) const;
    _ofVec2<T>&     rotateRad( T angle, const _ofVec2<T>& pivot );
    
    // Map ------------------------------------------------------------------
	
	/*! Map point to coordinate system defined by origin, vx, and vy. */
    _ofVec2<T> getMapped( const _ofVec2<T>& origin,
						  const _ofVec2<T>&     vx,
						  const _ofVec2<T>&     vy )  const;
    _ofVec2<T>&      map( const _ofVec2<T>& origin,
						  const _ofVec2<T>&     vx, 
						  const _ofVec2<T>&     vy );
    
    // Distance between two points ------------------------------------------
    
    T       distance( const _ofVec2<T>& pnt ) const;
    T squareDistance( const _ofVec2<T>& pnt ) const;
    
    // Linear interpolation -------------------------------------------------
    
    /**
     * p == 0.0 results in this point, 
     * p == 0.5 results in the midpoint, and 
     * p == 1.0 results in pnt being returned.
     */
    _ofVec2<T>   getInterpolated( const _ofVec2<T>& pnt, T p ) const;
    _ofVec2<T>&      interpolate( const _ofVec2<T>& pnt, T p );
	
    _ofVec2<T>         getMiddle( const _ofVec2<T>& pnt ) const;
    _ofVec2<T>&           middle( const _ofVec2<T>& pnt );
	
	// Average ---------------------------------------------------------------
	
	_ofVec2<T>& average( const _ofVec2<T>* points, int num );
	
    // Normalization ---------------------------------------------------------
    
    _ofVec2<T>  getNormalized() const;
    _ofVec2<T>&     normalize();
    
    // Limit length ----------------------------------------------------------
    
    _ofVec2<T>  getLimited( T max ) const;
    _ofVec2<T>&      limit( T max );
    
    // Perpendicular normalized vector ---------------------------------------
    
    _ofVec2<T>  getPerpendicular() const;
    _ofVec2<T>&    perpendicular();
	
	// Dot -------------------------------------------------------------------
	
	/*! Dot Product. */
    T dot( const _ofVec2<T>& vec ) const;
    
    // Length ----------------------------------------------------------------
    
    T        length() const;
    T lengthSquared() const;
    
    // Angle -----------------------------------------------------------------
    
    /**
     * Angle (deg) between two vectors.
     * This is a signed relative angle between -180 and 180.
     */
    T    angle( const _ofVec2<T>& vec ) const;
    T angleRad( const _ofVec2<T>& vec ) const;
    
    // IO Stream -------------------------------------------------------------
	
	template <typename S> friend 
	std::ostream& operator << ( std::ostream& os, const _ofVec2<S>& vec );
	template <typename S> friend 
	std::istream& operator >> ( std::istream& is, const _ofVec2<S>& vec );
    
	// return all zero vector
    static _ofVec2<T> zero() { 
		return _ofVec2<T>( 0, 0 ); }
    
    // return all one vector
    static _ofVec2<T> one() { 
		return _ofVec2<T>( 1, 1 ); }
	
    //
    // Deprecated -----------------------------------------------------------
    // Since: v006
    // 
	
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::lengthSquared() instead.", 
		T squareLength() const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getScale() instead.", 
		_ofVec2<T> rescaled( const T length ) const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::scale() instead.", 
		_ofVec2<T>& rescale( const T length )
	);

	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getRotated() instead.", 
		_ofVec2<T> rotated( T angle ) const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getNormalized() instead.", 
		 _ofVec2<T> normalized() const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getLimited() instead.", 
		_ofVec2<T> limited( T max ) const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getPerpendicular() instead.", 
		_ofVec2<T> perpendiculared() const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getInterpolated() instead.", 
		_ofVec2<T> interpolated( const _ofVec2<T>& pnt, T p ) const
	);
	
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getMiddled() instead.", 
		_ofVec2<T> middled( const _ofVec2<T>& pnt ) const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getMapped() instead.", 
		_ofVec2<T> mapped( const _ofVec2<T>& origin, 
						   const _ofVec2<T>&     vx, 
						   const _ofVec2<T>&     vy ) const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::squareDistance() instead.", 
		T distanceSquared( const _ofVec2<T>& pnt ) const
	);
    
	OF_DEPRECATED_MSG( 
		"Use _ofVec2<T>::getRotated() instead.", 
		_ofVec2<T> rotated( T angle, const _ofVec2<T>& pivot ) const
	);
    
};

//
// Implementation -----------------------------------------------------
//

// Constructors -------------------------------------------------------

template <typename T>
_ofVec2<T>::_ofVec2()
    : x(0), y(0) 
{}

template <typename T> 
_ofVec2<T>::_ofVec2( T _scalar )
	: x(_scalar), y(_scalar) 
{} 

template <typename T>_ofVec2<T>::_ofVec2( T _x, T _y )
    : x(_x), y(_y) 
{}

template <typename T> 
_ofVec2<T>::_ofVec2( const _ofVec3<T>& vec )
    : x(vec.x), y(vec.y) 
{}

template <typename T> 
_ofVec2<T>::_ofVec2( const _ofVec4<T>& vec )
    : x(vec.x), y(vec.y) 
{}

// Similarity/equality --------------------------------------------------

template <typename T> inline 
bool _ofVec2<T>::operator == ( const _ofVec2<T>& vec ) const {
    
    return ( x == vec.x ) 
        && ( y == vec.y );
}

template <typename T> inline 
bool _ofVec2<T>::operator != ( const _ofVec2<T>& vec ) const {

    return ( x != vec.x ) 
        || ( y != vec.y );
}

// Overloading for any type to any type ---------------------------------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator + ( const _ofVec2<T>& vec ) const {

    return _ofVec2<T>( 
		x + vec.x, // x
		y + vec.y  // y
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator += ( const _ofVec2<T>& vec ) {

    x += vec.x;
    y += vec.y;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator - ( const _ofVec2<T>& vec ) const {

    return _ofVec2<T>( 
		x - vec.x, // x
		y - vec.y  // y
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator -= ( const _ofVec2<T>& vec ) {

    x -= vec.x;
    y -= vec.y;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator * ( const _ofVec2<T>& vec ) const {
  
    return _ofVec2<T>( 
		x * vec.x, // x
		y * vec.y  // y
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator *= ( const _ofVec2<T>& vec ) {

    x *= vec.x;
    y *= vec.y;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator / ( const _ofVec2<T>& vec ) const {

    return _ofVec2<T>( 
		vec.x != 0 ? x / vec.x : x, // x
		vec.y != 0 ? y / vec.y : y  // y
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator /= ( const _ofVec2<T>& vec ) {

    vec.x != 0 ? x /= vec.x : x;
    vec.y != 0 ? y /= vec.y : y;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator + ( const T f ) const {

    return _ofVec2<T>( x + f, y + f );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator += ( const T f ) {

    x += f;
    y += f;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator - ( const T f ) const {

    return _ofVec2<T>( 
		x - f, // x 
		y - f  // y 
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator -= ( const T f ) {

    x -= f;
    y -= f;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator - () const {

    return _ofVec2<T>( -x, -y );
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator * ( const T f ) const {

    return _ofVec2<T>( 
		x * f, // x 
		y * f  // y
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator *= ( const T f ) {

    x *= f;
    y *= f;

    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::operator /(  const T f ) const {

    if ( f == 0 ) { 
        return _ofVec2<T>( x, y );
    }
    
    return _ofVec2<T>( 
		x / f, // x 
		y / f  // y
	);
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::operator /= ( const T f ) {

    if ( f == 0 ) {
        return *this;
    }
    
    x /= f;
    y /= f;

    return *this;
}

// IO Stream --------------------------------------------------

template <typename T> inline 
std::ostream& operator << ( std::ostream& os, const _ofVec2<T>& vec ) {

    os << vec.x << ", " << vec.y;

    return os;
}

template <typename T> inline 
std::istream& operator >> ( std::istream& is, _ofVec2<T>& vec ) {

    is >> vec.x; is.ignore(2);
    is >> vec.y;

    return is;
}
