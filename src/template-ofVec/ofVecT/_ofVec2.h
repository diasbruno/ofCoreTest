#pragma once

#include "_ofVecT.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

namespace of {

// Forward declaration for ofVec3 & 4.
template <typename T> class ofVec3;
template <typename T> class ofVec4;

template <typename T>
class ofVec2 {
	//	: public ofVecT<T> {
public:
    T x, y;
    
    static const int DIM = 2;
    
    ofVec2()
	: x(0), y(0) {}
	
    explicit ofVec2( T _scalar )
	: x(_scalar), y(_scalar) {}
	
    ofVec2( T _x, T _y )
	: x(_x), y(_y) {}
    
	ofVec2( const ofVec3<T>& vec )
	: x(vec.x), y(vec.y) {}
	
	ofVec2( const ofVec4<T>& vec )
	: x(vec.x), y(vec.y) {}
	
    // Getters and Setters. -------------------------------------------------
    
    void set( T _scalar );
    void set( T _x, T _y );
    void set( const ofVec2<T>& vec );
	
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
    
    bool operator == ( const ofVec2<T>& vec ) const;
    bool operator != ( const ofVec2<T>& vec ) const;
    
    bool match( const ofVec2<T>& vec, T tolerance=0.0001 ) const;
	
    // Overloading for any type to any type ---------------------------------
    
    ofVec2<T>  operator +  ( const ofVec2<T>& vec ) const;
    ofVec2<T>& operator += ( const ofVec2<T>& vec );
    ofVec2<T>  operator -  ( const ofVec2<T>& vec ) const;
    ofVec2<T>& operator -= ( const ofVec2<T>& vec );
    ofVec2<T>  operator *  ( const ofVec2<T>& vec ) const;
    ofVec2<T>& operator *= ( const ofVec2<T>& vec );
    ofVec2<T>  operator /  ( const ofVec2<T>& vec ) const;
    ofVec2<T>& operator /= ( const ofVec2<T>& vec );
    
    ofVec2<T>  operator +  ( const T f ) const;
    ofVec2<T>& operator += ( const T f );
    ofVec2<T>  operator -  ( const T f ) const;
    ofVec2<T>& operator -= ( const T f );
    ofVec2<T>  operator *  ( const T f ) const;
    ofVec2<T>& operator *= ( const T f );
    ofVec2<T>  operator /  ( const T f ) const;
    ofVec2<T>& operator /= ( const T f );
	
    ofVec2<T> operator - () const;
	
    // Alignment ------------------------------------------------------------
    
    /**
     * Checks if vectors look in the same direction.
     * Tolerance is specified in degree.
     */
    bool    isAligned( const ofVec2<T>& vec, T tolerance=0.0001 ) const;
    bool isAlignedRad( const ofVec2<T>& vec, T tolerance=0.0001 ) const;
    bool        align( const ofVec2<T>& vec, T tolerance=0.0001 ) const;
    bool     alignRad( const ofVec2<T>& vec, T tolerance=0.0001 ) const;
    
    // Scaling --------------------------------------------------------------
    
    ofVec2<T>  getScaled( const T length ) const;
    ofVec2<T>&     scale( const T length );
    
    // Rotation -------------------------------------------------------------
    
    ofVec2<T>     getRotated( T angle ) const;
    ofVec2<T>  getRotatedRad( T angle ) const;
    ofVec2<T>&        rotate( T angle );
    ofVec2<T>&     rotateRad( T angle );
    
    // Rotation - point around pivot ----------------------------------------
    
    ofVec2<T>     getRotated( T angle, const ofVec2<T>& pivot ) const;
    ofVec2<T>&        rotate( T angle, const ofVec2<T>& pivot );
    ofVec2<T>  getRotatedRad( T angle, const ofVec2<T>& pivot ) const;
    ofVec2<T>&     rotateRad( T angle, const ofVec2<T>& pivot );
    
    // Map point to coordinate system defined by origin, vx, and vy ---------
	
    ofVec2<T> getMapped( const ofVec2<T>& origin,
						const ofVec2<T>& vx,
						const ofVec2<T>& vy ) 
	const;
    ofVec2<T>&      map( const ofVec2<T>& origin,
						const ofVec2<T>& vx, 
						const ofVec2<T>& vy );
    
