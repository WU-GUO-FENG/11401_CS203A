
/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    static unsigned int previous_hash = 0;
    
    if (m <= 0 && key < 0) 
        return -1; // 處理錯誤輸入

    unsigned int A = 2654435769U; //選擇大數質數來打亂hash結果 
    
    unsigned int combined_key = (unsigned int)key + previous_hash; // 結合前一個 hash 值以增加隨機性
    
    unsigned int result = combined_key * A;

    previous_hash = result; // 更新 previous_hash 為當前的 hash 結果，提供給下一次使用
    
    // 4. 最後取餘數
    return result % m; //最後把結果限制在表格大小內
}

int myHashString(const std::string& str, int m) {
    if (m <= 0) 
        return -1;
    if (str.empty()) 
        return 0;

    uint32_t hash_value = 5381U; // U 後綴表示 unsigned

    for (char c : str) {

        hash_value = ((hash_value << 5) + hash_value) + (unsigned char)c;
    }

    const uint32_t C = 0x85ebca6bU; // 定義一個大質數用於混合
    
    hash_value ^= (hash_value >> 16); 
    
    hash_value *= C; //把hash_value和質數C位移後相乘來進一步打亂分布
    
    return (int)(hash_value % m); // 最後將數字分布到表格大小範圍內
}
