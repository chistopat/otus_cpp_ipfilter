//
// "Copyright [2020] <Copyright chistopat>
//

#pragma once

#include <functional>
#include <string>
#include <vector>

#include "ip_address.h"

enum class Order { ASC, DESC };

class IpAddressManager {
public:
  void Add(const std::string &ip_str);
  void PrintIf(std::ostream &os,
               const std::function<bool(const IpAddress &ip)> &predicate) const;
  void Sort(Order sort_order = Order::DESC);

private:
  std::vector<IpAddress> _pool;
};
