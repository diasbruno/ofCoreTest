
#include "_ofVec2.h"

// Pythagoras

// pow hypotenuse
#define P_HYPOTENUSE( x, y ) x * x + y * y
#define HYPOTENUSE( x, y ) sqrt( P_HYPOTENUSE( x, y ) )

// Dot Product

#define DOT_XYV2( x, y, vec ) x * vec.x + y * vec.y
#define DOT_YXV2( x, y, vec ) x * vec.y - y * vec.x

// Getters and Setters. -------------------------------------------------

template <typename T> inline 
void _ofVec2<T>::set( T _scalar ) {
	x = _scalar;
	y = _scalar;
}

template <typename T> inline 
void _ofVec2<T>::set( T _x, T _y ) {
	x = _x;
	y = _y;
}

template <typename T> inline 
void _ofVec2<T>::set( const _ofVec2<T>& v ) {
	x = v.x;
	y = v.y;
}

// Similarity/equality --------------------------------------------------

template <typename T> inline 
bool _ofVec2<T>::match( const _ofVec2<T>& v, T tolerance ) const {
    return (fabs( x - v.x ) < tolerance)
		&& (fabs( y - v.y ) < tolerance);
}

// Alignment ------------------------------------------------------------

/**
 * Checks if vectors look in the same direction.
 * Tolerance is specified in degree.
 */
template <typename T> inline 
bool _ofVec2<T>::isAligned( const _ofVec2<T>& v, T tolerance ) const { 
	return  fabs( this->angle( v ) ) < tolerance;
}

template <typename T> inline 
bool _ofVec2<T>::align( const _ofVec2<T>& v, T tolerance ) const {
	return isAligned( v, tolerance );
}

template <typename T> inline 
bool _ofVec2<T>::isAlignedRad( const _ofVec2<T>& v, T tolerance ) const {
	return  fabs( this->angleRad( v ) ) < tolerance;
}

template <typename T> inline 
bool _ofVec2<T>::alignRad( const _ofVec2<T>& v, T tolerance ) const {
	return isAlignedRad( v, tolerance );
}

