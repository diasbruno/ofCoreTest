#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

#include "ofCoreTests.h"

void bootApp() {
	ofAppGlutWindow win;
	ofSetupOpenGL( &win , 600, 400, OF_WINDOW );
	ofRunApp( new testApp );
}

/*! 
 
 All tests are placed in ofCore/ofCoreTests.h.
 
 */
int main() {
	bootApp();
	
//	run_tests();
	return 0;
}
