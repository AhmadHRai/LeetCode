# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head, n):
        # Initialize two pointers, 'fast' and 'slow', to the head of the list
        fast = slow = head
        # Move 'fast' n steps ahead of 'slow'
        for _ in range(n):
            fast = fast.next
        # If 'fast' has reached the end of the list, 'slow' is at the Nth node from the end
        if not fast:
            return head.next
        # Move both 'fast' and 'slow' until 'fast' reaches the end of the list
        while fast.next:
            fast = fast.next
            slow = slow.next
        # Remove the Nth node from the end by skipping it in the 'next' pointer of the node before it
        slow.next = slow.next.next
        # Return the modified list starting from the head
        return head

""" 
Approach:

    This solution uses the two-pointer technique to find the Nth node from the end of the list.
    Initially, both fast and slow pointers are at the head of the list.
    The fast pointer is moved n steps ahead. If fast reaches the end of the list, it means the list has fewer than n nodes, and the head of the list should be returned as  
        the next node after the head.
    If fast does not reach the end, it moves one step at a time until it does. The slow pointer also moves one step at a time.
    By the time fast reaches the end, slow is at the node before the Nth node from the end. This is because fast moves n steps ahead, and slow moves at the same pace, so the 
        difference in their positions is n.
    To remove the Nth node from the end, the next pointer of the node before it is updated to skip the Nth node, effectively removing it from the list.
    Finally, the modified list starting from the head is returned.

Complexity Analysis:

    Time Complexity:    The time complexity is O(L), where L is the length of the linked list. This is because each node is visited at most twice: once by fast and once by 
    slow.
    
    Space Complexity:   The space complexity is O(1) because no additional space is used that scales with the size of the input list. The two pointers and a constant amount 
    of variables are used, regardless of the list size.
    
 """