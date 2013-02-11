/*
 *  ofQuaternion.h
 *  
 *  Created by Aaron Meyers on 6/22/09 -- modified by Arturo Castro, Zach Lieberman, Memo Akten
 *  based on code from OSG - 
 *  see OSG license for more details: 
 *  http://www.openscenegraph.org/projects/osg/wiki/Legal
 * 
 */

#pragma once
#include "ofConstants.h"
#include "_ofVec.h"
#include <cmath>

#if (_MSC_VER)       
	// make microsoft visual studio complain less about double / float conversion.
	#pragma warning(disable : 4244)
#endif

template <typename T> class _ofMatrix4x4;

template <typename T>
class _ofQuaternion {
public:
    //    T _v[4];
    _ofVec4<T> _v;
    
    inline _ofQuaternion();
    inline _ofQuaternion( T x, T y, T z, T w );
    inline _ofQuaternion( const _ofVec4<T>& v );
    inline _ofQuaternion( T angle,  const _ofVec3<T>& axis );
    inline _ofQuaternion( T angle1, const _ofVec3<T>& axis1, 
						  T angle2, const _ofVec3<T>& axis2, 
						  T angle3, const _ofVec3<T>& axis3 );
    
    inline _ofQuaternion<T>& operator = ( const _ofQuaternion<T>& q );

    inline bool operator == ( const _ofQuaternion<T>& q ) const;
    inline bool operator != ( const _ofQuaternion<T>& q ) const;
    //    inline bool operator <(const _ofQuaternion& q) const;  // why?
        
    inline _ofVec4<T> asVec4() const;
    inline _ofVec3<T> asVec3() const;
    
    inline void set( T x, T y, T z, T w );
    inline void set( const _ofVec4<T>& v );
    
    void set( const _ofMatrix4x4<T>& matrix );
    void get( _ofMatrix4x4<T>& matrix ) const;
    
    inline T& operator []( int i );
    inline T operator []( int i ) const;
    
    inline T& x();
    inline T& y();
    inline T& z();
    inline T& w();
    
    inline T x() const;
    inline T y() const;
    inline T z() const;
    inline T w() const;
    
    // return true if the Quat represents a zero rotation, and therefore can be ignored in computations.
    inline bool zeroRotation() const;
    
    // BASIC ARITHMETIC METHODS
    // Implemented in terms of Vec4s. Some Vec4 operators, e.g.
    // operator* are not appropriate for quaternions (as
    // mathematical objects) so they are implemented differently.
    // Also define methods for conjugate and the multiplicative inverse.
    
    /*! Multiply by scalar. */
    inline const _ofQuaternion<T>  operator *  ( T rhs ) const;                  
    /*! Unary multiply by scalar. */
    inline       _ofQuaternion<T>& operator *= ( T rhs );                            
    /*! Binary multiply. */
    inline const _ofQuaternion<T>  operator *  ( const _ofQuaternion<T>& rhs ) const;     
    /*! Unary multiply. */
    inline       _ofQuaternion<T>& operator *= ( const _ofQuaternion<T>& rhs );               
    /*! Divide by scalar. */
    inline       _ofQuaternion<T>  operator /  ( T rhs ) const;                        
    inline       _ofQuaternion<T>& operator /= ( T rhs );                            // Unary divide by scalar
    inline const _ofQuaternion<T>  operator /  ( const _ofQuaternion<T>& denom ) const;   // Binary divide
    inline       _ofQuaternion<T>& operator /= ( const _ofQuaternion<T>& denom );             // Unary divide
    inline const _ofQuaternion<T>  operator +  ( const _ofQuaternion<T>& rhs   ) const;    // Binary addition
    inline       _ofQuaternion<T>& operator += ( const _ofQuaternion<T>& rhs   );              // Unary addition
    inline const _ofQuaternion<T>  operator -  ( const _ofQuaternion<T>& rhs   ) const;    // Binary subtraction
    inline       _ofQuaternion<T>& operator -= ( const _ofQuaternion<T>& rhs   );              // Unary subtraction
    inline const _ofQuaternion<T>  operator -  () const;                           // returns the negative of the quaternion. calls operator -() on the Vec4 */
    inline _ofVec3<T> operator*( const _ofVec3<T>& v ) const;                       // Rotate a vector by this quaternion.
    
    
    // Length of the quaternion = sqrt(vec . vec)
    inline T length() const;
    
