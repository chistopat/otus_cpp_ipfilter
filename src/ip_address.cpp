//
// "Copyright [2020] <Copyright chistopat>
//

#include "ip_address.h"

std::vector<int> ParseAddress(const std::string& data) {
  std::istringstream is(data);
  std::vector<int> result(4);
  char d0, d1, d2;
  is >> result[0] >> d0 >> result[1] >> d1 >> result[2] >> d2 >> result[3];
  if (!is.eof() || is.fail() || d0 != '.' || d1 != '.' || d2 != '.') {
    throw std::invalid_argument("Invalid IPv4 format: " + data);
  }
  for (const auto item : result) {
    if (item < 0 || item > 255) {
      throw std::invalid_argument("Invalid IPv4 value: " + data);
    }
  }
  return result;
}


IpAddress::IpAddress(const std::string &data) : ip_address({0, 0, 0, 0}) {
  if (!data.empty()) {
    auto tokens = ParseAddress(data);
    std::reverse(tokens.begin(), tokens.end());
    for (size_t i = 0; i < ip_address.octets.size(); i++) {
      ip_address.octets[i] = tokens[i];
    }
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
  return lhs.AsDec() < rhs.AsDec();
}

bool operator>(const IpAddress &lhs, const IpAddress &rhs) {
  return lhs.AsDec() > rhs.AsDec();
}
