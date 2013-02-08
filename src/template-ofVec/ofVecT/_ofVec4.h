#pragma once

//#include "_ofVecT.h"
#include "_ofVec2.h"
#include "_ofVec3.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

template <typename T> class _ofVec2;
template <typename T> class _ofVec3;

template<typename T>
class _ofVec4 {
public:
    T x, y, z, w;
    
    static const int DIM = 4;
    
    _ofVec4()
        : x(0), y(0), z(0), w(0) {}
    
    _ofVec4( T _x, T _y, T _z, T _w ) 
        : x(_x), y(_y), z(_z), w(_w) {}
    
    _ofVec4( const _ofVec4<T>& v ) 
        : x(v.x), y(v.y), z(v.z), w(v.w) {}
    
    _ofVec4( const _ofVec3<T>& v )
        : x(v.x), y(v.y), z(v.z), w(0) {}
	
	template <typename S>
	_ofVec4( const _ofVec4<S>& v ) 
		: x((T)v.x), y((T)v.y), z((T)v.z), w((T)v.w) {}
    
	template <typename S>
    _ofVec4( const _ofVec3<S>& v )
		: x((T)v.x), y((T)v.y), z((T)v.z), w(0) {}
	
    // Getters and Setters. -------------------------------------------------
    
	void set( T _scalar );
    void set( T _x, T _y, T _z, T _w );
    void set( const _ofVec4<T>& vec );
	
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
	
    // Similarity/equality --------------------------------------------------
    
    bool operator == ( const _ofVec4<T>& vec ) const;
    bool operator != ( const _ofVec4<T>& vec ) const;
    bool match( const _ofVec4<T>& vec, T tolerance=0.0001 ) const;
	
    // Overloading for any type to any type ---------------------------------	
    
    _ofVec4<T>  operator +  ( const _ofVec4<T>& vec ) const;
    _ofVec4<T>& operator += ( const _ofVec4<T>& vec );
    _ofVec4<T>  operator -  ( const T f ) const;
    _ofVec4<T>& operator -= ( const T f );
    _ofVec4<T>  operator -  ( const _ofVec4<T>& vec ) const;
    _ofVec4<T>& operator -= ( const _ofVec4<T>& vec );
    _ofVec4<T>  operator +  ( const T f ) const;
    _ofVec4<T>& operator += ( const T f );
	
    _ofVec4<T>  operator *  ( const _ofVec4<T>& vec ) const;
    _ofVec4<T>& operator *= ( const _ofVec4<T>& vec );
    _ofVec4<T>  operator *  ( const T f ) const;
    _ofVec4<T>& operator *= ( const T f );
    _ofVec4<T>  operator /  ( const _ofVec4<T>& vec ) const;
    _ofVec4<T>& operator /= ( const _ofVec4<T>& vec );
    _ofVec4<T>  operator /  ( const T f ) const;
    _ofVec4<T>& operator /= ( const T f );
	
    _ofVec4<T> operator - () const;
	
    // IO Stream -----------------------------------------------------------

    template <typename S> 
    friend ostream& operator<<(ostream& os, const _ofVec4<S>& vec);
    template <typename S> 
    friend istream& operator>>(istream& is, const _ofVec4<S>& vec);
	
    // Scaling --------------------------------------------------------------
    
    _ofVec4<T>  getScaled( const T length ) const;
    _ofVec4<T>&     scale( const T length );
	
    // Distance between two points ------------------------------------------
    
    T       distance( const _ofVec4<T>& pnt) const;
    T squareDistance( const _ofVec4<T>& pnt ) const;
	
    // Linear interpolation -------------------------------------------------
    
    /**
	 * p==0.0 results in this point, 
     * p==0.5 results in the midpoint, and 
     * p==1.0 results in pnt being returned.
	 */
    _ofVec4<T>  getInterpolated( const _ofVec4<T>& pnt, T p ) const;
    _ofVec4<T>&     interpolate( const _ofVec4<T>& pnt, T p );
    _ofVec4<T>        getMiddle( const _ofVec4<T>& pnt ) const;
    _ofVec4<T>&          middle( const _ofVec4<T>& pnt );
    _ofVec4<T>&         average( const _ofVec4<T>* points, int num );
    
	
    /** Dot Product. */
    T dot( const _ofVec4<T>& vec ) const;
	
    // Normalization --------------------------------------------------------
    
