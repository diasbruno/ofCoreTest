/*
 *  ofMatrix4x4.h
 *  
 *  Created by Aaron Meyers on 6/22/09 -- modified by Arturo Castro, Zach Lieberman, Memo Akten
 *  based on code from OSG - 
 *  see OSG license for more details: 
 *  http://www.openscenegraph.org/projects/osg/wiki/Legal
 * 
 */

#pragma once

#include "_ofVec.h"
#include "_ofQuaternion.h"
#include "_ofMatrixUtils.h"
#include "ofConstants.h"
#include <cmath>

//template <typename T> class _ofQuaternion;

#if (_MSC_VER)       
	// make microsoft visual studio complain less about double / float conversion and
	// truncation
	#pragma warning(disable : 4244)
	#pragma warning(disable : 4305)
#endif

template <typename T>
class _ofMatrix4x4 {
public:
	//	float _mat[4][4];
	_ofVec4<T> _mat[4];
	
	//---------------------------------------------
	// constructors
	_ofMatrix4x4() {
		makeIdentityMatrix();
	}
	
	_ofMatrix4x4( 
		T a00, T a01, T a02, T a03,
		T a10, T a11, T a12, T a13,
		T a20, T a21, T a22, T a23,
		T a30, T a31, T a32, T a33 
	);
	
	// Copy ---------------------------------------
	
	_ofMatrix4x4( const _ofMatrix4x4<T>& mat) {
		set( mat.getPtr() );
	}
	
	_ofMatrix4x4( T const * const ptr ) {
		set( ptr );
	}
	
	_ofMatrix4x4( const _ofQuaternion<T>& quat ) {
		makeRotationMatrix( quat );
	}
	
	//---------------------------------------------
	// destructor
	~_ofMatrix4x4<T>() {}
	
	//	int compare(const _ofMatrix4x4& m) const;
	//
	//	bool operator < (const _ofMatrix4x4& m) const { return compare(m)<0; }
	//	bool operator == (const _ofMatrix4x4& m) const { return compare(m)==0; }
	//	bool operator != (const _ofMatrix4x4& m) const { return compare(m)!=0; }
	
	//---------------------------------------------
	// write data with matrix(row,col)=number
	T& operator()(int row, int col) {
		return _mat[row][col];
	}
	
	//---------------------------------------------
	// read data with var=matrix(row,col)
	T operator()(int row, int col) const {
		return _mat[row][col];
	}
	
	//----------------------------------------
	_ofVec3<T> getRowAsVec3f(int i) const {
		return _ofVec3<T>(_mat[i][0], _mat[i][1], _mat[i][2]);
	}
	
	//----------------------------------------
	_ofVec4<T> getRowAsVec4f(int i) const {
		return _mat[i];
	}
	
	
	//---------------------------------------------
	// check if the matrix is valid
	bool isValid() const {
		return !isNaN();
	}
	
	bool isNaN() const;
	
	//---------------------------------------------
	// copy a matrix using = operator
	_ofMatrix4x4<T>& operator = (const _ofMatrix4x4<T>& rhs);
	
	//---------------------------------------------
	// methods to set the data of the matrix
	void set( const _ofMatrix4x4<T>& rhs);
	void set( T const * const ptr);
	void set( T a00, T a01, T a02, T a03,
	          T a10, T a11, T a12, T a13,
	          T a20, T a21, T a22, T a23,
	          T a30, T a31, T a32, T a33 );
	
	template <typename S>
	void set( S const * const ptr);
	
	//---------------------------------------------
	// access the internal data in T* format
	// useful for opengl matrix transformations
	T * getPtr() {
		return (T*)_mat;
	}
	const T * getPtr() const {
		return (const T *)_mat;
	}
	
	//---------------------------------------------
	// check matrix identity
	bool isIdentity() const;
	
	
	//---------------------------------------------
	// init matrix as identity, scale, translation...
	// all make* methods delete the current data
	void makeIdentityMatrix();
	
	void makeScaleMatrix( const _ofVec3<T>& );
	void makeScaleMatrix( T, T, T );
	
	void makeTranslationMatrix( const _ofVec3<T>& );
	void makeTranslationMatrix( T, T, T );
	
	void makeRotationMatrix( const _ofVec3<T>& from, const _ofVec3<T>& to );
	void makeRotationMatrix( T angle, const _ofVec3<T>& axis );
	void makeRotationMatrix( T angle, T x, T y, T z );
	void makeRotationMatrix( const _ofQuaternion<T>& );
	void makeRotationMatrix( T angle1, const _ofVec3<T>& axis1,
							 T angle2, const _ofVec3<T>& axis2,
							 T angle3, const _ofVec3<T>& axis3);
	
	
	// init related to another matrix
	bool             makeInvertOf( const _ofMatrix4x4<T>& rhs);
	void        makeOrthoNormalOf( const _ofMatrix4x4<T>& rhs);
	void makeFromMultiplicationOf( const _ofMatrix4x4<T>&, 
								   const _ofMatrix4x4<T>& );
	
