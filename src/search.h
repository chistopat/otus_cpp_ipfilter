//
// Created by Egor Chistyakov on 10/6/20.
//

#pragma once

#include "ip_address.h"
#include <vector>

std::vector<std::function<bool(const IpAddress &ip)>> searchQueries = {
    // All entries
    [](const IpAddress &ip) { return 1 == 1; },
    // First octet in Big Endian == 1
    [](const IpAddress &ip) { return ip.AsOctets()[3] == 1; },
    // First octet in Big Endian == 70
    // Second octet in Big Endian == 46
    [](const IpAddress &ip) {
      return (ip.AsOctets()[3] == 46 && ip.AsOctets()[2] == 70);
    },
    // Any octet == 46
    [](const IpAddress &ip) {
      return (ip.AsOctets()[3] == 46 || ip.AsOctets()[2] == 46 ||
              ip.AsOctets()[1] == 46 || ip.AsOctets()[0] == 46);
    },
};
