class Trie {
public:
    vector<Trie*> v; // Children of the current Trie node
    bool isEnd; // Indicates if this node represents the end of a number
    int data; // Store the actual number

    // Constructor to initialize the Trie node
    Trie() {
        v = vector<Trie*>(10, nullptr); // Create children for digits 0-9
        isEnd = false; // Initially not the end of a number
        data = -1; // Default value for data
    }
};

class Solution {
    // Method to insert a number into the Trie
    void insert(Trie* node, int a) {
        Trie* root = node; // Start from the given node
        string key = to_string(a); // Convert the number to string

        // Insert each digit of the number into the Trie
        for (auto &x : key) {
            int curr = x - '0'; // Get the integer value of the character
            if (root->v[curr] == nullptr) 
                root->v[curr] = new Trie(); // Create a new Trie node if it doesn't exist
            root = root->v[curr]; // Move to the next node
        }

        // Mark the end of the number and store the number
        root->isEnd = true; 
        root->data = a; 
    }

    vector<int> ans; // Vector to store the results

    // Method to traverse the Trie and collect numbers in lexicographical order
    void printAll(Trie* root) {
        // If the current node marks the end of a number, add it to the results
        if (root->isEnd) {
            ans.push_back(root->data);
        }

        // Recursively visit all child nodes
        for (int i = 0; i < 10; i++) {
            if (root->v[i]) 
                printAll(root->v[i]); // Visit non-null children
        }
    }

public:
    // Main method to get numbers from 1 to n in lexicographical order
    vector<int> lexicalOrder(int n) {
        ans.clear(); // Clear previous results
        Trie* root = new Trie(); // Create a new Trie root
        // Insert all numbers from 1 to n into the Trie
        for (int i = 1; i <= n; i++) 
            insert(root, i);
        
        // Collect numbers from the Trie in lexicographical order
        printAll(root);
        return ans; // Return the collected numbers
    }
};

/*
Approach:
1. Create a Trie data structure to store the numbers from 1 to n.
2. Insert each number as a string into the Trie, where each character represents a digit.
3. Use a depth-first traversal to collect the numbers in lexicographical order.
4. Return the result as a vector of integers.

Time Complexity:
- O(n * k) where `n` is the number of integers from 1 to `n` and `k` is the average number of digits in those integers (k = log10(n)).

Space Complexity:
- O(n * k) for storing the Trie nodes and the resulting integers.
*/
