#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	link.setup(120);
	beat = 0.0;
	phase = 0.0;
	ofSetLogLevel(OF_LOG_VERBOSE);
	// load settings.xml
	if (settings.loadFile("settings.xml") == false) {
		ofLog() << "XML ERROR, possibly quit";
	}
	settings.pushTag("settings");
	server = settings.getValue("server", "127.0.0.1");
	ofLog() << "server" << server;
	// local ws server ip, port, useSSL
	client.connect(server, 8088, false);

	ofSetLogLevel(OF_LOG_ERROR);

	client.addListener(this);
	ofSetFrameRate(24);
}

//--------------------------------------------------------------
void ofApp::update(){
	status = link.update();
	if (tempo != link.tempo()) {
		tempo = link.tempo();
		client.send("{\"cmd\" :[{\"type\" : 2,\"tempo\" : " + ofToString(link.tempo()) + "}]}");
		cout << "sending tempo change" << endl;
	}
	client.send("{\"cmd\" :[{\"type\" : 2,\"tempo\" : " + ofToString(link.tempo()) + "}]}");
	client.send("{\"cmd\" :[{\"type\" : 3,\"beat\" : " + ofToString(status.beat) + "}]}");
	client.send("{\"cmd\" :[{\"type\" : 4,\"phase\" : " + ofToString(status.phase) + "}]}");

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(255);
	ofDrawBitmapString("Tempo: " + ofToString(link.tempo()) + " Beats: " + ofToString(status.beat) + " Phase: " + ofToString(status.phase), 20, 20);
	ofDrawBitmapString("Number of peers: " + ofToString(link.numPeers()), 20, 40);

	ofDrawBitmapString("Type anywhere to send tempo to your server\nCheck the console for output!", 20, 60);
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
	//cout << "on idle" << endl;
}

//--------------------------------------------------------------
void ofApp::onMessage(ofxLibwebsockets::Event& args) {
	try {
	cout << "got message " << args.message << endl;
	if (!args.json.isNull()) {
		if (!args.json["tempo"].isNull()) {
			if (args.json["tempo"].asDouble() != tempo) {
				link.setTempo(tempo);
			}
			// args.json["setup"]["id"].asInt();
			// for some reason these come across as strings via JSON.stringify!
			/*int r = ofToInt(args.json["setup"]["color"]["r"].asString());
			int g = ofToInt(args.json["setup"]["color"]["g"].asString());
			int b = ofToInt(args.json["setup"]["color"]["b"].asString());*/
		}
		
	}
	else {
	}
	}
	catch (exception& e) {
		ofLogError() << e.what();
	}
}

//--------------------------------------------------------------
void ofApp::onBroadcast(ofxLibwebsockets::Event& args) {
	cout << "got broadcast " << args.message << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLogNotice("PRESSED KEY: " + ofToString(key));
	switch (key) {
	/*case OF_KEY_RIGHT:
		link.setQuantum(link.quantum() + 1);
		break;
	case OF_KEY_LEFT:
		link.setQuantum(link.quantum() - 1);
		break;
	case OF_KEY_UP:
		link.setTempo(link.tempo() + 1); 
		break;
	case OF_KEY_DOWN:
		link.setTempo(link.tempo() - 1);
		break;
	case 119:// w
	case 87: // W		
		
		break;*/
	case 27: // ESC
		exit();
		break;
	default:
		client.send("{\"cmd\" :[{\"type\" : 2,\"tempo\" : " + ofToString(link.tempo()) + "}]}");
		cout << "sending tempo" << endl;
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
