#pragma once

#include "cpptest.h"
#include "ofImage.h"

using namespace std;

class ofImage_Suite : public Test::Suite {
public:
	
    ofImage_Suite() 
    { 
        TEST_ADD( ofImage_Suite::test_instantiation     )
//		ofPixels pixels = tImage.getPixels();
//		if ( pixels.isAllocated() ) {
//			TEST_ADD( ofImage_Suite::test_initialized_pixels    )
//		}
    }
    
    ofImage tImage;
	
protected:
	
    void setup()     {}
    void tear_down() {}
	
private:
	
    void test_instantiation() {
		TEST_ASSERT( tImage.width == 0 )
		TEST_ASSERT( tImage.height == 0 )
		TEST_ASSERT( tImage.bpp == 0 )
		TEST_ASSERT( tImage.type == OF_IMAGE_UNDEFINED )
		TEST_ASSERT( tImage.isUsingTexture() == true )
	}
	
	void test_initialized_pixels() {
		// the default initialization of ofImage
		// don't allocate any pixels on the initialization.
		// this should be the correct behavior?
//		TEST_ASSERT( tImage.getPixels().isAllocated() == false )
//		TEST_ASSERT( tImage.getPixels().getWidth() == 0 )
//		TEST_ASSERT( tImage.getPixels().getHeight() == 0 )
	}
};