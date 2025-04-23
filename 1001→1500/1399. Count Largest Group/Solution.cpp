class Solution {
/*
int dsum(int n) {
    return n == 0 ? 0 : n % 10 + dsum(n / 10);
}
int countLargestGroup(int n) {
    int cnt[37] = {}, mx = 0;
    for (auto i = 1; i <= n; ++i)
        mx = max(mx, ++cnt[dsum(i)]);
    return count_if(begin(cnt), end(cnt), [&mx](int n) { return n == mx; });
}

// hashmap solution
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hashMap;
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;
            while (i0) {
                key += i0 % 10;
                i0 /= 10;
            }
            ++hashMap[key];
            maxValue = max(maxValue, hashMap[key]);
        }
        int count = 0;
        for (auto& [_, value] : hashMap) {
            if (value == maxValue) {
                ++count;
            }
        }
        return count;
    }
};
*/
public:
    int countLargestGroup(int n) {
        int freq[37] = {0};
        //1 <= n <= 10^4. the max of sumOfNumber() is 9+9+9+9=36; which save in freq[36] so size must be 37.
        int mx = 1;
        for(int i = 1; i <= n; i++) {
            mx = max(mx, ++freq[sumOfNumber(i)]);
        }
        return count(freq, freq+37, mx);
    }
private:
    int sumOfNumber(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};