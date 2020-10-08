//
// "Copyright [2020] <Copyright chistopat>
//

#define BOOST_TEST_MODULE test_version
#include "ip_address.h"
#include "ip_address_manager.h"
#include "search.h"
#include "sstream"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_valid_true) { BOOST_CHECK_EQUAL(1, 1); }
BOOST_AUTO_TEST_CASE(test_as_string) {
  BOOST_CHECK_EQUAL(IpAddress("127.0.0.1").AsString(), "127.0.0.1");
}
BOOST_AUTO_TEST_CASE(test_as_empty_string) {
  BOOST_CHECK_EQUAL(IpAddress("").AsString(), "0.0.0.0");
}
BOOST_AUTO_TEST_CASE(test_as_dec) {
  BOOST_CHECK_EQUAL(IpAddress("127.0.0.1").AsDec(), 2130706433);
}
BOOST_AUTO_TEST_CASE(test_as_octet) {
  BOOST_CHECK_EQUAL(+IpAddress("127.0.0.1").AsOctets()[0], 1);
  BOOST_CHECK_EQUAL(+IpAddress("127.0.0.1").AsOctets()[1], 0);
  BOOST_CHECK_EQUAL(+IpAddress("127.0.0.1").AsOctets()[2], 0);
  BOOST_CHECK_EQUAL(+IpAddress("127.0.0.1").AsOctets()[3], 127);
}
BOOST_AUTO_TEST_CASE(test_filter_by_all) {
  IpAddressManager ipManager;
  ipManager.Add("222.173.235.246");
  ipManager.Add("1.1.234.8");
  ipManager.Add("222.82.198.61");
  ipManager.Sort();
  std::ostringstream out;
  ipManager.PrintIf(out, searchQueries[0]);
  BOOST_CHECK_EQUAL(out.str(), "222.173.235.246\n222.82.198.61\n1.1.234.8\n");
}
BOOST_AUTO_TEST_CASE(test_filter_by_first) {
  IpAddressManager ipManager;
  ipManager.Add("222.173.235.246");
  ipManager.Add("1.1.234.8");
  ipManager.Add("222.82.198.61");
  ipManager.Add("1.29.168.152");
  ipManager.Add("222.130.177.64");
  ipManager.Add("1.70.44.170");
  ipManager.Sort();
  std::ostringstream out;
  ipManager.PrintIf(out, searchQueries[1]);
  BOOST_CHECK_EQUAL(out.str(), "1.70.44.170\n1.29.168.152\n1.1.234.8\n");
}
BOOST_AUTO_TEST_CASE(test_filter_by_first_second) {
  IpAddressManager ipManager;
  ipManager.Add("46.173.235.246");
  ipManager.Add("1.46.234.8");
  ipManager.Add("222.82.46.70");
  ipManager.Add("1.29.168.46");
  ipManager.Add("222.130.177.64");
  ipManager.Add("46.70.44.170");
  ipManager.Sort();
  std::ostringstream out;
  ipManager.PrintIf(out, searchQueries[2]);
  BOOST_CHECK_EQUAL(out.str(), "46.70.44.170\n");
}
BOOST_AUTO_TEST_CASE(test_filter_by_any) {
  IpAddressManager ipManager;
  ipManager.Add("46.173.235.246");
  ipManager.Add("1.46.234.8");
  ipManager.Add("222.82.46.61");
  ipManager.Add("1.29.168.46");
  ipManager.Add("222.130.177.64");
  ipManager.Add("1.70.44.170");
  ipManager.Sort();
  std::ostringstream out;
  ipManager.PrintIf(out, searchQueries[3]);
  BOOST_CHECK_EQUAL(out.str(),
                    "222.82.46.61\n46.173.235.246\n1.46.234.8\n1.29.168.46\n");
}

BOOST_AUTO_TEST_CASE(test_invalid_string) {

}
}
