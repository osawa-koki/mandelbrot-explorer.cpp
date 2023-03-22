#ifndef create_new_directory_hpp
#define create_new_directory_hpp

#include <iostream>
#include <cstring>
#include <sys/stat.h>
#include <cerrno>
#include <cstdlib>

void create_new_directory(const std::string &dir)
{
  struct stat st;
  if (stat(dir.c_str(), &st) == 0)
  {
    std::cerr << "Error: Directory '" << dir << "' already exists." << std::endl;
    exit(1);
  }
  else if (errno == ENOENT)
  {
    if (mkdir(dir.c_str(), 0777) != 0)
    {
      std::cerr << "Error: Failed to create directory '" << dir << "': " << std::strerror(errno) << std::endl;
      exit(1);
    }
  }
  else
  {
    std::cerr << "Error: Failed to check directory '" << dir << "': " << std::strerror(errno) << std::endl;
    exit(1);
  }
}

#endif
