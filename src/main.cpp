#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "ofCoreTests.h"

/*! Setup OF window app. */
void setupWindow() {
	ofAppGlutWindow win;
	ofSetupOpenGL( &win , 600, 400, OF_WINDOW );
}

/*! Change this include to test other app. */
#include "ofVecT_testApp.h"
void bootApp() {
	setupWindow();
	ofRunApp( new testApp );
}

/*! All tests are placed in ofCore/ofCoreTests.h. */
int main() {
	//bootApp();
	run_tests();
	return 0;
}
