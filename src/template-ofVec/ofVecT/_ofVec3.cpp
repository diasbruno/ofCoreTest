
#include "_ofVec3.h"

// Getters and Setters. -------------------------------------------------

template <typename T> inline 
void _ofVec3<T>::set( T _scalar ) {
	
    x = _scalar;
    y = _scalar;
    z = _scalar;
}

template <typename T> inline 
void _ofVec3<T>::set( T _x, T _y, T _z ) {
	
    x = _x;
    y = _y;
    z = _z;
}

template <typename T> inline 
void _ofVec3<T>::set( const _ofVec3<T>& vec ) {
	
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

// Similarity/equality --------------------------------------------------

template <typename T> inline 
bool _ofVec3<T>::match( const _ofVec3<T>& vec, T tolerance ) const {
	
    return (fabs(x - vec.x) < tolerance)
		&& (fabs(y - vec.y) < tolerance)
		&& (fabs(z - vec.z) < tolerance);
}

// Alignment ------------------------------------------------------------

/*! Checks if vectors look in the same direction. */
template <typename T> inline 
bool _ofVec3<T>::isAligned( const _ofVec3<T>& vec, T tolerance ) const {
	
    T angle = this->angle( vec );
    return  angle < tolerance;
}

template <typename T> inline 
bool _ofVec3<T>::align( const _ofVec3<T>& vec, T tolerance ) const {
	
    return isAligned( vec, tolerance );
}

template <typename T> inline 
bool _ofVec3<T>::isAlignedRad( const _ofVec3<T>& vec, T tolerance ) const {
	
    T angle = this->angleRad( vec );
    return  angle < tolerance;
}

template <typename T> inline 
bool _ofVec3<T>::alignRad( const _ofVec3<T>& vec, T tolerance ) const {
	
    return isAlignedRad( vec, tolerance );
}

// Scaling --------------------------------------------------------------

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::rescaled( const T length ) const {
	
    return getScaled( length );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getScaled( const T length ) const {
	
    T len = (T)sqrt( x * x + y * y + z * z );
	
    if( len > 0 )
        return _ofVec3<T>( 
			( x / len ) * length, // x
			( y / len ) * length, // y
			( z / len ) * length  // z
		);
    else
        return _ofVec3<T>();
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rescale( const T length ) {
	
    return scale( length );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::scale( const T length ) {
	
    T len = (T)sqrt( x * x + y * y + z * z );
	
    if ( len > 0 ) {
        x = ( x / len ) * length;
        y = ( y / len ) * length;
        z = ( z / len ) * length;
    }
	
    return *this;
}

// Rotation -------------------------------------------------------------

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::rotated( T angle, const _ofVec3<T>& axis ) const {
	
    return getRotated( angle, axis );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getRotated( T angle, const _ofVec3<T>& axis ) const {
	
    _ofVec3<T> ax = axis.getNormalized();
	
    T a = (T)(angle * DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    return _ofVec3<T>( 
		x * ( ax.x * ax.x * cosb + cosa )
	  + y * ( ax.x * ax.y * cosb - ax.z * sina )
	  + z * ( ax.x * ax.z * cosb + ax.y * sina ), // x
					  
		x * ( ax.y * ax.x * cosb + ax.z * sina )
	  + y * ( ax.y * ax.y * cosb + cosa ) 
	  + z * ( ax.y * ax.z * cosb - ax.x * sina ), // y
					  
		x * ( ax.z * ax.x * cosb - ax.y * sina )
	  + y * ( ax.z * ax.y * cosb + ax.x * sina )
	  + z * ( ax.z * ax.z * cosb + cosa )         // z
	);
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getRotatedRad( T angle, const _ofVec3<T>& axis ) const {
	
    _ofVec3<T> ax = axis.getNormalized();
	
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    return _ofVec3<T>( 
		x * ( ax.x * ax.x * cosb + cosa )
	  + y * ( ax.x * ax.y * cosb - ax.z * sina )
	  + z * ( ax.x * ax.z * cosb + ax.y * sina ), // x
	
		x * ( ax.y * ax.x * cosb + ax.z * sina )
	  + y * ( ax.y * ax.y * cosb + cosa ) 
	  + z * ( ax.y * ax.z * cosb - ax.x * sina ), // y
	
		x * ( ax.z * ax.x * cosb - ax.y * sina )
	  + y * ( ax.z * ax.y * cosb + ax.x * sina )
	  + z * ( ax.z * ax.z * cosb + cosa )         // z
	);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rotate( T angle, const _ofVec3<T>& axis ) {
	
    _ofVec3<T> ax = axis.getNormalized();
	
    T a = (T)(angle * DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T nx = x * ( ax.x * ax.x * cosb + cosa )
         + y * ( ax.x * ax.y * cosb - ax.z * sina )
         + z * ( ax.x * ax.z * cosb + ax.y * sina );
	
    T ny = x * ( ax.y * ax.x * cosb + ax.z * sina )
         + y * ( ax.y * ax.y * cosb + cosa )
         + z * ( ax.y * ax.z * cosb - ax.x * sina );
	
    T nz = x * ( ax.z * ax.x * cosb - ax.y * sina )
         + y * ( ax.z * ax.y * cosb + ax.x * sina )
         + z * ( ax.z * ax.z * cosb + cosa );
    
	x = nx; 
	y = ny; 
	z = nz;
	
    return *this;
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rotateRad( T angle, const _ofVec3<T>& axis ) {
	
    _ofVec3<T> ax = axis.getNormalized();
	
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T nx = x * ( ax.x * ax.x * cosb + cosa )
         + y * ( ax.x * ax.y * cosb - ax.z * sina )
         + z * ( ax.x * ax.z * cosb + ax.y * sina );
	
    T ny = x * ( ax.y * ax.x * cosb + ax.z * sina )
         + y * ( ax.y * ax.y * cosb + cosa )
         + z * ( ax.y * ax.z * cosb - ax.x * sina );
	
    T nz = x * ( ax.z * ax.x * cosb - ax.y * sina )
         + y * ( ax.z * ax.y * cosb + ax.x * sina )
         + z * ( ax.z * ax.z * cosb + cosa );
    
	x = nx; 
	y = ny; 
	z = nz;
	
    return *this;
}

// const???
template <typename T> inline 
_ofVec3<T> _ofVec3<T>::rotated( T ax, T ay, T az ) {
	
    return getRotated( ax, ay, az );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getRotated( T ax, T ay, T az ) const {
	
    T a = (T)cos( DEG_TO_RAD * (ax) );
    T b = (T)sin( DEG_TO_RAD * (ax) );
    T c = (T)cos( DEG_TO_RAD * (ay) );
    T d = (T)sin( DEG_TO_RAD * (ay) );
    T e = (T)cos( DEG_TO_RAD * (az) );
    T f = (T)sin( DEG_TO_RAD * (az) );
    
    T nx = c * e * x 
	     - c * f * y 
	     + d * z;
    T ny = (a * f + b * d * e) * x 
	     + (a * e - b * d * f) * y 
	     - b * c * z;
    T nz = (b * f - a * d * e) * x 
	     + (a * d * f + b * e) * y 
	     + a * c * z;
    
    return _ofVec3<T>( nx, ny, nz );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getRotatedRad( T ax, T ay, T az ) const {
	
    T a = cos( ax );
    T b = sin( ax );
    T c = cos( ay );
    T d = sin( ay );
    T e = cos( az );
    T f = sin( az );
    
    T nx = c * e * x 
	     - c * f * y 
	     + d * z;
    T ny = (a * f + b * d * e) * x 
	     + (a * e - b * d * f) * y 
	     - b * c * z;
    T nz = (b * f - a * d * e) * x 
	     + (a * d * f + b * e) * y 
	     + a * c * z;
    
    return _ofVec3<T>( nx, ny, nz );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rotate( T ax, T ay, T az ) {
	
    T a = (T)cos( DEG_TO_RAD *(ax) );
    T b = (T)sin( DEG_TO_RAD *(ax) );
    T c = (T)cos( DEG_TO_RAD *(ay) );
    T d = (T)sin( DEG_TO_RAD *(ay) );
    T e = (T)cos( DEG_TO_RAD *(az) );
    T f = (T)sin( DEG_TO_RAD *(az) );
    
    T nx = c * e * x 
	     - c * f * y 
	     + d * z;
    T ny = (a * f + b * d * e) * x 
	     + (a * e - b * d * f) * y 
	     - b * c * z;
    T nz = (b * f - a * d * e) * x 
	     + (a * d * f + b * e) * y 
	     + a * c * z;
    
    x = nx; 
	y = ny; 
	z = nz;
	
    return *this;
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rotateRad( T ax, T ay, T az ) {
	
    T a = cos( ax );
    T b = sin( ax );
    T c = cos( ay );
    T d = sin( ay );
    T e = cos( az );
    T f = sin( az );
    
    T nx = c * e * x 
	     - c * f * y 
	     + d * z;
    T ny = (a * f + b * d * e) * x 
	     + (a * e - b * d * f) * y 
	     - b * c * z;
    T nz = (b * f - a * d * e) * x 
	     + (a * d * f + b * e) * y 
	     + a * c * z;
    
    x = nx; 
	y = ny; 
	z = nz;
	
    return *this;
}


// Rotation - point around pivot ----------------------------------------

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::rotated( T angle,
								const _ofVec3<T>& pivot,
								const _ofVec3<T>&  axis ) 
								const {
    return getRotated(angle, pivot, axis);
}

template <typename T>
inline _ofVec3<T> _ofVec3<T>::getRotated( T angle,
                                          const _ofVec3<T>& pivot,
                                          const _ofVec3<T>&  axis ) 
										  const {
    
    _ofVec3<T> ax = axis.getNormalized();
											  
    T tx = x - pivot.x;
    T ty = y - pivot.y;
    T tz = z - pivot.z;
    
    T a = (T)(angle * DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = tx * ( ax.x * ax.x * cosb + cosa )
           + ty * ( ax.x * ax.y * cosb - ax.z * sina )
           + tz * ( ax.x * ax.z * cosb + ax.y * sina );
    T yrot = tx * ( ax.y * ax.x * cosb + ax.z * sina )
           + ty * ( ax.y * ax.y * cosb + cosa )
           + tz * ( ax.y * ax.z * cosb - ax.x * sina );
    T zrot = tx * ( ax.z * ax.x * cosb - ax.y * sina )
           + ty * ( ax.z * ax.y * cosb + ax.x * sina )
           + tz * ( ax.z * ax.z * cosb + cosa );
    
    return _ofVec3<T>( 
		xrot + pivot.x, // x
		yrot + pivot.y, // y 
		zrot + pivot.z  // z
	);
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getRotatedRad( T angle,
									  const _ofVec3<T>& pivot,
									  const _ofVec3<T>&  axis ) 
									  const {
    
    _ofVec3<T> ax = axis.getNormalized();
										  
    T tx = x - pivot.x;
    T ty = y - pivot.y;
    T tz = z - pivot.z;
    
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = tx*( ax.x * ax.x * cosb + cosa )
           + ty*( ax.x * ax.y * cosb - ax.z * sina )
           + tz*( ax.x * ax.z * cosb + ax.y * sina );
    T yrot = tx*( ax.y * ax.x * cosb + ax.z * sina )
           + ty*( ax.y * ax.y * cosb + cosa )
           + tz*( ax.y * ax.z * cosb - ax.x * sina );
    T zrot = tx*( ax.z * ax.x * cosb - ax.y * sina )
		   + ty*( ax.z * ax.y * cosb + ax.x * sina )
		   + tz*( ax.z * ax.z * cosb + cosa );
    
	return _ofVec3<T>( 
		xrot + pivot.x, // x
		yrot + pivot.y, // y 
		zrot + pivot.z  // z
	);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rotate( T angle,
								const _ofVec3<T>& pivot,
								const _ofVec3<T>& axis ) {
	
    _ofVec3<T> ax = axis.getNormalized();
	
    x -= pivot.x;
    y -= pivot.y;
    z -= pivot.z;
    
    T a = (T)(angle*DEG_TO_RAD);
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = x * ( ax.x * ax.x * cosb + cosa )
           + y * ( ax.x * ax.y * cosb - ax.z * sina )
           + z * ( ax.x * ax.z * cosb + ax.y * sina );
	
    T yrot = x * ( ax.y * ax.x * cosb + ax.z * sina )
           + y * ( ax.y * ax.y * cosb + cosa )
           + z * ( ax.y * ax.z * cosb - ax.x * sina );
	
    T zrot = x * ( ax.z * ax.x * cosb - ax.y * sina )
           + y * ( ax.z * ax.y * cosb + ax.x * sina )
		   + z * ( ax.z * ax.z * cosb + cosa );
    
    x = xrot + pivot.x;
    y = yrot + pivot.y;
    z = zrot + pivot.z;
    
    return *this;
}


template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::rotateRad( T angle,
								   const _ofVec3<T>& pivot,
								   const _ofVec3<T>& axis ) {
	
    _ofVec3<T> ax = axis.getNormalized();
	
    x -= pivot.x;
    y -= pivot.y;
    z -= pivot.z;
    
    T a = angle;
    T sina = sin( a );
    T cosa = cos( a );
    T cosb = 1.0f - cosa;
    
    T xrot = x * ( ax.x * ax.x * cosb + cosa )
           + y * ( ax.x * ax.y * cosb - ax.z * sina )
           + z * ( ax.x * ax.z * cosb + ax.y * sina );
	
    T yrot = x * ( ax.y * ax.x * cosb + ax.z * sina )
           + y * ( ax.y * ax.y * cosb + cosa)
           + z * ( ax.y * ax.z * cosb - ax.x * sina );
	
    T zrot = x * ( ax.z * ax.x * cosb - ax.y * sina )
           + y * ( ax.z * ax.y * cosb + ax.x * sina )
           + z * ( ax.z * ax.z * cosb + cosa );
    
    x = xrot + pivot.x;
    y = yrot + pivot.y;
    z = zrot + pivot.z;
    
    return *this;
}

// Map point to coordinate system defined by origin, vx, vy, and vz -----

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::mapped( const _ofVec3<T>& origin,
							   const _ofVec3<T>&     vx,
							   const _ofVec3<T>&     vy,
							   const _ofVec3<T>&     vz ) const {
	
    return getMapped( origin, vx, vy, vz );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getMapped( const _ofVec3<T>& origin,
								  const _ofVec3<T>&     vx,
								  const _ofVec3<T>&     vy,
								  const _ofVec3<T>&     vz ) const {
	
    return _ofVec3<T>( 
		origin.x + x * vx.x + y * vy.x + z * vz.x, // x
		origin.y + x * vx.y + y * vy.y + z * vz.y, // y
		origin.z + x * vx.z + y * vy.z + z * vz.z  // z
	);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::map( const _ofVec3<T>& origin,
							 const _ofVec3<T>&     vx,
						     const _ofVec3<T>&     vy,
							 const _ofVec3<T>&     vz ) {
	
    T xmap = origin.x + x * vx.x + y * vy.x + z * vz.x;
    T ymap = origin.y + x * vx.y + y * vy.y + z * vz.y;
	
    z = origin.z + x * vx.z + y * vy.z + z * vz.z;
    x = xmap;
    y = ymap;
	
    return *this;
}

// Distance between two points ------------------------------------------

template <typename T> inline 
T _ofVec3<T>::distance( const _ofVec3<T>& pnt) const {
    
	T vx = x - pnt.x;
    T vy = y - pnt.y;
    T vz = z - pnt.z;
	
    return (T)sqrt( vx * vx + vy * vy + vz * vz );
}

template <typename T> inline 
T  _ofVec3<T>::distanceSquared( const _ofVec3<T>& pnt ) const {
	
    return squareDistance( pnt );
}

template <typename T> inline 
T  _ofVec3<T>::squareDistance( const _ofVec3<T>& pnt ) const {
	
    T vx = x - pnt.x;
    T vy = y - pnt.y;
    T vz = z - pnt.z;
	
    return vx * vx + vy * vy + vz * vz;
}

// Linear interpolation -------------------------------------------------

/**
 * p == 0.0 results in this point, 
 * p == 0.5 results in the midpoint, and 
 * p == 1.0 results in pnt being returned.
 */
template <typename T> inline 
_ofVec3<T> _ofVec3<T>::interpolated( const _ofVec3<T>& pnt, T p ) const {
	
    return getInterpolated( pnt, p );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getInterpolated( const _ofVec3<T>& pnt, T p ) const {
	
    return _ofVec3<T>( 
		x * ( 1 - p ) + pnt.x * p, // x
		y * ( 1 - p ) + pnt.y * p, // y
	    z * ( 1 - p ) + pnt.z * p  // z
	);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::interpolate( const _ofVec3<T>& pnt, T p ) {
	
    x = x * ( 1 - p ) + pnt.x * p;
    y = y * ( 1 - p ) + pnt.y * p;
    z = z * ( 1 - p ) + pnt.z * p;
	
    return *this;
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::middled( const _ofVec3<T>& pnt ) const {
	
    return getMiddle(pnt);
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getMiddle( const _ofVec3<T>& pnt ) const {
	
    return _ofVec3<T>( 
		( x + pnt.x ) / 2.0f, // x
		( y + pnt.y ) / 2.0f, // y
		( z + pnt.z ) / 2.0f  // z
	);
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::middle( const _ofVec3<T>& pnt ) {
	
    x = ( x + pnt.x ) / 2.0f;
    y = ( y + pnt.y ) / 2.0f;
    z = ( z + pnt.z ) / 2.0f;
	
    return *this;
}


/*! Average (centroid) among points.
    Addition is sometimes useful for calculating averages too. */
template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::average( const _ofVec3<T>* points, int num ) {
    
	x = 0.f;
    y = 0.f;
    z = 0.f;
	
    for( int i = 0; i < num; i++ ) {
        x += points[ i ].x;
        y += points[ i ].y;
        z += points[ i ].z;
    }
	
    x /= num;
    y /= num;
    z /= num;
	
    return *this;
}

// Normalization --------------------------------------------------------

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::normalized() const {
	
    return getNormalized();
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getNormalized() const {
	
    T len = (T)sqrt( x * x + y * y + z * z );
    
	if( len > 0 ) {
        return _ofVec3<T>( 
			x / len, // x
			y / len, // y
			z / len  // z
		);
    } else {
        return _ofVec3<T>();
    }
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::normalize() {
	
    T len = (T)sqrt( x * x + y * y + z * z );
	
    if( len > 0 ) {
        x /= len;
        y /= len;
        z /= len;
    }
    return *this;
}

// Limit length ---------------------------------------------------------

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::limited( T max ) const {
	
    return getLimited( max );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getLimited( T max ) const {
	
    _ofVec3<T> limited;
    T lengthSquared = ( x * x + y * y + z * z );
	
    if ( lengthSquared > max * max 
	&&   lengthSquared > 0 ) {
		
        T ratio = max / (T)sqrt( lengthSquared );
        limited.set( x * ratio, y * ratio, z * ratio );
		
    } else {
        limited.set( x, y, z );
    }
	
    return limited;
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::limit(T max) {
    
	T lengthSquared = ( x * x + y * y + z * z );
	
    if ( lengthSquared > max*max 
	&&   lengthSquared > 0 ) {
		
        T ratio = max / (T)sqrt( lengthSquared );
        x *= ratio;
        y *= ratio;
        z *= ratio;
    }
	
    return *this;
}

// Perpendicular normalized vector --------------------------------------

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::crossed( const _ofVec3<T>& vec ) const {
	
    return getCrossed( vec );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getCrossed( const _ofVec3<T>& vec ) const {
	
    return _ofVec3<T>( y * vec.z - z * vec.y,
                       z * vec.x - x * vec.z,
                       x * vec.y - y * vec.x );
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::cross( const _ofVec3<T>& vec ) {
	
    T _x = y * vec.z - z * vec.y;
    T _y = z * vec.x - x * vec.z;
       z = x * vec.y - y * vec.x;
    x = _x;
    y = _y;
	
    return *this;
}

/*! Normalized perpendicular. */
template <typename T> inline 
_ofVec3<T> _ofVec3<T>::perpendiculared( const _ofVec3<T>& vec ) const {
    
	return getPerpendicular( vec );
}

template <typename T> inline 
_ofVec3<T> _ofVec3<T>::getPerpendicular( const _ofVec3<T>& vec ) const {
	
    T crossX = y * vec.z - z * vec.y;
    T crossY = z * vec.x - x * vec.z;
    T crossZ = x * vec.y - y * vec.x;
    
    T len = (T)sqrt( crossX * crossX +
					 crossY * crossY +
					 crossZ * crossZ );
    
    if( len > 0 ) {
        return _ofVec3<T>( 
			crossX / len, // x
			crossY / len, // y
		    crossZ / len  // z
		);
    } else {
		return _ofVec3<T>();
	}
}

template <typename T> inline 
_ofVec3<T>& _ofVec3<T>::perpendicular( const _ofVec3<T>& vec ) {
	
    T crossX = y * vec.z - z * vec.y;
    T crossY = z * vec.x - x * vec.z;
    T crossZ = x * vec.y - y * vec.x;
    
    T len = (T)sqrt( crossX * crossX +
					 crossY * crossY +
					 crossZ * crossZ );
    
    if( len > 0 ) {
        
		x = crossX / len;
        y = crossY / len;
        z = crossZ / len;
		
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
inline T _ofVec3<T>::dot( const _ofVec3<T>& vec ) const {
	
    return x * vec.x + y * vec.y + z * vec.z;
}

// Length ---------------------------------------------------------------

template <typename T> inline 
T _ofVec3<T>::length() const {
	
    return (T)sqrt( x * x + y * y + z * z );
}

template <typename T> inline 
T _ofVec3<T>::lengthSquared() const {
	
    return (T)( x * x + y * y + z * z );
}

template <typename T> inline 
T _ofVec3<T>::squareLength() const {
	
    return lengthSquared();
}

// Angle ----------------------------------------------------------------

/**
 * Angle (deg) between two vectors.
 * This is an unsigned relative angle from 0 to 180.
 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
 */
template <typename T> inline 
T _ofVec3<T>::angle( const _ofVec3<T>& vec ) const {
	
    _ofVec3<T> n1 = this->getNormalized();
    _ofVec3<T> n2 = vec.getNormalized();
	
    return (T)(acos( n1.dot( n2 ) ) * RAD_TO_DEG);
}

template <typename T> inline 
T _ofVec3<T>::angleRad( const _ofVec3<T>& vec ) const {
    
	_ofVec3<T> n1 = this->getNormalized();
    _ofVec3<T> n2 = vec.getNormalized();
	
    return (T)acos( n1.dot( n2 ) );
}

// Expanded at compiler time?
template class _ofVec3<int>;
template class _ofVec3<float>;
template class _ofVec3<double>;