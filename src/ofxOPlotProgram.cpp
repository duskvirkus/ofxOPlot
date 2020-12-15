#include "ofxOPlotProgram.h"

namespace ofxOPlot {

Program::Program() {

}

void Program::addDirective(const Directive& d) {
  directives.emplace_back(d);
}

void Program::sendNext(ofSerial& serial) {
  serial << directives.front();
  directives.pop_front();
}

}

