/**
 * Credits:
 * Code adopted from Lode Vandevenne http://student.kuleuven.be/~m0216922/CG/
 */

#pragma once

#include "ofConstants.h"

/*! OF matrix 3x3 representation.
 
    [ a b c ]
    [ d e f ]
    [ g h i ]                    
*/
template <typename T>
class _ofMatrix3x3 {
public:
	
    T a, b, c,
      d, e, f,
      g, h, i;

    typedef T type;

    _ofMatrix3x3()
    : a(0), b(0), c(0),
      d(0), e(0), f(0),
      g(0), h(0), i(0) {}
	
	_ofMatrix3x3( T _a,  T _b,  T _c,
				  T _d,  T _e,  T _f,
				  T _g,  T _h,  T _i )
    : a(_a), b(_b), c(_c),
      d(_d), e(_e), f(_f),
      g(_g), h(_h), i(_i) {}
	
	// Setters & Getters -------------------------------------------
	
    void set( 
        T _a, T _b, T _c,
        T _d, T _e, T _f,
        T _g, T _h, T _i 
    );
	
	// Accessors ---------------------------------------------------
	
    T& operator[]( const int& index ) {
        switch(index) {
            case 0:  return a;
            case 1:  return b;
            case 2:  return c;
            case 3:  return d;
            case 4:  return e;
            case 5:  return f;
            case 6:  return g;
            case 7:  return h;
            case 8:  return i;
            default: return a;
        }
    }
	
	// Overloading for any type to any type ---------------------------------
	
	/*! Multiply a matrix by a matrix entry by entry (i.e. a*a, b*b, c*c...)
	    This is referred to as an entrywise, Hadamard, or Schur product. */
	_ofMatrix3x3<T> entrywiseTimes( const _ofMatrix3x3<T>& A );
    /*! Add two matrices. */
    _ofMatrix3x3<T> operator + ( const _ofMatrix3x3<T>& B );
    /*! Subtract two matrices. */
    _ofMatrix3x3<T> operator - ( const _ofMatrix3x3<T>& B );
    /*! Multiply a matrix with a scalar. */
    _ofMatrix3x3<T> operator * ( T scalar );
	/*! Multiply a 3x3 matrix with a 3x3 matrix. */
    _ofMatrix3x3<T> operator * ( const _ofMatrix3x3<T>& B );
    /*! Divide a matrix through a scalar */
    _ofMatrix3x3<T> operator / ( T scalar );

	/*! for each a[i][j], + scalar. */
    void operator += ( const _ofMatrix3x3<T>& B );
	/*! for each a[i][j], - scalar. */
	void operator -= ( const _ofMatrix3x3<T>& B );
	/*! Multiply a matrix by a matrix this = this*B (in that order). */
	void operator *= ( const _ofMatrix3x3<T>& B );
	/*! for each a[i][j], * scalar. */
    void operator *= ( T scalar );
	/*! Divide a matrix by a matrix this = this*B (in that order). */
	void operator /= ( const _ofMatrix3x3<T>& B);
	/*! for each a[i][j], / scalar. */
    void operator /= ( T scalar );
	
	// Transpose ---------------------------------------------------
	
	/*!
     * This changes the matrix.
     * [ a b c ]T    [ a d g ]
     * [ d e f ]  =  [ b e h ]
     * [ g h i ]     [ c f i ]
     */
	void transpose();
	
	/*!
	 * Transpose without changing the matrix.
	 * Uses the "swap" method with additions 
     * and subtractions to swap the elements 
     * that aren't on the main diagonal.
	 * @return transposed matrix.
	 */
	_ofMatrix3x3<T> transpose( const _ofMatrix3x3<T>& A );
	
	// Determinant ------------------------------------------------
    
	/*! Determinant: 
	    http://mathworld.wolfram.com/Determinant.html */
    T determinant() const;
    /*! */	
    T determinant( const _ofMatrix3x3<T>& A );
	
	// Inverse ------------------------------------------------

    /*! 
     * Inverse of a 3x3 matrix the inverse 
     * is the adjoint divided through the determinant 
     * find the matrix of minors (minor = determinant 
     * of 2x2 matrix of the 2 rows/colums current element 
     * is NOT in) turn them in cofactors (= change some 
     * of the signs) find the adjoint by transposing 
     * the matrix of cofactors divide this through 
     * the determinant to get the inverse. 
     */
    void invert();
	
    _ofMatrix3x3<T> inverse( const _ofMatrix3x3<T>& A );
	
    // IO Stream ----------------------------------------------------

	template <typename S> friend 
    std::ostream& operator << ( std::ostream& os, const _ofMatrix3x3<S>& M );
	template <typename S> friend 
    std::istream& operator >> ( std::istream& is, _ofMatrix3x3<S>& M );
};

//
// Implementation ---------------------------------------------
//

// Overloading for any type to any type ---------------------------------

/*! Add two matrices. */
template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::operator + ( const _ofMatrix3x3<T>& B ) {
	
	_ofMatrix3x3<T> result;
	
	result.a = a + B.a;
	result.b = b + B.b;
	result.c = c + B.c;
	result.d = d + B.d;
	result.e = e + B.e;
	result.f = f + B.f;
	result.g = g + B.g;
	result.h = h + B.h;
	result.i = i + B.i;
	
	return result;
}

