
#include "ofVec3.h"

namespace of {

/*! Checks if vectors look in the same direction. */
template<typename T>
inline 
bool ofVec3<T>::isAligned( const ofVec3<T>& vec, float tolerance ) const {
	float angle = this->angle( vec );
	return  angle < tolerance;
}

/*! */
template<typename T>
inline 
bool ofVec3<T>::align( const ofVec3<T>& vec, float tolerance ) const {
    return isAligned( vec, tolerance );
}

/*! */
template<typename T>
inline 
bool ofVec3<T>::isAlignedRad( const ofVec3<T>& vec, float tolerance ) const {
	float angle = this->angleRad( vec );
	return angle < tolerance;
}

/*! */
template<typename T>
inline 
bool ofVec3<T>::alignRad( const ofVec3<T>& vec, float tolerance ) const {
    return isAlignedRad( vec, tolerance );
}

}