	_ofMatrix4x4<T> getInverse();
	
	
	//---------------------------------------------
	// init as opengl related matrix for perspective settings
	// see opengl docs of the related funciton for further details
	
	// glOrtho
	void       makeOrthoMatrix( double left,   double right,
						        double bottom, double top,
						        double zNear,  double zFar );
	
	// glOrtho2D
	void     makeOrtho2DMatrix( double left,   double right,
						        double bottom, double top );
	
	// glFrustum
	void     makeFrustumMatrix( double left,   double right,
						        double bottom, double top,
						        double zNear,  double zFar );
	
	// gluPerspective
	// Aspect ratio is defined as width/height.
	void makePerspectiveMatrix( double fovy,  double aspectRatio,
							    double zNear, double zFar );
	
	
	// makeLookAtMatrix:
	// creates a transformation matrix positioned at 'eye'
	// pointing at (along z axis) 'center'
	// this is what you use if you want an object to look at a point
	void     makeLookAtMatrix( const _ofVec3<T>& eye, 
                               const _ofVec3<T>& center, 
                               const _ofVec3<T>& up      );
	
	
	// makeLookAtViewMatrix:
	// creates *the inverse of* a transformation matrix positioned at 'eye'
	// pointing at (along z axis) 'center'
	// this is what you use when you want your view matrix looking at a point
	// (the inverse of makeLookAtMatrix), same as gluLookAt
	void makeLookAtViewMatrix( const _ofVec3<T>& eye, 
                               const _ofVec3<T>& center, 
                               const _ofVec3<T>& up      );
	
	
	//---------------------------------------------
	// Get the perspective components from a matrix
	// this only works with pure perspective projection matrices
	
	bool   getOrtho( double& left,   double& right,
	                 double& bottom, double& top,
	                 double& zNear,  double& zFar   ) const;
	
	bool getFrustum( double& left,   double& right,
	                 double& bottom, double& top,
	                 double& zNear,  double& zFar   ) const;
	
	/** Get the frustum settings of a symmetric perspective projection
	 * matrix.
	 * Return false if matrix is not a perspective matrix,
	 * where parameter values are undefined.
	 * Note, if matrix is not a symmetric perspective matrix then the
	 * shear will be lost.
	 * Asymmetric matrices occur when stereo, power walls, caves and
	 * reality center display are used.
	 * In these configuration one should use the AsFrustum method instead.
	 */
	bool getPerspective( double& fovy,  double& aspectRatio,
	                     double& zNear, double& zFar         ) const;
	
	// will only work for modelview matrices
	void getLookAt( _ofVec3<T>& eye, 
                    _ofVec3<T>& center, 
                    _ofVec3<T>& up,
	                T lookDistance = 1.0f ) const;
	
	
	
	//---------------------------------------------
	// decompose the matrix into translation, rotation,
	// scale and scale orientation.
	void decompose( _ofVec3<T>& translation,
				    _ofQuaternion<T>& rotation,
				    _ofVec3<T>& scale,
				    _ofQuaternion<T>& so         ) const;
	
	
	//---------------------------------------------
	// basic utility functions to create new matrices
	inline static _ofMatrix4x4<T>    newIdentityMatrix( void );
	inline static _ofMatrix4x4<T>       newScaleMatrix( const _ofVec3<T>& sv );
	inline static _ofMatrix4x4<T>       newScaleMatrix( T sx, T sy, T sz );
	inline static _ofMatrix4x4<T> newTranslationMatrix( const _ofVec3<T>& dv );
	inline static _ofMatrix4x4<T> newTranslationMatrix( T x, T y, T z );
	inline static _ofMatrix4x4<T>    newRotationMatrix( const _ofVec3<T>& from, const _ofVec3<T>& to );
	inline static _ofMatrix4x4<T>    newRotationMatrix( T angle,  T x, T y, T z );
	inline static _ofMatrix4x4<T>    newRotationMatrix( T angle,  const _ofVec3<T>& axis );
	inline static _ofMatrix4x4<T>    newRotationMatrix( T angle1, const _ofVec3<T>& axis1,
												        T angle2, const _ofVec3<T>& axis2,
												        T angle3, const _ofVec3<T>& axis3 );
	inline static _ofMatrix4x4<T>    newRotationMatrix( const _ofQuaternion<T>& quat );
	
	
	// create new matrices as transformation of another
	inline static _ofMatrix4x4<T>     getInverseOf( const _ofMatrix4x4<T>& matrix );
	inline static _ofMatrix4x4<T>  getTransposedOf( const _ofMatrix4x4<T>& matrix );
	inline static _ofMatrix4x4<T> getOrthoNormalOf( const _ofMatrix4x4<T>& matrix );
	
	
	// create new matrices related to glFunctions
	
	// glOrtho
	inline 
    static _ofMatrix4x4<T> newOrthoMatrix( double left,   double right,
										   double bottom, double top,
										   double zNear,  double zFar );
	
