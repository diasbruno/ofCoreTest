#include "cpptest.h"

using namespace std;

class ofVec3f_Suite : public Test::Suite {
public:
	
    ofVec3f_Suite() 
    { 
        TEST_ADD( ofVec3f_Suite::test_instance_creation     )
        TEST_ADD( ofVec3f_Suite::test_array_access          )
		TEST_ADD( ofVec3f_Suite::test_pointer_access        )
		TEST_ADD( ofVec3f_Suite::test_set_axis_vec3f_scalar )
		TEST_ADD( ofVec3f_Suite::test_equality              )
		TEST_ADD( ofVec3f_Suite::test_math_operations       )
    }
    
    ofVec3f tVec3f;
	
protected:
	
    virtual void setup()     {}
    virtual void tear_down() {}
	
private:
	
    void test_instance_creation() {
        TEST_ASSERT( tVec3f.x == 0 )
        TEST_ASSERT( tVec3f.y == 0 )
        TEST_ASSERT( tVec3f.z == 0 )
    }
	
    void test_array_access() {
        TEST_ASSERT( tVec3f[0] == 0 )
        TEST_ASSERT( tVec3f[1] == 0 )
        TEST_ASSERT( tVec3f[2] == 0 )
		// since vec3f has size of 3
		// this needs review?
		// TEST_ASSERT( tVec3f[3] == 0 )
    }
	
	void test_pointer_access() {
		tVec3f.x = 10;
		tVec3f.y = 12;
		tVec3f.z = 15;
		
		// needs to be managed manually.
		float *p = tVec3f.getPtr();
        TEST_ASSERT( *(p+0) == 10 )
        TEST_ASSERT( *(p+1) == 12 )
        TEST_ASSERT( *(p+2) == 15 )
    }
	
	void test_set_axis_vec3f_scalar() {
		// axis
		tVec3f.set( 20, 30, 40 );
		
        TEST_ASSERT( tVec3f.x == 20 )
        TEST_ASSERT( tVec3f.y == 30 )
        TEST_ASSERT( tVec3f.z == 40 )
		
		// vec3f
		tVec3f.set( ofVec3f( 40, 50, 60 ) );
		
		TEST_ASSERT( tVec3f.x == 40 )
        TEST_ASSERT( tVec3f.y == 50 )
        TEST_ASSERT( tVec3f.z == 60 )
		
		// scalar
		tVec3f.set( 10 );
		
		TEST_ASSERT( tVec3f.x == 10 )
        TEST_ASSERT( tVec3f.y == 10 )
        TEST_ASSERT( tVec3f.z == 10 )
    }
	
	void test_equality() {
		tVec3f.set( 20, 30, 40 );
		
        TEST_ASSERT( tVec3f == ofVec3f( 20, 30, 40 ) )
		TEST_ASSERT( tVec3f != ofVec3f( 20, 30, 50 ) )
    }
	
	void test_math_operations() {
		tVec3f.set( 20, 30, 40 );
		
		// operations between 2 vecs 
		// results in a new vec.
		
		TEST_ASSERT( tVec3f + ofVec3f( 40, 30, 400 ) == ofVec3f( 60, 60, 440 ) )
		
		tVec3f += ofVec3f( 40, 30, 400 );
		TEST_ASSERT( tVec3f == ofVec3f( 60, 60, 440 ) )
		
		
		TEST_ASSERT( tVec3f - ofVec3f( 20, 10, 600 ) == ofVec3f( 40, 50, -160 ) )
		
		tVec3f -= ofVec3f( 20, 10, 600 );
		TEST_ASSERT( tVec3f == ofVec3f( 40, 50, -160 ) )
		
		
		TEST_ASSERT( tVec3f * ofVec3f( 20, 10, -6 ) == ofVec3f( 8000, 500, -960 ) )
		
		tVec3f *= ofVec3f( 8000, 500, -960 );
		TEST_ASSERT( tVec3f == ofVec3f( 8000, 900, -2580 ) )
		
		
		TEST_ASSERT( tVec3f / ofVec3f( 20, 10, -5 ) == ofVec3f( -10, -9, -43 ) )
		
		tVec3f /= ofVec3f( 20, 10, -5 );
		TEST_ASSERT( tVec3f == ofVec3f( -10, -9, -43 ) )		
    }
};


