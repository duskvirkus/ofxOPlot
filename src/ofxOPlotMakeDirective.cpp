#include "ofxOPlotMakeDirective.h"

namespace ofxOPlot
{

Directive makeStartDirective() {
  Directive d;
  d.command(COMMAND::start);
  d.uint16(OPLOT_COMMAND_SIZE, 0);
  d.uint16(OPLOT_COMMAND_SIZE + sizeof(uint16_t), 1);
  d.uint16(OPLOT_COMMAND_SIZE + sizeof(uint16_t) * 2, 1);
  d.uint16(OPLOT_COMMAND_SIZE + sizeof(uint16_t) * 3, 0);
  return d;
}

Directive makeHomeDirective() {
  Directive d;
  d.command(COMMAND::home);
  return d;
}

Directive makeMoveDirective(float x, float y) {
  Directive d;
  d.command(COMMAND::move);
  d.float32(OPLOT_COMMAND_SIZE, x);
  d.float32(OPLOT_COMMAND_SIZE + sizeof(float), y);
  return d;
}

Directive makeMarkDirective(float x, float y) {
  Directive d;
  d.command(COMMAND::mark);
  d.float32(OPLOT_COMMAND_SIZE, x);
  d.float32(OPLOT_COMMAND_SIZE + sizeof(float), y);
  return d;
}

  
} // namespace ofxOPlot
