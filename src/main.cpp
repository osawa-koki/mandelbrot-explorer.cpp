#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main(int argc, char *argv[])
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

  std::string name = options["name"];
  std::cout << "NAME: " << name << std::endl;

  int from = std::stoi(options["from"]);
  std::cout << "FROM: " << from << std::endl;

  int upto = std::stoi(options["upto"]);
  std::cout << "UPTO: " << upto << std::endl;

  float aspect_ratio = std::stof(options["aspect-ratio"]);
  std::cout << "ASPECT_RATIO: " << aspect_ratio << std::endl;

  float shrink_ratio = std::stof(options["shrink-ratio"]);
  std::cout << "SHRINK_RATIO: " << shrink_ratio << std::endl;

  float filesize_height = std::stof(options["filesize-height"]);
  std::cout << "FILESIZE_HEIGHT: " << filesize_height << std::endl;

  float start_x = std::stof(options["start-x"]);
  std::cout << "START_X: " << start_x << std::endl;

  float start_y = std::stof(options["start-y"]);
  std::cout << "START_Y: " << start_y << std::endl;

  float default_width = std::stof(options["default-width"]);
  std::cout << "DEFAULT_WIDTH: " << default_width << std::endl;

  float default_height = std::stof(options["default-height"]);
  std::cout << "DEFAULT_HEIGHT: " << default_height << std::endl;

  int length = std::stoi(options["length"]);
  std::cout << "LENGTH: " << length << std::endl;

  return 0;
}
