#include <iostream>
#include <string>
#include <md5.hpp>
#include <gtest/gtest.h>

class Test02_WithoutReference : public testing::Test {
protected:
  void SetUp() override {
    MD5::md5_init();
  }
};

TEST_F(Test02_WithoutReference, TestCase01_Null_String) {
	std::string *src = new std::string("");
  std::string *expect = new std::string("d41d8cd98f00b204e9800998ecf8427e");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test02_WithoutReference, TestCase02_Single_Character) {
	std::string *src = new std::string("a");
  std::string *expect = new std::string("0cc175b9c0f1b6a831c399e269772661");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test02_WithoutReference, TestCase03_Triple_Characters) {
	std::string *src = new std::string("abc");
  std::string *expect = new std::string("900150983cd24fb0d6963f7d28e17f72");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test02_WithoutReference, TestCase04_MessageWithWhiteSpace) {
	std::string *src = new std::string("message digest");
  std::string *expect = new std::string("f96b697d7cb7938d525a2f31aaf161d0");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test02_WithoutReference, TestCase05_AllLowerAlphabet) {
	std::string *src = new std::string("abcdefghijklmnopqrstuvwxyz");
  std::string *expect = new std::string("c3fcd3d76192e4007dfb496cca67e13b");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}

TEST_F(Test02_WithoutReference, TestCase06_Triple_Characters_With_Uppercase) {
	std::string *src = new std::string("AbC");
  std::string *expect = new std::string("25aa3ee1c93cad3f274567281066dc18");

  MD5::Hash *hash = new MD5::Hash();
  MD5::hash(src, hash);

	std::string *dst = new std::string();
  MD5::to_string(hash, dst);

  ASSERT_EQ(*dst, *expect);
}
