//
// "Copyright [2020] <Copyright chistopat>
//

#include <algorithm>
#include <iostream>

#include "helper.h"
#include "ip_address_manager.h"
#include "search.h"

int main() {
  IpAddressManager ipManager;
  for (std::string row; getline(std::cin, row);) {
    try {
      auto tokens = SplitString(row, '\t');
      ipManager.Add(tokens[0]);
    } catch (std::invalid_argument& e) {
      std::cout << "[ERROR] - Incorrect input: " << e.what() << std::endl;
      continue;
    }
  }
  ipManager.Sort();
  for (const auto query : searchQueries) {
    ipManager.PrintIf(std::cout, query);
  }
  return 0;
}
