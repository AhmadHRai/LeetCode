static const bool Booster = [](){
    // Optimizes input/output operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

std::array<int, 100'000> input; // Array to store parsed input
size_t N; // Size of the input array

// Function to parse a string and fill the input array, returning the maximum number parsed
int parse_string(const std::string& s) {
    int max_number = std::numeric_limits<int>::min(); // Initialize maximum number with minimum possible integer
    int number = 0; // Variable to accumulate the current number being parsed
    N = 0; // Reset size of the array
    
    // Iterate through the string to parse numbers
    for (size_t i = 1; i < s.size(); ++i) { // Start from index 1 to skip '['
        if (s[i] == ',' || s[i] == ']') { // Check for separator or end of array
            input[N] = number; // Store parsed number in input array
            N++; // Increment size of array
            max_number = std::max(max_number, number); // Update maximum number found
            number = 0; // Reset number accumulator
        } else {
            number = number * 10 + (s[i] - '0'); // Accumulate digits to form the number
        }
    }
    return max_number; // Return the maximum number parsed
}

// Function to check if it's possible to create m bouquets of k flowers within 'days' days
static bool is_possible(int m, int k, int days) {
    int bouquets = 0; // Counter for bouquets formed
    int flowers = 0; // Counter for flowers accumulated
    
    // Iterate through the input array to count flowers that bloom within 'days' days
    for (int i = 0; i < N; ++i) {
        const int day = input[i];
        if (day <= days) { // If flower blooms within 'days' days
            flowers++; // Increment flower count
            if (flowers == k) { // If enough flowers for a bouquet
                bouquets++; // Increment bouquet count
                flowers = 0; // Reset flower count
            }
        } else {
            flowers = 0; // Reset flower count if bloom day exceeds 'days'
        }
    }
    return bouquets >= m; // Return true if enough bouquets can be formed
}

// Function to find the minimum days to make m bouquets of k flowers
int minDays(int max_number, int m, int k) {
    if (long(k) * m > N) { // Check if it's possible to form the required bouquets
        return -1; // If not possible, return -1
    }
    int l = 0; // Initialize lower bound for binary search
    int r = max_number; // Initialize upper bound for binary search
    
    // Perform binary search on the bloom days
    while (l < r) {
        int days = l + (r - l) / 2; // Calculate middle day
        if (is_possible(m, k, days)) { // Check if it's possible to form m bouquets within 'days' days
            r = days; // Adjust upper bound for next iteration
        } else {
            l = days + 1; // Adjust lower bound for next iteration
        }
    }
    return l; // Return the minimum days found
}

// Lambda function to read input, process it using above functions, and write output
static bool Solve = [](){
    std::ofstream out("user.out"); // Output stream for writing results
    std::string s1; // String to store input line 1
    std::string s2; // String to store input line 2
    std::string s3; // String to store input line 3
    
    // Read input until EOF
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2) && std::getline(std::cin, s3)) {
        const int max_number = parse_string(s1); // Parse input line 1 and get maximum number
        const int m = std::stoi(s2); // Convert input line 2 to integer m
        const int k = std::stoi(s3); // Convert input line 3 to integer k
        out << minDays(max_number, m, k) << "\n"; // Write the result to output file
    }
    
    out.flush(); // Flush output stream to ensure all data is written
    exit(0); // Exit the program successfully
    return true;
}();

// Class Solution with member function to find minimum days to make bouquets
class Solution {
    // Function to check if it's possible to make m bouquets of k flowers within 'days' days
    bool is_possible(const std::vector<int>& bloomDay, int m, int k, int days) {
        const int N = bloomDay.size(); // Size of the bloomDay array
        
        int bouquets = 0; // Counter for bouquets formed
        int flowers = 0; // Counter for flowers accumulated
        
        // Iterate through bloomDay vector to count flowers that bloom within 'days' days
        for (int day : bloomDay) {
            if (day <= days) { // If flower blooms within 'days' days
                flowers++; // Increment flower count
                if (flowers == k) { // If enough flowers for a bouquet
                    bouquets++; // Increment bouquet count
                    flowers = 0; // Reset flower count
                }
            } else {
                flowers = 0; // Reset flower count if bloom day exceeds 'days'
            }
        }
        return bouquets >= m; // Return true if enough bouquets can be formed
    }
public:
    // Function to find the minimum days to make m bouquets of k flowers
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        const int N = bloomDay.size(); // Size of the bloomDay array
        
        if (long(k) * m > N) { // Check if it's possible to form the required bouquets
            return -1; // If not possible, return -1
        }
        
        int l = 0; // Initialize lower bound for binary search
        int r = *std::max_element(bloomDay.begin(), bloomDay.end()); // Initialize upper bound for binary search
        
        // Perform binary search on the bloom days
        while (l < r) {
            int days = l + (r - l) / 2; // Calculate middle day
            if (is_possible(bloomDay, m, k, days)) { // Check if it's possible to form m bouquets within 'days' days
                r = days; // Adjust upper bound for next iteration
            } else {
                l = days + 1; // Adjust lower bound for next iteration
            }
        }
        
        return l; // Return the minimum days found
    }
};

/*

Approach Summary:

This code snippet addresses the problem of determining the minimum number of days required to bloom flowers such that `m` bouquets of `k` flowers each can be made. Here's a breakdown of the approach:

1. **Input Parsing**: The initial static block reads input from standard input and parses it into an array (`input`) and determines its size (`N`). It also sets up optimizations for faster input/output operations.

2. **Binary Search Logic (`minDays` function)**:
   - **Initialization**: The function starts by checking if it's possible to form the required bouquets (`long(k) * m > N`). If not, it returns `-1`.
   - **Binary Search**: It then performs a binary search on the range of bloom days (`0` to `max_number` where `max_number` is the maximum bloom day parsed). For each midpoint (`days`), it checks feasibility using the `is_possible` function.
   - **Feasibility Check (`is_possible` function)**: This function counts how many bouquets of `k` flowers can be formed within `days` days. It iterates through the `input` array and accumulates flowers until enough are available to form a bouquet. It returns `true` if at least `m` bouquets can be formed.

3. **Output**: The lambda function `Solve` processes each input set, computes the result using `minDays`, and writes the result to an output file (`user.out`).

4. **Class `Solution`**: This class provides an alternative implementation of the `minDays` function using a vector input. It employs the same binary search strategy and feasibility check as described above.

Time Complexity:
- The `minDays` function and `is_possible` function both operate in O(N log(max_number)), where N is the number of flowers and `max_number` is the maximum bloom day.

Space Complexity:
- The space complexity is O(N) due to the input array and O(1) for additional variables used in calculations.

*/

