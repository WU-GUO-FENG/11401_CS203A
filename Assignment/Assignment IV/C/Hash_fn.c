/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    if (m <= 0 || key < 0) 
        return -1; // 處理錯誤輸入
    
    unsigned int Hash_Value = 2654435769U;  //選擇大數質數來打亂hash結果  
    unsigned int result;

    result = (unsigned int)key * Hash_Value;

    return result % m; //最後把結果限制在表格大小內
}

int myHashString(const char* str, int m) {
    // TODO: replace with your own design
    if (m <= 0) //處理錯誤輸入
        return -1;
    if (str == NULL || *str == '\0') 
        return 0; // 處理空指標和空字串
    unsigned long hash_value = 5381; // 初始值選擇一個質數

    while (*str != '\0') {
        hash_value = ((hash_value << 5) + hash_value) + (unsigned char)*str;
        str++;
    }  //不斷對hash_value進行位移和加法運算，來打亂字串的分布
    
    // 最後將數字分布到表格大小範圍內
    return (int)(hash_value % m);
}
