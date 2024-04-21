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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Initialize two pointers, f and s, to traverse list1.
        // f is used to find the node before the insertion point,
        // and s is used to find the node after the insertion point.
        ListNode *f=list1,*s=list1;
        
        // Move f to the node before the insertion point in list1.
        for(int i=0;i<a-1;i++) f=f->next;
        
        // Move s to the node after the insertion point in list1.
        for(int i=0;i<b;i++) s=s->next;
        
        // Connect the node before the insertion point in list1 to the head of list2.
        f->next=list2;
        
        // Move list2 to the end of list2 to find the last node.
        while(list2->next!=NULL)
            list2=list2->next;
        
        // Connect the last node of list2 to the node after the insertion point in list1.
        list2->next=s->next;
        
        // Return the head of the merged list, which is the head of list1.
        return list1;
    }
};

/* 
Approach:
    The approach involves finding the correct positions in list1 where list2 should be inserted. It uses two pointers, f and s, to navigate through list1. f is moved to the node just 
    before the insertion point, and s is moved to the node just after the insertion point. Then, f->next is set to the head of list2, effectively inserting list2 into list1 at the 
    correct position. Finally, the last node of list2 is connected to the node following s in list1, completing the merge.

Complexity:
    Time Complexity: The time complexity of this solution is O(N), where N is the total number of nodes in list1 and list2. This is because the algorithm iterates through list1 to find the insertion points and then through list2 to find its end.

    Space Complexity: The space complexity is O(1), which means the space required does not grow with the size of the input lists. This is because only a fixed number of pointers (f and s) are used, and their space requirements do not depend on the size of the lists.
 */