    // Distance between two points ------------------------------------------
    
    T       distance( const ofVec2<T>& pnt ) const;
    T squareDistance( const ofVec2<T>& pnt ) const;
    
    // Linear interpolation -------------------------------------------------
    
    /**
     * p == 0.0 results in this point, 
     * p == 0.5 results in the midpoint, and 
     * p == 1.0 results in pnt being returned.
     */
    ofVec2<T>   getInterpolated( const ofVec2<T>& pnt, T p ) const;
    ofVec2<T>&      interpolate( const ofVec2<T>& pnt, T p );
    ofVec2<T>         getMiddle( const ofVec2<T>& pnt ) const;
    ofVec2<T>&           middle( const ofVec2<T>& pnt );
    ofVec2<T>&          average( const ofVec2<T>* points, int num );
    
    // Normalization --------------------------------------------------------
    
    ofVec2<T>  getNormalized() const;
    ofVec2<T>&     normalize();
    
    // Limit length ---------------------------------------------------------
    
    ofVec2<T>  getLimited( T max ) const;
    ofVec2<T>&      limit( T max );
    
    // Perpendicular normalized vector --------------------------------------
    
    ofVec2<T>  getPerpendicular() const;
    ofVec2<T>&    perpendicular();
    
    // Length ---------------------------------------------------------------
    
    T          length() const;
    T   lengthSquared() const;
    OF_DEPRECATED_MSG( "Use ofVec2<T>::lengthSquared() instead.", 
					  T squareLength() const);
    
    // Angle ----------------------------------------------------------------
    
    /**
     * Angle (deg) between two vectors.
     * This is a signed relative angle between -180 and 180.
     */
    T    angle( const ofVec2<T>& vec ) const;
    T angleRad( const ofVec2<T>& vec ) const;
    
    /**
     * Dot Product.
     */
    T dot( const ofVec2<T>& vec ) const;
    
    // IOS Stream ----------------------------------------------------------
	
    template <typename S> friend ostream& operator << ( ostream& os, const ofVec2<S>& vec );
    template <typename S> friend istream& operator >> ( istream& is, const ofVec2<S>& vec );
    
    //
    // Deprecated -----------------------------------------------------------
    // Since: v006
    // 
    
    // getScaled
    ofVec2<T> rescaled( const T length ) const;
    
    // scale
    ofVec2<T>& rescale( const T length );
    
    // getRotated
    ofVec2<T> rotated( T angle ) const;
    
    // getNormalized
    ofVec2<T> normalized() const;
    
    // getLimited
    ofVec2<T> limited(T max) const;
    
    // getPerpendicular
    ofVec2<T> perpendiculared() const;
    
    // getInterpolated
    ofVec2<T> interpolated( const ofVec2<T>& pnt, T p ) const;
    
    // getMiddled
    ofVec2<T> middled( const ofVec2<T>& pnt ) const;
    
    // getMapped 
    ofVec2<T> mapped( const ofVec2<T>& origin, const ofVec2<T>& vx, const ofVec2<T>& vy ) const;
    
    // squareDistance
    T distanceSquared( const ofVec2<T>& pnt ) const;
    
    // use getRotated
    ofVec2<T> rotated( T angle, const ofVec2<T>& pivot ) const;    
    
    // return all zero vector
    static ofVec2<T> zero() { return ofVec2<T>(0, 0); }
    
