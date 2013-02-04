#pragma once

#include "cpptest.h"
#include "ofVec.h"

using namespace std;

class ofVecT_Operations_Suite : public Test::Suite {
public:
	
    ofVecT_Operations_Suite() { 
		TEST_ADD( ofVecT_Operations_Suite::test_operations_2d )
		TEST_ADD( ofVecT_Operations_Suite::test_operations_3d )
		TEST_ADD( ofVecT_Operations_Suite::test_operations_4d )
		TEST_ADD( ofVecT_Operations_Suite::test_operation_with_different_types )
	}
	
protected:
	
	of::ofVec2<float> v2f;
	of::ofVec3<float> v3f;
	of::ofVec4<float> v4f;
	
    void     setup() {}
    void tear_down() {}
	
private:

    void test_operations_2d() {
        
        v2f.set( 10, 10 );
		TEST_ASSERT( v2f.x == 10 )
        TEST_ASSERT( v2f.y == 10 )

        v2f += 10;
		TEST_ASSERT( v2f.x == 20 )
        TEST_ASSERT( v2f.y == 20 )
    
        v2f -= 10;
		TEST_ASSERT( v2f.x == 10 )
        TEST_ASSERT( v2f.y == 10 )

        v2f *= 10;
		TEST_ASSERT( v2f.x == 100 )
        TEST_ASSERT( v2f.y == 100 )

        v2f /= 10;
		TEST_ASSERT( v2f.x == 10 )
        TEST_ASSERT( v2f.y == 10 )
	}
	
	void test_operations_3d() {
        
        v3f.set( 10, 10, 10 );
		TEST_ASSERT( v3f.x == 10 )
        TEST_ASSERT( v3f.y == 10 )
		TEST_ASSERT( v3f.y == 10 )
		
        v3f += 10;
		TEST_ASSERT( v3f.x == 20 )
        TEST_ASSERT( v3f.y == 20 )
		TEST_ASSERT( v3f.z == 20 )
		
        v3f -= 10;
		TEST_ASSERT( v3f.x == 10 )
        TEST_ASSERT( v3f.y == 10 )
		TEST_ASSERT( v3f.z == 10 )
		
        v3f *= 10;
		TEST_ASSERT( v3f.x == 100 )
        TEST_ASSERT( v3f.y == 100 )
		TEST_ASSERT( v3f.z == 100 )
		
        v3f /= 10;
		TEST_ASSERT( v3f.x == 10 )
        TEST_ASSERT( v3f.y == 10 )
		TEST_ASSERT( v3f.z == 10 )
	}
	
	void test_operations_4d() {
        
        v4f.set( 10, 10, 10, 10 );
		TEST_ASSERT( v4f.x == 10 )
        TEST_ASSERT( v4f.y == 10 )
		TEST_ASSERT( v4f.y == 10 )
		
        v4f += 10;
		TEST_ASSERT( v4f.x == 20 )
        TEST_ASSERT( v4f.y == 20 )
		TEST_ASSERT( v4f.z == 20 )
		
        v4f -= 10;
		TEST_ASSERT( v4f.x == 10 )
        TEST_ASSERT( v4f.y == 10 )
		TEST_ASSERT( v4f.z == 10 )
		
        v4f *= 10;
		TEST_ASSERT( v4f.x == 100 )
        TEST_ASSERT( v4f.y == 100 )
		TEST_ASSERT( v4f.z == 100 )
		
        v4f /= 10;
		TEST_ASSERT( v4f.x == 10 )
        TEST_ASSERT( v4f.y == 10 )
		TEST_ASSERT( v4f.z == 10 )
	}
	
	void test_operation_with_different_types() {
		
		of::ofVec2<int> v2i(30, 40);
		v2f += v2i;
		TEST_ASSERT( v2f.x == 40 )
        TEST_ASSERT( v2f.y == 50 )
		
		v2f += (int)40;
		TEST_ASSERT( v2f.x == 80 )
        TEST_ASSERT( v2f.y == 90 )
    }

};