template <typename T>
void _ofMatrix3x3<T>::operator += ( const _ofMatrix3x3<T>& B ) {
	
	a += B.a;
	b += B.b;
	c += B.c;
	d += B.d;
	e += B.e;
	f += B.f;
	g += B.g;
	h += B.h;
	i += B.i;
}

/*! Subtract two matrices. */
template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::operator - ( const _ofMatrix3x3<T>& B ) {
	
	_ofMatrix3x3<T> result;
	
	result.a = a - B.a;
	result.b = b - B.b;
	result.c = c - B.c;
	result.d = d - B.d;
	result.e = e - B.e;
	result.f = f - B.f;
	result.g = g - B.g;
	result.h = h - B.h;
	result.i = i - B.i;
	
	return result;
}

template <typename T>
void _ofMatrix3x3<T>::operator -= ( const _ofMatrix3x3<T>& B ) {
	
	a -= B.a;
	b -= B.b;
	c -= B.c;
	d -= B.d;
	e -= B.e;
	f -= B.f;
	g -= B.g;
	h -= B.h;
	i -= B.i;
}

/*! Multiply a matrix with a scalar. */
template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::operator * ( T scalar ) {
	
    _ofMatrix3x3<T> result;
	
    result.a = a * scalar;
	result.b = b * scalar;
	result.c = c * scalar;
	result.d = d * scalar;
	result.e = e * scalar;
	result.f = f * scalar;
	result.g = g * scalar;
	result.h = h * scalar;
	result.i = i * scalar;
	
    return result;
}

template <typename T>
void _ofMatrix3x3<T>::operator *= ( const _ofMatrix3x3<T>& B ) {
	*this = *this*B;
}

template <typename T>
void _ofMatrix3x3<T>::operator *= ( T scalar ) {
	
	a *= scalar;
	b *= scalar;
	c *= scalar;
	d *= scalar;
	e *= scalar;
	f *= scalar;
	g *= scalar;
	h *= scalar;
	i *= scalar;
}

/*! Multiply a 3x3 matrix with a 3x3 matrix. */
template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::operator * ( const _ofMatrix3x3<T>& B ) {
	
	_ofMatrix3x3<T> C;
	
	C.a = a * B.a + b * B.d + c * B.g;
	C.b = a * B.b + b * B.e + c * B.h;
	C.c = a * B.c + b * B.h + c * B.i;
	C.d = d * B.a + e * B.d + f * B.g;
	C.e = d * B.b + e * B.e + f * B.h;
	C.f = d * B.c + e * B.h + f * B.i;
	C.g = g * B.a + h * B.d + i * B.g;
	C.h = g * B.b + h * B.e + i * B.h;
	C.i = g * B.c + h * B.h + i * B.i;
	
    return C;
}

/*! Divide a matrix through a scalar. */
template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::operator / ( T scalar ) {
	
	_ofMatrix3x3<T> result;
	
	result.a = a / scalar;
	result.b = b / scalar;
	result.c = c / scalar;
	result.d = d / scalar;
	result.e = e / scalar;
	result.f = f / scalar;
	result.g = g / scalar;
	result.h = h / scalar;
	result.i = i / scalar;
	
	return result;
}

template <typename T>
void _ofMatrix3x3<T>::operator /= ( const _ofMatrix3x3<T>& B ) {
	
	a /= B.a;
	b /= B.b;
	c /= B.c;
	d /= B.d;
	e /= B.e;
	f /= B.f;
	g /= B.g;
	h /= B.h;
	i /= B.i;
}

template <typename T>
void _ofMatrix3x3<T>::operator /= ( T scalar ) {
	
	a /= scalar;
	b /= scalar;
	c /= scalar;
	d /= scalar;
	e /= scalar;
	f /= scalar;
	g /= scalar;
	h /= scalar;
	i /= scalar;
}

// IO Stream ----------------------------------------------------

template <typename T, typename S>
std::ostream& operator << ( std::ostream& os, const _ofMatrix3x3<S>& M ) {
	
    int w = 8;
	
    os	<< setw( w )
	<< M.a << ", " << setw( w )
	<< M.b << ", " << setw( w )
	<< M.c << std::endl;
	
	os	<< setw( w )
	<< M.d << ", " << setw( w )
	<< M.e << ", " << setw( w )
	<< M.f << std::endl;
	
	os	<< setw( w )
	<< M.g << ", " << setw( w )
	<< M.h << ", " << setw( w )
	<< M.i;
	
	return os;
}

template <typename T, typename S>
std::istream& operator >> ( std::istream& is, _ofMatrix3x3<S>& M ) {
	
	is >> M.a; is.ignore(2);
	is >> M.b; is.ignore(2);
	is >> M.c; is.ignore(1);
	is >> M.d; is.ignore(2);
	is >> M.e; is.ignore(2);
	is >> M.f; is.ignore(1);
	is >> M.h;
	
	return is;
}

typedef _ofMatrix3x3<int>    _ofMatrix3x3i;
typedef _ofMatrix3x3<float>  _ofMatrix3x3f;
typedef _ofMatrix3x3<double> _ofMatrix3x3d;

// This will be used to keep the same 
// type used on the entire core.
// typedef _ofMatrix3x3f ofMatrix3x3;
