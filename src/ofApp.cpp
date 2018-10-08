#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	link.setup(120);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofxAbletonLink::Status status = link.update();

	

	ofSetColor(0);
	ofDrawBitmapString("Tempo: " + ofToString(link.tempo()) + " Beats: " + ofToString(status.beat) + " Phase: " + ofToString(status.phase), 20, 20);
	ofDrawBitmapString("Number of peers: " + ofToString(link.numPeers()), 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RIGHT) {
		link.setQuantum(link.quantum() + 1);
	}
	else if (key == OF_KEY_LEFT) {
		link.setQuantum(link.quantum() - 1);
	}
	else if (key == OF_KEY_UP) {
		link.setTempo(link.tempo() + 1);
	}
	else if (key == OF_KEY_DOWN) {
		link.setTempo(link.tempo() - 1);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
