#pragma once

#include "cpptest.h"

#include <limits>
#include "ofMath.h"
#include "ofColor.h"

using namespace std;

class ofColor_Suite 
	: public Test::Suite {
public:
	
    ofColor_Suite() {
        TEST_ADD( ofColor_Suite::test_instantiation )
    }
    
    ofColor tColor;
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_instantiation() {
        TEST_ASSERT( tColor.r == 255.0 )
		TEST_ASSERT( tColor.g == 255.0 )
		TEST_ASSERT( tColor.b == 255.0 )
		TEST_ASSERT( tColor.a == 255.0 )
		
		tColor.set( ofColor_<float>::blue );
		
        TEST_ASSERT( tColor.r == 0.0 )
		TEST_ASSERT( tColor.g == 0.0 )
		TEST_ASSERT( tColor.b == 255.0 )
		TEST_ASSERT( tColor.a == 255.0 )
	}
	
};