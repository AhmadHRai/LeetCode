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
    // Function to find and calculate distances between critical points in a linked list
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;  // Vector to store indices of critical points
        ListNode* prev = nullptr;    // Pointer to previous node
        ListNode* curr = head;       // Pointer to current node
        int position = 0;            // Variable to track current position in the list
        
        // Traverse the linked list to find critical points
        while (curr != nullptr && curr->next != nullptr) {
            if (prev != nullptr && curr->next != nullptr) {
                // Check if the current node is a critical point
                if ((curr->val > prev->val && curr->val > curr->next->val) || 
                    (curr->val < prev->val && curr->val < curr->next->val)) {
                    criticalPoints.push_back(position);  // Add index of critical point to vector
                }
            }
            prev = curr;        // Move prev to current node
            curr = curr->next;  // Move curr to next node
            position++;         // Increment position counter
        }
        
        // If less than two critical points found, return {-1, -1} as specified
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        // Calculate minimum and maximum distances between critical points
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        // Iterate through criticalPoints vector to find minimum distance
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        // Return vector with minimum and maximum distances between critical points
        return {minDistance, maxDistance};
    }
};

/* 
Approach:
    Finding Critical Points:
    - Traverse the linked list to identify critical points where the value of a node is greater than both its predecessor and successor, or less than both.
    - Store the indices of these critical points in the `criticalPoints` vector.
    
    Calculating Distances:
    - If fewer than two critical points are found, return {-1, -1} indicating no valid distances.
    - Compute the maximum distance between the first and last critical points.
    - Compute the minimum distance between consecutive critical points in the `criticalPoints` vector.
    
Complexity:
    Time Complexity:
    - O(n), where n is the number of nodes in the linked list. The function traverses the list once to find critical points and calculates distances, performing constant-time operations in each iteration.
    
    Space Complexity:
    - O(m), where m is the number of critical points found. The function uses additional space proportional to the number of critical points to store their indices.
*/
