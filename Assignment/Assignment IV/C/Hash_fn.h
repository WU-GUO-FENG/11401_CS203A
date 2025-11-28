
/*
   ========================================
   hash_fn.h — declare your hash functions
   ========================================

   Description:
    宣告hash程式碼定義的函式和變數。

   Development History:
    - 2025/11/21: 上傳初始程式碼
    - 2025/11/26: 移除並未使用的宣告。
    - 2025/11/28: 新增標頭註解。

   Developer: WU-GUO-FENG <s1113306@mail.yzu.edu.tw>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>

/**
 * 字串雜湊函式 (djb2 演算法)
 * @param str 輸入的字串鍵值
 * @param m Hash Table 的大小
 * @return 處裡完成的索引值，若出錯則返回錯誤訊息
 */
int myHashString(const char* str, int m);
/**
 * 整數雜湊函式 (乘法雜湊法))
 * @param key 輸入的整數鍵值
 * @param m Hash Table 的大小
 * @return 處裡完成的索引值，若出錯則返回錯誤訊息
 */
int myHashInt(int key, int m);

#endif