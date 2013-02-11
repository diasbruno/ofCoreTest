#pragma once

#include "_ofVecT.h"
#include "_ofVec2.h"
#include "_ofVec4.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

template <typename T> class _ofVec2;
template <typename T> class _ofVec4;

template <typename T>
class _ofVec3 {
public:
    T x, y, z;
    
    static const int DIM = 3;
    
    _ofVec3()
		: x(0), y(0), z(0) {}
	
    _ofVec3( T _x, T _y, T _z = 0 )
		: x(_x), y(_y), z(_z) {}
    
    /// assigns scalar to x, y, and z
    explicit _ofVec3( T _scalar )
		: x(_scalar), y(_scalar), z(_scalar) {};
    
    _ofVec3( const _ofVec2<T>& vec )
		: x(vec.x), y(vec.y), z(0) {}
    
    _ofVec3( const _ofVec4<T>& vec )
		: x(vec.x), y(vec.y), z(vec.z) {}
	
	template <typename S>
	_ofVec3( const _ofVec2<S>& vec )
		: x((T)vec.x), y((T)vec.y), z(0) {}
    
	template <typename S>
    _ofVec3( const _ofVec4<S>& vec )
		: x((T)vec.x), y((T)vec.y), z((T)vec.z) {}
    
    
    // Getters and Setters. ------------------------------------------------
    
    void set( T _x, T _y, T _z = 0 );
    void set( const _ofVec3<T>& vec );
    void set( T _scalar );
    
	// Accessors -----------------------------------------------------------
	
	T* getPtr() 
    { return (T*)&x; }

	const T* getPtr() const 
    { return (const T*)&x; }
	
	T& operator[]( int n ) 
    { return getPtr()[n]; }
	
	T operator[]( int n ) const 
    { return getPtr()[n]; }
	
    // Similarity/equality --------------------------------------------------
    
    bool operator == ( const _ofVec3<T>& vec ) const;
    bool operator != ( const _ofVec3<T>& vec ) const;
	
    bool match( const _ofVec3<T>& vec, T tolerance ) const;
    
    // Overloading for any type to any type ---------------------------------	
    
    _ofVec3<T>  operator +  ( const _ofVec3<T>& vec ) const;
    _ofVec3<T>& operator += ( const _ofVec3<T>& vec );
    _ofVec3<T>  operator -  ( const _ofVec3<T>& vec ) const;
    _ofVec3<T>& operator -= ( const _ofVec3<T>& vec );
    _ofVec3<T>  operator *  ( const _ofVec3<T>& vec ) const;
    _ofVec3<T>& operator *= ( const _ofVec3<T>& vec );
    _ofVec3<T>  operator /  ( const _ofVec3<T>& vec ) const;
    _ofVec3<T>& operator /= ( const _ofVec3<T>& vec );
	
    _ofVec3<T>  operator +  ( const T f ) const;
    _ofVec3<T>& operator += ( const T f );
    _ofVec3<T>  operator -  ( const T f ) const;
    _ofVec3<T>& operator -= ( const T f );
    _ofVec3<T>  operator *  ( const T f ) const;
    _ofVec3<T>& operator *= ( const T f );
    _ofVec3<T>  operator /  ( const T f ) const;
    _ofVec3<T>& operator /= ( const T f );
    
    _ofVec3<T>  operator - () const;
	
    // Alignment ------------------------------------------------------------
    
    /*! Checks if vectors look in the same direction. */
    bool    isAligned( const _ofVec3<T>& vec, T tolerance=0.0001 ) const;
    bool        align( const _ofVec3<T>& vec, T tolerance=0.0001 ) const;
    bool isAlignedRad( const _ofVec3<T>& vec, T tolerance=0.0001 ) const;
    bool     alignRad( const _ofVec3<T>& vec, T tolerance=0.0001 ) const;
	
    // Scaling --------------------------------------------------------------	
    
    _ofVec3<T>  getScaled( const T length ) const;
    _ofVec3<T>&     scale( const T length );
    
    // Rotation -------------------------------------------------------------
    
