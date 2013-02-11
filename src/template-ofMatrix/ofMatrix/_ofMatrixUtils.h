#pragma once

template <typename T> class _ofMatrix3x3;
template <typename T> class _ofMatrix4x4;

#define SET_M3_ROW(row, v1, v2, v3 )    \
	_mat[(row)][0] = (v1); \
	_mat[(row)][1] = (v2); \
	_mat[(row)][2] = (v3); 

//#define INNER_M4_PRODUCT(a,b,r,c) \
//	((a)._mat[r][0] * (b)._mat[0][c]) \
//	+((a)._mat[r][1] * (b)._mat[1][c]) \
//	+((a)._mat[r][2] * (b)._mat[2][c]) \
//	+((a)._mat[r][3] * (b)._mat[3][c])

#define SET_M4_ROW(row, v1, v2, v3, v4 )    \
	_mat[(row)][0] = (v1); \
	_mat[(row)][1] = (v2); \
	_mat[(row)][2] = (v3); \
	_mat[(row)][3] = (v4);

#define INNER_M4_PRODUCT(a,b,r,c) \
	((a)._mat[r][0] * (b)._mat[0][c]) \
	+((a)._mat[r][1] * (b)._mat[1][c]) \
	+((a)._mat[r][2] * (b)._mat[2][c]) \
	+((a)._mat[r][3] * (b)._mat[3][c])

// Matrices Identity

template <typename T>
_ofMatrix3x3<T> matrixIdentity3x3() {
	
	return _ofMatrix3x3<T>( 
				1,0,0,
				0,1,0,
				0,0,1
		   );
}

template <typename T>
_ofMatrix4x4<T> matrixIdentity4x4() {
	
	return _ofMatrix4x4<T>( 
				1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1
		   );
}


template <typename T>
T matrixDeterminant3x3( const _ofMatrix3x3<T>& A ) {
	
	return A.determinant();
}

template <typename T>
_ofMatrix3x3<T> matrixInverse3x3( const _ofMatrix3x3<T>& A ) {
	
	_ofMatrix3x3<T> result = A;
	result.invert();
	
	return result;
}
