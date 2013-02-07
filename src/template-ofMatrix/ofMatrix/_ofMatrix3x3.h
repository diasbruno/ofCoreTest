/**
 * Credits:
 * Code adopted from Lode Vandevenne http://student.kuleuven.be/~m0216922/CG/
 */

#pragma once

#include "ofConstants.h"

namespace of {

template <typename T>
class ofMatrix3x3 {
public:
	
    /**
	 * [ a b c ]
	 * [ d e f ]
	 * [ g h i ]
	 */
    T a, b, c;
    T d, e, f;
    T g, h, i;
	
	
    ofMatrix3x3();
    ofMatrix3x3( T _a = 0.0, T _b = 0.0, T _c = 0.0,
				 T _d = 0.0, T _e = 0.0, T _f = 0.0,
				 T _g = 0.0, T _h = 0.0, T _i = 0.0 ) {
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
	
    void set( T _a, T _b, T _c,
			  T _d, T _e, T _f,
			  T _g, T _h, T _i );
	
	
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
	
	
	/**
     * Transpose:
     * This changes the matrix.
     * [ a b c ]T    [ a d g ]
     * [ d e f ]  =  [ b e h ]
     * [ g h i ]     [ c f i ]
     */
	
	void transpose();
	
	/**
	 * Transpose without changing the matrix.
	 * Uses the "swap" method with additions and subtractions to swap the elements that aren't on the main diagonal.
	 * @return transposed matrix.
	 */
	
	ofMatrix3x3<T> transpose(const ofMatrix3x3<T>& A);
	
	
	
	/**
	 * Determinant: http://mathworld.wolfram.com/Determinant.html
	 */
	
    T determinant() const;
	
    T determinant(const ofMatrix3x3<T>& A);
	
	
	
    /**
	 * Inverse of a 3x3 matrix
	 the inverse is the adjoint divided through the determinant
	 find the matrix of minors (minor = determinant of 2x2 matrix of the 2 rows/colums current element is NOT in)
	 turn them in cofactors (= change some of the signs)
	 find the adjoint by transposing the matrix of cofactors
	 divide this through the determinant to get the inverse
	 */
	
    void invert();
	
    ofMatrix3x3<T> inverse(const ofMatrix3x3<T>& A);
	
	
    /**
	 * Add two matrices
	 */
    ofMatrix3x3<T> operator+(const ofMatrix3x3<T>& B);
	
    void operator+=(const ofMatrix3x3<T>& B);
	
    /**
	 * Subtract two matrices
	 */
    ofMatrix3x3<T> operator-(const ofMatrix3x3<T>& B);
	
	void operator-=(const ofMatrix3x3<T>& B);
	
	
    /**
	 * Multiply a matrix with a scalar
	 */
    ofMatrix3x3<T> operator*(T scalar);
	
	/**
	 * Multiply a matrix by a matrix this = this*B (in that order)
	 */
	void operator*=(const ofMatrix3x3<T>& B);
	
	/**
	 * Multiply a matrix by a matrix entry by entry (i.e. a*a, b*b, c*c...)
	 This is referred to as an entrywise, Hadamard, or Schur product
	 */
    ofMatrix3x3<T> entrywiseTimes(const ofMatrix3x3<T>& A);
	
	/**
	 * Multiply a matrix by a scalar (multiples all entries by scalar)
	 */
    void operator*=(T scalar);
	
	template <typename S>
	friend ostream& operator<<(ostream& os, const ofMatrix3x3<S>& M);
	template <typename S>
	friend istream& operator>>(istream& is, ofMatrix3x3<S>& M);
	
	/**
     * Multiply a 3x3 matrix with a 3x3 matrix
     */
    ofMatrix3x3<T> operator*(const ofMatrix3x3<T>& B);
	
    /**
	 * Divide a matrix through a scalar
	 */
    ofMatrix3x3<T> operator/(T scalar);
	
	
	void operator/=(const ofMatrix3x3<T>& B);
	
    void operator/=(T scalar);
	
};

typedef ofMatrix3x3<int>    ofMatrix3x3i;
typedef ofMatrix3x3<float>  ofMatrix3x3f;
typedef ofMatrix3x3<double> ofMatrix3x3d;
	
}

