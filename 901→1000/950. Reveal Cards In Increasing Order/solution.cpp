class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort the deck in ascending order.
        sort(begin(deck), end(deck));
        // Initialize a list with indices from 0 to the size of the deck.
        list<int> l(deck.size());
        iota(begin(l), end(l), 0); // Fill the list with consecutive integers.
        // Initialize a result vector with the same size as the deck.
        vector<int> res(deck.size());
        // Initialize an iterator to the beginning of the list.
        auto lp = l.begin();
        // Iterate through the list, skipping elements based on the toggle of the skip variable.
        for (int i = 0, skip = 0; !l.empty(); skip = !skip) {
            // If the iterator has reached the end of the list, reset it to the beginning.
            if (lp == l.end()) lp = l.begin();
            // If the skip flag is set, increment the iterator to skip the current element.
            if (skip) ++lp;
            else {
                // Otherwise, assign the current deck element to the position indicated by the iterator in the result vector.
                res[*lp] = deck[i++];
                // Remove the current element from the list and increment the iterator.
                l.erase(lp++);
            }
        }
        // Return the result vector.
        return res;
    }
};

/* 
Approach

    The solution first sorts the deck in ascending order. It then initializes a list with indices from 0 to the size of the deck and a result vector with the same size as the deck. 
    The solution iterates through the list, skipping elements based on the toggle of the skip variable. If the skip flag is set, it increments the iterator to skip the current 
    element. Otherwise, it assigns the current deck element to the position indicated by the iterator in the result vector and removes the current element from the list. This process 
    ensures that the deck is rearranged in such a way that the elements are revealed in increasing order, with each element being revealed after the previous one.

Complexity

    Time complexity: O(n log n), where n is the number of elements in the deck. This is due to the sorting of the deck.
    
    Space complexity: O(n), as the solution uses a list and a vector with the same size as the deck.
 */
