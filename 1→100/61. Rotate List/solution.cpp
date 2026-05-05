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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ogHead = head;
        if(!head) return head;
        auto it = head;
        int len = 1;
        while(it->next) {
            len++;
            it = it->next;
        };
        it->next = head;
        int mod = k % len;
        auto jt = head;

        for(auto i = 1; i < (len-mod); i++) {
            jt=jt->next;
        };
        head = jt->next;
        jt->next=nullptr;
        return head;
    }
};
