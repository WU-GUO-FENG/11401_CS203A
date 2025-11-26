/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    整數的hash函數使用乘法散列法，選擇一個大質數來打亂輸入鍵的分布以減少碰撞的可能性。
    字串的hash函數則採用DJB2算法，通過對每個字元進行位移和加法運算來生成hash值。

   Development History:
    - 2025/11/21: 上傳初始程式碼。
    - 2025/11/26: 新增註解和參考、修改程式碼宣告、修改錯誤處理機制。


   References:
    - CSDN DJB2 算法：https://blog.csdn.net/gitblog_00521/article/details/151056038
    - 透過Gemini給出建議的質數大數
    
   Developer: WU-GUO-FENG <s1113306@mail.yzu.edu.tw>

 */
#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design

    if (m <= 0){
        printf ("hash table大小輸入錯誤");
        return -1;
    }
    if( key < 0){
        printf ("不支援負整數鍵值");
        return -2;
    }
    unsigned int Hash_Value = 2654435769U;  //選擇大數質數來打亂hash結果  
    unsigned int result;

    result = key * Hash_Value;

    return result % m; //最後把結果限制在表格大小內
}

int myHashString(const char* str, int m) {
    // TODO: replace with your own design
    if (m <= 0){
        printf ("hash table大小輸入錯誤");
        return -1;
    }    
    if (str == NULL || *str == '\0'){
        printf ("字串鍵值不可為空");
        return -2; 
    }
    unsigned long hash_value = 5381; // 初始值選擇一個質數

    while (*str != '\0') {
        hash_value = ((hash_value << 5) + hash_value) + *str;
        str++;
    }  //不斷對hash_value進行位移和加法運算，來打亂字串的分布

    // 最後將數字分布到表格大小範圍內
    return (int)(hash_value % m);

}

