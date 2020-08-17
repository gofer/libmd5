#include <iostream>
#include <string>
#include <md5.hpp>
#include <gtest/gtest.h>

class Test01_WithReference : public testing::Test {
protected:
  void SetUp() override {
    MD5::md5_init();
  }
};

TEST_F(Test01_WithReference, TestCase01_Null_String) {
	const std::string src = "";
  const std::string expect = "d41d8cd98f00b204e9800998ecf8427e";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test01_WithReference, TestCase02_Single_Character) {
	const std::string src = "a";
  const std::string expect = "0cc175b9c0f1b6a831c399e269772661";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test01_WithReference, TestCase03_Triple_Characters) {
	const std::string src = "abc";
  const std::string expect = "900150983cd24fb0d6963f7d28e17f72";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test01_WithReference, TestCase04_MessageWithWhiteSpace) {
	const std::string src = "message digest";
  const std::string expect = "f96b697d7cb7938d525a2f31aaf161d0";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test01_WithReference, TestCase05_AllLowerAlphabet) {
	const std::string src = "abcdefghijklmnopqrstuvwxyz";
  const std::string expect = "c3fcd3d76192e4007dfb496cca67e13b";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}

TEST_F(Test01_WithReference, TestCase06_Triple_Characters_With_Uppercase) {
	const std::string src = "AbC";
  const std::string expect = "25aa3ee1c93cad3f274567281066dc18";

	std::string dst = MD5::to_string( MD5::hash(src) );

  ASSERT_EQ(dst, expect);
}
