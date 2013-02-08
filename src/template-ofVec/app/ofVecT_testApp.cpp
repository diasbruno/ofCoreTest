#include "ofVecT_testApp.h"

namespace of {
	
	class Rect {
	public:
		
		ofVec3<double> position;
		::_ofVec2<double> frame;
		::_ofVec2<double> velocity;
		
		int alpha;
		
		bool isOutOfStage;
		
		Rect() {
			isOutOfStage = false;
			position = ofVec3<double>(0,0);
			frame = ::_ofVec2<double>(0,0);
			velocity = ::_ofVec2<double>(0,0);
			
			alpha = 255;
			
			position.x = ofGetWidth() / 2;
			position.y = ofGetHeight() / 2;
			
			ofLog() << position.x << endl;
			ofLog() << position.y << endl;
			
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
			
			alpha = alpha - 1;
			
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
	
	ofLog() << ofGetWidth() << endl;
	ofLog() << ofGetHeight() << endl;
	
	ofLog() << "Viewport width" << ofGetViewportWidth();
	ofLog() << "Viewport height" << ofGetViewportHeight();
}

//--------------------------------------------------------------
void testApp::update(){
	particles.push_back( new of::Rect() );
}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();
	of::Rect* r;
	int len = particles.size();
	for (int i = 0; i < len; i++) {
		r = particles[ i ];
		r->update();
		if ( !r->isOutOfStage ) {
			
			ofSetColor( 255, 255, 255, r->alpha );
			ofRect( r->position.x, r->position.y, r->frame.x, r->frame.y );
			
		}
	}
	ofPopMatrix();
	ofSetColor( 255, 255, 255, 255 );
	ofRect( -400, -100, 100, 100 );
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