	// glOrtho2D
	inline 
    static _ofMatrix4x4<T> newOrtho2DMatrix( double left,   double right,
											 double bottom, double top);
	
	// glFrustum
	inline 
    static _ofMatrix4x4<T> newFrustumMatrix( double left,   double right,
											 double bottom, double top,
											 double zNear,  double zFar );
	
	// gluPerspective
	inline 
    static _ofMatrix4x4<T> newPerspectiveMatrix( double fovy,  double aspectRatio,
												 double zNear, double zFar );
	
	// gluLookAt
	inline 
    static _ofMatrix4x4<T> newLookAtMatrix( const _ofVec3<T>& eye,
											const _ofVec3<T>& center,
											const _ofVec3<T>& up);
	
	
	//---------------------------------------------
	// matrix - vector multiplication
	// although opengl uses premultiplication
	// because of the way matrices are used in opengl:
	//
	// _ofMatrix4x4				        openGL
	// [  0 ] [  1 ] [  2 ] [  3 ]		[ 0 ] [ 4 ] [  8 ] [ 12 ]
	// [  4 ] [  5 ] [  6 ] [  7 ]		[ 1 ] [ 5 ] [  9 ] [ 13 ]
	// [  8 ] [  9 ] [ 10 ] [ 11 ]		[ 2 ] [ 6 ] [ 10 ] [ 14 ]
	// [ 12 ] [ 13 ] [ 14 ] [ 15 ]		[ 3 ] [ 7 ] [ 11 ] [ 15 ]
	//
	// in memory though both are layed in the same way
	// so when uploading a matrix it just works without
	// needing to transpose
	//
	// so although opengl docs explain transformations
	// like:
	//
	// _ofVec3<T> c = rotateZ 30º _ofVec3<T> a around _ofVec3<T> b
	//
	// openGL docs says: c = T(b)*R(30)*a;
	//
	// with _ofMatrix4x4:
	// _ofMatrix4x4 R = _ofMatrix4x4::newRotationMatrix(30,0,0,1);
	// _ofMatrix4x4 T = _ofMatrix4x4::newTranlationMatrix(b);
	// _ofVec3<T> c = a*R*T;
	// where * is calling postMult
	
	inline _ofVec3<T> postMult( const _ofVec3<T>& v ) const;
	inline _ofVec3<T> operator* (const _ofVec3<T>& v) const {
		return postMult(v);
	}
	
	inline _ofVec4<T> postMult( const _ofVec4<T>& v ) const;
	inline _ofVec4<T> operator* (const _ofVec4<T>& v) const {
		return postMult(v);
	}
	
	inline _ofVec3<T> preMult( const _ofVec3<T>& v ) const;
	inline _ofVec4<T> preMult( const _ofVec4<T>& v ) const;
	
	
	//---------------------------------------------
	// set methods: all these alter the components
	// deleting the previous data only in that components
	void setTranslation( T tx, T ty, T tz );
	void setTranslation( const _ofVec3<T>& v );
	void      setRotate( const _ofQuaternion<T>& q );
	
	//---------------------------------------------
	// all these apply the transformations over the
	// current one, it's actually postMult... and behaves
	// the opposite to the equivalent gl functions
	// glTranslate + glRotate == rotate + translate
	void translate( T tx, T ty, T tz );
	void translate( const _ofVec3<T>& v );
	void    rotate( T angle, T x, T y, T z );
	void rotateRad( T angle, T x, T y, T z );
	void    rotate( const _ofQuaternion<T>& q );
	void     scale( T x, T y, T z);
	void     scale( const _ofVec3<T>& v );
	
	//---------------------------------------------
	// all these apply the transformations over the
	// current one, it's actually preMult... and behaves
	// the the same the equivalent gl functions
	void glTranslate( T tx, T ty, T tz );
	void glTranslate( const _ofVec3<T>& v );
	void    glRotate( T angle, T x, T y, T z );
	void glRotateRad( T angle, T x, T y, T z );
	void    glRotate( const _ofQuaternion<T>& q );
	void     glScale( T x, T y, T z );
	void     glScale( const _ofVec3<T>& v );
	
	//---------------------------------------------
	// get methods: return matrix components
	// rotation and scale can only be used if the matrix
	// only has rotation or scale.
	// for matrices with both use decompose instead.
	_ofQuaternion<T> getRotate() const;
	_ofVec3<T>  getTranslation() const;
	_ofVec3<T>        getScale() const;
	
	
	//---------------------------------------------
	// apply a 3x3 transform of v*M[0..2,0..2].
	inline static _ofVec3<T> transform3x3( const _ofVec3<T>& v, const _ofMatrix4x4<T>& m );
	
	// apply a 3x3 transform of M[0..2,0..2]*v.
	inline static _ofVec3<T> transform3x3( const _ofMatrix4x4<T>& m, const _ofVec3<T>& v );
	
	
	//---------------------------------------------
	// basic Matrixf multiplication, our workhorse methods.
	void postMult( const _ofMatrix4x4<T>& );
	inline void operator *= ( const _ofMatrix4x4<T>& other ) {
		if ( this == &other ) {
			_ofMatrix4x4<T> temp(other);
			postMult( temp );
		} else postMult( other );
	}
	
