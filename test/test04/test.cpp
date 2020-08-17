#include <iostream>
#include <string>
#include <md5.hpp>
#include <gtest/gtest.h>

class Test04_WithoutReference : public testing::Test {
protected:
  void SetUp() override {
    MD5::md5_init();
  }
};

TEST_F(Test04_WithoutReference, TestCase01_All_Alphabet_And_Numeric_String) {
  std::string *src = new std::string(
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  std::string *expect = new std::string("d174ab98d277d9f5a5611c2c9f419d9f");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test04_WithoutReference, TestCase02_Long_String) {
  std::string *src = new std::string("12345678901234567890123456789012345678901"
                                     "234567890123456789012345678901234567890");
  std::string *expect = new std::string("57edf4a22be3c955ac49da2e2107b67a");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test04_WithoutReference, TestCase03_Practical_String_Without_Period) {
  std::string *src =
      new std::string("The quick brown fox jumps over the lazy dog");
  std::string *expect = new std::string("9e107d9d372bb6826bd81d3542a419d6");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test04_WithoutReference, TestCase04_Practical_String_With_Period) {
  std::string *src =
      new std::string("The quick brown fox jumps over the lazy dog.");
  std::string *expect = new std::string("e4d909c290d0fb1ca068ffaddf22cbd0");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}
