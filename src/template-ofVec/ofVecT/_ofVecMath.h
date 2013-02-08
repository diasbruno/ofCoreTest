#pragma once

// Non-Member operators

// Vec2<T>

template <typename T> inline 
_ofVec2<T> operator + ( T s, const _ofVec2<T>& v ) {
	
    return _ofVec2<T>( s + v.x, 
					   s + v.y );
}

template <typename T> inline 
_ofVec2<T> operator - ( T s, const _ofVec2<T>& v ) {
	
    return _ofVec2<T>( s - v.x, 
					   s - v.y );
}

template <typename T> inline 
_ofVec2<T> operator * ( T s, const _ofVec2<T>& v ) {
	
    return _ofVec2<T>( s * v.x, 
					   s * v.y );
}

template <typename T> inline 
_ofVec2<T> operator / ( T s, const _ofVec2<T>& v ) {
	
    return _ofVec2<T>( s / v.x, 
					   s / v.y );
}

// Vec3<T>

template <typename T> inline 
_ofVec3<T> operator + ( T s, const _ofVec3<T>& v ) {
	
    return _ofVec3<T>( s + v.x, 
					   s + v.y, 
					   s + v.z );
}

template <typename T> inline 
_ofVec3<T> operator - ( T s, const _ofVec3<T>& v ) {
	
    return _ofVec3<T>( s - v.x, 
					   s - v.y, 
					   s - v.z );
}

template <typename T> inline 
_ofVec3<T> operator * ( T s, const _ofVec3<T>& v ) {
	
    return _ofVec3<T>( s * v.x, 
					   s * v.y, 
					   s * v.z );
}

template <typename T> inline 
_ofVec3<T> operator / ( T s, const _ofVec3<T>& v ) {
	
    return _ofVec3<T>( s / v.x, 
					   s / v.y, 
					   s / v.z );
}

// Vec4<T>

template <typename T> inline 
_ofVec4<T> operator + ( T s, const _ofVec4<T>& v ) {
	
    return _ofVec4<T>( s + v.x, 
					  s + v.y, 
					  s + v.z, 
					  s + v.w );
}

template <typename T> inline 
_ofVec4<T> operator - ( T s, const _ofVec4<T>& v ) {
	
    return _ofVec4<T>( s - v.x, 
					   s - v.y, 
					   s - v.z, 
					   s - v.w );
}

template <typename T> inline 
_ofVec4<T> operator * ( T s, const _ofVec4<T>& v ) {
	
    return _ofVec4<T>( s * v.x, 
					   s * v.y, 
					   s * v.z, 
					   s * v.w );
}

template <typename T> inline 
_ofVec4<T> operator / ( T s, const _ofVec4<T>& v ) {
	
    return _ofVec4<T>( s / v.x, 
					   s / v.y, 
					   s / v.z, 
					   s / v.w );
}