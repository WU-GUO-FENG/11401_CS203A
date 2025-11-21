
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
    // TODO: replace with your own design
    static unsigned int previous_hash = 0; 
    
    if (m <= 0 || key < 0) 
        return -1;
    
    unsigned int A = 2654435769U; 
    
    unsigned int combined_key = (unsigned int)key + previous_hash;
    
    unsigned int result = combined_key * A;

    previous_hash = result; 

    return result % m;
}

int myHashString(const std::string& str, int m) {
    if (m <= 0 || str.empty()) 
        return -1;

    std::uint32_t hash_value = 5381U; 

    for (char c : str) {
        hash_value = ((hash_value << 5) + hash_value) + (unsigned char)c;
    }

    const std::uint32_t C = 0x85ebca6bU; 
    
    hash_value ^= (hash_value >> 16); 
    
    hash_value *= C; 
    
    hash_value ^= (hash_value >> 13);

    return (int)(hash_value % m);
}
