#pragma once

#include "cpptest.h"

using namespace std;

/*!
 
 Abstract class: 
	ofPixels_<PixelType>
 
 Extended classes:
	ofPixels      ( ofPixels_<unsigned char>  )
	ofFloatPixels ( ofPixels_<float>          )
	ofShortPixels ( ofPixels_<unsigned short> )
 
 */

class ofPixels_Suite : public Test::Suite {
public:
	
    ofPixels_Suite() 
    { 
        TEST_ADD( ofPixels_Suite::test_instance_creation     )
    }
    
    ofPixels tpixels;
	ofFloatPixels tpixels_f;
	ofShortPixels tpixels_s;
	
protected:
	
    virtual void setup()     {}
    virtual void tear_down() {
		tpixels.clear();
		tpixels_f.clear();
		tpixels_s.clear();
	}
	
private:
	
    void test_instance_creation() {
		
		// ofPixels
		
		TEST_ASSERT( tpixels.isAllocated() == false )
		TEST_ASSERT( tpixels.getPixels() == NULL )
		
		TEST_ASSERT( tpixels.getImageType() == OF_IMAGE_UNDEFINED ) 
		TEST_ASSERT( tpixels.getWidth() == 0 )
		TEST_ASSERT( tpixels.getHeight() == 0 )
		
		// ofFloatPixels
		
		TEST_ASSERT( tpixels_f.isAllocated() == false )
		TEST_ASSERT( tpixels_f.getPixels() == NULL )
		
		TEST_ASSERT( tpixels_f.getImageType() == OF_IMAGE_UNDEFINED ) 
		TEST_ASSERT( tpixels_f.getWidth() == 0 )
		TEST_ASSERT( tpixels_f.getHeight() == 0 )
		
		// ofShortPixels
		
		TEST_ASSERT( tpixels_s.isAllocated() == false )
		TEST_ASSERT( tpixels_s.getPixels() == NULL )
		
		TEST_ASSERT( tpixels_s.getImageType() == OF_IMAGE_UNDEFINED ) 
		TEST_ASSERT( tpixels_s.getWidth() == 0 )
		TEST_ASSERT( tpixels_s.getHeight() == 0 )
	}
};

class ofPixels_Scenarion : public Test::Suite {
public:
	
    ofPixels_Scenarion() 
    { 
        TEST_ADD( ofPixels_Scenarion::test_instance_creation     )
    }
    
    ofPixels tpixels;
	ofFloatPixels tpixels_f;
	ofShortPixels tpixels_s;
	
protected:
	
    virtual void setup()     {}
    virtual void tear_down() {
		tpixels.clear();
	}
	
private:
	
    void test_instance_creation() {
		
	}
};