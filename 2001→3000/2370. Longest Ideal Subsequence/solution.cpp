class Solution {
public:
    int longestIdealString(string s, int k) {
      int n=s.size();
      int ans=0;
      vector<int> dp(26,0);
      for(int i=0;i<n;i++){
        int element=s[i]-'a';
        // Left: Check for the longest ideal string by looking at characters to the left of the current character
        for(int j=element;j>=0&&j>=(element-k);j--){
            dp[element]=max(dp[element],dp[j]+1);
        }
        // Right: Check for the longest ideal string by looking at characters to the right of the current character
        for(int j=element+1;j<26&&j<=(element+k);j++){
            dp[element]=max(dp[element],dp[j]+1);
        }
        ans=max(ans,dp[element]);
      }
      // If no ideal string is found, return 1 as the minimum length of an ideal string is 1
      if(ans==0)return 1;
      return ans;
    }
};

/* 
Approach:

This solution uses dynamic programming to find the longest ideal string in a given string `s` with a maximum length difference of `k` between any two characters.

    1. Initialize a dynamic programming array `dp` with size 26 to store the longest ideal string length ending at each character.
    2. Iterate through each character in the string `s`.
    3. For each character, check for the longest ideal string by looking at characters to the left and right within the allowed length difference `k`.
    4. Update the `dp` array with the maximum length found for the current character.
    5. Keep track of the maximum length found across all characters.
    6. If no ideal string is found, return 1 as the minimum length of an ideal string is 1.

Complexity:
    Time Complexity: O(n*k), where n is the length of the string `s` and k is the maximum length difference allowed between any two characters. This is because for each 
    character in the string, we potentially check up to `k` characters to the left and right.
    Space Complexity: O(1), as the size of the dynamic programming array `dp` is constant and does not depend on the input size.

This approach is efficient for solving the problem within the given constraints, as it systematically explores the string to find the longest ideal string with a maximum length difference of `k`.
*/