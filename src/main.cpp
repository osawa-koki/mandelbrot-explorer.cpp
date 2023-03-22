#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmpxx.h>
#include <sys/stat.h>

#include "parse_commandline_args.hpp"
#include "options.hpp"
#include "create_new_directory.hpp"
#include "zero_padding.hpp"

#define OUTPUT_PRECISION 100

int main(int argc, char *argv[])
{
  Options opt = parse_commandline_args(argc, argv);

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

  // 対象のディレクトリを作成
  std::string target_directory = "./work/" + opt.name + "/";
  create_new_directory(target_directory);

  // マンデルブロ集合の計算
  for (int i = opt.from; i <= opt.upto; i++) {
    std::string filename = target_directory + zero_padding(i, 8) + ".png";
    std::cout << "FILENAME: " << filename << std::endl;
  }

  return 0;
}