    _ofVec4<T>  getNormalized() const;
    _ofVec4<T>&     normalize();
	
    // Limit length ---------------------------------------------------------
    
	_ofVec4<T>  getLimited( T max ) const;
    _ofVec4<T>&      limit( T max );
	
    // Length ---------------------------------------------------------------
    
    T        length() const;
    T lengthSquared() const;
	OF_DEPRECATED_MSG("Use _ofVec4<T>::lengthSquared() instead.", T squareLength() const);
	
	//
    // Deprecated -----------------------------------------------------------
    // Since: v006
    //
    
    // getScaled
    _ofVec4<T> rescaled( const T length ) const;
	
    // scale
    _ofVec4<T>& rescale( const T length );
	
    // getNormalized
    _ofVec4<T> normalized() const;
	
    // getLimited
    _ofVec4<T> limited(T max) const;
	
    // use squareDistance
    T  distanceSquared( const _ofVec4<T>& pnt ) const;
	
    // use getInterpolated
    _ofVec4<T> 	interpolated( const _ofVec4<T>& pnt, T p ) const;
	
    // use getMiddle
    _ofVec4<T> 	middled( const _ofVec4<T>& pnt ) const;    
    
	
    // return all zero vector
    static _ofVec4<T> zero() { return _ofVec4<T>(0, 0, 0, 0); }
    
    // return all one vector
    static _ofVec4<T> one() { return _ofVec4<T>(1, 1, 1, 1); }
	
};

//
// Implementation ---------------------------------------------
//

// Similarity/equality --------------------------------------------------

template <typename T> inline 
bool _ofVec4<T>::operator==( const _ofVec4<T>& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
}

template <typename T> inline 
bool _ofVec4<T>::operator!=( const _ofVec4<T>& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z) || (w != vec.w);
}

// Overloading for any type to any type ---------------------------------	

template<typename T> inline 
_ofVec4<T> _ofVec4<T>::operator+( const _ofVec4<T>& vec ) const {
	return _ofVec4<T>( x+vec.x, y+vec.y, z+vec.z, w+vec.w);
}

template<typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator+=( const _ofVec4<T>& vec ) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
	return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator-( const T f ) const {
	return _ofVec4<T>( x-f, y-f, z-f, w-f );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator-=( const T f ) {
	x -= f;
	y -= f;
	z -= f;
	w -= f;
	return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator-( const _ofVec4<T>& vec ) const {
	return _ofVec4<T>( x-vec.x, y-vec.y, z-vec.z, w-vec.w );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator-=( const _ofVec4<T>& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
	return *this;
}

template <typename T>
inline _ofVec4<T> _ofVec4<T>::operator+( const T f ) const {
	return _ofVec4<T>( x+f, y+f, z+f, w+f );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator+=( const T f ) {
	x += f;
	y += f;
	z += f;
	w += f;
	return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator-() const {
	return _ofVec4<T>( -x, -y, -z, -w );
}


template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator*( const _ofVec4<T>& vec ) const {
	return _ofVec4<T>( x*vec.x, y*vec.y, z*vec.z, w*vec.w );
}

template<typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator*=( const _ofVec4<T>& vec ) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	w *= vec.w;
	return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator*( const T f ) const {
	return _ofVec4<T>( x*f, y*f, z*f, w*f );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator*=( const T f ) {
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator/( const _ofVec4<T>& vec ) const {
	return _ofVec4<T>( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z, vec.w!=0 ? w/vec.w : w  );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator/=( const _ofVec4<T>& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	vec.w!=0 ? w/=vec.w : w;
	return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::operator/( const T f ) const {
	if(f == 0) return _ofVec4<T>(x, y, z, w);
	
	return _ofVec4<T>( x/f, y/f, z/f, w/f );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::operator/=( const T f ) {
	if(f == 0)return *this;
	
	x /= f;
	y /= f;
	z /= f;
	w /= f;
	return *this;
}

// IO Stream --------------------------------------------------

template <typename S> inline 
ostream& operator<<(ostream& os, const _ofVec4<S>& vec) {
	os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
	return os;
}

template <typename S> inline 
istream& operator>>(istream& is, _ofVec4<S>& vec) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	is.ignore(2);
	is >> vec.z;
	is.ignore(2);
	is >> vec.w;
	return is;
}
