# MD5 Hash Library for C++
[![BuldStatus](https://travis-ci.org/gofer/libmd5.svg?branch=dev-add_travis)](https://travis-ci.org/gofer/libmd5)

## What's this
This is MD5 hash library for C++.

## Attention
This code uses C++11 features.

## How to use

### With reference
MD5 hasing functions are in namespace MD5. 

  	MD5::Hash MD5::hash(const std::string &src);
    std::string to_string(const MD5::Hash &hash);

### Without reference
MD5 hasing function is in namespace MD5. These functions always return 0.

    int hash(const std::string *src, MD5::Hash *hash);
    int to_string(MD5::Hash *hash, std::string *dst);

### Examples
In detail, please show `md5_test.cpp`.
That code is compiled on following commands.

  g++ md5_test.cpp -I. -L. -lmd5 -std=c++11 -o test.out

## Licence
This codes are licensed by New BSD License.
