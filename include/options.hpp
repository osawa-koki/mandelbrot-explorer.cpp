#ifndef options_hpp
#define options_hpp

#include <string>
#include <gmpxx.h>

struct Options {
  std::string name;
  int from;
  int upto;
  float aspect_ratio;
  mpf_class shrink_ratio;
  float filesize_height;
  mpf_class start_x;
  mpf_class start_y;
  mpf_class default_width;
  mpf_class default_height;
};

#endif
