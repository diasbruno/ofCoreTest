#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

#include "cpptest.h"
#include "ofVec3f_test.h"
#include "ofColor_test.h"

void run_tests()
{
    Test::Suite ts;
    ts.add( auto_ptr<Test::Suite>( new ofVec3f_Suite ) );
    ts.add( auto_ptr<Test::Suite>( new ofColor_Suite ) );
    
    Test::TextOutput output( Test::TextOutput::Verbose );
    ts.run( output );
}

//========================================================================
int main() {
	run_tests();
    return 0;
}
