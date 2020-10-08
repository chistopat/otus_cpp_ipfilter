//
// "Copyright [2020] <Copyright chistopat>
//

#pragma once

#include <array>
#include <algorithm>
#include <cinttypes>
#include <sstream>
#include <string>

#include "./helper.h"

class IpAddress {
 public:
  explicit IpAddress(const std::string &data);
  std::string AsString() const;
  const std::array<uint8_t, 4> &AsOctets() const;
  uint32_t AsDec() const;

 private:
  union {
    std::array<uint8_t, 4> octets;
    uint32_t inet_addr;
  } ip_address;
};

bool operator<(const IpAddress &lhs, const IpAddress &rhs);
bool operator>(const IpAddress &lhs, const IpAddress &rhs);
