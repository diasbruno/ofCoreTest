#pragma once

#include "cpptest.h"
#include "_ofVec.h"

using namespace std;

class ofVecT_Suite : public Test::Suite {
public:
	
    ofVecT_Suite() { 
        TEST_ADD( ofVecT_Suite::test_instance_creation )
		TEST_ADD( ofVecT_Suite::test_array_access )
		TEST_ADD( ofVecT_Suite::test_equality )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
	void test_instance_creation() {
		ofVecT<float> v1f;
		TEST_ASSERT( v1f.x == 0 )
		
		ofVecT<float> v1f_( 10.f );
		TEST_ASSERT( v1f_.x == 10.f )
	}
	
	void test_array_access() {
		ofVecT<float> v1f( 23 );
		TEST_ASSERT( v1f[ 0 ] == 23 )
	}

	void test_equality() {		
        ofVec2f v2f( 12.0, 10.0 );
		ofVec2f v2f2( 12.0f, 10.0f );
		TEST_ASSERT( v2f.x == 12.0f )
		TEST_ASSERT( v2f.y == 10.0f )
        TEST_ASSERT( v2f == v2f2 )
    }
};