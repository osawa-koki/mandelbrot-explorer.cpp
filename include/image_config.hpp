#ifndef image_config_hpp
#define image_config_hpp

#include <string>
#include <gmpxx.h>
#include <complex>

struct ImageConfig {
  std::string filename;
  mpf_class width;
  mpf_class height;
  std::complex<mpf_class> upper_left;
  std::complex<mpf_class> lower_right;
};

#endif
