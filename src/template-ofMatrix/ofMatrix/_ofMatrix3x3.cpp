
#include "_ofMatrix3x3.h"

namespace of {

template <typename T>
void ofMatrix3x3<T>::set( T _a, T _b, T _c,
					  T _d, T _e, T _f,
					  T _g, T _h, T _i )
{
	a = _a;
	b = _b;
	c = _c;
	d = _d;
	e = _e;
	f = _f;
	g = _g;
	h = _h;
	i = _i;
}

/**
 * Transpose:
 * This changes the matrix.
 * [ a b c ]T    [ a d g ]
 * [ d e f ]  =  [ b e h ]
 * [ g h i ]     [ c f i ]
 */

template <typename T>
void ofMatrix3x3<T>::transpose() {
	b += d; d = b - d; b -= d; //swap b and d
	c += g; g = c - g; c -= g; //swap c and g
	f += h; h = f - h; f -= h; //swap f and h
}

/**
 * Transpose without changing the matrix.
 * Uses the "swap" method with additions and subtractions to swap the elements that aren't on the main diagonal.
 * @return transposed matrix.
 */

template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::transpose(const ofMatrix3x3<T>& A) {
	ofMatrix3x3<T> result = A;
	result.transpose();
	return result;
}

/**
 * Determinant: http://mathworld.wolfram.com/Determinant.html
 */
template <typename T>
T ofMatrix3x3<T>::determinant() const {
	T det = a * e * i
	+ b * f * g
	+ d * h * c
	- g * e * c
	- d * b * i
	- h * f * a;
	return det;
}

template <typename T>
T ofMatrix3x3<T>::determinant(const ofMatrix3x3<T>& A) {
	return A.determinant();
}

/**
 * Inverse of a 3x3 matrix
 the inverse is the adjoint divided through the determinant
 find the matrix of minors (minor = determinant of 2x2 matrix of the 2 rows/colums current element is NOT in)
 turn them in cofactors (= change some of the signs)
 find the adjoint by transposing the matrix of cofactors
 divide this through the determinant to get the inverse
 */
template <typename T>
void ofMatrix3x3<T>::invert() {
	T det = determinant();
	ofMatrix3x3<T> B;
	
	//included in these calculations: minor, cofactor (changed signs), transpose (by the order of "="), division through determinant
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
ofMatrix3x3<T> ofMatrix3x3<T>::inverse(const ofMatrix3x3<T>& A) {
	ofMatrix3x3<T> result = A;
	result.invert();
	return result;
}

/**
 * Add two matrices
 */
template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::operator+(const ofMatrix3x3<T>& B) {
	ofMatrix3x3<T> result;
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
void ofMatrix3x3<T>::operator+=(const ofMatrix3x3<T>& B) {
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

/**
 * Subtract two matrices
 */
template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::operator-(const ofMatrix3x3<T>& B) {
	ofMatrix3x3<T> result;
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
void ofMatrix3x3<T>::operator-=(const ofMatrix3x3<T>& B) {
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

/**
 * Multiply a matrix with a scalar
 */
template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::operator*(T scalar) {
	ofMatrix3x3<T> result;
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
void ofMatrix3x3<T>::operator*=(const ofMatrix3x3<T>& B) {
	*this = *this*B;
}

template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::entrywiseTimes(const ofMatrix3x3<T>& B){
	ofMatrix3x3<T> C = *this;
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

template <typename T>
void ofMatrix3x3<T>::operator*=(T scalar) {
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

/**
 * Multiply a 3x3 matrix with a 3x3 matrix
 */
template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::operator*(const ofMatrix3x3<T>& B) {
	ofMatrix3x3<T> C;
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

/**
 * Divide a matrix through a scalar
 */
template <typename T>
ofMatrix3x3<T> ofMatrix3x3<T>::operator/(T scalar) {
	ofMatrix3x3<T> result;
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
void ofMatrix3x3<T>::operator/=(const ofMatrix3x3<T>& B) {
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
void ofMatrix3x3<T>::operator/=(T scalar) {
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

template <typename T, typename S>
ostream& operator<<(ostream& os, const ofMatrix3x3<S>& M) {
	int w = 8;
	os	<< setw(w)
	<< M.a << ", " << setw(w)
	<< M.b << ", " << setw(w)
	<< M.c << std::endl;
	
	os	<< setw(w)
	<< M.d << ", " << setw(w)
	<< M.e << ", " << setw(w)
	<< M.f << std::endl;
	
	os	<< setw(w)
	<< M.g << ", " << setw(w)
	<< M.h << ", " << setw(w)
	<< M.i;
	return os;
}

template <typename T, typename S>
istream& operator>>(istream& is, ofMatrix3x3<S>& M) {
	is >> M.a; is.ignore(2);
	is >> M.b; is.ignore(2);
	is >> M.c; is.ignore(1);
	is >> M.d; is.ignore(2);
	is >> M.e; is.ignore(2);
	is >> M.f; is.ignore(1);
	is >> M.h;
	return is;
}

}
