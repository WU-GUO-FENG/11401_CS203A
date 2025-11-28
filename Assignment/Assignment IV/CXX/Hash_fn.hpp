/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
      宣告hash程式碼定義的函式和變數。


   Development History:
    - 2025/11/21: 上傳初始程式碼
    - 2025/11/26: 移除並未使用的宣告。
    - 2025/11/28: 新增標頭註解。


   Developer: WU-GUO-FENG <s1113306@mail.yzu.edu.tw>
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>
#include <cstdint>
using namespace std;

/**
 * 字串雜湊函式 (djb2 演算法+MurmurHash 3 混淆)
 * @param str 輸入的字串鍵值
 * @param m Hash Table 的大小
 * @return 處裡完成的索引值，若出錯則返回錯誤訊息
 */

int myHashString(const string& str, int m);
/**
 * 整數雜湊函式 (乘法雜湊法 + MurmurHash 3 混淆)
 * @param key 輸入的整數鍵值
 * @param m Hash Table 的大小
 * @return 處裡完成的索引值，若出錯則返回錯誤訊息
 */
int myHashInt(int key, int m);

#endif
