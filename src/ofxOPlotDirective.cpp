#include "ofxOPlotDirective.h"

namespace ofxOPlot
{
  
Directive::Directive() {
  for (int i = 0; i < OPLOT_DIRECTIVE_SIZE; ++i) {
    bytes[i] = 0;
  }
}

void Directive::command(COMMAND cmd) {
  const char* cmdString = "eror";
  switch (cmd) {
    case start:
      cmdString = "star";
      break;
    case home:
      cmdString = "home";
      break;
    case move:
      cmdString = "move";
      break;
    case mark:
      cmdString = "mark";
      break;
  }

  for (int i = 0; i < OPLOT_COMMAND_SIZE; ++i) {
    bytes[i] = cmdString[i];
  }
}

void Directive::uint16(int byteOffset, u_int16_t value) {
  if (static_cast<unsigned long>(byteOffset) < OPLOT_COMMAND_SIZE - (sizeof(uint16_t) + 1)) {
    cout << "error invalid byteOffset" << '\n';
    exit(1);
  }

  bytes[byteOffset] = value & 0xFF;
  bytes[byteOffset + 1] = (value >> 8) & 0xFF;
}

void Directive::float32(int byteOffset, float value) {
  if (static_cast<unsigned long>(byteOffset) < OPLOT_COMMAND_SIZE - (sizeof(float) + 3)) {
    cout << "error invalid byteOffset" << '\n';
    exit(1);
  }

  int* valueInt = reinterpret_cast<int*>(&value);

  bytes[byteOffset] = (*valueInt) & 0xFF;
  bytes[byteOffset + 1] = ((*valueInt) >> 8) & 0xFF;
  bytes[byteOffset + 2] = ((*valueInt) >> 16) & 0xFF;
  bytes[byteOffset + 3] = ((*valueInt) >> 24) & 0xFF;
}
  
ofSerial& operator<<(ofSerial& serial, const Directive& d) {
  for (int i = 0; i < OPLOT_DIRECTIVE_SIZE; ++i) {
    cout << d.bytes[i] << ' ' << static_cast<int>(d.bytes[i]) << '\n';
  }
  return serial;
}

} // namespace ofxOPlot
