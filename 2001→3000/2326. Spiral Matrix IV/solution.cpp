/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Function to fill an m x n matrix in a spiral order using values from a linked list
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1)); // Initialize the matrix with -1
        const int layer = min((m + 1) / 2, (n + 1) / 2); // Calculate the number of layers
        ListNode* curr = head; // Pointer to traverse the linked list
        
        for (int k = 0; k < layer; k++) {
            // Traverse the top row from left to right
            for (int j = k; j < n - k; j++, curr = curr->next) {
                if (curr) ans[k][j] = curr->val;
                else break;
            }
            // Traverse the right column from top to bottom
            for (int i = k + 1; i < m - k; i++, curr = curr->next) {
                if (curr) ans[i][n - 1 - k] = curr->val;
                else break;
            }
            // Traverse the bottom row from right to left
            for (int j = n - k - 2; j > k; j--, curr = curr->next) {
                if (curr) ans[m - 1 - k][j] = curr->val;
                else break;
            }
            // Traverse the left column from bottom to top
            for (int i = m - 1 - k; i > k; i--, curr = curr->next) {
                if (curr) ans[i][k] = curr->val;
                else break;
            }
            if (!curr) break; // Break if the list runs out of elements
        }
        return ans; // Return the filled matrix
    }
};

// Static initializer to optimize I/O operations
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

/*
Approach Summary:
- The `spiralMatrix` function fills an `m x n` matrix in a spiral order using the values from a singly linked list.
- The matrix is filled layer by layer, starting from the outermost layer and moving inward.
- The function traverses the linked list to populate each cell of the matrix in the specified spiral order.

Time Complexity:
- O(m * n), where m is the number of rows and n is the number of columns in the matrix. Each cell of the matrix is filled exactly once.

Space Complexity:
- O(m * n), where m is the number of rows and n is the number of columns. The space is used for the matrix `ans`.
*/
