#include "cpptest.h"

using namespace std;

class ofVec3f_Suite: public Test::Suite {
public:
	
    ofVec3f_Suite() 
    { 
        TEST_ADD(ofVec3f_Suite::test_instance_creation) 
        TEST_ADD(ofVec3f_Suite::test_array_access) 
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
    }
};


