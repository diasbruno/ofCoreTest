#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

#include "ofCoreTests.h"

void run_tests()
{
    Test::Suite ts;
    ts.add( auto_ptr<Test::Suite>( new ofVec3f_Suite ) );
    ts.add( auto_ptr<Test::Suite>( new ofColor_Suite ) );
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
    
    Test::TextOutput output( Test::TextOutput::Verbose );
    ts.run( output );
}

//========================================================================
int main() {
	run_tests();
    return 0;
}
