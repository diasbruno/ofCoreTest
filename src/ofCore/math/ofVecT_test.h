#pragma once

#include "cpptest.h"
#include "ofVecT.h"

using namespace std;

class ofVecT_Suite : public Test::Suite {
public:
	
    ofVecT_Suite() { 
        TEST_ADD( ofVecT_Suite::test_instance_creation_2d )
		TEST_ADD( ofVecT_Suite::test_instance_creation_3d )
		TEST_ADD( ofVecT_Suite::test_instance_creation_4d )
	}
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
    void test_instance_creation_2d() {
		
		of::ofVec2f vec2f( 10.0f, 10.0f );
		of::ofVec2d vec2d( 20.0, 20.0 );
		
		TEST_ASSERT( vec2f.x == 10.0f )
		TEST_ASSERT( vec2f.y == 10.0f )
		
		TEST_ASSERT( vec2d.x == 20.0 )
		TEST_ASSERT( vec2d.y == 20.0 )
	}
	
	void test_instance_creation_3d() {
		
		of::ofVec3f vec3f( 10.0f, 10.0f, 50.0f );
		of::ofVec3d vec3d( 20.0, 20.0, 50.0 );
		
		TEST_ASSERT( vec3f.x == 10.0f )
		TEST_ASSERT( vec3f.y == 10.0f )
		TEST_ASSERT( vec3f.z == 50.0f )
		
		TEST_ASSERT( vec3d.x == 20.0 )
		TEST_ASSERT( vec3d.y == 20.0 )
		TEST_ASSERT( vec3d.z == 50.0 )
	}
	
	void test_instance_creation_4d() {
		
		of::ofVec4f vec4f( 10.0f, 10.0f, 50.0f, 80.0f );
		of::ofVec4d vec4d( 20.0, 20.0, 50.0, 30.0 );
		
		TEST_ASSERT( vec4f.x == 10.0f )
		TEST_ASSERT( vec4f.y == 10.0f )
		TEST_ASSERT( vec4f.z == 50.0f )
		TEST_ASSERT( vec4f.w == 80.0f )
		
		TEST_ASSERT( vec4d.x == 20.0 )
		TEST_ASSERT( vec4d.y == 20.0 )
		TEST_ASSERT( vec4d.z == 50.0 )
		TEST_ASSERT( vec4d.w == 30.0 )
	}
	
};