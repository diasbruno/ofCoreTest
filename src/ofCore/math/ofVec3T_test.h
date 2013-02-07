#pragma once

#include "cpptest.h"
#include "_ofVec.h"

class ofVec3T_Suite : public Test::Suite {
public:
	
    ofVec3T_Suite() 
    { 
        TEST_ADD( ofVec3T_Suite::test_creation )
        TEST_ADD( ofVec3T_Suite::test_array_access )
		TEST_ADD( ofVec3T_Suite::test_pointer_access )
		TEST_ADD( ofVec3T_Suite::test_sets_equality )
		TEST_ADD( ofVec3T_Suite::test_operations )
    }
    
	of::ofVec3<int>    v3i;
    of::ofVec3<float>  v3f;
	of::ofVec3<double> v3d;
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_creation() {
        TEST_ASSERT( v3f.x == 0 )
        TEST_ASSERT( v3f.y == 0 )
        TEST_ASSERT( v3f.z == 0 )
    }
	
    void test_array_access() {
        TEST_ASSERT( v3f[0] == 0 )
        TEST_ASSERT( v3f[1] == 0 )
        TEST_ASSERT( v3f[2] == 0 )
		// since vec3f has size of 3
		// this needs review?
		// TEST_ASSERT( v3f[3] == 0 )
    }
	
	void test_pointer_access() {
		v3f.x = 10;
		v3f.y = 12;
		v3f.z = 15;
		
		// needs to be managed manually.
		float *p = v3f.getPtr();
        TEST_ASSERT( *(p+0) == 10 )
        TEST_ASSERT( *(p+1) == 12 )
        TEST_ASSERT( *(p+2) == 15 )
    }
	
	void test_sets_equality() {
		// axis
		v3i.set( 20, 30, 40 );
        TEST_ASSERT( v3i == of::ofVec3<int>( 20, 30, 40 ) )
		TEST_ASSERT( v3i != of::ofVec3<int>( 20, 30, 50 ) )
		
		// vec3f
		v3f.set( of::ofVec3f( 20, 30, 40 ) );
		TEST_ASSERT( v3f == of::ofVec3f( 20, 30, 40 ) )
		TEST_ASSERT( v3f != of::ofVec3f( 20, 30, 50 ) )
		
		// scalar
		v3d.set( 10 );
		TEST_ASSERT( v3d == of::ofVec3d( 10, 10, 10 ) )
		TEST_ASSERT( v3d != of::ofVec3d( 20, 30, 50 ) )
    }
	
	void test_operations() {
		v3i.set( 20, 30, 40 );
		
		v3i += of::ofVec3i( 40, 30, 20 );
		TEST_ASSERT( v3i == of::ofVec3i( 60, 60, 60 ) )
		TEST_ASSERT( v3i +  of::ofVec3i( 40, 30, 10 ) == of::ofVec3i( 100, 90, 70 ) )
		
		v3i -= of::ofVec3i( 20, 30, 120 );
		TEST_ASSERT( v3i == of::ofVec3i( 40, 30, -60 ) )
		TEST_ASSERT( v3i -  of::ofVec3i( 20, 10, 50 ) == of::ofVec3i( 20, 20, -110 ) )
		
		v3i *= of::ofVec3i( 2, 5, -4 );
		TEST_ASSERT( v3i == of::ofVec3i( 80, 150, 240 ) )
		TEST_ASSERT( v3i *  of::ofVec3i( 20,  10,  -2 ) == of::ofVec3i( 1600, 1500, -480 ) )
		
		v3i /= of::ofVec3i( 4, 5, 6 );
		TEST_ASSERT( v3i == of::ofVec3i( 20,  30, 40 ) )
		TEST_ASSERT( v3i /  of::ofVec3i(  2, -10, -5 ) == of::ofVec3i( 10, -3, -8 ) )
		
		v3i = -v3i; 
		TEST_ASSERT( v3i == of::ofVec3i( -20, -30, -40 ) );
		
		v3f.set( 20, 30, 40 );
		
		v3f += of::ofVec3f( 40, 30, 20 );
		TEST_ASSERT( v3f == of::ofVec3f( 60, 60, 60 ) )
		TEST_ASSERT( v3f +  of::ofVec3f( 40, 30, 10 ) == of::ofVec3f( 100, 90, 70 ) )
		
		v3f -= of::ofVec3f( 20, 30, 120 );
		TEST_ASSERT( v3f == of::ofVec3f( 40, 30, -60 ) )
		TEST_ASSERT( v3f -  of::ofVec3f( 20, 10, 50 ) == of::ofVec3f( 20, 20, -110 ) )
		
		v3f *= of::ofVec3f( 2, 5, -4 );
		TEST_ASSERT( v3f == of::ofVec3f( 80, 150, 240 ) )
		TEST_ASSERT( v3f *  of::ofVec3f( 20,  10,  -2 ) == of::ofVec3f( 1600, 1500, -480 ) )
		
		v3f /= of::ofVec3f( 4, 5, 6 );
		TEST_ASSERT( v3f == of::ofVec3f( 20,  30, 40 ) )
		TEST_ASSERT( v3f /  of::ofVec3f(  2, -10, -5 ) == of::ofVec3f( 10, -3, -8 ) )
		
		v3f = -v3f; 
		TEST_ASSERT( v3f == of::ofVec3f( -20, -30, -40 ) );
    }
};


