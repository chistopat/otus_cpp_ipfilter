//
// "Copyright [2020] <Copyright chistopat>
//

#include "ip_address.h"

IpAddress::IpAddress(const std::string &data) : ip_address({}) {
  if (data.empty()) {
    ip_address.octets = {0, 0, 0, 0};
    return;
  }
  auto tokens = SplitString(data, '.');
  std::reverse(tokens.begin(), tokens.end());
  for (size_t i = 0; i < ip_address.octets.size(); i++) {
    ip_address.octets[i] = stoi(tokens[i]);
  }
}

std::string IpAddress::AsString() const {
  std::ostringstream os;
  for (int i = 3; i >= 0; --i) {
    os << +ip_address.octets[i];
    if (i != 0) {
      os << '.';
    }
  }
  return os.str();
}

const std::array<uint8_t, 4> &IpAddress::AsOctets() const {
  return ip_address.octets;
}

uint32_t IpAddress::AsDec() const { return ip_address.inet_addr; }

bool operator<(const IpAddress &lhs, const IpAddress &rhs) {
  return lhs.AsDec() > rhs.AsDec();
}
