#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmp.h>
#include <gmpxx.h>
#include <sys/stat.h>
#include <complex>

#include "parse_commandline_args.hpp"
#include "options.hpp"
#include "create_new_directory.hpp"
#include "zero_padding.hpp"
#include "image_config.hpp"

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

    mpf_class shrink = mpf_class(opt.shrink_ratio, CALC_PRECISION);
    for (int j = 0; j < i; j++) {
      shrink *= opt.shrink_ratio;
    }
    mpf_class height = opt.default_height * shrink;
    std::cout << "shrink -> " << shrink << std::endl;
    std::cout << "height -> " << height << std::endl;

    mpf_class c_size_x = height * opt.aspect_ratio;
    mpf_class c_size_y = height;
    std::cout << "c_size_x -> " << c_size_x << std::endl;
    std::cout << "c_size_y -> " << c_size_y << std::endl;

    mpf_class new_start_x = opt.start_x + ((opt.default_width - c_size_x) / 2.0);
    mpf_class new_start_y = opt.start_y - ((opt.default_height - c_size_y) / 2.0);
    std::cout << "new_start_x -> " << new_start_x << std::endl;
    std::cout << "new_start_y -> " << new_start_y << std::endl;

    std::complex<mpf_class> upper_left = std::complex<mpf_class>(new_start_x, new_start_y);
    std::complex<mpf_class> lower_right = std::complex<mpf_class>(new_start_x + c_size_x, new_start_y - c_size_y);
    std::cout << "upper_left -> " << upper_left << std::endl;
    std::cout << "lower_right -> " << lower_right << std::endl;

    ImageConfig image_config = {
      filename,
      opt.filesize_height * opt.aspect_ratio,
      opt.filesize_height,
      upper_left,
      lower_right
    };
  }

  return 0;
}
