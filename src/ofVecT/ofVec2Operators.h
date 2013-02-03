#pragma once

// Equality -----------------------------------------------------

/*! Operators */
template<typename T>
inline
bool ofVec2<T>::operator == ( const ofVec2<T> & v ) const {
	return x == v.x 
        && y == v.y;
};

template<typename T>
inline
bool ofVec2<T>::operator != ( const ofVec2<T> & v ) const {
	return x != v.x 
        || y != v.y;
};

template<typename T>
inline
bool ofVec2<T>::match( const ofVec2<T>& v, T tolerance ) const {
	return fabs(x - v.x) < tolerance 
        && fabs(y - v.y) < tolerance;
};

// Operators -----------------------------------------------------

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator+( const ofVec2<T>& v ) const {
	return ofVec2<T>( x + v.x, y + v.y );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator+=( const ofVec2<T>& v ) {
	x += v.x;
	y += v.y;
	
	return *this;
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator-( const ofVec2<T>& v ) const {
	return ofVec2<T>( x - v.x, y - v.y );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator-=( const ofVec2<T>& v ) {
	x -= v.x;
	y -= v.y;
	
	return *this;
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator*( const ofVec2<T>& v ) const {
	return ofVec2<T>( x * v.x, y * v.y );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator*=( const ofVec2<T>& v ) {
	x *= v.x;
	y *= v.y;
	
	return *this;
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator/( const ofVec2<T>& v ) const {
	return ofVec2<T>( v.x != 0 ? x / v.x : x , v.y != 0 ? y / v.y : y );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator/=( const ofVec2<T>& v ) {
	v.x != 0 ? x /= v.x : x;
	v.y != 0 ? y /= v.y : y;
	
	return *this;
};


template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator+( const T s ) const {
	return ofVec2<T>( x + s, y + s );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator+=( const T s ) {
	x += s;
	y += s;
	
	return *this;
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator-( const T s ) const {
	return ofVec2<T>( x - s, y - s );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator-=( const T s ) {
	x -= s;
	y -= s;
	
	return *this;
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator-() const {
	return ofVec2<T>( -x, -y );
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator*( const T s ) const {
	return ofVec2<T>( x * s, y * s );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator*=( const T s ) {
	x *= s;
	y *= s;
	
	return *this;
};

template<typename T>
inline 
ofVec2<T> ofVec2<T>::operator/( const T s ) const {
	if( s == 0 ) return ofVec2<T>( x, y );
	
	return ofVec2<T>( x / s, y / s );
};

template<typename T>
inline 
ofVec2<T>& ofVec2<T>::operator/=( const T s ) {
	if( s == 0 ) return *this;
	
	x /= s;
	y /= s;
	
	return *this;
};
