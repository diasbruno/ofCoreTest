#include "ofVecT_testApp.h"
#include "ofVec.h"

namespace of {
	
	class Rect {
	public:
		of::ofVec3<float> position;
		of::ofVec2<float> frame;
		of::ofVec2<float> velocity;
		of::ofVecT<int> alpha;
		
		bool isOutOfStage;
		
		Rect() {
			isOutOfStage = false;
			
			alpha = 255;
			
			position.x =  ofGetWidth() / 2;
			position.y = ofGetHeight() / 2;
			
			float f = ofRandom( 40 );
			
			frame.x = f;
			frame.y = f;
			
			float v = -5 + ofRandom( 10 );	
			velocity.x = v;
			v = -5 + ofRandom( 10 );
			velocity.y = v;
		}
		
		void update() {
			position.x += velocity.x * 0.1;
			position.y += velocity.y * 0.1;
			
			alpha.x = alpha.x - 1;
			
			if ( ( position.x >  ofGetWidth() || position.x < 0 )
				||   ( position.y > ofGetHeight() || position.y < 0 ) ) {
				isOutOfStage = true;
			}
		}
	};
	
}

//--------------------------------------------------------------
void testApp::setup() {
	ofSetWindowTitle( "ofCoreTest - Template ofVec" );
	ofBackground( 0 );
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
	particles.push_back( new of::Rect() );
}

//--------------------------------------------------------------
void testApp::draw(){
	of::Rect* r;
	int len = particles.size();
	for (int i = 0; i < len; i++) {
		r = particles[ i ];
		r->update();
		if ( !r->isOutOfStage ) {
			
			ofSetColor( 255, 255, 255, r->alpha.x );
			ofRect( r->position.x, r->position.y, r->frame.x, r->frame.y );
			
		}
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}