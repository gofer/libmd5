#include <iostream>
#include <string>
#include <md5.hpp>
#include <gtest/gtest.h>

class Test03_WithReference : public testing::Test {
protected:
  void SetUp() override {
    MD5::md5_init();
  }
};

TEST_F(Test03_WithReference, TestCase01_All_Alphabet_And_Numeric_String) {
  const std::string src = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const std::string expect = "d174ab98d277d9f5a5611c2c9f419d9f";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test03_WithReference, TestCase02_Long_String) {
  const std::string src = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  const std::string expect = "57edf4a22be3c955ac49da2e2107b67a";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test03_WithReference, TestCase03_Practical_String_Without_Period) {
  const std::string src = "The quick brown fox jumps over the lazy dog";
  const std::string expect = "9e107d9d372bb6826bd81d3542a419d6";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test03_WithReference, TestCase04_Practical_String_With_Period) {
  const std::string src = "The quick brown fox jumps over the lazy dog.";
  const std::string expect = "e4d909c290d0fb1ca068ffaddf22cbd0";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}