    _ofVec3<T>     getRotated( T angle, const _ofVec3<T>& axis ) const;
    _ofVec3<T>  getRotatedRad( T angle, const _ofVec3<T>& axis ) const;
    _ofVec3<T>&        rotate( T angle, const _ofVec3<T>& axis );
    _ofVec3<T>&     rotateRad( T angle, const _ofVec3<T>& axis );
    _ofVec3<T>     getRotated( T ax, T ay, T az ) const;
    _ofVec3<T>  getRotatedRad( T ax, T ay, T az ) const;
    _ofVec3<T>&        rotate( T ax, T ay, T az );
    _ofVec3<T>&     rotateRad( T ax, T ay, T az );
    
    // Rotation - point around pivot ----------------------------------------
    
    _ofVec3<T>     getRotated( T angle, const _ofVec3<T>& pivot, 
                                        const _ofVec3<T>& axis ) const;
    _ofVec3<T>&        rotate( T angle, const _ofVec3<T>& pivot, 
                                        const _ofVec3<T>& axis );
    _ofVec3<T>  getRotatedRad( T angle, const _ofVec3<T>& pivot, 
                                        const _ofVec3<T>& axis ) const;
    _ofVec3<T>&     rotateRad( T angle, const _ofVec3<T>& pivot, 
                                        const _ofVec3<T>& axis );    
    
    // Map point to coordinate system defined by origin, vx, and vy ---------
    
    _ofVec3<T>  getMapped( const _ofVec3<T>& origin,
						 const _ofVec3<T>& vx,
						 const _ofVec3<T>& vy,
						 const _ofVec3<T>& vz ) 
	const;
    _ofVec3<T>&       map( const _ofVec3<T>& origin,
						 const _ofVec3<T>& vx,
						 const _ofVec3<T>& vy,
						 const _ofVec3<T>& vz );
    
    // Distance between two points ------------------------------------------
    
    T       distance( const _ofVec3<T>& pnt) const;
    T squareDistance( const _ofVec3<T>& pnt ) const;
    
    // Linear interpolation -------------------------------------------------
    
    /**
     * p == 0.0 results in this point, 
     * p == 0.5 results in the midpoint, and 
     * p == 1.0 results in pnt being returned.
     */
    _ofVec3<T>  getInterpolated( const _ofVec3<T>& pnt, T p ) const;
    _ofVec3<T>&     interpolate( const _ofVec3<T>& pnt, T p );
    _ofVec3<T>        getMiddle( const _ofVec3<T>& pnt ) const;
    _ofVec3<T>&          middle( const _ofVec3<T>& pnt );
    _ofVec3<T>&         average( const _ofVec3<T>* points, int num );
    
    // Normalization --------------------------------------------------------
    
    _ofVec3<T>  getNormalized() const;
    _ofVec3<T>&     normalize();
    
    // Limit length ---------------------------------------------------------
    
    _ofVec3<T> getLimited( T max ) const;
    _ofVec3<T>&     limit( T max );
    
    // Perpendicular normalized vector --------------------------------------
    
    _ofVec3<T>        getCrossed( const _ofVec3<T>& vec ) const;
    _ofVec3<T>&            cross( const _ofVec3<T>& vec );
    /*! Normalized perpendicular. */
    _ofVec3<T>  getPerpendicular( const _ofVec3<T>& vec ) const;
    _ofVec3<T>&    perpendicular( const _ofVec3<T>& vec );
    
    // Dot Product ----------------------------------------------------------
    
    T dot( const _ofVec3<T>& vec ) const;
	
    // Length ---------------------------------------------------------------
    
    T        length() const;
    T lengthSquared() const;
	
    OF_DEPRECATED_MSG( "Use _ofVec3<T>::lengthSquared() instead.", 
					  T squareLength() const );
	
    // Angle ----------------------------------------------------------------
	
    /**
     * Angle (deg) between two vectors.
     * This is an unsigned relative angle from 0 to 180.
     * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
     */
    T    angle( const _ofVec3<T>& vec ) const;
    T angleRad( const _ofVec3<T>& vec ) const;
    
    // IO Stream -----------------------------------------------------------

    template <typename S> 
    friend std::ostream& operator << ( std::ostream& os, const _ofVec3<S>& vec );
    template <typename S> 
    friend std::istream& operator >> ( std::istream& is, const _ofVec3<S>& vec );
    
    //
    // Deprecated -----------------------------------------------------------
    // Since: v006
    // 
    
    // getScaled
    _ofVec3<T> rescaled( const T length ) const;
    
    // scale
    _ofVec3<T>& rescale( const T length );
    
    // getRotated
    _ofVec3<T> rotated( T angle, const _ofVec3<T>& axis ) const;
    