	inline _ofMatrix4x4<T> operator * ( const _ofMatrix4x4<T> &m ) const {
		_ofMatrix4x4<T> r;
		r.makeFromMultiplicationOf(*this, m);
		return  r;
	}
	
	
	
	void preMult( const _ofMatrix4x4<T>& );
	
	
	
	//---------------------------------------------
	// specialized postMult methods, usually you want to use this
	// for transforming _ofVec not preMult
	// equivalent to postMult(newTranslationMatrix(v)); */
	inline void postMultTranslate( const _ofVec3<T>& v );
	// equivalent to postMult(scale(v));
	inline void postMultScale( const _ofVec3<T>& v );
	// equivalent to postMult(newRotationMatrix(q));
	inline void postMultRotate( const _ofQuaternion<T>& q );
	
	// AARON METHODS
	inline void postMultTranslate( T x, T y, T z );
	inline void    postMultRotate( T angle, T x, T y, T z );
	inline void     postMultScale( T x, T y, T z);
	
	
	//---------------------------------------------
	
    /*! equivalent to preMult(newTranslationMatrix(v)); */
	inline void preMultTranslate( const _ofVec3<T>& v );

	/*! equivalent to preMult(newRotationMatrix(q)); */
	inline void    preMultRotate( const _ofQuaternion<T>& q );

    /*! equivalent to preMult(newScaleMatrix(v)); */
	inline void     preMultScale( const _ofVec3<T>& v );


    // IO Stream ----------------------------------------------------

	template <typename S>
	friend std::ostream& operator << ( std::ostream& os, const _ofMatrix4x4<S>& M );
	template <typename S>
	friend std::istream& operator >> ( std::istream& is, _ofMatrix4x4<S>& M );
};


//--------------------------------------------------
// implementation of inline methods

template <typename T> inline 
bool _ofMatrix4x4<T>::isNaN() const {
	
#if (_MSC_VER) || defined (TARGET_ANDROID)
#ifndef isnan
#define isnan(a) ((a) != (a))
#endif
	
	return isnan( _mat[0][0] ) || isnan( _mat[0][1] ) || isnan( _mat[0][2] ) || isnan( _mat[0][3] ) 
        || isnan( _mat[1][0] ) || isnan( _mat[1][1] ) || isnan( _mat[1][2] ) || isnan( _mat[1][3] ) 
        || isnan( _mat[2][0] ) || isnan( _mat[2][1] ) || isnan( _mat[2][2] ) || isnan( _mat[2][3] ) 
        || isnan( _mat[3][0] ) || isnan( _mat[3][1] ) || isnan( _mat[3][2] ) || isnan( _mat[3][3] );
	
#else
	return std::isnan( _mat[0][0] ) || std::isnan( _mat[0][1] ) || std::isnan( _mat[0][2] ) || std::isnan( _mat[0][3] ) 
        || std::isnan( _mat[1][0] ) || std::isnan( _mat[1][1] ) || std::isnan( _mat[1][2] ) || std::isnan( _mat[1][3] ) 
        || std::isnan( _mat[2][0] ) || std::isnan( _mat[2][1] ) || std::isnan( _mat[2][2] ) || std::isnan( _mat[2][3] ) 
        || std::isnan( _mat[3][0] ) || std::isnan( _mat[3][1] ) || std::isnan( _mat[3][2] ) || std::isnan( _mat[3][3] );
	
#endif
	
}


template <typename T, typename S> inline 
std::ostream& operator << ( std::ostream& os, const _ofMatrix4x4<T>& M ) {

	int w = 8;
	os	<< setw( w )
	<< M._mat[0][0] << ", " << setw( w )
	<< M._mat[0][1] << ", " << setw( w )
	<< M._mat[0][2] << ", " << setw( w ) 
	<< M._mat[0][3] << std::endl;
	
	os	<< setw( w )
	<< M._mat[1][0] << ", " << setw( w ) 
	<< M._mat[1][1] << ", " << setw( w )
	<< M._mat[1][2] << ", " << setw( w ) 
	<< M._mat[1][3] << std::endl;
	
	os	<< setw( w )
	<< M._mat[2][0] << ", " << setw( w ) 
	<< M._mat[2][1] << ", " << setw( w )
	<< M._mat[2][2] << ", " << setw( w ) 
	<< M._mat[2][3] << std::endl;
	
	os	<< setw( w )
	<< M._mat[3][0] << ", " << setw( w ) 
	<< M._mat[3][1] << ", " << setw( w )
	<< M._mat[3][2] << ", " << setw( w ) 
	<< M._mat[3][3];
	
	return os;
}

