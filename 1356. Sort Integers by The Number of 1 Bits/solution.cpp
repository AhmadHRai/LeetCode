class Solution {
public:
    // This function takes a vector of integers as input and returns a vector of integers sorted by the number of 1s in their binary representation
    vector<int> sortByBits(vector<int>& arr) {
        // This line sorts the input vector using the compare function defined below
        sort(arr.begin(),arr.end(),compare);
        // This line returns the sorted vector
        return arr;
    }
    // This function takes two integers as input and returns true if the first one has less or equal number of 1s in its binary representation than the second one, or false otherwise
    static bool compare(int a, int b){
        // This line calculates the number of 1s in the binary representation of a using the numberof1s function defined below
        int p = numberof1s(a);
        // This line calculates the number of 1s in the binary representation of b using the same function
        int q = numberof1s(b);
        // This if-else block compares the number of 1s in a and b and returns true or false accordingly
        if(p==q){
            // If a and b have the same number of 1s, then return true if a is less than or equal to b, or false otherwise
            return (a<=b);
        }
        else{
            // If a and b have different number of 1s, then return true if a has less 1s than b, or false otherwise
            return (p<q);
        }
    }
    // This function takes an integer as input and returns the number of 1s in its binary representation
    static int numberof1s(int a){
        // This variable keeps track of the count of 1s
        int count = 0;
        // This while loop iterates until a becomes zero
        while(a){
            // This line performs a bitwise AND operation between a and a-1, which removes the rightmost 1 from a
            a = a&(a-1);
            // This line increments the count by one
            count++;
        }
        // This line returns the final count
        return count;
    }
};

/* 
The time complexity of this code is O(n log n), where n is the size of the input vector. This is because the sorting algorithm used by C++ STL sort function has an average 
case complexity of O(n log n), and the compare function has a constant time complexity of O(1).

the space complexity is O(1). The C++ STL sort function does not use any extra space apart from the input and output vectors. It only uses stack space for recursive calls, 
which is bounded by O(log n) 1. However, the space complexity is measured by the amount of additional space used by the algorithm, not the total space. Therefore, the space 
complexity is O(1) 2
 */