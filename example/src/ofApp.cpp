#include "ofApp.h"
#include "ofxAELoader.h"

namespace {
	ofFbo fbo_;
	float alpha_;
}
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofxAE::Loader loader;
	loader.loadComposition(composition_, "trackmat.json");
	composition_.setLoopState(FrameCounter::LOOP_NONE);
	
	fbo_.allocate(1024, 768, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
	composition_.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	composition_.draw();
//	
//	fbo_.begin();
//	ofClear(0);
//	ofPushStyle();
//	ofSetColor(ofColor::white, alpha_*255);
//	ofRect(0,0, 600, 768);
//	ofPopStyle();
//	fbo_.end();
////	fbo_.draw(0,0);
//	ofSetColor(ofColor::white, alpha_*255);
////	ofRect(500,0, 600, 768);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if('1' <= key && key <= '9') {
		composition_.setActiveMarker(key-'1');
	}
	else if(key == '0') {
		composition_.clearActiveMarker();
	}
	switch(key) {
		case OF_KEY_UP:
			alpha_ += 0.1;
			break;
		case OF_KEY_DOWN:
			alpha_ -= 0.1;
			break;
		case 32:
			alpha_ = 0;
			break;
		case OF_KEY_RETURN:
			alpha_ = 1;
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
