#pragma once

#include "cpptest.h"
#include "_ofMatrix4x4T.h"

class ofMatrix4x4_test : public Test::Suite {
public:
	
    ofMatrix4x4_test() { 
        TEST_ADD( ofMatrix4x4_test::test_creation )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_creation() {
		of::ofMatrix4x4 m(  1,  2,  3,  4, 
					    5,  6,  7,  8, 
					    9, 10, 11, 12,
					   13, 14, 15, 16  );
		int c = 1;
		for ( int i = 1; i < 5; i++ ) {
			for ( int j = 1; j < 5; j++ ) {
				TEST_ASSERT( m( i - 1, j - 1 ) == c );
				c++;
			}
		}
		
//		ofVec4<float> v4f( 1.0, 2.0, 3.0, 4.0 );
//		ofMatrix4x4 m( v4f );
//		TEST_ASSERT( q.x() == 1);
//		TEST_ASSERT( q.y() == 2);
//		TEST_ASSERT( q.z() == 3);
//		TEST_ASSERT( q.w() == 4);
	}
};