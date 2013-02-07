#pragma once

#include "cpptest.h"
#include "_ofMatrix3x3.h"

using namespace std;

class ofMatrix3x3_test : public Test::Suite {
public:
	
    ofMatrix3x3_test() { 
        TEST_ADD( ofMatrix3x3_test::test_creation )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_creation() {
		of::ofMatrix3x3<float> m(  
			1,  2,  3,  
			4,  5,  6,  
			7,  8,  9  
		);
		
		int c = 1;
		for ( int i = 1; i < 10; i++ ) {
			TEST_ASSERT( m[ i - 1 ] == c );
			c++;
		}
	}
};