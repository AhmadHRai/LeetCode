using int2=pair<int, int>;
const int N=1e5;
static int2 R[N];
static constexpr int M=1<<10, mask=M-1, bshift=10;
int freq[M];

void radix_sort(int2* nums, int n) {
    int2* buffer=(int2*)alloca(n*sizeof(int2));  // buffer
    int2* in=nums;
    int2* out=buffer;

    // 3 rounds covers 30 bits
    for (int round=0; round < 3; round++) {
        const int shift=round * bshift;
        memset(freq, 0, sizeof(freq));

        for (int i=0; i<n; i++)
            freq[(in[i].first>>shift) & mask]++;

        partial_sum(freq, freq+M, freq);

        for (int i=n-1; i >= 0; i--) {
            int x=(in[i].first>>shift) & mask;
            out[--freq[x]]=in[i];
        }

        // Swap pointers for the next round
        swap(in, out);
    }
    //data is currently in buffer. We must copy it back to nums.
    if (in != nums) {
        memcpy(nums, in, n * sizeof(int2));
    }
}

int2 nIdx[N];
int seq[N], values[N];
class Solution {
public:
    static vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n=nums.size();
        for(int i=0; i<n; i++)
            nIdx[i]={nums[i], i};

        // Sort nIdx
        radix_sort(nIdx, n);

        vector<int2> group={{0, 0}};// [s, e]= interval for group
        group.reserve(n);
        int prev=nIdx[0].first;

        // Create groups based on the limit condition
        for (int i=1; i<n; i++) {
            const int x=nIdx[i].first;
            if (x-prev <= limit)
                group.back().second=i;
            else
                group.push_back({i, i});
            prev=x;
        }

        // Sort indices within each group and assign values to nums
        for (auto& se : group) {
            auto [s, e]=se;
            int sn=e-s+1;
            for (int i=s, j=0; i<=e; i++){
                auto& [x, idx]=nIdx[i];
                values[j]=x;
                seq[j++]=idx;
            }

            sort(seq, seq+sn);
            for (int i=0; i<sn; i++) {
                nums[seq[i]]=values[i];
            }
        }

        return nums;
    }
};
