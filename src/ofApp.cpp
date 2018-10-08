#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);


	link.setup(120);

	ofSetLogLevel(OF_LOG_VERBOSE);
	// local ws server
	client.connect("localhost", 8088, false);
	// basic connection:
	//client.connect("echo.websocket.org");
	// OR optionally use SSL
//     client.connect("echo.websocket.org", true);

	// 1 - get default options
//    ofxLibwebsockets::ClientOptions options = ofxLibwebsockets::defaultClientOptions();

	// 2 - set basic params
//    options.host = "echo.websocket.org";

	// advanced: set keep-alive timeouts for events like
	// loss of internet

	// 3 - set keep alive params
	// BIG GOTCHA: on BSD systems, e.g. Mac OS X, these time params are system-wide
	// ...so ka_time just says "check if alive when you want" instead of "check if
	// alive after X seconds"
//    options.ka_time     = 1;
//    options.ka_probes   = 1;
//    options.ka_interval = 1;=

	// 4 - connect
//    client.connect(options);

	ofSetLogLevel(OF_LOG_ERROR);

	client.addListener(this);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofxAbletonLink::Status status = link.update();

	ofSetColor(255);
	ofDrawBitmapString("Tempo: " + ofToString(link.tempo()) + " Beats: " + ofToString(status.beat) + " Phase: " + ofToString(status.phase), 20, 20);
	ofDrawBitmapString("Number of peers: " + ofToString(link.numPeers()), 20, 40);

	ofDrawBitmapString("Type anywhere to send 'hello' to your server\nCheck the console for output!", 20, 60);
	ofDrawBitmapString(client.isConnected() ? "Client is connected" : "Client disconnected :(", 20, 100);

}
//--------------------------------------------------------------
void ofApp::onConnect(ofxLibwebsockets::Event& args) {
	cout << "on connected" << endl;
}

//--------------------------------------------------------------
void ofApp::onOpen(ofxLibwebsockets::Event& args) {
	cout << "on open" << endl;
}

//--------------------------------------------------------------
void ofApp::onClose(ofxLibwebsockets::Event& args) {
	cout << "on close" << endl;
}

//--------------------------------------------------------------
void ofApp::onIdle(ofxLibwebsockets::Event& args) {
	cout << "on idle" << endl;
}

//--------------------------------------------------------------
void ofApp::onMessage(ofxLibwebsockets::Event& args) {
	cout << "got message " << args.message << endl;
}

//--------------------------------------------------------------
void ofApp::onBroadcast(ofxLibwebsockets::Event& args) {
	cout << "got broadcast " << args.message << endl;
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
	else {
		client.send("Hello");
		cout << "sending hello" << endl;
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
