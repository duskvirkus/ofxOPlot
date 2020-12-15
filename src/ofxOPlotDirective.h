#pragma once

#include "ofxOPlotDefines.h"
#include "ofMain.h"

namespace ofxOPlot {

class Directive {
public:
  Directive();
  ~Directive() = default;

  void command(COMMAND);
  void uint16(int byteOffset, u_int16_t);
  void float32(int byteOffset, float);

  friend ofSerial& operator<<(ofSerial&, const Directive&);

private:
  u_int8_t bytes[OPLOT_DIRECTIVE_SIZE];
};

} // namespace ofxOPlot
