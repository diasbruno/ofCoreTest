#pragma once

#include "ofVecT.h"

namespace of {
	
// Forward declaration for ofVec2 & 3.
template <typename T> class ofVec2;
template <typename T> class ofVec3;

template<typename T>
class ofVec4 
    : public ofVecT<T> {
public:
    T x, y, z, w;
    
    static const int DIM = 4;
    
    ofVec4()
        : x(0), y(0), z(0), w(0) {}
    
    ofVec4( T _x, T _y, T _z, T _w ) 
        : x(_x), y(_y), z(_z), w(_w) {}
    
    ofVec4( const ofVec4<T>& v ) 
        : x(v.x), y(v.y), z(v.z), w(v.w) {}
    
    template <typename S>
    ofVec4( const ofVec3<S>& v )
        : x(v.x), y(v.y), z(v.z), w(0) {}
	
    // Getters and Setters. -------------------------------------------------
    
	void set( T _scalar );
    void set( T _x, T _y, T _z, T _w );
    void set( const ofVec4<T>& vec );
	
    // Similarity/equality --------------------------------------------------
    
    bool operator == ( const ofVec4<T>& vec ) const;
    bool operator != ( const ofVec4<T>& vec ) const;
    bool match( const ofVec4<T>& vec, T tolerance=0.0001 ) const;
	
    // Overloading for any type to any type ---------------------------------	
    
    template <typename S> ofVec4<T>  operator +  ( const ofVec4<S>& vec ) const;
    template <typename S> ofVec4<T>& operator += ( const ofVec4<S>& vec );
    template <typename S> ofVec4<T>  operator -  ( const S f ) const;
    template <typename S> ofVec4<T>& operator -= ( const S f );
    template <typename S> ofVec4<T>  operator -  ( const ofVec4<S>& vec ) const;
    template <typename S> ofVec4<T>& operator -= ( const ofVec4<S>& vec );
    template <typename S> ofVec4<T>  operator +  ( const S f ) const;
    template <typename S> ofVec4<T>& operator += ( const S f );
	
    template <typename S> ofVec4<T>  operator *  ( const ofVec4<S>& vec ) const;
    template <typename S> ofVec4<T>& operator *= ( const ofVec4<S>& vec );
    template <typename S> ofVec4<T>  operator *  ( const S f ) const;
    template <typename S> ofVec4<T>& operator *= ( const S f );
    template <typename S> ofVec4<T>  operator /  ( const ofVec4<S>& vec ) const;
    template <typename S> ofVec4<T>& operator /= ( const ofVec4<S>& vec );
    template <typename S> ofVec4<T>  operator /  ( const S f ) const;
    template <typename S> ofVec4<T>& operator /= ( const S f );
	
    ofVec4<T> operator - () const;

    template <typename S> friend ostream& operator<<(ostream& os, const ofVec4<S>& vec);
    template <typename S> friend istream& operator>>(istream& is, const ofVec4<S>& vec);
	
    // Scaling --------------------------------------------------------------
    
    ofVec4<T>  getScaled( const T length ) const;
    ofVec4<T>&     scale( const T length );
	
    // Distance between two points ------------------------------------------
    
    T       distance( const ofVec4<T>& pnt) const;
    T squareDistance( const ofVec4<T>& pnt ) const;
	
    // Linear interpolation -------------------------------------------------
    
    /**
	 * p==0.0 results in this point, 
     * p==0.5 results in the midpoint, and 
     * p==1.0 results in pnt being returned.
	 */
    ofVec4<T>  getInterpolated( const ofVec4<T>& pnt, T p ) const;
    ofVec4<T>&     interpolate( const ofVec4<T>& pnt, T p );
    ofVec4<T>        getMiddle( const ofVec4<T>& pnt ) const;
    ofVec4<T>&          middle( const ofVec4<T>& pnt );
    ofVec4<T>&         average( const ofVec4<T>* points, int num );
    
	
    /** Dot Product. */
    T dot( const ofVec4<T>& vec ) const;

    // Normalization --------------------------------------------------------
    
    ofVec4<T>  getNormalized() const;
    ofVec4<T>&     normalize();
	
    // Limit length ---------------------------------------------------------
    
	ofVec4<T>  getLimited( T max ) const;
    ofVec4<T>&      limit( T max );
	
    // Length ---------------------------------------------------------------
    
    T        length() const;
    T lengthSquared() const;
	OF_DEPRECATED_MSG("Use ofVec4<T>::lengthSquared() instead.", T squareLength() const);
	
	//
    // Deprecated -----------------------------------------------------------
    // Since: v006
    //
    
    // getScaled
    ofVec4<T> rescaled( const T length ) const;
	
    // scale
    ofVec4<T>& rescale( const T length );
	
    // getNormalized
    ofVec4<T> normalized() const;
	
    // getLimited
    ofVec4<T> limited(T max) const;
	
    // use squareDistance
    T  distanceSquared( const ofVec4<T>& pnt ) const;
	
    // use getInterpolated
    ofVec4<T> 	interpolated( const ofVec4<T>& pnt, T p ) const;
	
    // use getMiddle
    ofVec4<T> 	middled( const ofVec4<T>& pnt ) const;    
    

    // return all zero vector
    static ofVec4<T> zero() { return ofVec4<T>(0, 0, 0, 0); }
    
    // return all one vector
    static ofVec4<T> one() { return ofVec4<T>(1, 1, 1, 1); }

};

//
// Implementation ---------------------------------------------
//


// Getters and Setters. -------------------------------------------------

template<typename T>
inline void ofVec4<T>::set( T _x, T _y, T _z, T _w ) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

template<typename T>
inline void ofVec4<T>::set( const ofVec4<T>& vec ) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}