template <typename T, typename S> inline 
std::istream& operator >> ( std::istream& is, _ofMatrix4x4<T>& M ) {

	is >> M._mat[0][0]; is.ignore(2); 
	is >> M._mat[0][1]; is.ignore(2);
	is >> M._mat[0][2]; is.ignore(2);
	is >> M._mat[0][3]; is.ignore(1);
	
	is >> M._mat[1][0]; is.ignore(2); 
	is >> M._mat[1][1]; is.ignore(2);
	is >> M._mat[1][2]; is.ignore(2);
	is >> M._mat[1][3]; is.ignore(1);
	
	is >> M._mat[2][0]; is.ignore(2); 
	is >> M._mat[2][1]; is.ignore(2);
	is >> M._mat[2][2]; is.ignore(2);
	is >> M._mat[2][3]; is.ignore(1);
	
	is >> M._mat[3][0]; is.ignore(2); 
	is >> M._mat[3][1]; is.ignore(2);
	is >> M._mat[3][2]; is.ignore(2);
	is >> M._mat[3][3];

	return is;
}

template <typename T> inline 
_ofMatrix4x4<T>& _ofMatrix4x4<T>::operator = ( const _ofMatrix4x4<T>& rhs ) {
	
    if ( &rhs == this ) { 
        return *this; 
    }

	set( rhs.getPtr() );

	return *this;
}

template <typename T> inline 
void _ofMatrix4x4<T>::set( const _ofMatrix4x4<T>& rhs ) {

	set(rhs.getPtr());
}

template <typename T> inline 
void _ofMatrix4x4<T>::set( T const * const ptr ) {
	
    T* local_ptr = (T*)_mat;

	for ( int i = 0;i < 16; ++i ) {
        local_ptr[i] = (T)ptr[i];
    }
}
	
template <typename T>
template <typename S> inline 
void _ofMatrix4x4<T>::set( S const * const ptr ) {
	
    T* local_ptr = (T*)_mat;
	
    for ( int i = 0; i < 16; ++i ) {
        local_ptr[i] = (T)ptr[i];
    }
}

template <typename T> inline 
bool _ofMatrix4x4<T>::isIdentity() const {

	return _mat[0][0] == 1.0f && _mat[0][1] == 0.0f && _mat[0][2] == 0.0f &&  _mat[0][3] == 0.0f 
        && _mat[1][0] == 0.0f && _mat[1][1] == 1.0f && _mat[1][2] == 0.0f &&  _mat[1][3] == 0.0f 
        && _mat[2][0] == 0.0f && _mat[2][1] == 0.0f && _mat[2][2] == 1.0f &&  _mat[2][3] == 0.0f 
        && _mat[3][0] == 0.0f && _mat[3][1] == 0.0f && _mat[3][2] == 0.0f &&  _mat[3][3] == 1.0f;
}

template <typename T> inline 
void _ofMatrix4x4<T>::makeOrtho2DMatrix( double left,   double right,
										 double bottom, double top    ) {
	makeOrthoMatrix( left, right, bottom, top, -1.0, 1.0 );
}

template <typename T> inline 
_ofVec3<T> _ofMatrix4x4<T>::getTranslation() const {
	return _ofVec3<T>( _mat[3][0], _mat[3][1], _mat[3][2] );
}

template <typename T> inline 
_ofVec3<T> _ofMatrix4x4<T>::getScale() const {
	
    _ofVec3<T> x_vec( _mat[0][0], _mat[1][0], _mat[2][0] );
	_ofVec3<T> y_vec( _mat[0][1], _mat[1][1], _mat[2][1] );
	_ofVec3<T> z_vec( _mat[0][2], _mat[1][2], _mat[2][2] );

	return _ofVec3<T>( x_vec.length(), y_vec.length(), z_vec.length() );
}

