#pragma once

#include <climits>

#define OPLOT_DIRECTIVE_SIZE 12
#define OPLOT_COMMAND_SIZE 4
char static_assert_float32[1 - (2 * ((sizeof(float) * CHAR_BIT) != 32))];

namespace ofxOPlot {
enum COMMAND {
  start = 0,
  home,
  move,
  mark,
};
} // namespace ofxOPlot