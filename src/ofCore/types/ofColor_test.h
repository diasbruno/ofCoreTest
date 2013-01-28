#pragma once

#include "cpptest.h"

#include <limits>
#include "ofMath.h"
#include "ofColor.h"

using namespace std;

class ofColor_Suite : public Test::Suite {
public:
	
    ofColor_Suite() 
    { 
        TEST_ADD( ofColor_Suite::test_instance_creation     )
    }
    
    ofColor tColor;
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_instance_creation() {
        TEST_ASSERT( tColor.r == 255.0 )
		TEST_ASSERT( tColor.g == 255.0 )
		TEST_ASSERT( tColor.b == 255.0 )
		TEST_ASSERT( tColor.a == 255.0 )
		
		// ofColor.set( <#ofColor_ *color#> );
		tColor.set( ofColor_<float>::blue );
		
        TEST_ASSERT( tColor.r == 0.0 )
		TEST_ASSERT( tColor.g == 0.0 )
		TEST_ASSERT( tColor.b == 255.0 )
		TEST_ASSERT( tColor.a == 255.0 )
	}
	
};