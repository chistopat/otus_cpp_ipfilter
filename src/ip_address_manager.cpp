//
// "Copyright [2020] <Copyright chistopat>
//

#include "ip_address_manager.h"

#include "sstream"
#include <algorithm>

void IpAddressManager::Add(const std::string &ip_str) {
  _pool.emplace_back(IpAddress(ip_str));
}

void IpAddressManager::PrintIf(
    std::ostream &os,
    const std::function<bool(const IpAddress &ip)> &predicate) const {
  for (const auto ip : _pool) {
    if (predicate(ip)) {
      os << ip.AsString() << std::endl;
    }
  }
}

void IpAddressManager::Sort(Order sort_order) {
  auto less = [](const auto &lhs, const auto &rhs) {
    return lhs.AsDec() < rhs.AsDec();
  };
  auto greater = [](const auto &lhs, const auto &rhs) {
    return lhs.AsDec() > rhs.AsDec();
  };
  switch (sort_order) {
  case Order::DESC:
    std::sort(_pool.begin(), _pool.end(), less);
  case Order::ASC:
    std::sort(_pool.begin(), _pool.end(), greater);
  }
}
