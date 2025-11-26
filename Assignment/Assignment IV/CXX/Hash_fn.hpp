/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
      宣告hash程式碼定義的函式和變數。


   Development History:
    - 2025/11/21: 上傳初始程式碼
    - 2025/11/26: 移除並未使用的宣告。


   Developer: WU-GUO-FENG <s1113306@mail.yzu.edu.tw>
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>
#include <cstdint>
using namespace std;

int myHashString(const string& str, int m);
int myHashInt(int key, int m);

#endif
