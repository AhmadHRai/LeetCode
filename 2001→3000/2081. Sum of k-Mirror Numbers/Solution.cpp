class Solution {
public:
    // Convert number to base-k and return as string
    string toBaseK(long long num, int k) {
        string res = "";
        while (num > 0) {
            res += (num % k) + '0';
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    // Generate palindromes in base 10
    vector<long long> generatePalindromes(int length) {
        vector<long long> res;
        int half = pow(10, (length - 1) / 2);
        int start = (length == 1) ? 1 : half;
        int end = pow(10, (length + 1) / 2);
        for (int i = start; i < end; ++i) {
            string first = to_string(i);
            string pal = first;
            int j = (length % 2 == 0) ? first.size() - 1 : first.size() - 2;
            while (j >= 0)
                pal += first[j--];
            res.push_back(stoll(pal));
        }
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int length = 1;

        while (count < n) {
            vector<long long> palindromes = generatePalindromes(length);
            for (long long num : palindromes) {
                if (isPalindrome(toBaseK(num, k))) {
                    sum += num;
                    count++;
                    if (count == n)
                        return sum;
                }
            }
            length++;
        }
        return sum;
    }
};