//static utility methods
template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newIdentityMatrix( void ) {

	_ofMatrix4x4<T> m;
	m.makeIdentityMatrix();

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newScaleMatrix( T sx, T sy, T sz ) {
	
    _ofMatrix4x4<T> m;
	m.makeScaleMatrix( sx, sy, sz );

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newScaleMatrix( const _ofVec3<T>& v ) {

	return newScaleMatrix( v.x, v.y, v.z );
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newTranslationMatrix( T tx, T ty, T tz ) {

	_ofMatrix4x4<T> m;
	m.makeTranslationMatrix( tx, ty, tz );

	return m;
}

template <typename T>
inline _ofMatrix4x4<T> _ofMatrix4x4<T>::newTranslationMatrix(const _ofVec3<T>& v ) {
	return newTranslationMatrix(v.x, v.y, v.z );
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newRotationMatrix( const _ofQuaternion<T>& q ) {

	return _ofMatrix4x4<T>( q );
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newRotationMatrix( T angle, T x, T y, T z ) {

	_ofMatrix4x4<T> m;
	m.makeRotationMatrix( angle, x, y, z );

	return m;
}
	
template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newRotationMatrix( T angle, const _ofVec3<T>& axis ) {
	
    _ofMatrix4x4<T> m;
	m.makeRotationMatrix( angle, axis );

	return m;
}
	
template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newRotationMatrix(	T angle1, const _ofVec3<T>& axis1,
												    T angle2, const _ofVec3<T>& axis2,
												    T angle3, const _ofVec3<T>& axis3) {

	_ofMatrix4x4<T> m;
	m.makeRotationMatrix( angle1, axis1, angle2, axis2, angle3, axis3 );

	return m;
}
	
template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newRotationMatrix( const _ofVec3<T>& from, 
                                                    const _ofVec3<T>& to ) {

	_ofMatrix4x4<T> m;
	m.makeRotationMatrix( from, to );

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::getInverseOf( const _ofMatrix4x4<T>& matrix ) {

	_ofMatrix4x4<T> m;
	m.makeInvertOf( matrix );

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::getTransposedOf( const _ofMatrix4x4<T>& matrix ) {

	_ofMatrix4x4<T> m( matrix._mat[0][0], matrix._mat[1][0], matrix._mat[2][0], matrix._mat[3][0], 
                       matrix._mat[0][1], matrix._mat[1][1], matrix._mat[2][1], matrix._mat[3][1], 
                       matrix._mat[0][2], matrix._mat[1][2], matrix._mat[2][2], matrix._mat[3][2], 
                       matrix._mat[0][3], matrix._mat[1][3], matrix._mat[2][3], matrix._mat[3][3] );
	
    return m;
}
	
template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::getOrthoNormalOf( const _ofMatrix4x4<T>& matrix ) {

	_ofMatrix4x4<T> m;
	m.makeOrthoNormalOf( matrix );
	
    return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newOrthoMatrix( double left,   double right,
											     double bottom, double top,
											     double zNear,  double zFar ) {
	
    _ofMatrix4x4<T> m;
	m.makeOrthoMatrix( left, right, bottom, top, zNear, zFar );

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newOrtho2DMatrix( double left,   double right,
												   double bottom, double top   ) {
	
    _ofMatrix4x4<T> m;
	m.makeOrtho2DMatrix( left, right, bottom, top );

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newFrustumMatrix( double left,   double right,
												   double bottom, double top,
												   double zNear,  double zFar   ) {
	
    _ofMatrix4x4<T> m;
	m.makeFrustumMatrix(left, right, bottom, top, zNear, zFar);

	return m;
}

template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newPerspectiveMatrix( double fovy, 
                                                       double aspectRatio,
													   double zNear, 
                                                       double zFar ) {

	_ofMatrix4x4<T> m;
	m.makePerspectiveMatrix( fovy, aspectRatio, zNear, zFar );

	return m;
}
	
template <typename T> inline 
_ofMatrix4x4<T> _ofMatrix4x4<T>::newLookAtMatrix( const _ofVec3<T>& eye, 
                                                  const _ofVec3<T>& center, 
                                                  const _ofVec3<T>& up ) {
	
    _ofMatrix4x4<T> m;
	m.makeLookAtMatrix( eye, center, up );
	
    return m;
}

template <typename T> inline 
_ofVec3<T> _ofMatrix4x4<T>::postMult( const _ofVec3<T>& v ) const {
	
    T d = 1.0f / ( _mat[3][0] * v.x + _mat[3][1] * v.y + _mat[3][2] * v.z + _mat[3][3]);

	return _ofVec3<T>( ( _mat[0][0] * v.x + _mat[0][1] * v.y + _mat[0][2] * v.z + _mat[0][3] ) * d,
				       ( _mat[1][0] * v.x + _mat[1][1] * v.y + _mat[1][2] * v.z + _mat[1][3] ) * d,
				       ( _mat[2][0] * v.x + _mat[2][1] * v.y + _mat[2][2] * v.z + _mat[2][3] ) * d) ;
}

template <typename T> inline 
_ofVec3<T> _ofMatrix4x4<T>::preMult( const _ofVec3<T>& v ) const {

	T d = 1.0f / ( _mat[0][3] * v.x + _mat[1][3] * v.y + _mat[2][3] * v.z + _mat[3][3] );

	return _ofVec3<T>( ( _mat[0][0] * v.x + _mat[1][0] * v.y + _mat[2][0] * v.z + _mat[3][0] ) * d,
				       ( _mat[0][1] * v.x + _mat[1][1] * v.y + _mat[2][1] * v.z + _mat[3][1] ) * d,
				       ( _mat[0][2] * v.x + _mat[1][2] * v.y + _mat[2][2] * v.z + _mat[3][2] ) * d );
}

template <typename T> inline 
_ofVec4<T> _ofMatrix4x4<T>::postMult( const _ofVec4<T>& v ) const {

	return _ofVec4<T>( ( _mat[0][0] * v.x + _mat[0][1] * v.y + _mat[0][2] * v.z + _mat[0][3] * v.w ),
				       ( _mat[1][0] * v.x + _mat[1][1] * v.y + _mat[1][2] * v.z + _mat[1][3] * v.w ),
				       ( _mat[2][0] * v.x + _mat[2][1] * v.y + _mat[2][2] * v.z + _mat[2][3] * v.w ),
				       ( _mat[3][0] * v.x + _mat[3][1] * v.y + _mat[3][2] * v.z + _mat[3][3] * v.w ) );
}

template <typename T> inline 
_ofVec4<T> _ofMatrix4x4<T>::preMult( const _ofVec4<T>& v ) const {

	return _ofVec4<T>( ( _mat[0][0] * v.x + _mat[1][0] * v.y + _mat[2][0] * v.z + _mat[3][0] * v.w ),
				       ( _mat[0][1] * v.x + _mat[1][1] * v.y + _mat[2][1] * v.z + _mat[3][1] * v.w ),
				       ( _mat[0][2] * v.x + _mat[1][2] * v.y + _mat[2][2] * v.z + _mat[3][2] * v.w ),
				       ( _mat[0][3] * v.x + _mat[1][3] * v.y + _mat[2][3] * v.z + _mat[3][3] * v.w ) );
}
	
template <typename T> inline 
_ofVec3<T> _ofMatrix4x4<T>::transform3x3( const _ofVec3<T>& v, const _ofMatrix4x4<T>& m ) {

	return _ofVec3<T>( ( m._mat[0][0] * v.x + m._mat[1][0] * v.y + m._mat[2][0] * v.z ),
				       ( m._mat[0][1] * v.x + m._mat[1][1] * v.y + m._mat[2][1] * v.z ),
				       ( m._mat[0][2] * v.x + m._mat[1][2] * v.y + m._mat[2][2] * v.z ) );
}
	
template <typename T> inline 
_ofVec3<T> _ofMatrix4x4<T>::transform3x3( const _ofMatrix4x4<T>& m, const _ofVec3<T>& v ) {

	return _ofVec3<T>( ( m._mat[0][0] * v.x + m._mat[0][1] * v.y + m._mat[0][2] *v.z ),
				       ( m._mat[1][0] * v.x + m._mat[1][1] * v.y + m._mat[1][2] *v.z ),
				       ( m._mat[2][0] * v.x + m._mat[2][1] * v.y + m._mat[2][2] *v.z ) );
}

template <typename T> inline 
void _ofMatrix4x4<T>::preMultTranslate( const _ofVec3<T>& v ) {
	
    for ( unsigned i = 0; i < 3; ++i ) {

		T tmp = v.getPtr()[i];
		
        if ( tmp == 0 ) { continue; }

		_mat[3][0] += tmp * _mat[i][0];
		_mat[3][1] += tmp * _mat[i][1];
		_mat[3][2] += tmp * _mat[i][2];
		_mat[3][3] += tmp * _mat[i][3];
	}
}

template <typename T> inline 
void _ofMatrix4x4<T>::postMultTranslate( const _ofVec3<T>& v ) {
	for (unsigned i = 0; i < 3; ++i) {

		T tmp = v.getPtr()[ i ];
		
        if ( tmp == 0 ) { continue; }

		_mat[0][i] += tmp * _mat[0][3];
		_mat[1][i] += tmp * _mat[1][3];
		_mat[2][i] += tmp * _mat[2][3];
		_mat[3][i] += tmp * _mat[3][3];
	}
}

// AARON METHOD
template <typename T> inline 
void _ofMatrix4x4<T>::postMultTranslate( T x, T y, T z ) {

	if ( x != 0 ) {
		_mat[0][0] += x * _mat[0][3];
		_mat[1][0] += x * _mat[1][3];
		_mat[2][0] += x * _mat[2][3];
		_mat[3][0] += x * _mat[3][3];
	}
	if ( y != 0 ) {
		_mat[0][1] += y * _mat[0][3];
		_mat[1][1] += y * _mat[1][3];
		_mat[2][1] += y * _mat[2][3];
		_mat[3][1] += y * _mat[3][3];
	}
	if ( z != 0 ) {
		_mat[0][2] += z * _mat[0][3];
		_mat[1][2] += z * _mat[1][3];
		_mat[2][2] += z * _mat[2][3];
		_mat[3][2] += z * _mat[3][3];
	}
}

template <typename T> inline 
void _ofMatrix4x4<T>::preMultScale( const _ofVec3<T>& v ) {

	_mat[0][0] *= v.getPtr()[0];
	_mat[0][1] *= v.getPtr()[0];
	_mat[0][2] *= v.getPtr()[0];
	_mat[0][3] *= v.getPtr()[0];
	_mat[1][0] *= v.getPtr()[1];
	_mat[1][1] *= v.getPtr()[1];
	_mat[1][2] *= v.getPtr()[1];
	_mat[1][3] *= v.getPtr()[1];
	_mat[2][0] *= v.getPtr()[2];
	_mat[2][1] *= v.getPtr()[2];
	_mat[2][2] *= v.getPtr()[2];
	_mat[2][3] *= v.getPtr()[2];
}

template <typename T> inline 
void _ofMatrix4x4<T>::postMultScale( const _ofVec3<T>& v ) {
	
    _mat[0][0] *= v.getPtr()[0];
	_mat[1][0] *= v.getPtr()[0];
	_mat[2][0] *= v.getPtr()[0];
	_mat[3][0] *= v.getPtr()[0];
	_mat[0][1] *= v.getPtr()[1];
	_mat[1][1] *= v.getPtr()[1];
	_mat[2][1] *= v.getPtr()[1];
	_mat[3][1] *= v.getPtr()[1];
	_mat[0][2] *= v.getPtr()[2];
	_mat[1][2] *= v.getPtr()[2];
	_mat[2][2] *= v.getPtr()[2];
	_mat[3][2] *= v.getPtr()[2];
}

template <typename T> inline 
void _ofMatrix4x4<T>::rotate( const _ofQuaternion<T>& q ) {

	postMultRotate( q );
}

template <typename T> inline 
void _ofMatrix4x4<T>::rotate( T angle, T x, T y, T z ) {

	postMultRotate( angle, x, y, z );
}

template <typename T> inline 
void _ofMatrix4x4<T>::rotateRad( T angle, T x, T y, T z ) {
	
    postMultRotate( angle * RAD_TO_DEG, x, y, z );
}

template <typename T> inline 
void _ofMatrix4x4<T>::translate( T tx, T ty, T tz ) {

	postMultTranslate( tx, ty, tz );
}

template <typename T> inline 
void _ofMatrix4x4<T>::translate( const _ofVec3<T>& v ) {
	
    postMultTranslate(v);
}

template <typename T> inline
void _ofMatrix4x4<T>::scale( T x, T y, T z ) {

	postMultScale(x,y,z);
}

template <typename T> inline 
void _ofMatrix4x4<T>::scale( const _ofVec3<T>& v ) {

	postMultScale(v);
}

template <typename T> inline 
void _ofMatrix4x4<T>::glRotate(T angle, T x, T y, T z ) {

	preMultRotate( _ofQuaternion<T>( angle, _ofVec3<T>( x, y, z ) ) );
}

template <typename T> inline 
void _ofMatrix4x4<T>::glRotateRad( T angle, T x, T y, T z ) {

	preMultRotate( _ofQuaternion<T>( angle * RAD_TO_DEG, _ofVec3<T>( x, y, z) ) );
}

template <typename T> inline 
void _ofMatrix4x4<T>::glRotate( const _ofQuaternion<T>& q ) {

	preMultRotate( q );
}

template <typename T> inline 
void _ofMatrix4x4<T>::glTranslate( T tx, T ty, T tz ) {

	preMultTranslate( _ofVec3<T>( tx, ty, tz ) );
}

template <typename T> inline 
void _ofMatrix4x4<T>::glTranslate( const _ofVec3<T>& v ) {

	preMultTranslate(v);
}

template <typename T> inline 
void _ofMatrix4x4<T>::glScale( T x, T y, T z ) {

	preMultScale(_ofVec3<T>(x,y,z));
}

template <typename T> inline 
void _ofMatrix4x4<T>::glScale( const _ofVec3<T>& v ) {

	preMultScale(v);
}

// AARON METHOD
template <typename T> inline 
void _ofMatrix4x4<T>::postMultScale( T x, T y, T z ) {

	_mat[0][0] *= x;
	_mat[1][0] *= x;
	_mat[2][0] *= x;
	_mat[3][0] *= x;
	_mat[0][1] *= y;
	_mat[1][1] *= y;
	_mat[2][1] *= y;
	_mat[3][1] *= y;
	_mat[0][2] *= z;
	_mat[1][2] *= z;
	_mat[2][2] *= z;
	_mat[3][2] *= z;
}
	
template <typename T> inline 
void _ofMatrix4x4<T>::preMultRotate( const _ofQuaternion<T>& q ) {
	if ( q.zeroRotation() ) { return; }

	_ofMatrix4x4<T> r;
	r.setRotate(q);
	preMult(r);
}
	
template <typename T> inline 
void _ofMatrix4x4<T>::postMultRotate( const _ofQuaternion<T>& q ) {
	if ( q.zeroRotation() ) { return; }

	_ofMatrix4x4<T> r;
	r.setRotate(q);
	postMult(r);
}

// AARON METHOD
template <typename T> inline 
void _ofMatrix4x4<T>::postMultRotate( T angle, T x, T y, T z ) {
	_ofMatrix4x4<T> r;
	r.makeRotationMatrix(angle, x, y, z);
	postMult(r);
}

template <typename T> inline 
_ofVec3<T> operator * ( const _ofVec3<T>& v, const _ofMatrix4x4<T>& m ) {
//	ofLog() << "Matrix * operation" << v.x << v.y << v.z;
	return m.preMult(v);
}

template <typename T> inline 
_ofVec4<T> operator * ( const _ofVec4<T>& v, const _ofMatrix4x4<T>& m ) {
	return m.preMult(v);
}


typedef _ofMatrix4x4<int>    _ofMatrix4x4i;
typedef _ofMatrix4x4<float>  _ofMatrix4x4f;
typedef _ofMatrix4x4<double> _ofMatrix4x4d;

// This will be used to keep the same 
// type used on the entire core.
// typedef _ofMatrix4x4f ofMatrix4x4;