// Scaling --------------------------------------------------------------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::rescaled( const T length ) const {
    return getScaled(length);
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getScaled( const T length ) const {
	
    T len = (T)HYPOTENUSE( x, y );
    
	if( len > 0 ) {
        return _ofVec2<T>( ( x / len ) * length, 
						   ( y / len ) * length );
	} else {
		return _ofVec2<T>();
	}
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::rescale( const T length ) {
	
    return scale( length );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::scale( const T length ) {
	
    T len = (T)HYPOTENUSE( x, y );
    
	if ( len > 0 ) {
        x = ( x / len ) * length;
        y = ( y / len ) * length;
    }
	
    return *this;
}

// Rotation ---------------------------------------------------------------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::rotated( T angle ) const {
	
    return getRotated( angle );
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getRotated( T angle ) const {
	
    T a = (T)( angle * DEG_TO_RAD );
	
    return _ofVec2<T>( x * cos( a ) - y * sin( a ),
					   x * sin( a ) + y * cos( a ) );
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getRotatedRad( T angle ) const {
	
    T a = angle;
	
    return _ofVec2<T>( x * cos( a ) - y * sin( a ),
					   x * sin( a ) + y * cos( a ) );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::rotate( T angle ) {
	
    T a = (T)( angle * DEG_TO_RAD );
    T xrot = x * cos( a ) - y * sin( a );
	
    y = x * sin( a ) + y * cos( a );
    x = xrot;
	
    return *this;
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::rotateRad( T angle ) {
	
    T a = angle;
    T xrot = x * cos( a ) - y * sin( a );
	
    y = x * sin( a ) + y * cos( a );
    x = xrot;
	
    return *this;
}

// Rotate point by angle (deg) around pivot point. ----------------------

// This method is deprecated in 006 please use getRotated instead
template <typename T> inline 
_ofVec2<T> _ofVec2<T>::rotated( T angle, const _ofVec2<T>& pivot ) const {
	
    return getRotated( angle, pivot );
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getRotated( T angle, const _ofVec2<T>& pivot ) const {
	
    T a = (T)( angle * DEG_TO_RAD );
	
    return _ofVec2<T>( ( ( x - pivot.x ) * cos( a ) - ( y - pivot.y ) * sin( a ) ) + pivot.x,
					   ( ( x - pivot.x ) * sin( a ) + ( y - pivot.y ) * cos( a ) ) + pivot.y );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::rotate( T angle, const _ofVec2<T>& pivot ) {
	
    T a = (T)( angle * DEG_TO_RAD );
    T xrot = ( ( x - pivot.x ) * cos( a ) - ( y - pivot.y ) * sin( a ) ) + pivot.x;
	
    y = ( ( x - pivot.x ) * sin( a ) + ( y - pivot.y ) * cos( a ) ) + pivot.y;
    x = xrot;
	
    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getRotatedRad( T angle, const _ofVec2<T>& pivot ) const {
	
    T a = angle;
	
    return _ofVec2<T>( ( ( x - pivot.x ) * cos( a ) - ( y - pivot.y ) * sin( a ) ) + pivot.x,
					   ( ( x - pivot.x ) * sin( a ) + ( y - pivot.y ) * cos( a ) ) + pivot.y );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::rotateRad( T angle, const _ofVec2<T>& pivot ) {
	
    T a = angle;
    T xrot = ( ( x - pivot.x ) * cos( a ) - ( y - pivot.y ) * sin( a ) ) + pivot.x;
	
    y = ( ( x - pivot.x ) * sin( a ) + ( y - pivot.y ) * cos( a ) ) + pivot.y;
    x = xrot;
	
    return *this;
}

// Map point to coordinate system defined by origin, vx, and vy ---------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getMapped( const _ofVec2<T>& origin,
								  const _ofVec2<T>& vx,
								  const _ofVec2<T>& vy ) 
								  const {
    return _ofVec2<T>( origin.x + x * vx.x + y * vy.x,
					   origin.y + x * vx.y + y * vy.y );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::map( const _ofVec2<T>& origin,
							 const _ofVec2<T>& vx, 
							 const _ofVec2<T>& vy ) {
    T xmap = origin.x + x * vx.x + y * vy.x;
    
	y = origin.y + x * vx.y + y * vy.y;
    x = xmap;
	
    return *this;
}

// This method is deprecated in 006 please use getMapped instead
template <typename T> inline 
_ofVec2<T> _ofVec2<T>::mapped( const _ofVec2<T>& origin,
							   const _ofVec2<T>& vx,
							   const _ofVec2<T>& vy ) const {
    return getMapped( origin, vx, vy );
}

// Distance between two points ------------------------------------------

template <typename T> inline 
T _ofVec2<T>::distance( const _ofVec2<T>& pnt) const {
    
	T vx = x - pnt.x;
    T vy = y - pnt.y;
	
    return (T)HYPOTENUSE( vx, vy );
}

//this method is deprecated in 006 please use squareDistance
template <typename T> inline 
T _ofVec2<T>::distanceSquared( const _ofVec2<T>& pnt ) const {
    
	return squareDistance( pnt );
}

template <typename T> inline 
T _ofVec2<T>::squareDistance( const _ofVec2<T>& pnt ) const {
	
    T vx = x - pnt.x;
    T vy = y - pnt.y;
	
    return P_HYPOTENUSE( vx, vy );
}

// Linear interpolation -------------------------------------------------

/**
 * p == 0.0 results in this point, 
 * p == 0.5 results in the midpoint, and 
 * p == 1.0 results in pnt being returned.
 */
template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getInterpolated( const _ofVec2<T>& pnt, T p ) const {
	
    return _ofVec2<T>( x * ( 1 - p ) + pnt.x * p, 
					   y * ( 1 - p ) + pnt.y * p );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::interpolate( const _ofVec2<T>& pnt, T p ) {
	
    x = x * ( 1 - p ) + pnt.x * p;
    y = y * ( 1 - p ) + pnt.y * p;
	
    return *this;
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getMiddle( const _ofVec2<T>& pnt ) const {
	
    return _ofVec2<T>( ( x + pnt.x ) / 2.0f, 
					   ( y + pnt.y ) / 2.0f );
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::middle( const _ofVec2<T>& pnt ) {
	
    x = ( x + pnt.x ) / 2.0f;
    y = ( y + pnt.y ) / 2.0f;
	
    return *this;
}

/*! this method is deprecated in 006 please use getInterpolated. */
template <typename T> inline 
_ofVec2<T> _ofVec2<T>::interpolated( const _ofVec2<T>& pnt, T p ) const {
	
    return getInterpolated( pnt, p );
}

/*! this method is deprecated in 006 please use getMiddle */
template <typename T> inline 
_ofVec2<T> _ofVec2<T>::middled( const _ofVec2<T>& pnt ) const{
	
    return getMiddle( pnt );
}

/*! Average (centroid) among points.
 Addition is sometimes useful for calculating averages too. */
template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::average( const _ofVec2<T>* points, int num ) {
	
    x = 0.f;
    y = 0.f;
	
    for( int i = 0; i < num; i++ ) {
        x += points[ i ].x;
        y += points[ i ].y;
    }
	
    x /= num;
    y /= num;
	
    return *this;
}

// Normalization --------------------------------------------------------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::normalized() const {
	
    return getNormalized();
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getNormalized() const {
	
    T len = (T)P_HYPOTENUSE( x, y );
	
    if( len > 0 ) {
        return _ofVec2<T>( x / len, 
						   y / len );
    } else {
        return _ofVec2<T>();
    }
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::normalize() {
	
    T len = (T)P_HYPOTENUSE( x, y );
	
    if( len > 0 ) {
        x /= len;
        y /= len;
    }
	
    return *this;
}

// Limit length ---------------------------------------------------------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::limited( T max ) const {
	
    return getLimited( max );
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getLimited( T max ) const {
	
    _ofVec2<T> limited;
    T lengthSquared = P_HYPOTENUSE( x, y );
	
    if ( lengthSquared > max * max 
	&&   lengthSquared > 0 ) {
        T ratio = max / (T)sqrt( lengthSquared );
        limited.set( x * ratio, y * ratio );
    } else {
        limited.set( x, y );
    }
	
    return limited;
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::limit( T max ) {
	
    T lengthSquared = P_HYPOTENUSE( x, y );
	
    if ( lengthSquared > max * max 
	&&   lengthSquared > 0 ) {
        T ratio = max/(T)sqrt( lengthSquared );
        x *= ratio;
        y *= ratio;
    }
	
    return *this;
}

// Perpendicular normalized vector --------------------------------------

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::perpendiculared() const {
	
    return getPerpendicular();
}

template <typename T> inline 
_ofVec2<T> _ofVec2<T>::getPerpendicular() const {
	
    T len = (T)HYPOTENUSE( x, y );
	
    if( len > 0 ) {
        return _ofVec2<T>( -( y / len ), 
						      x / len    );
    } else {
		return _ofVec2<T>();
	}
}

template <typename T> inline 
_ofVec2<T>& _ofVec2<T>::perpendicular() {
	
    T len = (T)HYPOTENUSE( x, y );
	
    if( len > 0 ) {
        T _x = x;
        x    = -( y / len );
        y    =   _x / len;
    }
	
    return *this;
}

// Length ---------------------------------------------------------------

template <typename T> inline 
T _ofVec2<T>::length() const {
	
    return (T)HYPOTENUSE( x, y );
}

template <typename T> inline 
T _ofVec2<T>::lengthSquared() const {
	
    return (T)P_HYPOTENUSE( x, y );
}

template <typename T> inline 
T _ofVec2<T>::squareLength() const {
	
    return lengthSquared();
}

// Angle ----------------------------------------------------------------

/*! Angle (deg) between two vectors.
 This is a signed relative angle between -180 and 180. */
template <typename T> inline 
T _ofVec2<T>::angle( const _ofVec2<T>& vec ) const {
	
    return (T)(atan2( DOT_YXV2( x, y, vec ), 
					  DOT_XYV2( x, y, vec ) ) * RAD_TO_DEG);
}

/*! Angle (deg) between two vectors.
 This is a signed relative angle between -180 and 180. */
template <typename T> inline 
T _ofVec2<T>::angleRad( const _ofVec2<T>& vec ) const {
	
    return atan2( DOT_YXV2( x, y, vec ), 
				  DOT_XYV2( x, y, vec ) );
}


/*! Dot Product. */
template <typename T> inline 
T _ofVec2<T>::dot( const _ofVec2<T>& vec ) const {
	
    return DOT_XYV2( x, y, vec );
}

// Expanded at compiler time?
template class _ofVec2<int>;
template class _ofVec2<float>;
template class _ofVec2<double>;