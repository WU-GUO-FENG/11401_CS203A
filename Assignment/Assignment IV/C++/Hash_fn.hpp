/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>
#include <limits>   // 確認高位元整數正常使用不會溢出
#include <cstdint>  // 確保位元數準確
using namespace std; // 簡化std使用

int myHashString(const std::string& str, int m);
int myHashInt(int key, int m);

#endif
