#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmp.h>
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

    // let c_size_x = Float::with_val(RUG_PREC, height.clone()) * Float::with_val(RUG_PREC, aspect_ratio);
    // let c_size_y = Float::with_val(RUG_PREC, height.clone());
    // let new_start_x:Float = start_x.clone() + ((default_width - c_size_x.clone()) / 2.0);
    // let new_start_y:Float = start_y.clone() - ((default_height - c_size_y.clone()) / 2.0);
    // let upper_left = Complex::with_val(RUG_PREC, (new_start_x.clone(), new_start_y.clone()));
    // let lower_right = Complex::with_val(RUG_PREC, (new_start_x.clone() + c_size_x.clone(), new_start_y.clone() - c_size_y.clone()));
    
    mpf_class shrink = mpf_class(opt.shrink_ratio, CALC_PRECISION);
    for (int j = 0; j < i; j++) {
      shrink *= opt.shrink_ratio;
    }
    mpf_class height = opt.default_height * shrink;
    std::cout << "shrink -> " << shrink << std::endl;
    std::cout << "height -> " << height << std::endl;
  }

  return 0;
}
