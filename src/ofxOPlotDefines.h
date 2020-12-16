#pragma once

#define OPLOT_DIRECTIVE_SIZE 12
#define OPLOT_COMMAND_SIZE 4

namespace ofxOPlot {
enum COMMAND {
  start = 0,
  home,
  move,
  mark,
};
} // namespace ofxOPlot