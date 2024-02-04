class Solution {
public:
    string minWindow(string s, string t) {
        // create a vector of size 128 to store the frequency of each character in t
        vector<int> map(128,0);

        // loop through each character in t and increment its frequency in map
        for (char c : t) {
            map[c]++;
        }

        // initialize counter to the size of t, which is the number of characters we need to find in s
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;

        // loop through each character in s using end as the pointer
        while (end < s.size()){

            // if the current character is in t, decrement its frequency in map and decrement counter
            // this means we have found one more character in the current window
            if (map[s[end++]]-- > 0) {
                counter--;
            }

            // while counter is zero, which means we have found all the characters in t in the current window
            while (counter == 0) {

                // if the current window is smaller than the previous minimum window, update head and d
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }

                // if the character at begin is in t, increment its frequency in map and increment counter
                // this means we are moving the begin pointer to shrink the window and look for a smaller one
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }

        // if d is INT_MAX, it means we did not find any window that contains all the characters in t, so return an empty string
        // otherwise, return the substring of s from head to head + d, which is the minimum window
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

/* 
Complexity Analysis:
    The time complexity of this code is O(n), where n is the length of s, because we only scan through s once using the two pointers. 
    The space complexity of this code is O(1), because we only use a constant size vector map and a few variables.
 */