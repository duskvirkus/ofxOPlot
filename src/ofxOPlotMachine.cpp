#include "ofxOPlotMachine.h"

namespace ofxOPlot {

void Machine::setup() {
  setup(0, 9600);
}

void Machine::setup(int serialIndex, int baud) {
  serial.setup(serialIndex, baud);
  programPtr = nullptr;
  ready = false;
}

void Machine::update() {
  if (serial.available() >= 4) {
    vector<uint8_t> reply;

    while (serial.available() > 0) {
      reply.emplace_back(serial.readByte());
    }

    std::string s = "";
    for (int i = 0; i < 4; ++i) {
      s += static_cast<char>(reply[i]);
    }

    if (s == "done") {
      cout << "command compleate" << '\n';
      ready = true;
    }

    // TODO: handle error
  }
  
  if (programPtr != nullptr && ready) {
    programPtr->sendNext(serial);
    ready = false;
  }
}

void Machine::loadProgram(const Program& p) {
  programPtr = make_unique<Program>(Program(p));
  programPtr->sendNext(serial);
}

}