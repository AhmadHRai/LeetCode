#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool canBeEqual(std::string s1, std::string s2) {
        if (s1[0] > s1[2]) std::swap(s1[0], s1[2]);
        if (s2[0] > s2[2]) std::swap(s2[0], s2[2]);

        if (s1[1] > s1[3]) std::swap(s1[1], s1[3]);
        if (s2[1] > s2[3]) std::swap(s2[1], s2[3]);

        uint32_t val1, val2;
        std::memcpy(&val1, s1.data(), 4);
        std::memcpy(&val2, s2.data(), 4);

        return val1 == val2;

        // return *((uint32_t*)s1.data()) == *((uint32_t*)s2.data());
    }
};
