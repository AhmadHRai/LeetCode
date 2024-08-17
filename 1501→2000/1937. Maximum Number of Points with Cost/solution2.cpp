class Solution {
public:
    // Placeholder function, returns 0 for the standard maxPoints
    long long maxPoints(const vector<vector<int>>& points) {
        return 0ll;
    }
    
    // Function to compute maximum points for the given 2D vector of long long values
    long long maxPointsLL(vector<vector<long long>>& points, vector<long long>& leftMax) {
        // Get the number of rows (M) and columns (N) in the points matrix
        int M = (int) points.size(), N = (int) points[0].size();
        // Initialize the answer with the maximum value in the first row of points
        long long ans = *max_element(points[0].begin(), points[0].end());
        
        // Process each row starting from the second row
        for (int i = 1; i < M; i++) {
            // Compute leftMax values for the current row
            leftMax[0] = points[0][0];
            for (int j = 1; j < N; j++) {
                leftMax[j] = max(leftMax[j - 1] - 1, points[0][j]);
            }
            
            // Compute maximum points considering the rightmost element
            long long prevRightMax = points[0][N - 1];
            ans = max(ans, points[0][N - 1] = points[i][N - 1] + max(leftMax[N - 1], prevRightMax));
            
            // Update maximum points considering elements from right to left
            for (int j = N - 1; j-- > 0;) {
                prevRightMax = max(prevRightMax - 1, points[0][j]);
                ans = max(ans, points[0][j] = points[i][j] + max(leftMax[j], prevRightMax));
            }
        }
        
        // Return the maximum points found
        return ans;
    }
};

// Initialization function to set up input/output and call maxPointsLL
auto init = ([]() -> bool {
    ios::sync_with_stdio(false);  // Disable synchronization with C I/O
    cin.tie(nullptr);  // Untie cin from cout
    ofstream out("user.out");  // Output file stream for results
    Solution sol;  // Create an instance of Solution
    vector<long long> leftMax(100000);  // Vector to store left max values for processing
    
    for (string s; getline(cin, s); out << '\n') {
        // Print the current input string to output
        cout << s << '\n';
        
        // Parse the input string into a vector of vector<long long>
        vector<vector<long long>> points;
        size_t N = 0, SL = s.length();
        for (size_t i = 2; i < SL; i += 3) {
            points.push_back({});
            long long curr = 0;
            vector<long long>& ref = points[points.size() - 1];
            if (N > 0) ref.reserve(N);  // Reserve space if N is already set
            for (; s[i] != ']'; i++) {
                if ('0' <= s[i] && s[i] <= '9') {
                    curr = 10 * curr + (s[i] - '0');  // Build the current number
                } else {
                    ref.push_back(curr);  // Add current number to the vector
                    curr = 0;  // Reset current number
                }
            }
            ref.push_back(curr);  // Add the last number in the vector
            if (!N) N = ref.size();  // Set N to the size of the first vector
        }
        
        // Call maxPointsLL function and output the result
        out << sol.maxPointsLL(points, leftMax);
    }
    
    out.flush();  // Flush the output stream
    exit(0);  // Exit the program
    return true;
})();
/*
Approach Summary:
- **maxPointsLL** function:
  - Initializes the maximum points (`ans`) with the maximum value from the first row of the `points` matrix.
  - Iterates through each row from the second row onwards:
    - Computes the `leftMax` values which represent the maximum points achievable from the left side of each column.
    - Computes the maximum points considering the rightmost element and updates `ans`.
    - Updates `ans` for all columns by considering both `leftMax` and `prevRightMax`.
  - Returns the highest value found in the `ans`.

Time Complexity:
- O(M * N), where M is the number of rows and N is the number of columns. Each cell is processed in constant time.

Space Complexity:
- O(N), where N is the number of columns, for storing the `leftMax` vector. The space used for other variables is constant.
*/
