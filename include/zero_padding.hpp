#ifndef zero_padding_hpp
#define zero_padding_hpp

#include <string>

std::string zero_padding(int n, int length)
{
  std::string n_str = std::to_string(n);
  if (n_str.length() >= length)
  {
    return n_str;
  }
  std::string padded_str(length - n_str.length(), '0');
  return padded_str + n_str;
}

#endif
