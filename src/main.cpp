#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmpxx.h>

#define CALC_PRECISION 128
#define OUTPUT_PRECISION 100

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

int main(int argc, char *argv[])
{
  Options opt = parse_command_line(argc, argv);

  std::cout << "NAME: " << opt.name << std::endl;
  std::cout << "FROM: " << opt.from << std::endl;
  std::cout << "UPTO: " << opt.upto << std::endl;
  std::cout << "ASPECT_RATIO: " << opt.aspect_ratio << std::endl;
  std::cout << "SHRINK_RATIO: " << opt.shrink_ratio << std::endl;
  std::cout << "FILESIZE_HEIGHT: " << opt.filesize_height << std::endl;
  std::cout << "START_X: " << std::setprecision(OUTPUT_PRECISION) << opt.start_x << std::endl;
  std::cout << "START_Y: " << std::setprecision(OUTPUT_PRECISION) << opt.start_y << std::endl;
  std::cout << "DEFAULT_WIDTH: " << opt.default_width << std::endl;
  std::cout << "DEFAULT_HEIGHT: " << opt.default_height << std::endl;
  std::cout << "LENGTH: " << opt.length << std::endl;

  return 0;
}
