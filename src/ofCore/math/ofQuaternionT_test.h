#pragma once

#include "cpptest.h"
#include "_ofQuaternion.h"

class ofQuaternion_test 
	: public Test::Suite {
public:
	
    ofQuaternion_test() { 
		
        TEST_ADD( ofQuaternion_test::test_instantiation1 )
		TEST_ADD( ofQuaternion_test::test_instantiation2 )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_instantiation1() {
		
		_ofQuaternionf q( 1, 2, 3, 4 );
		
		TEST_ASSERT( q.x() == 1);
		TEST_ASSERT( q.y() == 2);
		TEST_ASSERT( q.z() == 3);
		TEST_ASSERT( q.w() == 4);
	}
	
	/*! Instante with a vector 4. */
	void test_instantiation2() {
		
		_ofVec4<float> v4f( 1.0, 2.0, 3.0, 4.0 );
		_ofQuaternionf q( v4f );
		
		TEST_ASSERT( q.x() == 1);
		TEST_ASSERT( q.y() == 2);
		TEST_ASSERT( q.z() == 3);
		TEST_ASSERT( q.w() == 4);
	}
		
};