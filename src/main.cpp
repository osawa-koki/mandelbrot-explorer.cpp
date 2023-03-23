#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <gmp.h>
#include <gmpxx.h>
#include <sys/stat.h>
#include <complex>
#include <thread>
#include <vector>

#include "const.hpp"
#include "parse_commandline_args.hpp"
#include "options.hpp"
#include "create_new_directory.hpp"
#include "zero_padding.hpp"
#include "image_config.hpp"
#include "mandelbrot.hpp"

int main(int argc, char *argv[])
{
  Options opt = parse_commandline_args(argc, argv);

  std::cout << "===== ===== ===== OPTIONS ===== ===== =====" << std::endl;
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
  std::cout << "===== ===== ===== ===== ===== ===== =====" << std::endl;

  // 対象のディレクトリを作成
  std::string target_directory = "./work/" + opt.name + "/";
  create_new_directory(target_directory);

  const int num_threads = 4;
  const int start = opt.from;
  const int end = opt.upto;
  const int block_size = (end - start + 1) / num_threads;
  std::vector<std::thread> threads(num_threads);

  for (int i = 0; i < num_threads; i++) {
    int thread_start = start + i * block_size;
    int thread_end = (i == num_threads - 1) ? end : thread_start + block_size - 1;
    threads[i] = std::thread([&target_directory, &opt, thread_start, thread_end]() {
      for (int i = thread_start; i <= thread_end; i++) {
        // 進捗を表示
        std::cout << "=====> running..." << std::endl;

        std::string filename = target_directory + zero_padding(i, 8) + ".png";
        mpf_class shrink = mpf_class(opt.shrink_ratio, CALC_PRECISION);
        for (int j = 0; j < i; j++)
        {
          shrink *= opt.shrink_ratio;
        }
        mpf_class height = opt.default_height * shrink;
        mpf_class c_size_x = height * opt.aspect_ratio;
        mpf_class c_size_y = height;
        mpf_class new_start_x = opt.start_x + ((opt.default_width - c_size_x) / 2.0);
        mpf_class new_start_y = opt.start_y - ((opt.default_height - c_size_y) / 2.0);
        std::complex<mpf_class> upper_left = std::complex<mpf_class>(new_start_x, new_start_y);
        std::complex<mpf_class> lower_right = std::complex<mpf_class>(new_start_x + c_size_x, new_start_y - c_size_y);

        ImageConfig image_config = {
          filename,
          opt.filesize_height * opt.aspect_ratio,
          opt.filesize_height,
          upper_left,
          lower_right,
          mpf_class(1, CALC_PRECISION) + mpf_class(i, CALC_PRECISION) / mpf_class(opt.upto - opt.from, CALC_PRECISION)
        };
        mandelbrot(image_config);
      }
    });
  }

  for (int i = 0; i < num_threads; i++) {
    threads[i].join();
  }

  return 0;
}
