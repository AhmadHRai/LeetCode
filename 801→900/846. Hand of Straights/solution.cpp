/**
 * Checks if the given hand of cards can be divided into groups of size groupSize,
 * where each group consists of consecutive cards with the same value.
 *
 * @param hand A vector of integers representing the hand of cards.
 * @param groupSize An integer representing the size of each group.
 * @return True if the hand can be divided into valid groups, false otherwise.
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();

        // Check if the total number of cards is divisible by groupSize
        if (handSize % groupSize != 0) {
            return false;
        }

        // Map to store the count of each card value
        map<int, int> cardCount;
        for (int i = 0; i < handSize; i++) {
            cardCount[hand[i]]++;
        }

        // Process the cards until the map is empty
        while (!cardCount.empty()) {
            // Get the smallest card value
            int currentCard = cardCount.begin()->first;
            
            // Check each consecutive sequence of groupSize cards
            for (int i = 0; i < groupSize; i++) {
                // If a card is missing or has exhausted its occurrences
                if (cardCount[currentCard + i] == 0) {
                    return false;
                }
                // Decrease the count of the current card value
                cardCount[currentCard + i]--;
                // Remove the card value from the map if its occurrences are exhausted
                if (cardCount[currentCard + i] < 1) {
                    cardCount.erase(currentCard + i);
                }
            }
        }

        // If all groups are formed successfully, return true
        return true;
    }
};

/*
Approach:
    - Check if the total number of cards is divisible by groupSize. If not, return false.
    - Use a map (cardCount) to count occurrences of each card value in the hand.
    - Process the cards in the hand until the map is empty:
        - Get the smallest card value from the map.
        - Check if consecutive sequences of groupSize cards can be formed:
            - If any card in the sequence is missing or its occurrences are exhausted, return false.
            - Decrease the count of each card in the sequence.
            - Remove card values from the map if their occurrences are exhausted.
    - If all groups of size groupSize are formed successfully, return true.

Complexity Analysis:
    - Time Complexity: O(n log n)
      where n is the number of cards in the hand. The sorting of keys in a map takes O(n log n) time, and each card is processed once.
      
    - Space Complexity: O(n)
      where n is the number of cards in the hand. Extra space is used for the map to store card counts.

*/

