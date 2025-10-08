#include <vector>
#include <algorithm> // For std::sort and std::lower_bound
#include <cmath>     // For std::ceil if we were using floating point, but the integer trick is better

class Solution {
public:
    /**
     * @brief Calculates the number of successful spell-potion pairs.
     * @param spells A vector of integers representing the strengths of spells.
     * @param potions A vector of integers representing the strengths of potions.
     * @param success The minimum total strength for a pair to be successful.
     * @return A vector of integers where the i-th element is the count of potions
     * that will form a successful pair with the i-th spell.
     */
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        // Sort the potions vector to enable efficient searching (binary search).
        // Time Complexity: O(m log m), where m is the number of potions.
        std::sort(potions.begin(), potions.end());

        // Pre-allocate the result vector to avoid reallocations inside the loop.
        // The size will be equal to the number of spells.
        std::vector<int> successfulPairsCount(spells.size());
        int n = potions.size();

        // Iterate through each spell to find its successful potion pairs.
        // Time Complexity: O(s log m), where s is the number of spells.
        for (int i = 0; i < spells.size(); ++i) {
            long long currentSpellStrength = spells[i];

            // To find the minimum potion strength needed for a success, we calculate:
            // spell * potion >= success  =>  potion >= success / spell
            // Since we need an integer value, we need the ceiling of the division.
            // The formula (a + b - 1) / b is a standard integer arithmetic trick for ceil(a / b).
            // We cast to long long to prevent potential overflow in the numerator.
            long long minPotionStrength = (success + currentSpellStrength - 1) / currentSpellStrength;

            // Use std::lower_bound to find the first potion with strength >= minPotionStrength.
            // lower_bound performs a binary search.
            // Time Complexity: O(log m)
            auto it = std::lower_bound(potions.begin(), potions.end(), minPotionStrength);

            // The number of successful potions is the distance from this iterator to the end of the vector.
            successfulPairsCount[i] = std::distance(it, potions.end());
        }

        return successfulPairsCount;
    }
};