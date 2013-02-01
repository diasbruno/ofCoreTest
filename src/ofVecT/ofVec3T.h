#pragma once

namespace of { // using namespace to avoid collision.
	
	
template<typename T>
class ofVec3T {
public:
	T x, y, z;
	
	static const int DIM = 3;
	
	ofVec3T()
	: x(0), y(0), z(0) {}
	
	ofVec3T( T _x, T _y, T _z )
	: x(_x), y(_y), z(_z) {}
	
	template<typename S>
	ofVec3T( const ofVec3T<S>& v ) {
		
	}
	
};
	
}