    // return all one vector
    static ofVec2<T> one() { return ofVec2<T>(1, 1); }
};

//
// Implementation -------------------------------------------------------
//


// Getters and Setters. -------------------------------------------------

template <typename T>
inline void ofVec2<T>::set( T _scalar ) {
    x = _scalar;
    y = _scalar;
}

template <typename T>
inline void ofVec2<T>::set( T _x, T _y ) {
    x = _x;
    y = _y;
}

template <typename T>
inline void ofVec2<T>::set( const ofVec2<T>& vec ) {
    x = vec.x;
    y = vec.y;
}


// Similarity/equality --------------------------------------------------

template <typename T>
inline bool ofVec2<T>::operator==( const ofVec2<T>& vec ) const {
    return (x == vec.x) && (y == vec.y);
}

template <typename T>
inline bool ofVec2<T>::operator!=( const ofVec2<T>& vec ) const {
    return (x != vec.x) || (y != vec.y);
}

template <typename T>
inline bool ofVec2<T>::match( const ofVec2<T>& vec, T tolerance ) const {
    return (fabs(x - vec.x) < tolerance)
    && (fabs(y - vec.y) < tolerance);
}

// Overloading for any type to any type ---------------------------------

template <typename T>
inline ofVec2<T> ofVec2<T>::operator+( const ofVec2<T>& vec ) const {
    return ofVec2<T>( x+vec.x, y+vec.y);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator+=( const ofVec2<T>& vec ) {
    x += vec.x;
    y += vec.y;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator-( const ofVec2<T>& vec ) const {
    return ofVec2<T>(x-vec.x, y-vec.y);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator-=( const ofVec2<T>& vec ) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator*( const ofVec2<T>& vec ) const {
    return ofVec2<T>(x*vec.x, y*vec.y);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator*=( const ofVec2<T>& vec ) {
    x*=vec.x;
    y*=vec.y;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator/( const ofVec2<T>& vec ) const {
    return ofVec2<T>( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator/=( const ofVec2<T>& vec ) {
    vec.x!=0 ? x/=vec.x : x;
    vec.y!=0 ? y/=vec.y : y;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator+( const T f ) const {
    return ofVec2<T>( x+f, y+f);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator+=( const T f ) {
    x += f;
    y += f;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator-( const T f ) const {
    return ofVec2<T>( x-f, y-f);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator-=( const T f ) {
    x -= f;
    y -= f;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator-() const {
    return ofVec2<T>(-x, -y);
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator*( const T f ) const {
    return ofVec2<T>(x*f, y*f);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator*=( const T f ) {
    x*=f;
    y*=f;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::operator/( const T f ) const {
    if(f == 0) return ofVec2<T>(x, y);
    
    return ofVec2<T>(x/f, y/f);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::operator/=( const T f ) {
    if(f == 0) return *this;
    
    x/=f;
    y/=f;
    return *this;
}

// Alignment ------------------------------------------------------------

/**
 * Checks if vectors look in the same direction.
 * Tolerance is specified in degree.
 */
template <typename T>
inline bool ofVec2<T>::isAligned( const ofVec2<T>& vec, T tolerance ) const { 
	return  fabs( this->angle( vec ) ) < tolerance;
}

template <typename T>
inline bool ofVec2<T>::align( const ofVec2<T>& vec, T tolerance ) const {
	return isAligned( vec, tolerance );
}

template <typename T>
inline bool ofVec2<T>::isAlignedRad( const ofVec2<T>& vec, T tolerance ) const {
	return  fabs( this->angleRad( vec ) ) < tolerance;
}

template <typename T>
inline bool ofVec2<T>::alignRad( const ofVec2<T>& vec, T tolerance ) const {
	return isAlignedRad( vec, tolerance );
}

// Scaling --------------------------------------------------------------

template <typename T>
inline ofVec2<T> ofVec2<T>::rescaled( const T length ) const {
    return getScaled(length);
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getScaled( const T length ) const {
    T l = (T)sqrt(x*x + y*y);
    if( l > 0 )
        return ofVec2<T>( (x/l)*length, (y/l)*length );
    else
        return ofVec2<T>();
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::rescale( const T length ){
    return scale(length);
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::scale( const T length ) {
    T l = (T)sqrt(x*x + y*y);
    if (l > 0) {
        x = (x/l)*length;
        y = (y/l)*length;
    }
    return *this;
}



// Rotation
//
//
template <typename T>
inline ofVec2<T> ofVec2<T>::rotated( T angle ) const {
    return getRotated(angle);
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getRotated( T angle ) const {
    T a = (T)(angle*DEG_TO_RAD);
    return ofVec2<T>( x*cos(a) - y*sin(a),
                     x*sin(a) + y*cos(a) );
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getRotatedRad( T angle ) const {
    T a = angle;
    return ofVec2<T>( x*cos(a) - y*sin(a),
                     x*sin(a) + y*cos(a) );
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::rotate( T angle ) {
    T a = (T)(angle * DEG_TO_RAD);
    T xrot = x*cos(a) - y*sin(a);
    y = x*sin(a) + y*cos(a);
    x = xrot;
    return *this;
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::rotateRad( T angle ) {
    T a = angle;
    T xrot = x*cos(a) - y*sin(a);
    y = x*sin(a) + y*cos(a);
    x = xrot;
    return *this;
}



// Rotate point by angle (deg) around pivot point.
//
//

// This method is deprecated in 006 please use getRotated instead
template <typename T>
inline ofVec2<T> ofVec2<T>::rotated( T angle, const ofVec2<T>& pivot ) const {
    return getRotated(angle, pivot);
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getRotated( T angle, const ofVec2<T>& pivot ) const {
    T a = (T)(angle * DEG_TO_RAD);
    return ofVec2<T>( ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x,
                     ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y );
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::rotate( T angle, const ofVec2<T>& pivot ) {
    T a = (T)(angle * DEG_TO_RAD);
    T xrot = ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x;
    y = ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y;
    x = xrot;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getRotatedRad( T angle, const ofVec2<T>& pivot ) const {
    T a = angle;
    return ofVec2<T>( ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x,
                     ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y );
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::rotateRad( T angle, const ofVec2<T>& pivot ) {
    T a = angle;
    T xrot = ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x;
    y = ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y;
    x = xrot;
    return *this;
}



// Map point to coordinate system defined by origin, vx, and vy ---------

template <typename T>
inline ofVec2<T> ofVec2<T>::getMapped( const ofVec2<T>& origin,
									  const ofVec2<T>& vx,
									  const ofVec2<T>& vy ) const
{
    return ofVec2<T>( origin.x + x*vx.x + y*vy.x,
                     origin.y + x*vx.y + y*vy.y );
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::map( const ofVec2<T>& origin,
								 const ofVec2<T>& vx, 
								 const ofVec2<T>& vy )
{
    T xmap = origin.x + x*vx.x + y*vy.x;
    y = origin.y + x*vx.y + y*vy.y;
    x = xmap;
    return *this;
}

// This method is deprecated in 006 please use getMapped instead
template <typename T>
inline ofVec2<T> ofVec2<T>::mapped( const ofVec2<T>& origin,
								   const ofVec2<T>& vx,
								   const ofVec2<T>& vy ) const{
    return getMapped(origin, vx, vy);
}

// Distance between two points ------------------------------------------

template <typename T>
inline T ofVec2<T>::distance( const ofVec2<T>& pnt) const {
    T vx = x-pnt.x;
    T vy = y-pnt.y;
    return (T)sqrt(vx*vx + vy*vy);
}

//this method is deprecated in 006 please use squareDistance
template <typename T>
inline T ofVec2<T>::distanceSquared( const ofVec2<T>& pnt ) const {
    return squareDistance(pnt);
}

template <typename T>
inline T ofVec2<T>::squareDistance( const ofVec2<T>& pnt ) const {
    T vx = x-pnt.x;
    T vy = y-pnt.y;
    return vx*vx + vy*vy;
}

// Linear interpolation -------------------------------------------------

/**
 * p == 0.0 results in this point, 
 * p == 0.5 results in the midpoint, and 
 * p == 1.0 results in pnt being returned.
 */
template <typename T>
inline ofVec2<T> ofVec2<T>::getInterpolated( const ofVec2<T>& pnt, T p ) const {
    return ofVec2<T>( x*(1-p) + pnt.x*p, y*(1-p) + pnt.y*p );
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::interpolate( const ofVec2<T>& pnt, T p ) {
    x = x*(1-p) + pnt.x*p;
    y = y*(1-p) + pnt.y*p;
    return *this;
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getMiddle( const ofVec2<T>& pnt ) const {
    return ofVec2<T>( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f );
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::middle( const ofVec2<T>& pnt ) {
    x = (x+pnt.x)/2.0f;
    y = (y+pnt.y)/2.0f;
    return *this;
}

/*! this method is deprecated in 006 please use getInterpolated. */
template <typename T>
inline ofVec2<T> ofVec2<T>::interpolated( const ofVec2<T>& pnt, T p ) const{
    return getInterpolated(pnt, p);
}

/*! this method is deprecated in 006 please use getMiddle */
template <typename T>
inline ofVec2<T> ofVec2<T>::middled( const ofVec2<T>& pnt ) const{
    return getMiddle(pnt);
}

/*! Average (centroid) among points.
 Addition is sometimes useful for calculating averages too. */
template <typename T>
inline ofVec2<T>& ofVec2<T>::average( const ofVec2<T>* points, int num ) {
    x = 0.f;
    y = 0.f;
    for( int i=0; i<num; i++) {
        x += points[i].x;
        y += points[i].y;
    }
    x /= num;
    y /= num;
    return *this;
}

// Normalization --------------------------------------------------------

template <typename T>
inline ofVec2<T> ofVec2<T>::normalized() const {
    return getNormalized();
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getNormalized() const {
    T length = (T)sqrt(x*x + y*y);
    if( length > 0 ) {
        return ofVec2<T>( x/length, y/length );
    } else {
        return ofVec2<T>();
    }
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::normalize() {
    T length = (T)sqrt(x*x + y*y);
    if( length > 0 ) {
        x /= length;
        y /= length;
    }
    return *this;
}

// Limit length ---------------------------------------------------------

template <typename T>
inline ofVec2<T> ofVec2<T>::limited(T max) const{
    return getLimited(max);
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getLimited(T max) const {
    ofVec2<T> limited;
    T lengthSquared = (x*x + y*y);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio);
    } else {
        limited.set(x,y);
    }
    return limited;
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::limit(T max) {
    T lengthSquared = (x*x + y*y);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
    }
    return *this;
}

// Perpendicular normalized vector --------------------------------------

template <typename T>
inline ofVec2<T> ofVec2<T>::perpendiculared() const {
    return getPerpendicular();
}

template <typename T>
inline ofVec2<T> ofVec2<T>::getPerpendicular() const {
    T length = (T)sqrt( x*x + y*y );
    if( length > 0 )
        return ofVec2<T>( -(y/length), x/length );
    else
        return ofVec2<T>();
}

template <typename T>
inline ofVec2<T>& ofVec2<T>::perpendicular() {
    T length = (T)sqrt( x*x + y*y );
    if( length > 0 ) {
        T _x = x;
        x = -(y/length);
        y = _x/length;
    }
    return *this;
}

// Length ---------------------------------------------------------------

template <typename T>
inline T ofVec2<T>::length() const {
    return (T)sqrt( x*x + y*y );
}

template <typename T>
inline T ofVec2<T>::lengthSquared() const {
    return (T)(x*x + y*y);
}

template <typename T>
inline T ofVec2<T>::squareLength() const {
    return lengthSquared();
}

// Angle ----------------------------------------------------------------

/*! Angle (deg) between two vectors.
 This is a signed relative angle between -180 and 180. */
template <typename T>
inline T ofVec2<T>::angle( const ofVec2<T>& vec ) const {
    return (T)(atan2( x*vec.y-y*vec.x, x*vec.x + y*vec.y )*RAD_TO_DEG);
}

/*! Angle (deg) between two vectors.
 This is a signed relative angle between -180 and 180. */
template <typename T>
inline T ofVec2<T>::angleRad( const ofVec2<T>& vec ) const {
    return atan2( x*vec.y-y*vec.x, x*vec.x + y*vec.y );
}


/*! Dot Product. */
template <typename T>
inline T ofVec2<T>::dot( const ofVec2<T>& vec ) const {
    return x*vec.x + y*vec.y;
}

template <typename T, typename S>
inline ostream& operator<<(ostream& os, const ofVec2<S>& vec) {
    os << vec.x << ", " << vec.y;
    return os;
}

template <typename T, typename S>
inline istream& operator>>(istream& is, ofVec2<S>& vec) {
    is >> vec.x;
    is.ignore(2);
    is >> vec.y;
    return is;
}

}