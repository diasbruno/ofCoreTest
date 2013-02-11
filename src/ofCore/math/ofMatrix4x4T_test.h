#pragma once

#include "cpptest.h"
#include "_ofMatrix4x4.h"

class ofMatrix4x4_test 
	: public Test::Suite {
public:
	
    ofMatrix4x4_test() { 
		
        TEST_ADD( ofMatrix4x4_test::test_instantiation1 )
		TEST_ADD( ofMatrix4x4_test::test_instantiation2 )
	}
	
protected:
	
    void     setup() {
		identity.set(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}
    void tear_down() {}
	
private:
	
	_ofMatrix4x4<float> identity;
		
	/*! Instantiation without arguments.
	    Create identity matrix. */
    void test_instantiation1() {
		
		_ofMatrix4x4<float> test;
		
		int c = 1;
		
		for ( int i = 1; i < 5; i++ ) {
			for ( int j = 1; j < 5; j++ ) {
				
				TEST_ASSERT( test( i - 1, j - 1 ) == identity( i - 1, j - 1 ) );
				c++;
			}
		}
	}
		
	/*! Instantiation with arguments. */
	void test_instantiation2() {
		
		_ofMatrix4x4<float> test(
			 1,  2,  3,  4, 
			 5,  6,  7,  8, 
			 9, 10, 11, 12,
			13, 14, 15, 16  
		);
		
		int c = 1;
		
		for ( int i = 1; i < 5; i++ ) {
			for ( int j = 1; j < 5; j++ ) {
				
				TEST_ASSERT( test( i - 1, j - 1 ) == c );
				c++;
			}
		}
	}
	
};