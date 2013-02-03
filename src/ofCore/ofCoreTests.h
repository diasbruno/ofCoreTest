#pragma once

// Types
//#include "ofVec3f_test.h"
//#include "ofColor_test.h"
// Graphics
//#include "ofPixels_test.h"
//#include "ofImage_test.h"
// Utils
//#include "ofSystemUtils_test.h"
//#include "ofUtils_test.h"


#include "ofVecT_test.h"
#include "ofVecT_Operations_test.h"

// uncomment this line to export 
// the results as html.
//#define CPPTEST_OUTPUT

static Test::Suite ts_types;

/*! */
void run_tests_for_ofVecT() {
    ts_types.add( auto_ptr<Test::Suite>( new ofVecT_Suite ) );
    ts_types.add( auto_ptr<Test::Suite>( new ofVecT_Operations_Suite ) );
}

void run_tests() {
	// comment tests you don't want to run.
	run_tests_for_ofVecT();
    
#ifdef CPPTEST_OUTPUT
    Test::HtmlOutput output;
	output.generate( std::cout, true, "HTML Tests" );
#else
    Test::TextOutput output( Test::TextOutput::Verbose );
#endif
	
    ts_types.run( output );
}