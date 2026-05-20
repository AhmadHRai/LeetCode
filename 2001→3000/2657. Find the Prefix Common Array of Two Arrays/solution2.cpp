#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> v;
        int n = (int)A.size();
        vector<int> C(n,0);
        if (n == 1) {
            C[0] = 1;
            return C;
        }
        for (int i = 0; i < n; i++){
            int k = 0;

            for (int j = 0; j <= i; j++){
                for (int l = 0; l <= i; l++){
                    if (A[j] == B[l]){
                        k++;
                        break;
                    }
                }
            }
            C[i] = k;
        }return C;
    }
};  
#pragma GCC optimize("Ofast")

#include <iostream>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}
