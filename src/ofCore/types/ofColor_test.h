
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
	
    virtual void setup()     {}
    virtual void tear_down() {}
	
private:
	
    void test_instance_creation() {
        TEST_ASSERT( tColor.r == 1 )
		TEST_ASSERT( tColor.b == 1 )
		TEST_ASSERT( tColor.r == 1 )
	}
	
	void test_instance_creation() {
		// should initialize with 
		// a default value?
        TEST_ASSERT( tColor.r == 1 )
		TEST_ASSERT( tColor.b == 1 )
		TEST_ASSERT( tColor.r == 1 )
	}
	
};