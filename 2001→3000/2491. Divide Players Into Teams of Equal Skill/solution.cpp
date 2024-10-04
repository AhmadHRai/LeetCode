#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Step 1: Sort the skill array to easily form pairs
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        // Calculate the required sum for each pair
        int totalSkill = skill[0] + skill[n - 1]; 
        long long chemistrySum = 0; // Initialize total chemistry sum

        // Step 2: Pair players using two pointers
        for (int i = 0; i < n / 2; i++) {
            // Check if the sum of current pair matches the required totalSkill
            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1; // Invalid configuration, return -1
            }
            // Calculate the chemistry (product of pair) and add it to the sum
            chemistrySum += (long long)skill[i] * skill[n - i - 1];
        }

        return chemistrySum; // Return total chemistry
    }
};

/*
  Approach:
  The goal is to divide players into pairs such that the sum of skills in each 
  pair is the same, and to calculate the total chemistry of these pairs, defined 
  as the sum of the products of their skills.
  
  Steps:
  1. Sort the skill array. This allows us to pair the lowest skill player with 
     the highest skill player to achieve a consistent total skill across pairs.
  2. Define the required total skill for each pair as the sum of the lowest and 
     highest skill players.
  3. Use a loop to create pairs. For each pair, check if their skill sum matches 
     the required total skill. If not, return -1, indicating an invalid configuration.
  4. If valid, compute the chemistry for the pair as the product of their skills 
     and accumulate this value into a total chemistry sum.
  5. After processing all pairs, return the total chemistry sum.

  Complexity Analysis:
  - Time Complexity: O(N log N), where N is the number of players. This is due 
    to the sorting step. The pairing step runs in O(N).
  - Space Complexity: O(1), as we use a fixed amount of extra space regardless 
    of the input size.
 */
