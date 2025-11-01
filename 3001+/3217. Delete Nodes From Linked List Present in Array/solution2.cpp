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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set for quick lookups
        unordered_set<int> values(nums.begin(), nums.end());

        // Skip nodes that are in the set
        while (head && values.count(head->val)) {
            head = head->next;
        }

        ListNode* curr = head;
        while (curr && curr->next) {
            // Skip nodes whose value is in the set
            while (curr->next && values.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        return head;
    }
};