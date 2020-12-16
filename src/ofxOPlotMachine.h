#pragma once

#include "ofxOPlotProgram.h"
#include "ofMain.h"
#include <memory>

namespace ofxOPlot {

class Machine {
public:

  Machine() = default;
  ~Machine() = default;

  void setup();
  void setup(int serialIndex, int baud);
  void update();

  void loadProgram(const Program&);

private:

  ofSerial serial;
  bool ready;
  std::unique_ptr<Program> programPtr;

};

}

