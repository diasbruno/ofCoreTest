/*
 *  _ofQuaternionT.cpp
 *  ofCoreTest
 *
 *  Created by Bruno Dias on 2/6/13.
 *  Copyright 2013 Interactive Developer. All rights reserved.
 *
 */

#include "_ofQuaternionT.h"

#include "_ofMatrix4x4.h"
#include "ofMath.h"

namespace of {

template <typename T>
void ofQuaternion<T>::set(const ofMatrix4x4<T>T& matrix) {
	*this = matrix.getRotate();
}

template <typename T>
void ofQuaternion<T>::get(ofMatrix4x4<T>T& matrix) const {
	matrix.makeRotationMatrix(*this);
}


/// Set the elements of the Quat to represent a rotation of angle
/// (degrees) around the axis (x,y,z)
template <typename T>
void ofQuaternion<T>::makeRotate( T angle, T x, T y, T z ) {
	angle = ofDegToRad(angle);
	
	const T epsilon = 0.0000001f;
	
	T length = sqrtf( x * x + y * y + z * z );
	if (length < epsilon) {
		// ~zero length axis, so reset rotation to zero.
		*this = ofQuaternion<T>();
		return;
	}
	
	T inversenorm  = 1.0f / length;
	T coshalfangle = cosf( 0.5f * angle );
	T sinhalfangle = sinf( 0.5f * angle );
	
	_v.x = x * sinhalfangle * inversenorm;
	_v.y = y * sinhalfangle * inversenorm;
	_v.z = z * sinhalfangle * inversenorm;
	_v.w = coshalfangle;
}


template <typename T>
void ofQuaternion<T>::makeRotate( T angle, const ofVec3<T>& vec ) {
	makeRotate( angle, vec.x, vec.y, vec.z );
}


template <typename T>
void ofQuaternion<T>::makeRotate ( T angle1, const ofVec3<T>& axis1,
							       T angle2, const ofVec3<T>& axis2,
							       T angle3, const ofVec3<T>& axis3 ) {
	ofQuaternion<T> q1; q1.makeRotate(angle1,axis1);
	ofQuaternion<T> q2; q2.makeRotate(angle2,axis2);
	ofQuaternion<T> q3; q3.makeRotate(angle3,axis3);
	
	*this = q1*q2*q3;
}

/** Make a rotation Quat which will rotate vec1 to vec2
 
 This routine uses only fast geometric transforms, without costly acos/sin computations.
 It's exact, fast, and with less degenerate cases than the acos/sin method.
 
 For an explanation of the math used, you may see for example:
 http://logiciels.cnes.fr/MARMOTTES/marmottes-mathematique.pdf
 
 @note This is the rotation with shortest angle, which is the one equivalent to the
 acos/sin transform method. Other rotations exists, for example to additionally keep
 a local horizontal attitude.
 
 @author Nicolas Brodu
 */
template <typename T>
void ofQuaternion<T>::makeRotate( const ofVec3<T>& from, const ofVec3<T>& to ) {
	
	// This routine takes any vector as argument but normalized
	// vectors are necessary, if only for computing the dot product.
	// Too bad the API is that generic, it leads to performance loss.
	// Even in the case the 2 vectors are not normalized but same length,
	// the sqrt could be shared, but we have no way to know beforehand
	// at this point, while the caller may know.
	// So, we have to test... in the hope of saving at least a sqrt
	ofVec3<T> sourceVector = from;
	ofVec3<T> targetVector = to;
	
	T fromLen2 = from.lengthSquared();
	T fromLen;
	// normalize only when necessary, epsilon test
	if ((fromLen2 < 1.0 - 1e-7) || (fromLen2 > 1.0 + 1e-7)) {
		fromLen = sqrt(fromLen2);
		sourceVector /= fromLen;
	} else fromLen = 1.0;
	
	T toLen2 = to.lengthSquared();
	// normalize only when necessary, epsilon test
	if ((toLen2 < 1.0 - 1e-7) || (toLen2 > 1.0 + 1e-7)) {
		T toLen;
		// re-use fromLen for case of mapping 2 vectors of the same length
		if ((toLen2 > fromLen2 - 1e-7) && (toLen2 < fromLen2 + 1e-7)) {
			toLen = fromLen;
		} else toLen = sqrt(toLen2);
		targetVector /= toLen;
	}
	
	
	// Now let's get into the real stuff
	// Use "dot product plus one" as test as it can be re-used later on
	double dotProdPlus1 = 1.0 + sourceVector.dot(targetVector);
	
	// Check for degenerate case of full u-turn. Use epsilon for detection
	if (dotProdPlus1 < 1e-7) {
		
		// Get an orthogonal vector of the given vector
		// in a plane with maximum vector coordinates.
		// Then use it as quaternion axis with pi angle
		// Trick is to realize one value at least is >0.6 for a normalized vector.
		if (fabs(sourceVector.x) < 0.6) {
			const double norm = sqrt(1.0 - sourceVector.x * sourceVector.x);
			_v.x = 0.0;
			_v.y = sourceVector.z / norm;
			_v.z = -sourceVector.y / norm;
			_v.w = 0.0;
		} else if (fabs(sourceVector.y) < 0.6) {
			const double norm = sqrt(1.0 - sourceVector.y * sourceVector.y);
			_v.x = -sourceVector.z / norm;
			_v.y = 0.0;
			_v.z = sourceVector.x / norm;
			_v.w = 0.0;
		} else {
			const double norm = sqrt(1.0 - sourceVector.z * sourceVector.z);
			_v.x = sourceVector.y / norm;
			_v.y = -sourceVector.x / norm;
			_v.z = 0.0;
			_v.w = 0.0;
		}
	}
	
	else {
		// Find the shortest angle quaternion that transforms normalized vectors
		// into one other. Formula is still valid when vectors are colinear
		const double s = sqrt(0.5 * dotProdPlus1);
		const ofVec3<T> tmp = sourceVector.getCrossed(targetVector) / (2.0 * s);
		_v.x = tmp.x;
		_v.y = tmp.y;
		_v.z = tmp.z;
		_v.w = s;
	}
}


// Make a rotation Quat which will rotate vec1 to vec2
// Generally take adot product to get the angle between these
// and then use a cross product to get the rotation axis
// Watch out for the two special cases of when the vectors
// are co-incident or opposite in direction.
template <typename T>
void ofQuaternion<T>::makeRotate_original( const ofVec3<T>& from, const ofVec3<T>& to ) {
	const T epsilon = 0.0000001f;
	
	T length1  = from.length();
	T length2  = to.length();
	
	// dot product vec1*vec2
	T cosangle = from.dot(to) / (length1 * length2);
	
	if ( fabs(cosangle - 1) < epsilon ) {
		//osg::notify(osg::INFO)<<"*** Quat::makeRotate(from,to) with near co-linear vectors, epsilon= "<<fabs(cosangle-1)<<std::endl;
		
		// cosangle is close to 1, so the vectors are close to being coincident
		// Need to generate an angle of zero with any vector we like
		// We'll choose (1,0,0)
		makeRotate( 0.0, 0.0, 0.0, 1.0 );
	} else
		if ( fabs(cosangle + 1.0) < epsilon ) {
			// vectors are close to being opposite, so will need to find a
			// vector orthongonal to from to rotate about.
			ofVec3<T> tmp;
			if (fabs(from.x) < fabs(from.y))
				if (fabs(from.x) < fabs(from.z)) tmp.set(1.0, 0.0, 0.0); // use x axis.
				else tmp.set(0.0, 0.0, 1.0);
				else if (fabs(from.y) < fabs(from.z)) tmp.set(0.0, 1.0, 0.0);
				else tmp.set(0.0, 0.0, 1.0);
			
			ofVec3<T> fromd(from.x, from.y, from.z);
			
			// find orthogonal axis.
			ofVec3<T> axis(fromd.getCrossed(tmp));
			axis.normalize();
			
			_v.x = axis[0]; // sin of half angle of PI is 1.0.
			_v.y = axis[1]; // sin of half angle of PI is 1.0.
			_v.z = axis[2]; // sin of half angle of PI is 1.0.
			_v.w = 0; // cos of half angle of PI is zero.
			
		} else {
			// This is the usual situation - take a cross-product of vec1 and vec2
			// and that is the axis around which to rotate.
			ofVec3<T> axis(from.getCrossed(to));
			T angle = acos( cosangle );
			makeRotate( angle, axis );
		}
}

template <typename T>
void ofQuaternion<T>::getRotate( T& angle, ofVec3<T>& vec ) const {
	T x, y, z;
	getRotate(angle, x, y, z);
	vec.x = x;
	vec.y = y;
	vec.z = z;
}
// Get the angle of rotation and axis of this Quat object.
// Won't give very meaningful results if the Quat is not associated
// with a rotation!
template <typename T>
void ofQuaternion<T>::getRotate( T& angle, T& x, T& y, T& z ) const {
	T sinhalfangle = sqrt( _v.x * _v.x + _v.y * _v.y + _v.z * _v.z );
	
	angle = 2.0 * atan2( sinhalfangle, _v.w );
	if (sinhalfangle) {
		x = _v.x / sinhalfangle;
		y = _v.y / sinhalfangle;
		z = _v.z / sinhalfangle;
	} else {
		x = 0.0;
		y = 0.0;
		z = 1.0;
	}
	
	angle = ofRadToDeg(angle);
}


/// Spherical Linear Interpolation
/// As t goes from 0 to 1, the Quat object goes from "from" to "to"
/// Reference: Shoemake at SIGGRAPH 89
/// See also
/// http://www.gamasutra.com/features/programming/19980703/quaternions_01.htm
template <typename T>
void ofQuaternion<T>::slerp( T t, const ofQuaternion<T>& from, const ofQuaternion<T>& to ) {
	const double epsilon = 0.00001;
	double omega, cosomega, sinomega, scale_from, scale_to ;
	
	ofQuaternion<T> quatTo(to);
	// this is a dot product
	
	cosomega = from.asVec4().dot(to.asVec4());
	
	if ( cosomega < 0.0 ) {
		cosomega = -cosomega;
		quatTo = -to;
	}
	
	if ( (1.0 - cosomega) > epsilon ) {
		omega = acos(cosomega) ; // 0 <= omega <= Pi (see man acos)
		sinomega = sin(omega) ;  // this sinomega should always be +ve so
								 // could try sinomega=sqrt(1-cosomega*cosomega) to avoid a sin()?
		scale_from = sin((1.0 - t) * omega) / sinomega ;
		scale_to = sin(t * omega) / sinomega ;
	} else {
		/* --------------------------------------------------
		 The ends of the vectors are very close
		 we can use simple linear interpolation - no need
		 to worry about the "spherical" interpolation
		 -------------------------------------------------- */
		scale_from = 1.0 - t ;
		scale_to = t ;
	}
	
	*this = (from * scale_from) + (quatTo * scale_to);
	
	// so that we get a Vec4
}


// ref at http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/index.htm
template <typename T>
ofVec3<T> ofQuaternion<T>::getEuler() const {
	T test = x()*y() + z()*w();
	T heading;
	T attitude;
	T bank;
	if (test > 0.499) { // singularity at north pole
		heading = 2 * atan2(x(), w());
		attitude = PI/2;
		bank = 0;
	} else if (test < -0.499) { // singularity at south pole
		heading = -2 * atan2(x(), w());
		attitude = - PI/2;
		bank = 0;
	} else {
		T sqx = x() * x();
		T sqy = y() * y();
		T sqz = z() * z();
		heading = atan2(2.0f * y() * w() - 2.0f * x() * z(), 1.0f - 2.0f*sqy - 2.0f*sqz);
		attitude = asin(2*test);
		bank = atan2(2.0f*x() * w() - 2.0f * y() * z(), 1.0f - 2.0f*sqx - 2.0f*sqz);
	}
	
	return ofVec3<T>(ofRadToDeg(attitude), ofRadToDeg(heading), ofRadToDeg(bank));
}

#define QX  _v.x
#define QY  _v.y
#define QZ  _v.z
#define QW  _v.w

}
