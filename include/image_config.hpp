#ifndef image_config_hpp
#define image_config_hpp

#include <string>
#include <gmpxx.h>

struct ImageConfig {
  std::string filename;
  int width;
  int height;
  mpf_class upper_left;
  mpf_class lower_right;
};

#endif