// Similarity/equality --------------------------------------------------

template<typename T>
inline bool ofVec4<T>::operator==( const ofVec4<T>& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
}

template<typename T>
inline bool ofVec4<T>::operator!=( const ofVec4<T>& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z) || (w != vec.w);
}

template<typename T>
inline bool ofVec4<T>::match( const ofVec4<T>& vec, T tolerance) const {
	return ( fabs(x - vec.x) < tolerance )
        && ( fabs(y - vec.y) < tolerance )
        && ( fabs(z - vec.z) < tolerance )
        && ( fabs(w - vec.w) < tolerance );
}

// Overloading for any type to any type ---------------------------------	

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator+( const ofVec4<S>& vec ) const {
	return ofVec4<T>( x+vec.x, y+vec.y, z+vec.z, w+vec.w);
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator+=( const ofVec4<S>& vec ) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
	return *this;
}

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator-( const S f ) const {
	return ofVec4<T>( x-f, y-f, z-f, w-f );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator-=( const S f ) {
	x -= f;
	y -= f;
	z -= f;
	w -= f;
	return *this;
}

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator-( const ofVec4<S>& vec ) const {
	return ofVec4<T>( x-vec.x, y-vec.y, z-vec.z, w-vec.w );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator-=( const ofVec4<S>& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
	return *this;
}

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator+( const S f ) const {
	return ofVec4<T>( x+f, y+f, z+f, w+f );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator+=( const S f ) {
	x += f;
	y += f;
	z += f;
	w += f;
	return *this;
}

template<typename T>
inline ofVec4<T> ofVec4<T>::operator-() const {
	return ofVec4<T>( -x, -y, -z, -w );
}


template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator*( const ofVec4<S>& vec ) const {
	return ofVec4<T>( x*vec.x, y*vec.y, z*vec.z, w*vec.w );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator*=( const ofVec4<S>& vec ) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	w *= vec.w;
	return *this;
}

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator*( const S f ) const {
	return ofVec4<T>( x*f, y*f, z*f, w*f );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator*=( const S f ) {
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator/( const ofVec4<S>& vec ) const {
	return ofVec4<T>( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z, vec.w!=0 ? w/vec.w : w  );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator/=( const ofVec4<S>& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	vec.w!=0 ? w/=vec.w : w;
	return *this;
}

template<typename T>
template<typename S>
inline ofVec4<T> ofVec4<T>::operator/( const S f ) const {
	if(f == 0) return ofVec4<T>(x, y, z, w);
	
	return ofVec4<T>( x/f, y/f, z/f, w/f );
}

template<typename T>
template<typename S>
inline ofVec4<T>& ofVec4<T>::operator/=( const S f ) {
	if(f == 0)return *this;
	
	x /= f;
	y /= f;
	z /= f;
	w /= f;
	return *this;
}

template<typename S>
inline ostream& operator<<(ostream& os, const ofVec4<S>& vec) {
	os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
	return os;
}

template<typename S>
inline istream& operator>>(istream& is, ofVec4<S>& vec) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	is.ignore(2);
	is >> vec.z;
	is.ignore(2);
	is >> vec.w;
	return is;
}

// Scaling --------------------------------------------------------------

template<typename T>
inline ofVec4<T> ofVec4<T>::rescaled( const T length ) const {
	return getScaled(length);
}

template<typename T>
inline ofVec4<T> ofVec4<T>::getScaled( const T length ) const {
	T l = (T)sqrt(x*x + y*y + z*z + w*w);
	if( l > 0 )
		return ofVec4<T>( (x/l)*length, (y/l)*length,
					   (z/l)*length, (w/l)*length );
	else
		return ofVec4<T>();
}

template<typename T>
inline ofVec4<T>& ofVec4<T>::rescale( const T length ) {
	return scale(length);
}

template<typename T>
inline ofVec4<T>& ofVec4<T>::scale( const T length ) {
	T l = (T)sqrt(x*x + y*y + z*z + w*w);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
		z = (z/l)*length;
		w = (w/l)*length;
	}
	return *this;
}

// Distance between two points ------------------------------------------

template<typename T>
inline T ofVec4<T>::distance( const ofVec4<T>& pnt) const {
	T vx = x-pnt.x;
	T vy = y-pnt.y;
	T vz = z-pnt.z;
	T vw = w-pnt.w;
	return (T)sqrt( vx*vx + vy*vy + vz*vz + vw*vw );
}

template<typename T>
inline T ofVec4<T>::distanceSquared( const ofVec4<T>& pnt ) const {
	return squareDistance(pnt);
}

template<typename T>
inline T ofVec4<T>::squareDistance( const ofVec4<T>& pnt ) const {
	T vx = x-pnt.x;
	T vy = y-pnt.y;
	T vz = z-pnt.z;
	T vw = w-pnt.w;
	return vx*vx + vy*vy + vz*vz + vw*vw;
}

// Linear interpolation -------------------------------------------------

/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */
template<typename T>
inline ofVec4<T> ofVec4<T>::interpolated( const ofVec4<T>& pnt, T p ) const{
	return getInterpolated(pnt,p);
}

template<typename T>
inline ofVec4<T> ofVec4<T>::getInterpolated( const ofVec4<T>& pnt, T p ) const {
	return ofVec4<T>( x*(1-p) + pnt.x*p,
				   y*(1-p) + pnt.y*p,
				   z*(1-p) + pnt.z*p,
				   w*(1-p) + pnt.w*p );
}

template<typename T>
inline ofVec4<T>& ofVec4<T>::interpolate( const ofVec4<T>& pnt, T p ) {
	x = x*(1-p) + pnt.x*p;
	y = y*(1-p) + pnt.y*p;
	z = z*(1-p) + pnt.z*p;
	w = w*(1-p) + pnt.w*p;
	return *this;
}

template<typename T>
inline ofVec4<T> ofVec4<T>::middled( const ofVec4<T>& pnt ) const {
	return getMiddle(pnt);
}

template<typename T>
inline ofVec4<T> ofVec4<T>::getMiddle( const ofVec4<T>& pnt ) const {
	return ofVec4<T>( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f,
				   (z+pnt.z)/2.0f, (w+pnt.w)/2.0f );
}

template<typename T>
inline ofVec4<T>& ofVec4<T>::middle( const ofVec4<T>& pnt ) {
	x = (x+pnt.x)/2.0f;
	y = (y+pnt.y)/2.0f;
	z = (z+pnt.z)/2.0f;
	w = (w+pnt.w)/2.0f;
	return *this;
}


/*! Average (centroid) among points.
    (Addition is sometimes useful for calculating averages too). */
template<typename T>
inline ofVec4<T>& ofVec4<T>::average( const ofVec4<T>* points, int num ) {
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;
	for( int i=0; i<num; i++) {
		x += points[i].x;
		y += points[i].y;
		z += points[i].z;
		w += points[i].w;
	}
	x /= num;
	y /= num;
	z /= num;
	w /= num;
	return *this;
}

// Normalization --------------------------------------------------------

template<typename T>
inline ofVec4<T> ofVec4<T>::normalized() const {
	return getNormalized();
}

template<typename T>
inline ofVec4<T> ofVec4<T>::getNormalized() const {
	T length = (T)sqrt(x*x + y*y + z*z + w*w);
	if( length > 0 ) {
		return ofVec4<T>( x/length, y/length, z/length, w/length );
	} else {
		return ofVec4<T>();
	}
}

template<typename T>
inline ofVec4<T>& ofVec4<T>::normalize() {
	T lenght = (T)sqrt(x*x + y*y + z*z + w*w);
	if( lenght > 0 ) {
		x /= lenght;
		y /= lenght;
		z /= lenght;
		w /= lenght;
	}
	return *this;
}

// Limit length ---------------------------------------------------------

template<typename T>
inline ofVec4<T> ofVec4<T>::limited(T max) const {
	return getLimited(max);
}

template<typename T>
inline ofVec4<T> ofVec4<T>::getLimited(T max) const {
    ofVec4<T> limited;
    T lengthSquared = (x*x + y*y + z*z + w*w);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio, w*ratio );
    } else {
        limited.set(x,y,z,w);
    }
    return limited;
}

template<typename T>
inline ofVec4<T>& ofVec4<T>::limit(T max) {
    T lengthSquared = (x*x + y*y + z*z + w*w);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
        w *= ratio;
    }
    return *this;
}

// Length ---------------------------------------------------------------

template<typename T>
inline T ofVec4<T>::length() const {
	return (T)sqrt( x*x + y*y + z*z + w*w );
}

template<typename T>
inline T ofVec4<T>::lengthSquared() const {
	return (T)(x*x + y*y + z*z + w*w);
}

template<typename T>
inline T ofVec4<T>::squareLength() const {
	return lengthSquared();
}

/**
 * Dot Product.
 */
template<typename T>
inline T ofVec4<T>::dot( const ofVec4<T>& vec ) const {
	return x*vec.x + y*vec.y + z*vec.z + w*vec.w;
}

}
