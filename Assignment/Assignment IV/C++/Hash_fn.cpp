
/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    整數的hash函數使用乘法散列法，字串的hash函數則採用DJB2算法，同時增加了MurmurHash 3的混淆步驟
    預計能夠提升hash值的分布均勻性。
    狀態繼承會破壞hash的確定性，因此改為增加MurmurHash 3。

   Development History:
    - 2025/11/21: 上傳初始程式碼
    - 2025/11/26: 新增註解和參考、修改Hashint從繼承狀態改為增加MurmurHash 3，。

   References:
    - CSDN MurmurHash 3 算法：https://blog.csdn.net/weixin_43114209/article/details/143133955
    - 透過Gemini給出建議的質數大數

   Developer: WU-GUO-FENG <s1113306@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    
    if (m <= 0 || key < 0)
        return -1;  // 處理錯誤輸入
    
    unsigned int A = 2654435769U;  //選擇大數質數來打亂hash結果  
        
    unsigned int result = key * A;

    result ^= (result >> 16); // 使用MurmurHash 3算法混淆hash值
    result *= 0x85ebca6bU;
    result ^= (result >> 13);

    return result % m;   //最後把結果限制在表格大小內
}

int myHashString(const string& str, int m) {
    if (m <= 0 || str.empty())
        return -1;   //處理錯誤輸入

    uint32_t hash_value = 5381U; // 初始值選擇一個質數
    unsigned char c;

    for (char c : str) {
        hash_value = ((hash_value << 5) + hash_value) + c;
    }   //不斷對hash_value進行位移和加法運算，來打亂字串的分布
    
    hash_value ^= (hash_value >> 16);   // 使用MurmurHash 3算法混淆hash值 
    hash_value *= 0x85ebca6bU; 
    hash_value ^= (hash_value >> 13);

    return (int)(hash_value % m);     // 最後將數字分布到表格大小範圍內

}
