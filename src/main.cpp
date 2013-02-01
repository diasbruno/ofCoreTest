#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

#include "ofVecT_test.h"

// 0 output as console 
// 1 output as html
#define CPPTEST_OUTPUT 0 

static Test::Suite ts_types;
static Test::Suite ts_graphics;

/*! */
void run_tests_for_ofVecT() {
    ts_types.add( auto_ptr<Test::Suite>( new ofVecT_Suite ) );
}

void run_tests() {
	// comment tests you don't want to run.
	run_tests_for_ofVecT();
    
#if CPPTEST_OUTPUT == 1
    Test::HtmlOutput output;
	output.generate( std::cout, true, "HTML Tests" );
#else
    Test::TextOutput output( Test::TextOutput::Verbose );
#endif
	
    ts_types.run( output );
}

/*! */
int main() {
	run_tests();
    return 0;
}
