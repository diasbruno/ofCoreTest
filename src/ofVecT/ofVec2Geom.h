#pragma once

// Scale -----------------------------------------------------


template <typename T>
inline 
ofVec2<T> ofVec2<T>::getScaled( const T length ) const {
	float l = (float)sqrt(x*x + y*y);
	if( l > 0 )
		return ofVec2<T>( (x/l)*length, (y/l)*length );
	else
		return ofVec2<T>();
}


template <typename T>
inline 
ofVec2<T>& ofVec2<T>::scale( const T length ) {
	float l = (float)sqrt(x*x + y*y);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
	}
	return *this;
}

// Rotation ----------------------------------------------------


template <typename T>
inline 
ofVec2<T> ofVec2<T>::getRotated( T angle ) const {
	T a = (T)(angle*DEG_TO_RAD);
	return ofVec2<T>( x*cos(a) - y*sin(a),
				   x*sin(a) + y*cos(a) );
}

template <typename T>
inline 
ofVec2<T> ofVec2<T>::getRotatedRad( T angle ) const {
	T a = angle;
	return ofVec2<T>( x*cos(a) - y*sin(a),
				   x*sin(a) + y*cos(a) );
}

template <typename T>
inline 
ofVec2<T>& ofVec2<T>::rotate( T angle ) {
	T a = (T)(angle * DEG_TO_RAD);
	T xrot = x*cos(a) - y*sin(a);
	y = x*sin(a) + y*cos(a);
	x = xrot;
	return *this;
}

template <typename T>
inline 
ofVec2<T>& ofVec2<T>::rotateRad( T angle ) {
	T a = angle;
	T xrot = x*cos(a) - y*sin(a);
	y = x*sin(a) + y*cos(a);
	x = xrot;
	return *this;
}

// Rotate point by angle (deg) around pivot point. ---------------


template <typename T>
inline 
ofVec2<T> ofVec2<T>::getRotated( T angle, const ofVec2<T>& pivot ) const {
	T a = (T)(angle * DEG_TO_RAD);
	return ofVec2<T>( ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x,
				   ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y );
}

template <typename T>
inline 
ofVec2<T>& ofVec2<T>::rotate( T angle, const ofVec2<T>& pivot ) {
	T a = (T)(angle * DEG_TO_RAD);
	T xrot = ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x;
	y = ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y;
	x = xrot;
	return *this;
}

template <typename T>
inline 
ofVec2<T> ofVec2<T>::getRotatedRad( T angle, const ofVec2<T>& pivot ) const {
	T a = angle;
	return ofVec2<T>( ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x,
				   ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y );
}

template <typename T>
inline 
ofVec2<T>& ofVec2<T>::rotateRad( T angle, const ofVec2<T>& pivot ) {
	T a = angle;
	T xrot = ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x;
	y = ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y;
	x = xrot;
	return *this;
}


//
// Deprecated --------------------------------------------------
// Version: 006
//


// Scale -----------------------------------------------------

/*! Use getScaled() instead. */
template <typename T>
inline 
ofVec2<T> ofVec2<T>::rescaled( const T length ) const {
	return getScaled(length);
}

/*! Use scale() instead. */
template <typename T>
inline 
ofVec2<T>& ofVec2<T>::rescale( const T length ){
	return scale(length);
}

// Rotation ----------------------------------------------------

/*! Use getRotated( T angle ) instead. */
template <typename T>
inline 
ofVec2<T> ofVec2<T>::rotated( T angle ) const {
	return getRotated( angle );
}

// Rotate point by angle (deg) around pivot point. ---------------

/*! Use getRotated( T angle, const ofVec2<T>& pivot ) instead. */
template <typename T>
inline 
ofVec2<T> ofVec2<T>::rotated( T angle, const ofVec2<T>& pivot ) const {
	return getRotated( angle, pivot );
}
