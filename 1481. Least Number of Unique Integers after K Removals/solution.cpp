
/* 
Approach:
    The C++ code is a solution to the problem of finding the least number of unique integers in an array after removing k elements. The code uses an unordered map to count the 
    frequency of each element in the array, and then sorts the frequencies in a vector. The code then iterates through the vector and removes the elements with the smallest frequencies 
    until k becomes zero or negative. The code then returns the number of non-zero frequencies in the vector, which represents the number of unique integers left in the array. */

class Solution {
public:
    // Define a function that takes two parameters: a vector of integers representing the array, an integer representing the number of elements to remove, and returns an integer representing the least number of unique integers in the array after removing k elements
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Declare an unordered map of integers to integers, which will store the frequency of each element in the array
        unordered_map<int,int>mp;
        // Loop through the array and increment the frequency of each element in the map
        for(auto a : arr)mp[a]++;
        // Declare a vector of integers, which will store the frequencies of the elements in the map
        vector<int>v;
        // Declare an integer variable named cnt, which will store the number of unique integers in the array after removing k elements
        int cnt=0;
        // Loop through the map and push the frequency of each element to the vector
        for(auto a :mp){
            v.push_back(a.second);
        }
        // Sort the vector in ascending order, so that the smallest frequencies are at the front
        sort(v.begin(),v.end());
        // Loop through the vector from the first element to the last element
        for(int i =0;i<v.size();i++){
            // If k is greater than the current frequency, it means we can remove all the elements with that frequency from the array, so we subtract the frequency from k and set the frequency to zero in the vector
            if(k > v[i]){
                k-=v[i];
                v[i]=0;
            // Else, if k is less than or equal to the current frequency, it means we can only remove some of the elements with that frequency from the array, so we subtract k from the frequency and set k to zero
            } else{
                v[i] -= k;
                k =0;
            }
            // If the current frequency is not zero, it means there are still some elements with that frequency left in the array, so we increment the cnt variable by one
            if(v[i]!=0)cnt++;
        }
        // Return the cnt variable as the answer
        return cnt;
    }
};

/* 
Complexity:
    Time complexity: The code has three main loops: one that iterates over the array, one that iterates over the map, and one that iterates over the vector. The first loop takes O (n) 
    time, where n is the size of the array. The second loop takes O (m) time, where m is the number of unique elements in the array. The third loop also takes O (m) time. The sorting 
    of the vector takes O (m log m) time. Therefore, the total time complexity is O (n + m log m), which is bounded by O (n log n) in the worst case when m = n.

    Space complexity: The code uses an unordered map and a vector to store the frequencies of the elements. The map takes O (m) space, where m is the number of unique elements in the 
    array. The vector takes O (m) space as well. Therefore, the total space complexity is O (m), which is bounded by O (n) in the worst case when m = n.
 */