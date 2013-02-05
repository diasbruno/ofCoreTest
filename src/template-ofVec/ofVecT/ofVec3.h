#pragma once

#include "ofVecT.h"
#include "ofVec2.h"
#include "ofVec4.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

namespace of {
	
template <typename T>
class ofVec3
    : public ofVecT<T> {
public:
    T x, y, z;
    
    static const int DIM = 3;
    
    ofVec3()
    : x(0), y(0), z(0) {}

    ofVec3( T _x, T _y, T _z = 0 )
    : x(_x), y(_y), z(0) {}
    
    /// assigns scalar to x, y, and z
    template <typename S>
    explicit ofVec3( S _scalar )
		: x(_scalar), y(_scalar), z(_scalar) {};
    
    template <typename S>
    ofVec3( const ofVec2<S>& vec )
		: x(vec.x), y(vec.y), z(0) {}
    
//        template <typename S>
//        ofVec3( const ofVec4<S>& vec )
//        : x(vec.x), y(vec.y), z(vec.z) {}
    
    
    // Getters and Setters. -------------------------------------------------
    
    void set( T _x, T _y, T _z = 0 );
    void set( const ofVec3<T>& vec );
    void set( T _scalar );
    
    // Similarity/equality --------------------------------------------------
    
    template <typename S> bool operator == ( const ofVec3<S>& vec ) const;
    template <typename S> bool operator != ( const ofVec3<S>& vec ) const;

    bool match( const ofVec3<T>& vec, T tolerance ) const;
    
    // Overloading for any type to any type ---------------------------------	
    
    template <typename S> ofVec3<T>  operator +  ( const ofVec3<S>& vec ) const;
    template <typename S> ofVec3<T>& operator += ( const ofVec3<S>& vec );
    template <typename S> ofVec3<T>  operator -  ( const ofVec3<S>& vec ) const;
    template <typename S> ofVec3<T>& operator -= ( const ofVec3<S>& vec );
    template <typename S> ofVec3<T>  operator *  ( const ofVec3<S>& vec ) const;
    template <typename S> ofVec3<T>& operator *= ( const ofVec3<S>& vec );
    template <typename S> ofVec3<T>  operator /  ( const ofVec3<S>& vec ) const;
    template <typename S> ofVec3<T>& operator /= ( const ofVec3<S>& vec );

    template <typename S> ofVec3<T>  operator +  ( const S f ) const;
    template <typename S> ofVec3<T>& operator += ( const S f );
    template <typename S> ofVec3<T>  operator -  ( const S f ) const;
    template <typename S> ofVec3<T>& operator -= ( const S f );
    template <typename S> ofVec3<T>  operator *  ( const S f ) const;
    template <typename S> ofVec3<T>& operator *= ( const S f );
    template <typename S> ofVec3<T>  operator /  ( const S f ) const;
    template <typename S> ofVec3<T>& operator /= ( const S f );
    
    ofVec3<T>  operator - () const;
        
    // Alignment ------------------------------------------------------------
    
    /*! Checks if vectors look in the same direction. */
    bool    isAligned( const ofVec3<T>& vec, T tolerance ) const;
    bool        align( const ofVec3<T>& vec, T tolerance ) const;
    bool isAlignedRad( const ofVec3<T>& vec, T tolerance ) const;
    bool     alignRad( const ofVec3<T>& vec, T tolerance ) const;

    // Scaling --------------------------------------------------------------		
    
    ofVec3<T>  getScaled( const T length ) const;
    ofVec3<T>&     scale( const T length );
    
    // Rotation -------------------------------------------------------------
    
    ofVec3<T>     getRotated( T angle, const ofVec3<T>& axis ) const;
    ofVec3<T>  getRotatedRad( T angle, const ofVec3<T>& axis ) const;
    ofVec3<T>&        rotate( T angle, const ofVec3<T>& axis );
    ofVec3<T>&     rotateRad( T angle, const ofVec3<T>& axis );
    ofVec3<T>     getRotated( T ax, T ay, T az ) const;
    ofVec3<T>  getRotatedRad( T ax, T ay, T az ) const;
    ofVec3<T>&        rotate( T ax, T ay, T az );
    ofVec3<T>&     rotateRad( T ax, T ay, T az );
    
    // Rotation - point around pivot ----------------------------------------
    
    ofVec3<T>     getRotated( T angle, const ofVec3<T>& pivot, const ofVec3<T>& axis ) const;
    ofVec3<T>&        rotate( T angle, const ofVec3<T>& pivot, const ofVec3<T>& axis );
    ofVec3<T>  getRotatedRad( T angle, const ofVec3<T>& pivot, const ofVec3<T>& axis ) const;
    ofVec3<T>&     rotateRad( T angle, const ofVec3<T>& pivot, const ofVec3<T>& axis );    
    
    // Map point to coordinate system defined by origin, vx, and vy ---------
    
    ofVec3<T>  getMapped( const ofVec3<T>& origin,
                          const ofVec3<T>& vx,
                          const ofVec3<T>& vy,
                          const ofVec3<T>& vz ) 
                          const;
    ofVec3<T>&       map( const ofVec3<T>& origin,
                          const ofVec3<T>& vx,
                          const ofVec3<T>& vy,
                          const ofVec3<T>& vz );
    
    // Distance between two points ------------------------------------------
    
    T       distance( const ofVec3<T>& pnt) const;
    T squareDistance( const ofVec3<T>& pnt ) const;
    
    // Linear interpolation -------------------------------------------------
    
    /**
     * p == 0.0 results in this point, 
     * p == 0.5 results in the midpoint, and 
     * p == 1.0 results in pnt being returned.
     */
    ofVec3<T>  getInterpolated( const ofVec3<T>& pnt, T p ) const;
    ofVec3<T>&     interpolate( const ofVec3<T>& pnt, T p );
    ofVec3<T>        getMiddle( const ofVec3<T>& pnt ) const;
    ofVec3<T>&          middle( const ofVec3<T>& pnt );
    ofVec3<T>&         average( const ofVec3<T>* points, int num );
    
    // Normalization --------------------------------------------------------
    
    ofVec3<T>  getNormalized() const;
    ofVec3<T>&     normalize();
    
    // Limit length ---------------------------------------------------------
    
    ofVec3<T> getLimited( T max ) const;
    ofVec3<T>&     limit( T max );
    
    // Perpendicular normalized vector --------------------------------------
    
    ofVec3<T>        getCrossed( const ofVec3<T>& vec ) const;
    ofVec3<T>&            cross( const ofVec3<T>& vec );
    /*! Normalized perpendicular. */
    ofVec3<T>  getPerpendicular( const ofVec3<T>& vec ) const;
    ofVec3<T>&    perpendicular( const ofVec3<T>& vec );
    
    // Dot Product ----------------------------------------------------------
    
    T dot( const ofVec3<T>& vec ) const;

    // Length ---------------------------------------------------------------
    
    T        length() const;
    T lengthSquared() const;

    OF_DEPRECATED_MSG( "Use ofVec3<T>::lengthSquared() instead.", 
                       T squareLength() const );

    // Angle ----------------------------------------------------------------

    /**
     * Angle (deg) between two vectors.
     * This is an unsigned relative angle from 0 to 180.
     * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
     */
    T    angle( const ofVec3<T>& vec ) const;
    T angleRad( const ofVec3<T>& vec ) const;
    
    template <typename S> friend ostream& operator << ( ostream& os, const ofVec3<S>& vec );
    template <typename S> friend istream& operator >> ( istream& is, const ofVec3<S>& vec );
    
    //
    // Deprecated -----------------------------------------------------------
    // Since: v006
    // 
    
    // getScaled
    ofVec3<T> rescaled( const T length ) const;
    
    // scale
    ofVec3<T>& rescale( const T length );
    
    // getRotated
    ofVec3<T> rotated( T angle, const ofVec3<T>& axis ) const;
    
    // getRotated should this be const???
    ofVec3<T> rotated( T ax, T ay, T az );
    
    // getNormalized
    ofVec3<T> normalized() const;
    
    // getLimited
    ofVec3<T> limited( T max) const;
    
    // getCrossed
    ofVec3<T> crossed( const ofVec3<T>& vec ) const;
    
    // getPerpendicular
    ofVec3<T> perpendiculared( const ofVec3<T>& vec ) const;
    
    // use getMapped
    ofVec3<T> mapped( const ofVec3<T>& origin,
                      const ofVec3<T>& vx,
                      const ofVec3<T>& vy,
                      const ofVec3<T>& vz ) const;
    
    // use squareDistance
    T distanceSquared( const ofVec3<T>& pnt ) const;
    
    // use getInterpolated
    ofVec3<T> interpolated( const ofVec3<T>& pnt, T p ) const;
    
    // use getMiddle
    ofVec3<T> middled( const ofVec3<T>& pnt ) const;
    
    // use getRotated
    ofVec3<T> rotated( T angle,
                       const ofVec3<T>& pivot,
                       const ofVec3<T>& axis ) const;    
    
    // return all zero vector
    static ofVec3<T> zero() { return ofVec3<T>(0, 0, 0); }
    
    // return all one vector
    static ofVec3<T> one() { return ofVec3<T>(1, 1, 1); }
};

//
// Implementation -----------------------------------------------
//

// Getters and Setters. -------------------------------------------------

template <typename T>
inline void ofVec3<T>::set( T _scalar ) {
    x = _scalar;
    y = _scalar;
    z = _scalar;
}

template <typename T>
inline void ofVec3<T>::set( T _x, T _y, T _z ) {
    x = _x;
    y = _y;
    z = _z;
}

template <typename T>
inline void ofVec3<T>::set( const ofVec3<T>& vec ) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

// Similarity/equality --------------------------------------------------

template <typename T>
template <typename S>
inline bool ofVec3<T>::operator==( const ofVec3<S>& vec ) const {
    return (x == vec.x) && (y == vec.y) && (z == vec.z);
}

template <typename T>
template <typename S>
inline bool ofVec3<T>::operator!=( const ofVec3<S>& vec ) const {
    return (x != vec.x) || (y != vec.y) || (z != vec.z);
}

template <typename T>
inline bool ofVec3<T>::match( const ofVec3<T>& vec, T tolerance ) const{
    return (fabs(x - vec.x) < tolerance)
    && (fabs(y - vec.y) < tolerance)
    && (fabs(z - vec.z) < tolerance);
}

// Alignment ------------------------------------------------------------

/*! Checks if vectors look in the same direction. */
template <typename T>
inline bool ofVec3<T>::isAligned( const ofVec3<T>& vec, T tolerance ) const {
    T angle = this->angle( vec );
    return  angle < tolerance;
}

template <typename T>
inline bool ofVec3<T>::align( const ofVec3<T>& vec, T tolerance ) const {
    return isAligned( vec, tolerance );
}

template <typename T>
inline bool ofVec3<T>::isAlignedRad( const ofVec3<T>& vec, T tolerance ) const {
    T angle = this->angleRad( vec );
    return  angle < tolerance;
}

template <typename T>
inline bool ofVec3<T>::alignRad( const ofVec3<T>& vec, T tolerance ) const {
    return isAlignedRad( vec, tolerance );
}


// Overloading for any type to any type ---------------------------------	

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator+( const ofVec3<S>& pnt ) const {
    return ofVec3<T>( x+pnt.x, y+pnt.y, z+pnt.z );
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator+=( const ofVec3<S>& pnt ) {
    x+=pnt.x;
    y+=pnt.y;
    z+=pnt.z;
    return *this;
}

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator-( const ofVec3<S>& vec ) const {
    return ofVec3<T>( x-vec.x, y-vec.y, z-vec.z );
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator-=( const ofVec3<S>& vec ) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator*( const ofVec3<S>& vec ) const {
    return ofVec3<T>( x*vec.x, y*vec.y, z*vec.z );
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator*=( const ofVec3<S>& vec ) {
    x*=vec.x;
    y*=vec.y;
    z*=vec.z;
    return *this;
}

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator/( const ofVec3<S>& vec ) const {
    return ofVec3<T>( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z );
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator/=( const ofVec3<S>& vec ) {
    vec.x!=0 ? x/=vec.x : x;
    vec.y!=0 ? y/=vec.y : y;
    vec.z!=0 ? z/=vec.z : z;
    return *this;
}

template <typename T>
inline ofVec3<T> ofVec3<T>::operator-() const {
    return ofVec3<T>( -x, -y, -z );
}


template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator+( const S f ) const {
    return ofVec3<T>( x+f, y+f, z+f);
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator+=( const S f ) {
    x += f;
    y += f;
    z += f;
    return *this;
}

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator-( const S f ) const {
    return ofVec3<T>( x-f, y-f, z-f);
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator-=( const S f ) {
    x -= f;
    y -= f;
    z -= f;
    return *this;
}

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator*( const S f ) const {
    return ofVec3<T>( x*f, y*f, z*f );
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator*=( const S f ) {
    x*=f;
    y*=f;
    z*=f;
    return *this;
}

template <typename T>
template <typename S>
inline ofVec3<T> ofVec3<T>::operator/( const S f ) const {
    if(f == 0) return ofVec3<T>( x, y, z);
    
    return ofVec3<T>( x/f, y/f, z/f );
}

template <typename T>
template <typename S>
inline ofVec3<T>& ofVec3<T>::operator/=( const S f ) {
    if(f == 0) return *this;
    
    x/=f;
    y/=f;
    z/=f;
    return *this;
}

// Scaling --------------------------------------------------------------

template <typename T>
inline ofVec3<T> ofVec3<T>::rescaled( const T length ) const {
    return getScaled(length);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getScaled( const T length ) const {
    T l = (T)sqrt(x*x + y*y + z*z);
    if( l > 0 )
        return ofVec3<T>( (x/l)*length, (y/l)*length, (z/l)*length );
    else
        return ofVec3<T>();
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::rescale( const T length ) {
    return scale(length);
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::scale( const T length ) {
    T l = (T)sqrt(x*x + y*y + z*z);
    if (l > 0) {
        x = (x/l)*length;
        y = (y/l)*length;
        z = (z/l)*length;
    }
    return *this;
}

// Rotation -------------------------------------------------------------

template <typename T>
inline ofVec3<T> ofVec3<T>::rotated( T angle, const ofVec3<T>& axis ) const {
    return getRotated(angle, axis);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getRotated( T angle, const ofVec3<T>& axis ) const {
    ofVec3<T> ax = axis.normalized();
    T a = (T)(angle*DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    return ofVec3<T>( x*(ax.x*ax.x*cosb + cosa)
                     + y*(ax.x*ax.y*cosb - ax.z*sina)
                     + z*(ax.x*ax.z*cosb + ax.y*sina),
                     x*(ax.y*ax.x*cosb + ax.z*sina)
                     + y*(ax.y*ax.y*cosb + cosa)
                     + z*(ax.y*ax.z*cosb - ax.x*sina),
                     x*(ax.z*ax.x*cosb - ax.y*sina)
                     + y*(ax.z*ax.y*cosb + ax.x*sina)
                     + z*(ax.z*ax.z*cosb + cosa) );
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getRotatedRad( T angle, const ofVec3<T>& axis ) const {
    ofVec3<T> ax = axis.normalized();
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    return ofVec3<T>( x*(ax.x*ax.x*cosb + cosa)
                     + y*(ax.x*ax.y*cosb - ax.z*sina)
                     + z*(ax.x*ax.z*cosb + ax.y*sina),
                     x*(ax.y*ax.x*cosb + ax.z*sina)
                     + y*(ax.y*ax.y*cosb + cosa)
                     + z*(ax.y*ax.z*cosb - ax.x*sina),
                     x*(ax.z*ax.x*cosb - ax.y*sina)
                     + y*(ax.z*ax.y*cosb + ax.x*sina)
                     + z*(ax.z*ax.z*cosb + cosa) );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::rotate( T angle, const ofVec3<T>& axis ) {
    ofVec3<T> ax = axis.normalized();
    T a = (T)(angle*DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T nx = x*(ax.x*ax.x*cosb + cosa)
    + y*(ax.x*ax.y*cosb - ax.z*sina)
    + z*(ax.x*ax.z*cosb + ax.y*sina);
    T ny = x*(ax.y*ax.x*cosb + ax.z*sina)
    + y*(ax.y*ax.y*cosb + cosa)
    + z*(ax.y*ax.z*cosb - ax.x*sina);
    T nz = x*(ax.z*ax.x*cosb - ax.y*sina)
    + y*(ax.z*ax.y*cosb + ax.x*sina)
    + z*(ax.z*ax.z*cosb + cosa);
    x = nx; y = ny; z = nz;
    return *this;
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::rotateRad(T angle, const ofVec3<T>& axis ) {
    ofVec3<T> ax = axis.normalized();
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T nx = x*(ax.x*ax.x*cosb + cosa)
    + y*(ax.x*ax.y*cosb - ax.z*sina)
    + z*(ax.x*ax.z*cosb + ax.y*sina);
    T ny = x*(ax.y*ax.x*cosb + ax.z*sina)
    + y*(ax.y*ax.y*cosb + cosa)
    + z*(ax.y*ax.z*cosb - ax.x*sina);
    T nz = x*(ax.z*ax.x*cosb - ax.y*sina)
    + y*(ax.z*ax.y*cosb + ax.x*sina)
    + z*(ax.z*ax.z*cosb + cosa);
    x = nx; y = ny; z = nz;
    return *this;
}

// const???
template <typename T>
inline ofVec3<T> ofVec3<T>::rotated(T ax, T ay, T az) {
    return getRotated(ax,ay,az);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getRotated(T ax, T ay, T az) const {
    T a = (T)cos(DEG_TO_RAD*(ax));
    T b = (T)sin(DEG_TO_RAD*(ax));
    T c = (T)cos(DEG_TO_RAD*(ay));
    T d = (T)sin(DEG_TO_RAD*(ay));
    T e = (T)cos(DEG_TO_RAD*(az));
    T f = (T)sin(DEG_TO_RAD*(az));
    
    T nx = c * e * x - c * f * y + d * z;
    T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
    T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
    
    return ofVec3<T>( nx, ny, nz );
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getRotatedRad(T ax, T ay, T az) const {
    T a = cos(ax);
    T b = sin(ax);
    T c = cos(ay);
    T d = sin(ay);
    T e = cos(az);
    T f = sin(az);
    
    T nx = c * e * x - c * f * y + d * z;
    T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
    T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
    
    return ofVec3<T>( nx, ny, nz );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::rotate(T ax, T ay, T az) {
    T a = (T)cos(DEG_TO_RAD*(ax));
    T b = (T)sin(DEG_TO_RAD*(ax));
    T c = (T)cos(DEG_TO_RAD*(ay));
    T d = (T)sin(DEG_TO_RAD*(ay));
    T e = (T)cos(DEG_TO_RAD*(az));
    T f = (T)sin(DEG_TO_RAD*(az));
    
    T nx = c * e * x - c * f * y + d * z;
    T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
    T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
    
    x = nx; y = ny; z = nz;
    return *this;
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::rotateRad(T ax, T ay, T az) {
    T a = cos(ax);
    T b = sin(ax);
    T c = cos(ay);
    T d = sin(ay);
    T e = cos(az);
    T f = sin(az);
    
    T nx = c * e * x - c * f * y + d * z;
    T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
    T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
    
    x = nx; y = ny; z = nz;
    return *this;
}


// Rotation - point around pivot ----------------------------------------

template <typename T>
inline ofVec3<T> ofVec3<T>::rotated( T angle,
                                    const ofVec3<T>& pivot,
                                    const ofVec3<T>& axis ) const{
    return getRotated(angle, pivot, axis);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getRotated( T angle,
                                       const ofVec3<T>& pivot,
                                       const ofVec3<T>& axis ) const
{
    ofVec3<T> ax = axis.normalized();
    T tx = x - pivot.x;
    T ty = y - pivot.y;
    T tz = z - pivot.z;
    
    T a = (T)(angle*DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = tx*(ax.x*ax.x*cosb + cosa)
    + ty*(ax.x*ax.y*cosb - ax.z*sina)
    + tz*(ax.x*ax.z*cosb + ax.y*sina);
    T yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
    + ty*(ax.y*ax.y*cosb + cosa)
    + tz*(ax.y*ax.z*cosb - ax.x*sina);
    T zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
    + ty*(ax.z*ax.y*cosb + ax.x*sina)
    + tz*(ax.z*ax.z*cosb + cosa);
    
    
    return ofVec3<T>( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getRotatedRad( T angle,
                                          const ofVec3<T>& pivot,
                                          const ofVec3<T>& axis ) const
{
    ofVec3<T> ax = axis.normalized();
    T tx = x - pivot.x;
    T ty = y - pivot.y;
    T tz = z - pivot.z;
    
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = tx*(ax.x*ax.x*cosb + cosa)
    + ty*(ax.x*ax.y*cosb - ax.z*sina)
    + tz*(ax.x*ax.z*cosb + ax.y*sina);
    T yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
    + ty*(ax.y*ax.y*cosb + cosa)
    + tz*(ax.y*ax.z*cosb - ax.x*sina);
    T zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
    + ty*(ax.z*ax.y*cosb + ax.x*sina)
    + tz*(ax.z*ax.z*cosb + cosa);
    
    
    return ofVec3<T>( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::rotate( T angle,
                                    const ofVec3<T>& pivot,
                                    const ofVec3<T>& axis )
{
    ofVec3<T> ax = axis.normalized();
    x -= pivot.x;
    y -= pivot.y;
    z -= pivot.z;
    
    T a = (T)(angle*DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = x*(ax.x*ax.x*cosb + cosa)
    + y*(ax.x*ax.y*cosb - ax.z*sina)
    + z*(ax.x*ax.z*cosb + ax.y*sina);
    T yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
    + y*(ax.y*ax.y*cosb + cosa)
    + z*(ax.y*ax.z*cosb - ax.x*sina);
    T zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
    + y*(ax.z*ax.y*cosb + ax.x*sina)
    + z*(ax.z*ax.z*cosb + cosa);
    
    x = xrot + pivot.x;
    y = yrot + pivot.y;
    z = zrot + pivot.z;
    
    return *this;
}


template <typename T>
inline ofVec3<T>& ofVec3<T>::rotateRad( T angle,
                                       const ofVec3<T>& pivot,
                                       const ofVec3<T>& axis )
{
    ofVec3<T> ax = axis.normalized();
    x -= pivot.x;
    y -= pivot.y;
    z -= pivot.z;
    
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = x*(ax.x*ax.x*cosb + cosa)
    + y*(ax.x*ax.y*cosb - ax.z*sina)
    + z*(ax.x*ax.z*cosb + ax.y*sina);
    T yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
    + y*(ax.y*ax.y*cosb + cosa)
    + z*(ax.y*ax.z*cosb - ax.x*sina);
    T zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
    + y*(ax.z*ax.y*cosb + ax.x*sina)
    + z*(ax.z*ax.z*cosb + cosa);
    
    x = xrot + pivot.x;
    y = yrot + pivot.y;
    z = zrot + pivot.z;
    
    return *this;
}

// Map point to coordinate system defined by origin, vx, vy, and vz -----

template <typename T>
inline ofVec3<T> ofVec3<T>::mapped( const ofVec3<T>& origin,
                                   const ofVec3<T>& vx,
                                   const ofVec3<T>& vy,
                                   const ofVec3<T>& vz ) const{
    return getMapped(origin, vx, vy, vz);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getMapped( const ofVec3<T>& origin,
                                      const ofVec3<T>& vx,
                                      const ofVec3<T>& vy,
                                      const ofVec3<T>& vz ) const
{
    return ofVec3<T>( origin.x + x*vx.x + y*vy.x + z*vz.x,
                     origin.y + x*vx.y + y*vy.y + z*vz.y,
                     origin.z + x*vx.z + y*vy.z + z*vz.z );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::map( const ofVec3<T>& origin,
                                 const ofVec3<T>& vx,
                                 const ofVec3<T>& vy,
                                 const ofVec3<T>& vz )
{
    T xmap = origin.x + x*vx.x + y*vy.x + z*vz.x;
    T ymap =  origin.y + x*vx.y + y*vy.y + z*vz.y;
    z = origin.z + x*vx.z + y*vy.z + z*vz.z;
    x = xmap;
    y = ymap;
    return *this;
}

// Distance between two points ------------------------------------------

template <typename T>
inline T ofVec3<T>::distance( const ofVec3<T>& pnt) const {
    T vx = x-pnt.x;
    T vy = y-pnt.y;
    T vz = z-pnt.z;
    return (T)sqrt(vx*vx + vy*vy + vz*vz);
}

template <typename T>
inline T  ofVec3<T>::distanceSquared( const ofVec3<T>& pnt ) const{
    return squareDistance(pnt);
}

template <typename T>
inline T  ofVec3<T>::squareDistance( const ofVec3<T>& pnt ) const {
    T vx = x-pnt.x;
    T vy = y-pnt.y;
    T vz = z-pnt.z;
    return vx*vx + vy*vy + vz*vz;
}

// Linear interpolation -------------------------------------------------

/**
 * p == 0.0 results in this point, 
 * p == 0.5 results in the midpoint, and 
 * p == 1.0 results in pnt being returned.
 */
template <typename T>
inline ofVec3<T> ofVec3<T>::interpolated( const ofVec3<T>& pnt, T p ) const {
    return getInterpolated(pnt,p);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getInterpolated( const ofVec3<T>& pnt, T p ) const {
    return ofVec3<T>( x*(1-p) + pnt.x*p,
                     y*(1-p) + pnt.y*p,
                     z*(1-p) + pnt.z*p );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::interpolate( const ofVec3<T>& pnt, T p ) {
    x = x*(1-p) + pnt.x*p;
    y = y*(1-p) + pnt.y*p;
    z = z*(1-p) + pnt.z*p;
    return *this;
}

template <typename T>
inline ofVec3<T> ofVec3<T>::middled( const ofVec3<T>& pnt ) const {
    return getMiddle(pnt);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getMiddle( const ofVec3<T>& pnt ) const {
    return ofVec3<T>( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f, (z+pnt.z)/2.0f );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::middle( const ofVec3<T>& pnt ) {
    x = (x+pnt.x)/2.0f;
    y = (y+pnt.y)/2.0f;
    z = (z+pnt.z)/2.0f;
    return *this;
}


/*! Average (centroid) among points.
    Addition is sometimes useful for calculating averages too. */
template <typename T>
inline ofVec3<T>& ofVec3<T>::average( const ofVec3<T>* points, int num ) {
    x = 0.f;
    y = 0.f;
    z = 0.f;
    for( int i=0; i<num; i++) {
        x += points[i].x;
        y += points[i].y;
        z += points[i].z;
    }
    x /= num;
    y /= num;
    z /= num;
    return *this;
}

// Normalization --------------------------------------------------------

template <typename T>
inline ofVec3<T> ofVec3<T>::normalized() const {
    return getNormalized();
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getNormalized() const {
    T length = (T)sqrt(x*x + y*y + z*z);
    if( length > 0 ) {
        return ofVec3<T>( x/length, y/length, z/length );
    } else {
        return ofVec3<T>();
    }
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::normalize() {
    T length = (T)sqrt(x*x + y*y + z*z);
    if( length > 0 ) {
        x /= length;
        y /= length;
        z /= length;
    }
    return *this;
}

// Limit length ---------------------------------------------------------

template <typename T>
inline ofVec3<T> ofVec3<T>::limited(T max) const {
    return getLimited(max);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getLimited(T max) const {
    ofVec3<T> limited;
    T lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio);
    } else {
        limited.set(x,y,z);
    }
    return limited;
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::limit(T max) {
    T lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
    }
    return *this;
}

// Perpendicular normalized vector --------------------------------------

template <typename T>
inline ofVec3<T> ofVec3<T>::crossed( const ofVec3<T>& vec ) const {
    return getCrossed(vec);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getCrossed( const ofVec3<T>& vec ) const {
    return ofVec3<T>( y*vec.z - z*vec.y,
                     z*vec.x - x*vec.z,
                     x*vec.y - y*vec.x );
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::cross( const ofVec3<T>& vec ) {
    T _x = y*vec.z - z*vec.y;
    T _y = z*vec.x - x*vec.z;
    z = x*vec.y - y*vec.x;
    x = _x;
    y = _y;
    return *this;
}

/*! Normalized perpendicular. */
template <typename T>
inline ofVec3<T> ofVec3<T>::perpendiculared( const ofVec3<T>& vec ) const {
    return getPerpendicular(vec);
}

template <typename T>
inline ofVec3<T> ofVec3<T>::getPerpendicular( const ofVec3<T>& vec ) const {
    T crossX = y*vec.z - z*vec.y;
    T crossY = z*vec.x - x*vec.z;
    T crossZ = x*vec.y - y*vec.x;
    
    T length = (T)sqrt(crossX*crossX +
                       crossY*crossY +
                       crossZ*crossZ);
    
    if( length > 0 )
        return ofVec3<T>( crossX/length, crossY/length, crossZ/length );
    else
        return ofVec3<T>();
}

template <typename T>
inline ofVec3<T>& ofVec3<T>::perpendicular( const ofVec3<T>& vec ) {
    T crossX = y*vec.z - z*vec.y;
    T crossY = z*vec.x - x*vec.z;
    T crossZ = x*vec.y - y*vec.x;
    
    T length = (T)sqrt(crossX*crossX +
                       crossY*crossY +
                       crossZ*crossZ);
    
    if( length > 0 ) {
        x = crossX/length;
        y = crossY/length;
        z = crossZ/length;
    } else {
        x = 0.f;
        y = 0.f;
        z = 0.f;
    }
    
    return *this;
}

// Dot Product ----------------------------------------------------------

/*! Dot Product. */
template <typename T>
inline T ofVec3<T>::dot( const ofVec3<T>& vec ) const {
    return x*vec.x + y*vec.y + z*vec.z;
}

// Length ---------------------------------------------------------------

template <typename T>
inline T ofVec3<T>::length() const {
    return (T)sqrt( x*x + y*y + z*z );
}

template <typename T>
inline T ofVec3<T>::lengthSquared() const {
    return (T)(x*x + y*y + z*z);
}

template <typename T>
inline T ofVec3<T>::squareLength() const {
    return lengthSquared();
}

// Angle ----------------------------------------------------------------

/**
 * Angle (deg) between two vectors.
 * This is an unsigned relative angle from 0 to 180.
 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
 */
template <typename T>
inline T ofVec3<T>::angle( const ofVec3<T>& vec ) const {
    ofVec3<T> n1 = this->normalized();
    ofVec3<T> n2 = vec.normalized();
    return (T)(acos( n1.dot(n2) )*RAD_TO_DEG);
}

template <typename T>
inline T ofVec3<T>::angleRad( const ofVec3<T>& vec ) const {
    ofVec3<T> n1 = this->normalized();
    ofVec3<T> n2 = vec.normalized();
    return (T)acos( n1.dot(n2) );
}


template <typename S>
inline ostream& operator<<(ostream& os, const ofVec3<S>& vec) {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}

template <typename S>
inline istream& operator>>(istream& is, ofVec3<S>& vec) {
    is >> vec.x;
    is.ignore(2);
    is >> vec.y;
    is.ignore(2);
    is >> vec.z;
    return is;
}

}
