#ifndef parse_commandline_args_hpp
#define parse_commandline_args_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmpxx.h>

#include "options.hpp"
#include "const.hpp"

Options parse_commandline_args(int argc, char *argv[])
{
  std::map<std::string, std::string> options;
  for (int i = 1; i < argc; i += 2)
  {
    std::string arg = argv[i];
    if (arg[0] == '-')
    {
      std::string val;
      if (i + 1 < argc)
      {
        val = argv[i + 1];
      }
      options[arg.substr(1)] = val;
    }
  }

  Options opt;
  opt.name = options["name"];
  opt.from = std::stoi(options["from"]);
  opt.upto = std::stoi(options["upto"]);
  opt.aspect_ratio = std::stof(options["aspect-ratio"]);
  opt.shrink_ratio = mpf_class(options["shrink-ratio"], CALC_PRECISION);
  opt.filesize_height = std::stof(options["filesize-height"]);
  opt.start_x = mpf_class(options["start-x"], CALC_PRECISION);
  opt.start_y = mpf_class(options["start-y"], CALC_PRECISION);
  opt.default_width = mpf_class(options["default-width"], CALC_PRECISION);
  opt.default_height = mpf_class(options["default-height"], CALC_PRECISION);

  return opt;
}

#endif
