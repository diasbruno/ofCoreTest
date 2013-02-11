
#include "_ofVec4.h"

// Getters and Setters. -------------------------------------------------

template <typename T> inline 
void _ofVec4<T>::set( T _x, T _y, T _z, T _w ) {
	
    x = _x;
	y = _y;
	z = _z;
	w = _w;
}

template <typename T> inline 
void _ofVec4<T>::set( const _ofVec4<T>& vec ) {

	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}

// Similarity/equality --------------------------------------------------

template<typename T> inline 
bool _ofVec4<T>::match( const _ofVec4<T>& vec, T tolerance ) const {
	
    return ( fabs( x - vec.x ) < tolerance )
	    && ( fabs( y - vec.y ) < tolerance )
	    && ( fabs( z - vec.z ) < tolerance )
    	&& ( fabs( w - vec.w ) < tolerance );
}

// Scaling --------------------------------------------------------------

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::rescaled( const T length ) const {

	return getScaled( length );
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::getScaled( const T length ) const {

	T len = (T)sqrt( x * x + y * y + z * z + w * w);
	
    if( len > 0 ) {
		return _ofVec4<T>( 
            ( x / len ) * length, // x
            ( y / len ) * length, // y
            ( z / len ) * length, // z
            ( w / len ) * length  // w
        );

    } else {
		return _ofVec4<T>();
    }
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::rescale( const T length ) {
	return scale(length);
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::scale( const T length ) {

	T len = (T)sqrt( x * x + y * y + z * z + w * w );
	
    if ( len > 0 ) {
		x = ( x / len ) * length;
		y = ( y / len ) * length;
		z = ( z / len ) * length;
		w = ( w / len ) * length;
	}

	return *this;
}

// Distance between two points ------------------------------------------

template <typename T> inline 
T _ofVec4<T>::distance( const _ofVec4<T>& pnt) const {

	T vx = x - pnt.x;
	T vy = y - pnt.y;
	T vz = z - pnt.z;
	T vw = w - pnt.w;

	return (T)sqrt( vx * vx + vy * vy + vz * vz + vw * vw );
}

template <typename T> inline 
T _ofVec4<T>::distanceSquared( const _ofVec4<T>& pnt ) const {

	return squareDistance( pnt );
}

template <typename T> inline 
T _ofVec4<T>::squareDistance( const _ofVec4<T>& pnt ) const {

	T vx = x - pnt.x;
	T vy = y - pnt.y;
	T vz = z - pnt.z;
	T vw = w - pnt.w;

	return vx * vx + vy * vy + vz * vz + vw * vw;
}

// Linear interpolation -------------------------------------------------

/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */
template <typename T> inline 
_ofVec4<T> _ofVec4<T>::interpolated( const _ofVec4<T>& pnt, T p ) const {

	return getInterpolated( pnt, p );
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::getInterpolated( const _ofVec4<T>& pnt, T p ) const {

	return _ofVec4<T>( 
        x * ( 1 - p ) + pnt.x * p, // x
		y * ( 1 - p ) + pnt.y * p, // y
		z * ( 1 - p ) + pnt.z * p, // z
		w * ( 1 - p ) + pnt.w * p  // w
    );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::interpolate( const _ofVec4<T>& pnt, T p ) {

	x = x * ( 1 - p ) + pnt.x * p;
	y = y * ( 1 - p ) + pnt.y * p;
	z = z * ( 1 - p ) + pnt.z * p;
	w = w * ( 1 - p ) + pnt.w * p;
	
    return *this;
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::middled( const _ofVec4<T>& pnt ) const {

	return getMiddle( pnt );
}

template<typename T>
inline _ofVec4<T> _ofVec4<T>::getMiddle( const _ofVec4<T>& pnt ) const {

	return _ofVec4<T>( 
        ( x + pnt.x ) / 2.0f, // x
        ( y + pnt.y ) / 2.0f, // y
		( z + pnt.z ) / 2.0f, // z
        ( w + pnt.w ) / 2.0f  // w
    );
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::middle( const _ofVec4<T>& pnt ) {

	x = ( x + pnt.x ) / 2.0f;
	y = ( y + pnt.y ) / 2.0f;
	z = ( z + pnt.z ) / 2.0f;
	w = ( w + pnt.w ) / 2.0f;

	return *this;
}


/*! Average (centroid) among points.
 (Addition is sometimes useful for calculating averages too). */
template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::average( const _ofVec4<T>* points, int num ) {

	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;

	for( int i = 0; i < num; i++ ) {
		x += points[ i ].x;
		y += points[ i ].y;
		z += points[ i ].z;
		w += points[ i ].w;
	}

	x /= num;
	y /= num;
	z /= num;
	w /= num;

	return *this;
}

// Normalization --------------------------------------------------------

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::normalized() const {

	return getNormalized();
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::getNormalized() const {
	
    T length = (T)sqrt( x * x + y * y + z * z + w * w );
	
    if( length > 0 ) {
		return _ofVec4<T>(
            x / length, 
            y / length, 
            z / length, 
            w / length 
        );
	} else {
		return _ofVec4<T>();
	}
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::normalize() {

	T lenght = (T)sqrt( x * x + y * y + z * z + w * w );
	
    if( lenght > 0 ) {
		x /= lenght;
		y /= lenght;
		z /= lenght;
		w /= lenght;
	}

	return *this;
}

// Limit length ---------------------------------------------------------

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::limited( T max ) const {

	return getLimited( max );
}

template <typename T> inline 
_ofVec4<T> _ofVec4<T>::getLimited(T max) const {

    _ofVec4<T> limited;
    T lengthSquared = ( x * x + y * y + z * z + w * w );
    
    if( lengthSquared > max * max 
    &&  lengthSquared > 0 ) {
    
        T ratio = max / (T)sqrt( lengthSquared );
        limited.set( x * ratio, y * ratio, z * ratio, w * ratio );
    
    } else {
        limited.set( x, y, z, w );
    }

    return limited;
}

template <typename T> inline 
_ofVec4<T>& _ofVec4<T>::limit( T max ) {

    T lengthSquared = ( x * x + y * y + z * z + w * w );

    if ( lengthSquared > max * max 
    &&   lengthSquared > 0 ) {
    
        T ratio = max / (T)sqrt( lengthSquared );
        x *= ratio;
        y *= ratio;
        z *= ratio;
        w *= ratio;
    }
    
    return *this;
}

// Length ---------------------------------------------------------------

template <typename T> inline 
T _ofVec4<T>::length() const {
	
    return (T)sqrt( x * x + y * y + z * z + w * w );
}

template <typename T> inline 
T _ofVec4<T>::lengthSquared() const {

	return (T)( x * x + y * y + z * z + w * w );
}

template <typename T> inline 
T _ofVec4<T>::squareLength() const {
	
    return lengthSquared();
}

/*! Dot Product. */
template<typename T>
inline T _ofVec4<T>::dot( const _ofVec4<T>& vec ) const {
	return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

// Expanded at compiler time?
template class _ofVec4<int>;
template class _ofVec4<float>;
template class _ofVec4<double>;
