
/*
   ========================================
   hash_fn.h — declare your hash functions
   ========================================

   Description:
    宣告hash程式碼定義的函式和變數。

   Development History:
    - 2025/11/21: 上傳初始程式碼
    - 2025/11/26: 移除並未使用的宣告。

   Developer: WU-GUO-FENG <s1113306@mail.yzu.edu.tw>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>

int myHashString(const char* str, int m);
int myHashInt(int key, int m);

#endif