#pragma once

#include "cpptest.h"
#include "ofVec.h"

using namespace std;

class ofVecT_Suite : public Test::Suite {
public:
	
    ofVecT_Suite() { 
        TEST_ADD( ofVecT_Suite::test_instance_creation_2d )
		TEST_ADD( ofVecT_Suite::test_instance_creation_3d )
		TEST_ADD( ofVecT_Suite::test_instance_creation_4d )
		TEST_ADD( ofVecT_Suite::test_equality )
		TEST_ADD( ofVecT_Suite::test_assignments )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_instance_creation_2d() {
		
		of::ofVec2f v2f( 10.0f, 10.0f );
		TEST_ASSERT( v2f.x == 10.0f )
		TEST_ASSERT( v2f.y == 10.0f )

        of::ofVec2f nv2f;
		nv2f.set( v2f );
		TEST_ASSERT( nv2f.x == 10.0f )
		TEST_ASSERT( nv2f.y == 10.0f )
		
		of::ofVec2<int> v2i( 10, 40 );
		TEST_ASSERT( v2i.x == 10 )
		TEST_ASSERT( v2i.y == 40 )
	}
	
	void test_instance_creation_3d() {
		
		of::ofVec3f v3f( 10.0f, 10.0f, 50.0f );
		TEST_ASSERT( v3f.x == 10.0f )
		TEST_ASSERT( v3f.y == 10.0f )
		TEST_ASSERT( v3f.z == 50.0f )
		
		of::ofVec3d v3d( 20.0, 20.0, 50.0 );
		TEST_ASSERT( v3d.x == 20.0 )
		TEST_ASSERT( v3d.y == 20.0 )
		TEST_ASSERT( v3d.z == 50.0 )

		of::ofVec3<int> v3i(10,40, 50);
		TEST_ASSERT( v3i.x == 10 )
		TEST_ASSERT( v3i.y == 40 )
		TEST_ASSERT( v3i.z == 50 )
	}
	
	void test_instance_creation_4d() {
			
		of::ofVec4d v4d( 20.0, 20.0, 50.0, 30.0 );
		TEST_ASSERT( v4d.x == 20.0 )
		TEST_ASSERT( v4d.y == 20.0 )
		TEST_ASSERT( v4d.z == 50.0 )
		TEST_ASSERT( v4d.w == 30.0 )
		
		of::ofVec4<int> v4i( 10, 40, 50, 22 );
		TEST_ASSERT( v4i.x == 10 )
		TEST_ASSERT( v4i.y == 40 )
		TEST_ASSERT( v4i.z == 50 )
		TEST_ASSERT( v4i.w == 22 )
	}
	
	void test_array_access() {
		of::ofVec2<float> v2f( 23, 42 );
		TEST_ASSERT( v2f[ 0 ] == 23 )
        TEST_ASSERT( v2f[ 1 ] == 42 )
		
		of::ofVec4d v4d( 20.0, 20.0, 50.0, 30.0 );
		TEST_ASSERT( v4d[ 0 ] == 20.0f )
		TEST_ASSERT( v4d[ 1 ] == 20.0f )
		TEST_ASSERT( v4d[ 2 ] == 50.0f )
		TEST_ASSERT( v4d[ 3 ] == 30.0f )
	}

	void test_equality() {
		of::ofVecT<int> v1i( 50 );
        TEST_ASSERT( v1i == of::ofVecT<int>( 50 ) ) 
		
        of::ofVec2f v2f( 12.0, 10.0 );
		of::ofVec2f v2f2( 12.0f, 10.0f );
		TEST_ASSERT( v2f.x == 12.0f )
		TEST_ASSERT( v2f.y == 10.0f )
        TEST_ASSERT( v2f == v2f2 )
		
		of::ofVec2<int> v2i( 12, 10 );
		TEST_ASSERT( v2f == v2i )
		
		v2i.set(40, 20);
		TEST_ASSERT( v2f != v2i )
    }
    
    void test_assignments() {
        of::ofVec2f v2f( 2, 2 );
        of::ofVec3f v3f( v2f );
		TEST_ASSERT( v3f.x == 2.0f )
		TEST_ASSERT( v3f.y == 2.0f )

		// probably this is not precise. double -> float
        of::ofVec2d v2d( 3, 3 );
        of::ofVec3f v3ff( v2d );
		TEST_ASSERT( v3ff.x == 3.0 )
		TEST_ASSERT( v3ff.y == 3.0 )
    }
};