    // Length of the quaternion = vec . vec
    inline T length2() const;
    
    // Conjugate
    inline _ofQuaternion<T> conj() const;
    
    // Multiplicative inverse method: q^(-1) = q^*/(q.q^*)
    inline const _ofQuaternion<T> inverse() const;
    
    
    
    // METHODS RELATED TO ROTATIONS
    // Set a quaternion which will perform a rotation of an
    // angle around the axis given by the vector(x,y,z).
    // Should be written to also accept an angle and a Vec3?
    
    // Define Spherical Linear interpolation method also
    void makeRotate( T angle, T x, T y, T z );
    void makeRotate( T angle,  const _ofVec3<T>& vec );
    void makeRotate( T angle1, const _ofVec3<T>& axis1, 
                     T angle2, const _ofVec3<T>& axis2, 
                     T angle3, const _ofVec3<T>& axis3 );
    
    
    // Make a rotation Quat which will rotate vec1 to vec2.
    // Generally take a dot product to get the angle between these
    // and then use a cross product to get the rotation axis
    // Watch out for the two special cases when the vectors
    // are co-incident or opposite in direction.
    void makeRotate( const _ofVec3<T>& vec1, 
                     const _ofVec3<T>& vec2 );
    
    void makeRotate_original( const _ofVec3<T>& vec1, 
                              const _ofVec3<T>& vec2 );
    
    // Return the angle and vector components represented by the quaternion.
    void getRotate( T& angle, T& x, T& y, T& z ) const;
    void getRotate( T& angle, _ofVec3<T>& vec ) const;
    
    // calculate and return the rotation as euler angles
    _ofVec3<T> getEuler() const;
    
    
    // Spherical Linear Interpolation.
    // As t goes from 0 to 1, the Quat object goes from "from" to "to".
    void slerp( T t, 
                const _ofQuaternion<T>& from, 
                const _ofQuaternion<T>& to );
	
    inline void normalize();
	
	// IO Stream --------------------------------------------------------
	
	inline std::ostream& operator << ( std::ostream& os );
    inline std::istream& operator >> ( std::istream& is );
};


