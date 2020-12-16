#pragma once

#include "ofxOPlotDirective.h"
#include <deque>
#include <string>

namespace ofxOPlot {

class Program {
public:

  Program();
  ~Program() = default;

  void addDirective(const Directive&);
  void sendNext(ofSerial&);

  // TODO: Add save and load
  // void save(std::string path);
  // void load(std::string path);

private:

  std::deque<Directive> directives;

};

}

