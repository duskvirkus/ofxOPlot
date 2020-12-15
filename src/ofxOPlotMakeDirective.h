#pragma once

#include "ofxOPlotDefines.h"
#include "ofxOPlotDirective.h"

namespace ofxOPlot {

Directive makeStartDirective();
Directive makeHomeDirective();
Directive makeMoveDirective(float x, float y);
Directive makeMarkDirective(float x, float y);

};
