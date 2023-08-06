// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);


  FibLFSR l3("0111011010110110");
  BOOST_REQUIRE(l3.generate(5) == 25);

  
  FibLFSR l4("0111011010110110");
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 0);
  BOOST_REQUIRE(l4.step() == 0);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 0);
  BOOST_REQUIRE(l4.step() == 0);
 
  
}
