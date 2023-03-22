#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmpxx.h>

#include "options.hpp"

#define CALC_PRECISION 128

Options parse_command_line(int argc, char *argv[])
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
  opt.shrink_ratio = std::stof(options["shrink-ratio"]);
  opt.filesize_height = std::stof(options["filesize-height"]);
  opt.start_x = mpf_class(options["start-x"], CALC_PRECISION);
  opt.start_y = mpf_class(options["start-y"], CALC_PRECISION);
  opt.default_width = std::stof(options["default-width"]);
  opt.default_height = std::stof(options["default-height"]);
  opt.length = std::stoi(options["length"]);

  return opt;
}