    // getRotated should this be const???
    _ofVec3<T> rotated( T ax, T ay, T az );
    
    // getNormalized
    _ofVec3<T> normalized() const;
    
    // getLimited
    _ofVec3<T> limited( T max) const;
    
    // getCrossed
    _ofVec3<T> crossed( const _ofVec3<T>& vec ) const;
    
    // getPerpendicular
    _ofVec3<T> perpendiculared( const _ofVec3<T>& vec ) const;
    
    // use getMapped
    _ofVec3<T> mapped( const _ofVec3<T>& origin,
					   const _ofVec3<T>& vx,
					   const _ofVec3<T>& vy,
					   const _ofVec3<T>& vz ) const;
    
    // use squareDistance
    T distanceSquared( const _ofVec3<T>& pnt ) const;
    
    // use getInterpolated
    _ofVec3<T> interpolated( const _ofVec3<T>& pnt, T p ) const;
    
    // use getMiddle
    _ofVec3<T> middled( const _ofVec3<T>& pnt ) const;
    
    // use getRotated
    _ofVec3<T> rotated( T angle,
					  const _ofVec3<T>& pivot,
					  const _ofVec3<T>& axis ) const;    
    
    // return all zero vector
    static _ofVec3<T> zero() 
    { return _ofVec3<T>( 0, 0, 0 ); }
    
    // return all one vector
    static _ofVec3<T> one() 
    { return _ofVec3<T>( 1, 1, 1 ); }
};

//
// Implementation ---------------------------------------------
//

// Similarity/equality --------------------------------------------------

template <typename T> inline 
bool _ofVec3<T>::operator==( const _ofVec3<T>& vec ) const {
    return (x == vec.x) && (y == vec.y) && (z == vec.z);
}

template <typename T> inline 
bool _ofVec3<T>::operator!=( const _ofVec3<T>& vec ) const {
    return (x != vec.x) || (y != vec.y) || (z != vec.z);
}

// Overloading for any type to any type ---------------------------------	

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator+( const _ofVec3<T>& pnt ) const {
    return _ofVec3<T>( x+pnt.x, y+pnt.y, z+pnt.z );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator+=( const _ofVec3<T>& pnt ) {
    x+=pnt.x;
    y+=pnt.y;
    z+=pnt.z;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator-( const _ofVec3<T>& vec ) const {
    return _ofVec3<T>( x-vec.x, y-vec.y, z-vec.z );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator-=( const _ofVec3<T>& vec ) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator*( const _ofVec3<T>& vec ) const {
    return _ofVec3<T>( x*vec.x, y*vec.y, z*vec.z );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator*=( const _ofVec3<T>& vec ) {
    x*=vec.x;
    y*=vec.y;
    z*=vec.z;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator/( const _ofVec3<T>& vec ) const {
    return _ofVec3<T>( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator/=( const _ofVec3<T>& vec ) {
    vec.x!=0 ? x/=vec.x : x;
    vec.y!=0 ? y/=vec.y : y;
    vec.z!=0 ? z/=vec.z : z;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator-() const {
    return _ofVec3<T>( -x, -y, -z );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator+( const T f ) const {
    return _ofVec3<T>( x+f, y+f, z+f);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator+=( const T f ) {
    x += f;
    y += f;
    z += f;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator-( const T f ) const {
    return _ofVec3<T>( x-f, y-f, z-f);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator-=( const T f ) {
    x -= f;
    y -= f;
    z -= f;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator*( const T f ) const {
    return _ofVec3<T>( x*f, y*f, z*f );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator*=( const T f ) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::operator/( const T f ) const {
    if(f == 0) return _ofVec3<T>( x, y, z);
    
    return _ofVec3<T>( x/f, y/f, z/f );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::operator/=( const T f ) {
    if(f == 0) return *this;
    
    x/=f;
    y/=f;
    z/=f;
    return *this;
}

// IO Stream --------------------------------------------------

template <typename S> inline 
std::ostream& operator << ( std::ostream& os, const _ofVec3<S>& vec ) {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}

template <typename S> inline 
std::istream& operator >> ( std::istream& is, _ofVec3<S>& vec) {
    is >> vec.x; is.ignore( 2 );
    is >> vec.y; is.ignore( 2 );
    is >> vec.z;
    return is;
}
