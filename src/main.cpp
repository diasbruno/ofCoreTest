#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

#include "ofCoreTests.h"

// 0 output as console 
// 1 output as html
#define CPPTEST_OUTPUT 0 

static Test::Suite ts_types;
static Test::Suite ts_graphics;

/*! */
void run_tests_for_types() {
    ts_types.add( auto_ptr<Test::Suite>( new ofVec3f_Suite ) );
    ts_types.add( auto_ptr<Test::Suite>( new ofColor_Suite ) );
}

void run_tests_for_graphics() {
	ts_graphics.add( auto_ptr<Test::Suite>( new ofPixels_Suite ) );
	ts_graphics.add( auto_ptr<Test::Suite>( new ofPixels_Scenarion ) );
	//ts.add( auto_ptr<Test::Suite>( new ofImage_Suite ) );
}

void run_tests() {
	// comment tests you don't want to run.
	run_tests_for_types();
	run_tests_for_graphics();
    
    Test::HtmlOutput output;
	output.generate( std::cout, true, "HTML Tests" );
	
    ts_types.run( output );
	ts_graphics.run( output );
}

/*! */
int main() {
	run_tests();
    return 0;
}
