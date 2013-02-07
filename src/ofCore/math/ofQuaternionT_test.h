#pragma once

#include "cpptest.h"

using namespace std;

class ofQuaternion_test : public Test::Suite {
public:
	
    ofQuaternion_test() { 
        TEST_ADD( ofQuaternion_test::test_instance_creation )
		TEST_ADD( ofQuaternion_test::test_instance_creation_vec4 )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_instance_creation() {
		ofQuaternion q( 1, 2, 3, 4 );
		TEST_ASSERT( q.x() == 1);
		TEST_ASSERT( q.y() == 2);
		TEST_ASSERT( q.z() == 3);
		TEST_ASSERT( q.w() == 4);
	}
	
	void test_instance_creation_vec4() {
		ofVec4<float> v4f( 1.0, 2.0, 3.0, 4.0 );
		ofQuaternion q( v4f );
		TEST_ASSERT( q.x() == 1);
		TEST_ASSERT( q.y() == 2);
		TEST_ASSERT( q.z() == 3);
		TEST_ASSERT( q.w() == 4);
	}
};