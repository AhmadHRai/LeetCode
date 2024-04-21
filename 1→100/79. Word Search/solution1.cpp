class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Iterate over each cell in the board.
        for (unsigned int i = 0; i < board.size(); i++) 
            for (unsigned int j = 0; j < board[0].size(); j++) 
                // If the word can be formed starting from the current cell, return true.
                if (dfs(board, i, j, word))
                    return true;
        // If the word cannot be formed from any cell, return false.
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        // Base case: If the word is empty, it means the word has been found, so return true.
        if (!word.size())
            return true;
        // If the current cell is out of bounds or does not match the first character of the word, return false.
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
            return false;
        // Mark the current cell as visited by replacing its character with '*'.
        char c = board[i][j];
        board[i][j] = '*';
        // Recursively check the neighboring cells to see if the word can be formed from there.
        string s = word.substr(1);
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        // Backtrack by restoring the original character in the current cell.
        board[i][j] = c;
        // Return true if the word can be formed, otherwise return false.
        return ret;
    }
};

/*
Approach Summary

    This solution uses a depth-first search (DFS) to explore all possible paths in the board that could form the given word. It starts 
    by iterating over each cell in the board. For each cell, it checks if the word can be formed starting from that cell. If the word 
    can be formed, it returns true. If the word cannot be formed from any cell, it returns false.

    The DFS function checks if the current cell can be the starting point of the word. If the word is empty, it means the word has been 
    found, so it returns true. If the current cell is out of bounds or does not match the first character of the word, it returns 
    false. It then marks the current cell as visited by replacing its character with '*'. It then recursively checks the neighboring 
    cells (up, down, left, and right) to see if the word can be formed from there. If any of the recursive calls return true, it means 
    the word can be formed, so it returns true. After exploring all paths, it backtracks by restoring the original character in the 
    current cell.

Time Complexity Analysis

    The time complexity is O(N*4^L), where N is the number of cells in the board, and L is the length of the word. This is because in 
    the worst case, the algorithm explores all cells and all possible paths of length L.

Space Complexity Analysis

    The space complexity is O(L), where L is the length of the word. This is because the maximum depth of the recursive call stack is 
    proportional to the length of the word.

 */
