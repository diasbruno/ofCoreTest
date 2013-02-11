
#include "_ofMatrix3x3.h"

template <typename T>
void _ofMatrix3x3<T>::set( T _a, T _b, T _c,
						   T _d, T _e, T _f,
						   T _g, T _h, T _i  ) {
	
	a = _a; b = _b; c = _c;
	d = _d; e = _e; f = _f;
	g = _g;	h = _h; i = _i;
}

// Overloading for any type to any type ---------------------------------

template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::entrywiseTimes( const _ofMatrix3x3<T>& B ) {
	
    _ofMatrix3x3<T> C = *this;
	
    C.a *= B.a;
	C.b *= B.b;
	C.c *= B.c;
	C.d *= B.d;
	C.e *= B.e;
	C.f *= B.f;
	C.g *= B.g;
	C.h *= B.h;
	C.i *= B.i;
	
    return C;
}

/**
 * Transpose:
 * This changes the matrix.
 * [ a b c ]T    [ a d g ]
 * [ d e f ]  =  [ b e h ]
 * [ g h i ]     [ c f i ]
 */
template <typename T>
void _ofMatrix3x3<T>::transpose() {
	
	b += d; d = b - d; b -= d; //swap b and d
	c += g; g = c - g; c -= g; //swap c and g
	f += h; h = f - h; f -= h; //swap f and h
}

/**
 * Transpose without changing the matrix.
 * Uses the "swap" method with additions and subtractions 
 * to swap the elements that aren't on the main diagonal.
 * @return transposed matrix.
 */
template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::transpose( const _ofMatrix3x3<T>& A ) {
	
	_ofMatrix3x3<T> result = A;
	result.transpose();
	
	return result;
}

/**
 * Determinant: http://mathworld.wolfram.com/Determinant.html
 */
template <typename T>
T _ofMatrix3x3<T>::determinant() const {
	
	T det = a * e * i
	      + b * f * g
		  + d * h * c
	      - g * e * c
	      - d * b * i
	      - h * f * a;
	
	return det;
}

template <typename T>
T _ofMatrix3x3<T>::determinant( const _ofMatrix3x3<T>& A ) {
	
	return A.determinant();
}

/**
 Inverse of a 3x3 matrix
 the inverse is the adjoint divided through the determinant
 find the matrix of minors (minor = determinant of 2x2 matrix 
 of the 2 rows/colums current element is NOT in)
 turn them in cofactors (= change some of the signs)
 find the adjoint by transposing the matrix of cofactors
 divide this through the determinant to get the inverse
 */
template <typename T>
void _ofMatrix3x3<T>::invert() {
	
	T det = determinant();
	_ofMatrix3x3<T> B;
	
	//included in these calculations: minor, cofactor (changed signs), 
    //transpose (by the order of "="), division through determinant
	B.a = ( e * i - h * f) / det;	
	B.b = (-b * i + h * c) / det;
	B.c = ( b * f - e * c) / det;
	B.d = (-d * i + g * f) / det;
	B.e = ( a * i - g * c) / det;
	B.f = (-a * f + d * c) / det;
	B.g = ( d * h - g * e) / det;
	B.h = (-a * h + g * b) / det;
	B.i = ( a * e - d * b) / det;
	
	*this = B;
}

template <typename T>
_ofMatrix3x3<T> _ofMatrix3x3<T>::inverse( const _ofMatrix3x3<T>& A ) {
	
	_ofMatrix3x3<T> result = A;
	result.invert();
	
	return result;
}

template class _ofMatrix3x3<int>;
template class _ofMatrix3x3<float>;
template class _ofMatrix3x3<double>;