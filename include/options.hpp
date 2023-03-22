#include <string>
#include <gmpxx.h>

struct Options {
  std::string name;
  int from;
  int upto;
  float aspect_ratio;
  float shrink_ratio;
  float filesize_height;
  mpf_class start_x;
  mpf_class start_y;
  float default_width;
  float default_height;
  int length;
};