//----------------------------------------
template <typename T>
_ofQuaternion<T>::_ofQuaternion() {
    _v.set( 0, 0, 0, 1 );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>::_ofQuaternion( T x, T y, T z, T w ) {
    _v.set( x, y, z, w );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>::_ofQuaternion( const _ofVec4<T>& v ) {
	_v = v;
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>::_ofQuaternion( T angle, const _ofVec3<T>& axis ) {
	
    makeRotate( angle, axis );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>::_ofQuaternion( T angle1, const _ofVec3<T>& axis1, 
								 T angle2, const _ofVec3<T>& axis2, 
								 T angle3, const _ofVec3<T>& axis3 ) {
	
    makeRotate( angle1, axis1, angle2, axis2, angle3, axis3 );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator = ( const _ofQuaternion<T>& q ) {
	
    _v = q._v;
	
    return *this;
}


//----------------------------------------
template <typename T>
bool _ofQuaternion<T>::operator == ( const _ofQuaternion<T>& q ) 
	const {
	
    return _v == q._v;
}


//----------------------------------------
template <typename T>
bool _ofQuaternion<T>::operator != ( const _ofQuaternion<T>& q ) 
	const {
		
    return _v != q._v;
}


//----------------------------------------
//bool _ofQuaternion<T>::operator <(const _ofQuaternion<T>& q) const {
//    if(_v.x < v._v.x) return true;
//    else if(_v.x > v._v.x) return false;
//    else if(_v.y < v._v.y) return true;
//    else if(_v.y > v._v.y) return false;
//    else if(_v.z < v._v.z) return true;
//    else if(_v.z > v._v.z) return false;
//    else return (_v.w < v._v.w);
//}



//----------------------------------------
template <typename T>
_ofVec4<T> _ofQuaternion<T>::asVec4() const {
    return _v;
}


//----------------------------------------
template <typename T>
_ofVec3<T> _ofQuaternion<T>::asVec3() const {
    return _ofVec3<T>(_v);
}


//----------------------------------------
template <typename T>
void _ofQuaternion<T>::set( T x, T y, T z, T w ) {
    _v.set( x, y, z, w );
}


//----------------------------------------
template <typename T>
void _ofQuaternion<T>::set( const _ofVec4<T>& v ) {
    _v = v;
}


//----------------------------------------
template <typename T>
T& _ofQuaternion<T>::operator []( int i ) {
    return _v[ i ];
}



//----------------------------------------
template <typename T>
T _ofQuaternion<T>::operator []( int i ) const {
    return _v[ i ];
}


//----------------------------------------
template <typename T>
T& _ofQuaternion<T>::x() {
    return _v.x;
}


//----------------------------------------
template <typename T>
T& _ofQuaternion<T>::y() {
    return _v.y;
}


//----------------------------------------
template <typename T>
T& _ofQuaternion<T>::z() {
    return _v.z;
}


//----------------------------------------
template <typename T>
T& _ofQuaternion<T>::w() {
    return _v.w;
}


//----------------------------------------
template <typename T>
T _ofQuaternion<T>::x() const {
    return _v.x;
}


//----------------------------------------
template <typename T>
T _ofQuaternion<T>::y() const {
    return _v.y;
}


//----------------------------------------
template <typename T>
T _ofQuaternion<T>::z() const {
    return _v.z;
}


//----------------------------------------
template <typename T>
T _ofQuaternion<T>::w() const {
    return _v.w;
}


//----------------------------------------
template <typename T>
bool _ofQuaternion<T>::zeroRotation() const {
    return _v.x == 0.0 
	    && _v.y == 0.0 
	    && _v.z == 0.0 
	    && _v.w == 1.0;
}



//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::operator *( T rhs ) 
	const {
	
    return _ofQuaternion<T>( _v.x * rhs, 
							 _v.y * rhs, 
							 _v.z * rhs, 
							 _v.w * rhs );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator *= ( T rhs ) {
	
    _v.x *= rhs;
    _v.y *= rhs;
    _v.z *= rhs;
    _v.w *= rhs;
	
    return *this; // enable nesting
}


//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::operator*(const _ofQuaternion<T>& rhs) const {
    return _ofQuaternion<T>( rhs._v.w * _v.x + rhs._v.x * _v.w + rhs._v.y * _v.z - rhs._v.z * _v.y,
                             rhs._v.w * _v.y - rhs._v.x * _v.z + rhs._v.y * _v.w + rhs._v.z * _v.x,
                             rhs._v.w * _v.z + rhs._v.x * _v.y - rhs._v.y * _v.x + rhs._v.z * _v.w,
                             rhs._v.w * _v.w - rhs._v.x * _v.x - rhs._v.y * _v.y - rhs._v.z * _v.z );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator*=(const _ofQuaternion<T>& rhs) {
    T x  = rhs._v.w * _v.x + rhs._v.x * _v.w + rhs._v.y * _v.z - rhs._v.z * _v.y;
    T y  = rhs._v.w * _v.y - rhs._v.x * _v.z + rhs._v.y * _v.w + rhs._v.z * _v.x;
    T z  = rhs._v.w * _v.z + rhs._v.x * _v.y - rhs._v.y * _v.x + rhs._v.z * _v.w;
    _v.w = rhs._v.w * _v.w - rhs._v.x * _v.x - rhs._v.y * _v.y - rhs._v.z * _v.z;
    
    _v.z = z;
    _v.y = y;
    _v.x = x;
    
    return (*this); // enable nesting
}


//----------------------------------------
template <typename T>
_ofQuaternion<T> _ofQuaternion<T>::operator / ( T rhs ) 
	const {
	
    T div = 1.0 / rhs;
		
    return _ofQuaternion<T>( _v.x * div, 
							 _v.y * div, 
							 _v.z * div, 
							 _v.w * div  );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator /= ( T rhs ) {
    
	T div = 1.0 / rhs;
	
    _v.x *= div;
    _v.y *= div;
    _v.z *= div;
    _v.w *= div;
	
    return *this;
}


//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::operator / ( const _ofQuaternion<T>& denom ) 
	const {
	
    return ( (*this) * denom.inverse() );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator /= ( const _ofQuaternion<T>& denom ) {
    (*this) = (*this) * denom.inverse();
    return (*this); // enable nesting
}


//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::operator + ( const _ofQuaternion<T>& rhs ) 
	const {
		
    return _ofQuaternion<T>( _v.x + rhs._v.x, 
							 _v.y + rhs._v.y,
                             _v.z + rhs._v.z, 
							 _v.w + rhs._v.w );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator += ( const _ofQuaternion<T>& rhs ) {
	
    _v.x += rhs._v.x;
    _v.y += rhs._v.y;
    _v.z += rhs._v.z;
    _v.w += rhs._v.w;
	
    return *this; // enable nesting
}


//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::operator - ( const _ofQuaternion<T>& rhs ) 
	const {
	
    return _ofQuaternion<T>( _v.x - rhs._v.x, 
							 _v.y - rhs._v.y,
                             _v.z - rhs._v.z, 
							 _v.w - rhs._v.w );
}


//----------------------------------------
template <typename T>
_ofQuaternion<T>& _ofQuaternion<T>::operator -= ( const _ofQuaternion<T>& rhs ) {
	
    _v.x -= rhs._v.x;
    _v.y -= rhs._v.y;
    _v.z -= rhs._v.z;
    _v.w -= rhs._v.w;
	
    return *this; // enable nesting
}


//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::operator - () 
	const {
		
    return _ofQuaternion<T>( -_v.x, -_v.y, -_v.z, -_v.w );
}


//----------------------------------------
template <typename T>
T _ofQuaternion<T>::length() 
	const {
    
	return sqrt( _v.x * _v.x + _v.y * _v.y + _v.z * _v.z + _v.w * _v.w );
}


//----------------------------------------
template <typename T>
T _ofQuaternion<T>::length2() 
	const {
    
	return _v.x * _v.x 
	     + _v.y * _v.y 
	     + _v.z * _v.z 
	     + _v.w * _v.w;
}


//----------------------------------------
template <typename T>
_ofQuaternion<T> _ofQuaternion<T>::conj() 
	const {
		
    return _ofQuaternion<T>( -_v.x, -_v.y, -_v.z, _v.w );
}


//----------------------------------------
template <typename T>
const _ofQuaternion<T> _ofQuaternion<T>::inverse() const {
    return conj() / length2();
}



//----------------------------------------
template <typename T>
_ofVec3<T> _ofQuaternion<T>::operator*(const _ofVec3<T>& v) const {
    // nVidia SDK implementation
    _ofVec3<T> uv, uuv;
    _ofVec3<T> qvec( _v.x, _v.y, _v.z );
	
    uv = qvec.getCrossed(v);    //uv = qvec ^ v;
    uuv = qvec.getCrossed(uv);    //uuv = qvec ^ uv;
    uv *= (2.0f * _v.w);
    uuv *= 2.0f;
    return v + uv + uuv;
}

template <typename T>
void _ofQuaternion<T>::normalize(){
	T len = _v.w*_v.w + _v.x*_v.x + _v.y*_v.y + _v.z*_v.z;
	T factor = 1.0f / sqrt(len);
	_v.x *= factor;
	_v.y *= factor;
	_v.z *= factor;
	_v.w *= factor;
}

// IO Stream --------------------------------------------------------

template <typename T>
std::ostream& _ofQuaternion<T>::operator << ( std::ostream& os ) {
	os << _v.x << ", " << _v.y << ", " << _v.z << ", " << _v.w;
	return os;
}

template <typename T>
std::istream& _ofQuaternion<T>::operator >> ( std::istream& is ) {
	is >> _v.x;
	is.ignore(2);
	is >> _v.y;
	is.ignore(2);
	is >> _v.z;
	is.ignore(2);
	is >> _v.w;
	return is;
}

typedef _ofQuaternion<int>    _ofQuaternioni;
typedef _ofQuaternion<float>  _ofQuaternionf;
typedef _ofQuaternion<double> _ofQuaterniond;

// This will be used to keep the same 
// type used on the entire core.
// typedef _ofQuaternionf ofQuaternion;