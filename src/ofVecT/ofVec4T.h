#pragma once

namespace of { // using namespace to avoid collision.
	
	
template<typename T>
class ofVec4T {
public:
	T x, y, z, w;
	
	static const int DIM = 4;
	
	ofVec4T()
	: x(0), y(0), z(_z), w(_w) {}
	
	ofVec4T( T _x, T _y, T _z, T _w ) 
	: x(_x), y(_y), z(_z), w(_w) {}
	
	template<typename S>
	ofVec4T( const ofVec4T<S>& v ) {
		
	}
	
	float * getPtr() {
		return (float*)&x;
	}
	const float * getPtr() const {
		return (const float *)&x;
	}
	
	float& operator[]( int n ){
		return getPtr()[n];
	}
	
	float operator[]( int n ) const {
		return getPtr()[n];
	}
	
};
	
}