#include <png.h>
#include <iostream>
#include <fstream>

#include "const.hpp"
#include "image_config.hpp"

int mandelbrot(ImageConfig image_config)
{
  // 画像の幅と高さを指定する
  int width = image_config.width;
  int height = image_config.height;

  mpf_class x_min = image_config.upper_left.real();
  mpf_class x_max = image_config.lower_right.real();
  mpf_class y_min = image_config.upper_left.imag();
  mpf_class y_max = image_config.lower_right.imag();

  // 画像のデータを格納する配列を確保する
  png_bytep *row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
  for (int y = 0; y < height; y++)
  {
    row_pointers[y] = (png_byte *)malloc(sizeof(png_byte) * width * 4);
  }

  // マンデルブロ集合を描写する
  for (int y = 0; y < height; y++)
  {
    png_bytep row = row_pointers[y];
    for (int x = 0; x < width; x++)
    {
      png_bytep px = &(row[x * 4]);
      px[0] = 0;               // 赤
      px[1] = 0;               // 緑
      px[2] = 0;               // 青
      px[3] = MAX_COLOR_VALUE; // 不透明度

      // マンデルブロ集合の計算を行う
      mpf_class x0 = x_min + (x_max - x_min) * mpf_class(x, CALC_PRECISION) / mpf_class(width, CALC_PRECISION);
      mpf_class y0 = y_min + (y_max - y_min) * mpf_class(y, CALC_PRECISION) / mpf_class(height, CALC_PRECISION);
      mpf_class x1 = mpf_class(0.0, CALC_PRECISION);
      mpf_class y1 = mpf_class(0.0, CALC_PRECISION);
      int i = 0;
      while (x1 * x1 + y1 * y1 <= 2 * 2 && i < MAX_ITERATIONS)
      {
        mpf_class x2 = x1 * x1 - y1 * y1 + x0;
        mpf_class y2 = 2 * x1 * y1 + y0;
        x1 = x2;
        y1 = y2;
        i++;
      }

      // マンデルブロ集合の計算結果を色に変換する
      int color = i * MAX_COLOR_VALUE / MAX_ITERATIONS;
      px[0] = color;
      px[1] = 0;
      px[2] = 0;
      px[3] = MAX_COLOR_VALUE;
    }
  }

  // 画像をファイルに出力する
  std::ofstream output_file(image_config.filename, std::ios::binary);
  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  png_infop info = png_create_info_struct(png);
  png_set_write_fn(
      png, &output_file, [](png_structp png, png_bytep data, png_size_t length)
      { ((std::ostream *)png_get_io_ptr(png))->write((char *)data, length); },
      nullptr);
  png_set_IHDR(
      png,
      info,
      width, height,
      8,
      PNG_COLOR_TYPE_RGBA,
      PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_DEFAULT,
      PNG_FILTER_TYPE_DEFAULT);

  png_write_info(png, info);
  png_write_image(png, row_pointers);
  png_write_end(png, NULL);

  // メモリを解放する
  for (int y = 0; y < height; y++)
  {
    free(row_pointers[y]);
  }
  free(row_pointers);

  return 0;
}
