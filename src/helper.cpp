//
// "Copyright [2020] <Copyright chistopat>
//

#include <sstream>
#include <array>

#include "helper.h"

std::vector<std::string> SplitString(const std::string &data, char dlm) {
  std::vector<std::string> result;
  std::istringstream is(data);
  std::string token;
  while (getline(is, token, dlm)) {
    result.push_back(token);
  }
  return result;
}
