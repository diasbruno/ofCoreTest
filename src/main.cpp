#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "ofCoreTests.h"



#include "ofVecT_testApp.h"
void bootApp() {
	ofAppGlutWindow win;
	ofSetupOpenGL( &win , 600, 400, OF_WINDOW );
	ofRunApp( new testApp );
}

/*! 
 
 All tests are placed in ofCore/ofCoreTests.h.
 
 */
int main() {
	//bootApp();
	run_tests();
	return 0;
}
