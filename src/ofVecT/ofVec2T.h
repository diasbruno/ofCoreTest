#pragma once

namespace of { // using namespace to avoid collision.
	
	
template<typename T>
class ofVec2T {
public:
	T x, y;
	
	static const int DIM = 2;
	
	ofVec2T()
	: x(0), y(0) {}
	
	ofVec2T( T _x, T _y )
	: x(_x), y(_y) {}
	
	template<typename S>
	ofVec2T( const ofVec2T<S>& v ) {
		
	}
	
};

}