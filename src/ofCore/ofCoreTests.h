#pragma once

// Types
#include "ofColor_test.h"
// Graphics
#include "ofPixels_test.h"
#include "ofImage_test.h"
// Utils
#include "ofSystemUtils_test.h"
#include "ofUtils_test.h"


#include "ofVecT_test.h"
#include "ofVec2T_test.h"
#include "ofVec3T_test.h"
#include "ofVec4T_test.h"

#include "ofMatrix3x3T_test.h"
//#include "ofMatrix4x4T_test.h"
//#include "ofQuaternionT_test.h"

// uncomment this line to export 
// the results as html.
//#define CPPTEST_OUTPUT

static Test::Suite ts_types;


void run_test_for_math() {
	ts_types.add( auto_ptr<Test::Suite>( new ofVecT_Suite ) );
	ts_types.add( auto_ptr<Test::Suite>( new ofVec2T_Suite ) );
	ts_types.add( auto_ptr<Test::Suite>( new ofVec3T_Suite ) );
	ts_types.add( auto_ptr<Test::Suite>( new ofVec4T_Suite ) );
	ts_types.add( auto_ptr<Test::Suite>( new ofMatrix3x3_test ) );
//	ts_types.add( auto_ptr<Test::Suite>( new ofMatrix4x4_test ) );
//	ts_types.add( auto_ptr<Test::Suite>( new ofQuaternion_test ) );
}

void run_test_for_utils() {
	ts_types.add( auto_ptr<Test::Suite>( new ofSystemUtils_Suite ) );
	ts_types.add( auto_ptr<Test::Suite>( new ofUtils_DateTimeFrame_Suite ) );
	ts_types.add( auto_ptr<Test::Suite>( new ofUtils_ofAppPaths_Suite ) );
}

void run_tests() {
	// comment tests you don't want to run.
	run_test_for_math();
//	run_test_for_utils();
    
#ifdef CPPTEST_OUTPUT
    Test::HtmlOutput output;
	output.generate( std::cout, true, "HTML Tests" );
#else
    Test::TextOutput output( Test::TextOutput::Verbose );
#endif
	
    ts_types.run( output );
}
